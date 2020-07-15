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
	HANDLE hanle;
	int choice;
	int status = TRUE;

	
	// set console to white background and black character
	system("color f0");

	// get console hander
	hanle = GetStdHandle(STD_OUTPUT_HANDLE);

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

	switch (choice)
	{
	case CREATE:
		headStudent = create();
		break;
	case LOAD:
		headStudent = load(headStudent);
		break;
	case QUERY:
		headStudent = query(headStudent);
		break;
	case DEL:
		headStudent = del(headStudent);
		break;
	case ADD:
		headStudent = add(headStudent);
		break;
	case PRINT:
		printAll(headStudent);
		break;
	case SAVE:
		saveToFile(headStudent);
		break;
	case EXIT:
		status = FALSE;
		break;
	default:
		// show warning on console
		printf("   Please input valid number");
		getchar();
		break;
	}

	return status;
}