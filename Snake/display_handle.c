#include "display_handle.h"

//*********************************************//
//                                             //
// Define the functions used for display       //
// pictures, shapes and words                  //
//                                             //
//*********************************************//

/***********************************
* Draw one snake in welcome window
***********************************/
void drawSnakeLogo(void) {
	color(PURPLE);
	gotoxy(35, 1);
	printf("/^\\/^\\");

	gotoxy(34, 2);
	printf("|__|  0|");

	color(GREEN_DEEP);
	gotoxy(33, 2);
	printf("_");

	color(RED);
	gotoxy(25, 3);
	printf("\\/");

	color(GREEN_DEEP);
	gotoxy(31, 3);
	printf("/");

	color(YELLOW_DARK);
	gotoxy(37, 3);
	printf("\\_/");

	color(GREEN_LIGTH);
	gotoxy(41, 3);
	printf(" \\");

	color(RED);
	gotoxy(26, 4);
	printf("\\____");

	color(RED);
	gotoxy(32, 4);
	printf("__________/");

	color(GREEN_DEEP);
	gotoxy(31, 4);
	printf("|");

	color(GREEN_LIGTH);
	gotoxy(43, 4);
	printf("\\");

	color(GREEN_DEEP);
	gotoxy(32, 5);
	printf("\\______");

	color(GREEN_LIGTH);
	gotoxy(44, 5);
	printf("\\");

	gotoxy(39, 6);
	printf("|     |                 \\");

	gotoxy(38, 7);
	printf("/     /                   \\");

	gotoxy(37, 8);
	printf("/     /                    \\ \\");

	gotoxy(35, 9);
	printf("/     /                      \\  \\");

	gotoxy(34, 10);
	printf("/     /                        \\  \\");

	gotoxy(33, 11);
	printf("/     /          _----_          \\  \\");

	gotoxy(32, 12);
	printf("/     /       _-~       ~-_        |  |");

	gotoxy(31, 13);
	printf("(     (     _-~   _--_    ~-_      _/  |");

	gotoxy(32, 14);
	printf("\\   ~-_____-~   _-~   ~-_   ~-_-~     /");

	gotoxy(33, 15);
	printf("~-_           _-~       ~-_       _-~");

	gotoxy(35, 16);
	printf("~--______-~             ~-___-~");
}
