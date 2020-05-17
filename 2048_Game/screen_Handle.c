#include "screen_Handle.h"



//**************************************
// Set the character color
//**************************************
int color(int clr) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);

	return 0;
}

//**************************************
// Set cursor position
//**************************************
void gotoxy(int x, int y) {

	COORD pos;

	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//**************************************
// Draw the game logo "2048"
//**************************************
void draw_Title(void) {

	system("CLS");
	color(BL_GR_LIGHT);
	gotoxy(17, 2);
	printf("¡ö¡ö¡ö     ¡ö¡ö¡ö¡ö     ¡ö  ¡ö     ¡ö¡ö¡ö¡ö");
	gotoxy(17, 3);
	printf("    ¡ö     ¡ö    ¡ö     ¡ö  ¡ö     ¡ö    ¡ö");
	gotoxy(17, 4);
	printf("¡ö¡ö¡ö     ¡ö    ¡ö     ¡ö  ¡ö     ¡ö¡ö¡ö¡ö");
	gotoxy(17, 5);
	printf("¡ö         ¡ö    ¡ö     ¡ö¡ö¡ö     ¡ö    ¡ö");
	gotoxy(17, 6);
	printf("¡ö¡ö¡ö     ¡ö¡ö¡ö¡ö         ¡ö     ¡ö¡ö¡ö¡ö");
}

//**************************************
// Draw the menu table with game options
//**************************************
void draw_Menu(void) {
	int i, j;

	// print the frame
	color(YELLOW);
	for (i = 9; i <= 20; i++) {
		for (j = 15; j <= 60; j++) {
			gotoxy(j, i);
			if ((i == 9) || (i == 20)) {
				printf("=");
			}
			else if ((j == 15) || (j == 59)) {
				printf("||");
			}
		}
	}

	// display the valid choices
	color(PINK);
	gotoxy(22, 12);
	printf("1. Begin");
	gotoxy(42, 12);
	printf("2. Instruction");
	gotoxy(32, 16);
	printf("3. Exit");
}

//**************************************
// Draw the game instructions
//**************************************
void draw_Instruct(void) {
	int idx;

	system("CLS");

	color(GREEN_LIGTH);
	idx = 7;
	gotoxy(18, idx);
	printf("1. Player use ¡ü¡ý¡û¡ú to move the numbers");
	idx += 2;
	gotoxy(18, idx);
	printf("2. If two numbers are same in the selected direction, numbers are merged");
	idx += 2;
	gotoxy(18, idx);
	printf("3. After each movement, new number is randomly added to the table");
	idx += 2;
	gotoxy(18, idx);
	printf("4. If 2048 is produced, game wins");
	idx += 2;
	gotoxy(18, idx);
	printf("5. If numbers cannot be moved, game fails");
	idx += 2;
	gotoxy(18, idx);
	printf("6. Press ESC to Pause or Quit game");

}

//**************************************
// Draw the game area grids
//**************************************
void draw_GameTable(void) {
	int i, j, k;
	
	color(YELLOW);

	// draw the horizon lines
	for (j = 2; j <= 22; j += 5) {
		gotoxy(15, j);
		for (k = 1; k < 38; k++) {
			printf("-");
		}
		printf("\n");
	}

	// draw five vertical lines
	for (i = 3; i < 7; i++) {
		gotoxy(15, i);
		printf("|        |        |        |        |");
	}

	for (i = 8; i < 12; i++) {
		gotoxy(15, i);
		printf("|        |        |        |        |");
	}

	for (i = 13; i < 17; i++) {
		gotoxy(15, i);
		printf("|        |        |        |        |");
	}

	for (i = 18; i < 22; i++) {
		gotoxy(15, i);
		printf("|        |        |        |        |");
	}
}

//**************************************
// Print the game info
//**************************************
void draw_GameInfo(void) {
	extern gameInfo_t g_GameInfo;

	color(BL_GR_LIGHT);
	gotoxy(16, 1);
	printf("Score: %ld", g_GameInfo.score);

	color(PINK);
	gotoxy(42, 1);
	printf("Steps: %ld", g_GameInfo.step);

	color(GREEN_LIGTH);
	gotoxy(44, 23);
	printf("Time: %ld s", time(NULL) - g_GameInfo.time);

	g_GameInfo.step++;
}

//********************************************
// Draw the winning text
//********************************************
void draw_WinScreen(void) {
	int idx;
	extern gameInfo_t g_GameInfo;

	system("CLS");

	// show the game score and steps
	idx = 3;
	color(WHITE_LIGHT);
	gotoxy(34, idx++);
	printf("Your final score is: %d", g_GameInfo.score);
	gotoxy(34, idx++);
	printf("   Your total steps: %d", g_GameInfo.step);
	gotoxy(34, idx++);
	printf("    Your have spend: %d sec", time(NULL) - g_GameInfo.time);

	idx += 4;

	// show the banner
	color(BL_GR_LIGHT);
	gotoxy(1, idx++);
	printf("      ¡ö              ¡ö              ¡ö       ¡ö¡ö¡ö¡ö       ¡ö¡ö        ¡ö \n");
	gotoxy(1, idx++);
	printf("       ¡ö            ¡ö¡ö            ¡ö           ¡ö          ¡ö ¡ö       ¡ö \n");
	gotoxy(1, idx++);
	printf("        ¡ö          ¡ö  ¡ö          ¡ö            ¡ö          ¡ö  ¡ö      ¡ö \n");
	gotoxy(1, idx++);
	printf("         ¡ö        ¡ö    ¡ö        ¡ö             ¡ö          ¡ö   ¡ö     ¡ö \n");
	gotoxy(1, idx++);
	printf("          ¡ö      ¡ö      ¡ö      ¡ö              ¡ö          ¡ö    ¡ö    ¡ö \n");
	gotoxy(1, idx++);
	printf("           ¡ö    ¡ö        ¡ö    ¡ö               ¡ö          ¡ö     ¡ö   ¡ö \n");
	gotoxy(1, idx++);
	printf("            ¡ö  ¡ö          ¡ö  ¡ö                ¡ö          ¡ö      ¡ö  ¡ö \n");
	gotoxy(1, idx++);
	printf("             ¡ö¡ö            ¡ö¡ö                 ¡ö          ¡ö       ¡ö ¡ö \n");
	gotoxy(1, idx++);
	printf("              ¡ö              ¡ö               ¡ö¡ö¡ö¡ö       ¡ö        ¡ö¡ö \n");

	idx += 4;

	// show the text
	gotoxy(25, 17);
	color(PINK);
	printf("Well done! Remember winning is not the end of fight");
}

//********************************************
// Draw the failure text
//********************************************
void draw_FailScreen(void) {
	int idx;
	extern gameInfo_t g_GameInfo;

	system("CLS");
	
	// show the game score and steps
	idx = 3;
	color(YELLOW);
	gotoxy(34, idx++);
	printf("Your final score is: %d", g_GameInfo.score);
	gotoxy(34, idx++);
	printf("   Your total steps: %d", g_GameInfo.step);

	// show the banner
	idx = 10;
	color(RED_DEEP);
	gotoxy(19, idx++);
	printf("      ¡ö¡ö¡ö¡ö¡ö     ¡ö         ¡ö       ¡ö ¡ö           \n");
	gotoxy(19, idx++);
	printf("      ¡ö             ¡ö¡ö       ¡ö       ¡ö    ¡ö        \n");
	gotoxy(19, idx++);
	printf("      ¡ö             ¡ö ¡ö      ¡ö       ¡ö       ¡ö     \n");
	gotoxy(19, idx++);
	printf("      ¡ö             ¡ö  ¡ö     ¡ö       ¡ö        ¡ö    \n");
	gotoxy(19, idx++);
	printf("      ¡ö¡ö¡ö¡ö¡ö     ¡ö   ¡ö    ¡ö       ¡ö        ¡ö    \n");
	gotoxy(19, idx++);
	printf("      ¡ö             ¡ö    ¡ö   ¡ö       ¡ö        ¡ö    \n");
	gotoxy(19, idx++);
	printf("      ¡ö             ¡ö     ¡ö  ¡ö       ¡ö       ¡ö     \n");
	gotoxy(19, idx++);
	printf("      ¡ö             ¡ö      ¡ö ¡ö       ¡ö     ¡ö       \n");
	gotoxy(19, idx++);
	printf("      ¡ö¡ö¡ö¡ö¡ö     ¡ö         ¡ö       ¡ö ¡ö           \n");

	idx += 4;

	// show the text
	gotoxy(23, idx++);
	color(PINK);
	printf("Fails and wins are just life, Heroes will insist\n");
}

//**************************************
// Set number colors
//**************************************
void set_NumColor(int num) {
	int col;

	switch (num)
	{
	case 2:
		col = WHITE;
		break;
	case 4:
		col = BLUE_LIGHT;
		break;
	case 8:
		col = GREEN_LIGTH;
		break;
	case 16:
		col = BL_GR_LIGHT;
		break;
	case 32:
		col = PINK;
		break;
	case 64:
		col = YELLOW;
		break;
	case 128:
		col = GRAY;
		break;
	case 256:
		col = RED;
		break;
	case 512:
		col = YELLOW_DARK;
		break;
	case 1024:
		col = WHITE_LIGHT;
		break;
	case 2048:
		col = YELLOW_DARK;
		break;

	default:
		col = WHITE;
		break;
	}
	color(col);
}