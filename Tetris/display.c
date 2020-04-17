#include "display.h"

/*
 * set the welcome title
 */
void title() {
	color(15);
	gotoxy(29, 3);
	printf(" My Tetris Game\n");

	color(11);
	gotoxy(18, 5);
	printf("¡ö");
	gotoxy(18, 6);
	printf("¡ö¡ö");
	gotoxy(18, 7);
	printf("¡ö");

	color(14);
	gotoxy(26, 6);
	printf("¡ö¡ö");
	gotoxy(28, 7);
	printf("¡ö¡ö");

	color(10);
	gotoxy(36, 6);
	printf("¡ö¡ö");
	gotoxy(36, 7);
	printf("¡ö¡ö");

	color(13);
	gotoxy(45, 5);
	printf("¡ö");
	gotoxy(45, 6);
	printf("¡ö");
	gotoxy(45, 7);
	printf("¡ö");
	gotoxy(45, 8);
	printf("¡ö");

	color(12);
	gotoxy(52, 6);
	printf("¡ö");
	gotoxy(52, 7);
	printf("¡ö¡ö¡ö¡ö");
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
		break;
	case 2:
	case 3:
	case 4:
	default:
		break;

	}
}