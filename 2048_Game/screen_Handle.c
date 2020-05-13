#include "screen_Handle.h"

const num_color[NUM_COUNT] = { WHITE, BLUE_LIGHT, GREEN_LIGTH, BL_GR_LIGHT, PINK, YELLOW,
								GRAY, PURPLE, BLUE_DEEP, GREEN_DEEP, RED };

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
	gameStatus_t status;

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

		status = game_main(choice);

		// handle the invalid choice
		if (GS_INVALID == status) {
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
		for (k = 1; k < 42; k++) {
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
	extern gameInfo_t g_gameInfo;

	color(BL_GR_LIGHT);
	gotoxy(16, 1);
	printf("Score: %ld", g_gameInfo.score);

	color(PINK);
	gotoxy(42, 1);
	printf("Steps: %ld", g_gameInfo.step);

	color(GREEN_LIGTH);
	gotoxy(44, 23);
	printf("Time: %ld", g_gameInfo.time);
}

//**************************************
// Set number colors
//**************************************
void set_NumColor(color_t col) {
	color(num_color[NUM_COUNT]);
}