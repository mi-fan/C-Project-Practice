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
	printf("2. Game Rule");
	gotoxy(22, 16);
	printf("3. Instruction");
	gotoxy(42, 16);
	printf("4. Exit");
}

//**************************************
// Show the menu with game options
//**************************************
void menu(void) {
	int choice = 0;
	int status;

	// draw the menu with frame
	draw_Menu();
	
	// keyboard input
	gotoxy(21, 22);
	color(PURPLE);
	printf("Your choice is ... ");

	// run game branch
	while (TRUE)
	{
		scanf_s("%d", &choice);

		status = game_Route(choice);

		// handle the invalid choice
		if (FALSE == status) {
			gotoxy(21, 23);
			color(RED);
			printf("Input a integer of 1, 2, 3, 4 ...  \b");
		}
		else{
			break;
		}
	}
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
	printf("Time: %ld", g_GameInfo.time);
}

//********************************************
// Draw the winning text
//********************************************
void draw_WinScreen(void) {
	extern gameInfo_t g_GameInfo;

	system("CLS");

	// show the game score and steps
	color(WHITE_LIGHT);
	gotoxy(34, 3);
	printf("Your final score is: %d", g_GameInfo.score);
	gotoxy(34, 4);
	printf("   Your total steps: %d", g_GameInfo.step);
	gotoxy(34, 4);
	printf("    Your have spend: %d sec", time(NULL) - g_GameInfo.time);

	// show the banner
	color(BL_GR_LIGHT);
	gotoxy(1, 7);
	printf("      ¡ö              ¡ö              ¡ö       ¡ö¡ö¡ö¡ö       ¡ö¡ö        ¡ö \n");
	gotoxy(1, 8);
	printf("       ¡ö            ¡ö¡ö            ¡ö           ¡ö          ¡ö ¡ö       ¡ö \n");
	gotoxy(1, 9);
	printf("        ¡ö          ¡ö  ¡ö          ¡ö            ¡ö          ¡ö  ¡ö      ¡ö \n");
	gotoxy(1, 10);
	printf("         ¡ö        ¡ö    ¡ö        ¡ö             ¡ö          ¡ö   ¡ö     ¡ö \n");
	gotoxy(1, 11);
	printf("          ¡ö      ¡ö      ¡ö      ¡ö              ¡ö          ¡ö    ¡ö    ¡ö \n");
	gotoxy(1, 12);
	printf("           ¡ö    ¡ö        ¡ö    ¡ö               ¡ö          ¡ö     ¡ö   ¡ö \n");
	gotoxy(1, 13);
	printf("            ¡ö  ¡ö          ¡ö  ¡ö                ¡ö          ¡ö      ¡ö  ¡ö \n");
	gotoxy(1, 14);
	printf("             ¡ö¡ö            ¡ö¡ö                 ¡ö          ¡ö       ¡ö ¡ö \n");
	gotoxy(1, 15);
	printf("              ¡ö              ¡ö               ¡ö¡ö¡ö¡ö       ¡ö        ¡ö¡ö \n");

	// show the text
	gotoxy(33, 17);
	color(PINK);
	printf("Well done! Remember winning is not the end of fight");
}

//********************************************
// Draw the failure text
//********************************************
void draw_FailScreen(void) {
	extern gameInfo_t g_GameInfo;

	system("CLS");
	
	// show the game score and steps
	color(YELLOW);
	gotoxy(34, 3);
	printf("Your final score is: %d", g_GameInfo.score);
	gotoxy(34, 4);
	printf("   Your total steps: %d", g_GameInfo.step);

	// show the banner
	color(RED_DEEP);
	gotoxy(19, 7);
	printf("      ¡ö¡ö¡ö¡ö¡ö     ¡ö         ¡ö       ¡ö ¡ö           \n");
	gotoxy(19, 8);
	printf("      ¡ö             ¡ö¡ö       ¡ö       ¡ö    ¡ö        \n");
	gotoxy(19, 9);
	printf("      ¡ö             ¡ö ¡ö      ¡ö       ¡ö       ¡ö     \n");
	gotoxy(19, 10);
	printf("      ¡ö             ¡ö  ¡ö     ¡ö       ¡ö        ¡ö    \n");
	gotoxy(19, 11);
	printf("      ¡ö¡ö¡ö¡ö¡ö     ¡ö   ¡ö    ¡ö       ¡ö         ¡ö   \n");
	gotoxy(19, 12);
	printf("      ¡ö             ¡ö    ¡ö   ¡ö       ¡ö        ¡ö    \n");
	gotoxy(19, 13);
	printf("      ¡ö             ¡ö     ¡ö  ¡ö       ¡ö       ¡ö     \n");
	gotoxy(19, 14);
	printf("      ¡ö             ¡ö      ¡ö ¡ö       ¡ö     ¡ö       \n");
	gotoxy(19, 15);
	printf("      ¡ö¡ö¡ö¡ö¡ö     ¡ö         ¡ö       ¡ö ¡ö           \n");

	// show the text
	gotoxy(30, 17);
	color(PINK);
	printf("Fails and wins are just life, Heroes will insist");
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