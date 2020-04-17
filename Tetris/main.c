#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

// macro define
#define FRAME_X        (13)
#define FRAME_Y        (3)
#define FRAME_HEIGHT   (20)
#define FRAME_WIDTH    (18)

// global variable
int i, j, tmp, tmp1, tmp2;
int a[80][80] = { 0 };
int b[4];

// structure define
struct Tetris
{
	int x;
	int y;
	int flag;
	int next;
	int speed;
	int number;
	int score;
	int level;
};

// console handle
HANDLE hOut;              

// function declaration
int color(int clr);
void gotoxy(int x, int y);
void drawGameFrame(void);
void flag(struct Tetris *);
void makeTetris(struct Tetris *);
void printTetris(struct Tetris *);
void cleanTetris(struct Tetris *);
int ifMove(struct Tetris*);
void delFullLine(struct Tetris*);
void gamePlay(void);
void regulation(void);
void explation(void);
void welcome(void);
void replay(struct Tetris*);
void title(void);
void flower(void);
void close(void);

// function definition
/*
 * set print color
 */
int color(int clr) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);

	return 0;
}

/*
 * set cursor position
 */
void gotoxy(int x, int y) {
	COORD pos;

	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

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

int main(void) {
	title();

	welcome();
	
	return 0;
}