#include "screen_Handle.h"

//**************************************
// set the character color
//**************************************
int color(int clr) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);

	return 0;
}

//**************************************
// set cursor position
//**************************************
void gotoxy(int x, int y) {

	COORD pos;

	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//**************************************
// Print the game logo "2048"
//**************************************
void title(void) {
	color(11);
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
// Show the menu with game options
//**************************************
void menu(void) {
	int choice = 0;
	int i, j;
	gameStatus_t status;

	// print the frame
	color(14);
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
	color(12);
	gotoxy(22, 12);
	printf("1. Begin");
	gotoxy(42, 12);
	printf("2. Game Rule");
	gotoxy(22, 16);
	printf("3. Instruction");
	gotoxy(42, 16);
	printf("4. Exit");

	// keyboard input
	gotoxy(21, 22);
	color(5);
	printf("Your choice is ... ");

	while (TRUE)
	{
		scanf_s("%d", &choice);

		// run the game branch
		status = game_main(choice);

		// handle the invalid choice
		if (GS_INVALID == status) {
			gotoxy(21, 23);
			color(12);
			printf("Input a integer of 1, 2, 3, 4 ...  \b");
		}
		else{
			break;
		}
	}
}