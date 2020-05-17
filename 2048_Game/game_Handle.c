#include "common.h"

void game_Main(void);

//**************************************
// Run game option according to choice
//**************************************
int game_Route(int choice) {
	int status = TRUE;

	switch (choice)
	{
	case CHC_BEGIN:
		game_Main();
		break;
	case CHC_INSTRUCT:
		draw_Instruct();
		break;
	case CHC_EXIT:
		exit(0);
		break;
	default:
		status = FALSE;
		break;
	}

	if (FALSE == status) {
		//TODO: ILLEGAL COMMAND HANDLE
	}

	return status;
}

//****************************************
// Align the non-zero number to high grid
// e.g. 2 0 2 4 ----> 0 2 2 4
//****************************************
static int nums_Align(int* line) {
	int i, j;
	int ret = ST_FAIL;
	
	j = LEN - 1;
	// the valid number should move to end of the line
	for (i = LEN - 1; i > 0; i--) {
		// exchange higher hole with lower valid number
		if (line[i] == 0) {
			j = (j - 1 < i - 1)? (j - 1):(i -1);
			// find valid number
			while ((line[j] == 0) && (j >= 0)) {
				j--;
			}

			if (j < 0) {
				break;
			}
			line[i] = line[j];
			line[j] = 0;
			ret = ST_RUN;   // effective movement is possible
		}
	}

	return ret;
}

//********************************************
// Add the numbers in one row or column
// Return value indicates the move capability
//********************************************
static int nums_Add(int* line) {
	extern gameInfo_t g_GameInfo;
	int i;
	int ret = ST_FAIL;

	// e.g. 2 0 4 4 --->  0 2 4 4
	ret |= nums_Align(line);

	// add the adjacent and equal numbers
	// the sum shows in higher grid
	// e.g. 0 2 4 4 ----> 0 2 0 8
	for (i = LEN - 1; i > 0 ; i--) {
		if ((line[i - 1] == line[i])&&(0 != line[i])) {
			line[i] = (line[i] << 1);
			line[i - 1] = 0;
			g_GameInfo.score += line[i];
			g_GameInfo.numCount--;

			if (line[i] == 2048)
			{
				return ST_WIN;
			}

			ret = ST_RUN;
		}
	}

	// e.g. 0 2 0 8 ----> 0 0 2 8
	ret |= nums_Align(line);

	return ret;
}
//********************************************
// Divide the game table into 4 lines
//********************************************
inline void divide_RowColumn(int dir, int fix, int arg, int* line, int table[4][4]) {
	switch (dir)
	{
	case D_UP:
		line[arg] = table[LEN - 1 - arg][fix];
		break;
	case D_LEFT:
		line[arg] = table[fix][LEN - 1 - arg];
		break;
	case D_RIGHT:
		line[arg] = table[fix][arg];
		break;
	case D_DOWN:
		line[arg] = table[arg][fix];
		break;
	default:
		break;
	}
}

//********************************************
// Combine the 4 lines to game table
//********************************************
inline void combine_RowColumn(int dir, int fix, int arg, int* line, int table[4][4]) {
	switch (dir)
	{
	case D_UP:
		table[LEN - 1 - arg][fix] = line[arg];
		break;
	case D_LEFT:
		table[fix][LEN - 1 - arg] = line[arg];
		break;
	case D_RIGHT:
		table[fix][arg] = line[arg];
		break;
	case D_DOWN:
		table[arg][fix] = line[arg];
		break;
	default:
		break;
	}
}

//********************************************
// Try to move in specific direction
//********************************************
static int kb_Move(int dir) {
	extern int g_GameTable[LEN][LEN];
	int line[LEN] = { 0, 0, 0, 0 };
	int i, j;
	int ret = ST_FAIL;


	for (i = 0; i < LEN; i++) {
		for (j = 0; j < LEN; j++) {
			divide_RowColumn(dir, i, j, line, g_GameTable);   	
		}

		ret |= nums_Add(line);        // try to add and align numbers

		for (j = 0; j < LEN; j++) {
			combine_RowColumn(dir, i, j, line, g_GameTable);    
		}
	}

	return ret;
}

