#include "common.h"
/***********************************************************
 *
 *                  Main functions
 *
 ***********************************************************/

static int run_modules(int choice);

 /***********************************************************
  * main()
  ***********************************************************/
int main(void) {
	int choice;
	int status = TRUE;

	// init the link list
	initLink();
	
	// set console to white background and black character
	system("color f0");

	// get console hander
	g_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// main body
	do {
		// show the menu
		menu();

		// get the choice
		scanf_s("%d", &choice);

		// handle the choice
		status = run_modules(choice);

	} while (TRUE == status);

	return 0;
}

/***********************************************************
 * Jump to corresponding modules according to choice
 ***********************************************************/
static int run_modules(int choice) {
	int status = TRUE;
#if 0
	switch (choice)
	{
	// create link list of students
	case CREATE:
		headStudent = create();
		break;
	// load file of consumptions
	case LOAD:
		headStudent = load(headStudent);
		break;
	// query the consumption info
	case QUERY:
		headStudent = query(headStudent);
		break;
	// delete the consumption info
	case DEL:
		headStudent = del(headStudent);
		break;
	// add student consumption info
	case ADD:
		headStudent = add(headStudent);
		break;
	// show all student consumption info
	case PRINT:
		printAll(headStudent);
		break;
	// save info to file
	case SAVE:
		saveToFile(headStudent);
		break;
	// exit to main menu
	case EXIT:
		status = FALSE;
		break;
	// unexpected input handle
	default:
		// show warning on console
		printf("   Please input valid number");
		getchar();
		break;
	}
#endif
	return status;
}