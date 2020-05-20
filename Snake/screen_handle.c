#include "screen_handle.h"

//*********************************************//
//                                             //
// Define the functions used for screen color  //
// and cursor control                          //
//                                             //
//*********************************************//

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