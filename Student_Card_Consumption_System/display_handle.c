#include "common.h"

/***********************************************************
 *
 *          Functions for screen display
 *
 ***********************************************************/
/***********************************************************
 * Set text color to red
 ***********************************************************/
inline void setTextColorRed(HANDLE handle) {
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY |
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED);
}

/***********************************************************
 * Set text color to black
 ***********************************************************/
inline void setTextColorBlack(HANDLE handle) {
	SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY |
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}

/***********************************************************
 * Set text color to purple
 ***********************************************************/
inline void setTextColorPurple(HANDLE handle) {
	SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY |
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE);
}

/***********************************************************
 * Set text color to blue
 ***********************************************************/
inline void setTextColorBlue(HANDLE handle) {
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY |
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_BLUE);
}

/***********************************************************
 * Set text color to pink
 ***********************************************************/
inline void setTextColorPink(HANDLE handle) {
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY |
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_RED);
}

/***********************************************************
 * Show top menu for selection
 ***********************************************************/
void menu(void) {
	system("CLS");
	printf("\n\n\n");

	// get console handler
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// set screen text
	setTextColorRed(handle);
	printf("\t\t\t     Student Consumption Management System\t\t\n\n");

	// show options
	setTextColorBlack(handle);
	printf("\t\t-------------------------------------------------------------\n\n");
	printf("\t\t\t    1    Create student information     \n\n");
	printf("\t\t\t    2    Load consumption information     \n\n");
	printf("\t\t\t    3    Query consumption information     \n\n");
	printf("\t\t\t    4    Delete consumption information     \n\n");
	printf("\t\t\t    5    Add consumption information     \n\n");
	printf("\t\t\t    6    Show all information     \n\n");
	printf("\t\t\t    7    Save record to file     \n\n");
	printf("\t\t\t    0    Exit     \n\n");
	printf("\t\t-------------------------------------------------------------\n\n");
	printf("\t\t choose[0-7]: ");
}