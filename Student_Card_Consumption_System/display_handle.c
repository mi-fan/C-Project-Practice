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
 * Set text color to green
 ***********************************************************/
inline void setTextColorGreen(HANDLE handle) {
	SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | 
		BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_RED);
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

/***********************************************************
 * Show all consumption records
 ***********************************************************/
void printAll(Record head) {
	system("CLS");
	Record tmp;
	setTextColorBlue(g_output_handle);
	printf("\n\n\t\t\t\t Show all student consumption records\n");
	setTextColorBlack(g_output_handle);

	if (headStudent == NULL) {
		setTextColorRed(g_output_handle);
		printf("\n\t\t No records. Please create new record\n");
		setTextColorBlack(g_output_handle);
	}
	else {
		// set table head
		setTextColorPink(g_output_handle);
		printf("\n\t\t Total %d students\n\n", g_record_len);
		setTextColorGreen(g_output_handle);
		printf("\t\t------------------------------------------------------------\n");
		setTextColorPurple(g_output_handle);
		printf("\t\t   |  ID\t|\t name\t|     consume     |\n");
		setTextColorGreen(g_output_handle);
		printf("\t\t------------------------------------------------------------\n");
		setTextColorBlack(g_output_handle);
		tmp = headStudent;
		
		// show all info
		do {
			setTextColorBlue(g_output_handle);
			printf("\t\t    %d\t\t     %s\t     %d\t\n", tmp->id, tmp->name, tmp->money);
			setTextColorGreen(g_output_handle);
			printf("\t\t------------------------------------------------------------\n");
			tmp = tmp->next;
		} while (tmp != NULL);

		_getch();
	}

}