//********************************************
// ESC command handler
//********************************************
static int kb_Esc(void) {
	char ch;
	int ret;

	gotoxy(20, 23);
	color(YELLOW);
	printf("Are you sure to quit game? [y/n]");

	ch = _getch();

	if (('y' == ch) || ('Y' == ch)) {
		ret = ST_QUIT;
	}
	else {
		ret = ST_RESUME;             //N or other input is considered as continue command
	}

	return ret;
}

//********************************************
// Processing the keyboard input
//********************************************
static int kb_control(int key){
	int status = ST_FAIL;

	switch (key)
	{
	case D_UP:
	case D_LEFT:
	case D_RIGHT:
	case D_DOWN:
		status = kb_Move(key);
		break;
	case ESC:              // press ESC to pause or quit game
		status = kb_Esc();
		break;

	default:
		status = ST_ILLEGAL;
		break;
	}

	return status;
}

//********************************************
// Clear former screen, draw game table
//********************************************
void game_Begin(void) {
	int;
	extern gameInfo_t g_GameInfo;
	extern int g_GameTable[LEN][LEN];

	system("CLS");
	
	g_GameInfo.time = time(NULL);    // get current time as begin time
	g_GameInfo.numCount = 0;
	
	memset(g_GameTable, 0, sizeof(g_GameTable));

	draw_GameTable();
	draw_GameInfo();
}

int game_CheckFull(void) {
	extern gameInfo_t g_GameInfo;
	if (g_GameInfo.numCount == 16)
		return TRUE;
	else
		return FALSE;
}

//********************************************
// Randomly generate one number in empty grid
//********************************************
void game_RandNum(void) {
	int i = 0, j = 0;
	extern int g_GameTable[LEN][LEN];
	extern gameInfo_t g_GameInfo;

	srand(time(NULL));

	// randomly find a grid without non-zero number
	do {
		i = rand() % LEN;
		j = rand() % LEN;
	} while (g_GameTable[i][j] != 0);

	// generate 2 or 4
	if (rand() & 0x1) {               
		g_GameTable[i][j] = 2;
	}
	else {
		g_GameTable[i][j] = 4;
	}

	g_GameInfo.numCount++;
}

//********************************************
// Update number and color after moving
//********************************************
void game_UpdateTable(void) {
	int i, j;
	int num;
	extern int g_GameTable[LEN][LEN];

	draw_GameTable();
	draw_GameInfo();

	for (i = 0; i < LEN; i++) {
		for (j = 0; j < LEN; j++) {
			num = g_GameTable[i][j];

			gotoxy(15 + j * 9 + 4, 2 + i * 5 + 3);

			if (num != 0) {
				set_NumColor(num);
				printf("%d", num);
			}
		}
	}
}

//********************************************
// Game play process
//********************************************
void game_Main(void) {
	int ch;
	int res;

	game_Begin();         // keep game frame fixed
	game_RandNum();       // add new number
	game_UpdateTable();   // show the first number

	while (TRUE) {
		//if (_kbhit())
		{
			if ( (ch = _getch()) != 27) {   // getch will return 0xE0 before ¡ü¡ý¡û¡ú
				ch = _getch();
			}


			// move the number, or change game status
			res = kb_control(ch);

			if (res & ST_WIN) {
				draw_WinScreen();
				return;
			}
			else if (res & (ST_ILLEGAL|ST_RESUME)) {    // invalid operation, get another hit
				continue;
			}
			else if (res & ST_QUIT) {              // player quit the game, return to main screen
				return;            
			}
			else if (res & ST_FAIL) {
				draw_FailScreen();
				return;
			}

			// if there are still 16 numbers after movement
			// no chance to reduce old and generate new numbers
			if (TRUE == game_CheckFull()) { 
				draw_FailScreen();
				return;
			}
			
			// res == ST_RUN, successful step
			game_RandNum();       // add new number
			game_UpdateTable();   // update table after moving and adding numbers

		}
	}
}



