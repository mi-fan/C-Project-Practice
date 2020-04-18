#include "display.h"

extern int gameArea[80][80];
/*
 * set the welcome title
 */
void title() {
	color(15);
	gotoxy(29, 3);
	printf(" My Tetris Game\n");

	color(11);
	gotoxy(18, 5);
	printf("■");
	gotoxy(18, 6);
	printf("■■");
	gotoxy(18, 7);
	printf("■");

	color(14);
	gotoxy(26, 6);
	printf("■■");
	gotoxy(28, 7);
	printf("■■");

	color(10);
	gotoxy(36, 6);
	printf("■■");
	gotoxy(36, 7);
	printf("■■");

	color(13);
	gotoxy(45, 5);
	printf("■");
	gotoxy(45, 6);
	printf("■");
	gotoxy(45, 7);
	printf("■");
	gotoxy(45, 8);
	printf("■");

	color(12);
	gotoxy(52, 6);
	printf("■");
	gotoxy(52, 7);
	printf("■■■■");
}

/*
 * menue frame
 */
void welcome() {
	int res;
	int k, l;

	// the menu frame
	color(14);

	for (k = 9; k <= 20; k++) {
		for (l = 15; l <= 60; l++) {
			gotoxy(l, k);
			if ((k == 9) || (k == 20))
				printf("=");
			else if ((l == 15) || (l == 59))
				printf("||");
		}
	}

	// menu context
	color(12);
	gotoxy(25, 12);
	printf("1. Begin");
	gotoxy(40, 12);
	printf("2. Keyboard Setting");
	gotoxy(25, 17);
	printf("3. Play Rule");
	gotoxy(40, 17);
	printf("4. Exit");

	color(3);
	gotoxy(21, 22);
	printf("Choose[1 2 3 4]:[ ]\b\b");

	color(14);
	scanf_s("%d", &res);

	switch (res) {
	case 1:
		system("cls");
		drawGameFrame();     //show the game window
		break;
	case 2:
	case 3:
	case 4:
	default:
		break;

	}
}

void drawGameFrame(void) {
	int i;

	gotoxy(FRAME_X + FRAME_WIDTH - 7, FRAME_Y - 2);
	color(11);
	printf("TTTTTTetris!");   // game window title

	gotoxy(FRAME_X + 2*FRAME_WIDTH + 3, FRAME_Y +7);
	color(2);
	printf("**********");     // top line for next piece area

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 13, FRAME_Y + 7);
	color(3);
	printf("NEXT PIECE");     // show text

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 13);
	color(2);
	printf("**********");     // bottom line for next piece area

	printf("NEXT PIECE");     // show text

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 15);
	color(14);
	printf("  ↑ : rotate");     // explaination

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 19);
	color(14);
	printf("SPACE: pause");      // explaination

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 17);
	color(14);
	printf(" ESC : exit");       // explaination

	gameArea[FRAME_X][FRAME_Y + FRAME_HEIGHT] = 2;
	gameArea[FRAME_X + 2*FRAME_WIDTH - 2][FRAME_Y + FRAME_HEIGHT] = 2;

	for (i = 1; i < 2 * FRAME_WIDTH -1; i++) {                  // print the top line of game area
		gotoxy(FRAME_X + i, FRAME_Y);
		printf("=");
	}

	for (i = 1; i < 2 * FRAME_WIDTH - 1; i++) {                                  // print the bottome line of game area
		gotoxy(FRAME_X + i, FRAME_Y + FRAME_HEIGHT);
		printf("=");
		gameArea[FRAME_X + i][FRAME_Y + FRAME_HEIGHT] = FLAG_BOUNDRY;        // mark the bottom of game area, to keep pieces inside the boundry
	}

	for (i = 1; i < FRAME_HEIGHT; i++) {                                     // print the bottome line of game area
		gotoxy(FRAME_X, FRAME_Y + i);
		printf("‖");
		gameArea[FRAME_X][FRAME_Y + i] = FLAG_BOUNDRY;                       // mark the left boundry of game area
	}

	for (i = 1; i < FRAME_HEIGHT; i++) {                                     // print the left line of game area
		gotoxy(FRAME_X + 2*FRAME_WIDTH - 2, FRAME_Y + i);
		printf("‖");
		gameArea[FRAME_X + 2 * FRAME_WIDTH - 2][FRAME_Y + i] = FLAG_BOUNDRY; // mark the right boundry of game area
	}
}