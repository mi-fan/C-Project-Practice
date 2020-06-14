/******************************************************
*
*  Description:
*
*  Functions for text color and cursor control
*
*
******************************************************/

#include "screen_handle.h"

/*******************************
* Set text color
*******************************/
int color(int clr) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);

	return 0;
}

/*******************************
* Set cursor position
*******************************/
void gotoxy(int x, int y) {

	COORD pos;

	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}