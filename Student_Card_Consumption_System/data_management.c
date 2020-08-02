#include "data_management.h"
#include "display_handle.h"

/***********************************************************
 *
 *         Management of consumption information
 *
 ***********************************************************/
/***********************************************************
 * Create new student consumption record
 ***********************************************************/
Record create(void) {
	Record inputStu;

	int count = 0;

	inputStu = (Record)malloc(sizeof(struct recordNode));

	// create new student record, including ID, name and payment
	do {
		printf("\t Please input student and consumption information (input ID with 0 to finish):\n");
		printf("\t Student ID: ");
		scanf_s("%d", &inputStu->id);

		// finish creating if student ID is zero
		if (inputStu->id == 0) {
			break;
		}

		// only positive ID is allowed
		if (inputStu->id < 0) {
			setTextColorRed(g_output_handle);
			printf("\t Invalid student ID, input again!\n");
			setTextColorBlack(g_output_handle);

			continue;
		}

		//exclude existing student ID
		if (NULL != searchSameId(headStudent, inputStu->id)){
			setTextColorRed(g_output_handle);
			printf("\t Existing student ID, input again!\n");
			setTextColorBlack(g_output_handle);

			continue;
		}

		// continue to receive other parameter
		printf("\t Student name: ");
		scanf_s("%s", &inputStu->name);
		printf("\t Money:");
		scanf_s("%d", &inputStu->money);

		// create new record node according to input
		currStudent->next  = (Record)malloc(sizeof(struct recordNode));
		currStudent->id    = inputStu->id;
		currStudent->money = inputStu->money;
		memcpy_s(currStudent->name, NAME_LEN * sizeof(char), inputStu->name, NAME_LEN * sizeof(char));
		
		// move to next
		currStudent = currStudent->next;
		currStudent->next = NULL;
		g_record_len++;
		count++;
	} while (1);

	// sort the link from initial position
	sortLink(headStudent);

	setTextColorPurple(g_output_handle);
	printf("\t      Create %d student records this time\n", count);
	printf("\t      Total %d student records\n", g_record_len);
	setTextColorBlack(g_output_handle);

	_getch();

	return headStudent;
}

/***********************************************************
 * Add new consumption record to existing student
 ***********************************************************/
Record add(void) {
	Record tmpStu;
	int id;
	int inputMoney = 0;

	// add new record to valid student ID
	do {
		printf("\t Please input student ID (input ID with 0 to finish):\n");
		printf("\t Student ID: ");
		scanf_s("%d", &id);

		// finish creating if student ID is zero
		if (id == 0) {
			break;
		}

		// only positive ID is allowed
		if (id < 0) {
			setTextColorRed(g_output_handle);
			printf("\t Invalid student ID, input again!\n");
			setTextColorBlack(g_output_handle);

			continue;
		}

		//exclude not existed student ID
		if (NULL == (tmpStu = searchSameId(headStudent, id))) {
			setTextColorRed(g_output_handle);
			printf("\t Invalid student ID, input again!\n");
			setTextColorBlack(g_output_handle);

			continue;
		}

		// continue to receive other parameter
		printf("\t Student name: %s", tmpStu->name);
		printf("\t Input Money:");
		scanf_s("%d", &inputMoney);

		if (inputMoney <= 0) {
			setTextColorRed(g_output_handle);
			printf("\t Invalid money, input again!\n");
			setTextColorBlack(g_output_handle);

			continue;
		}

		tmpStu->money += inputMoney;

	} while (1);
}

/***********************************************************
 * Query the consumption record of one student from ID
 ***********************************************************/
Record query(void) {
	int id;
	Record outputStudent;

	system("CLS");

	setTextColorBlue(g_output_handle);

	printf("\n\n\t\t\t Query the student consumption record:\n");

	setTextColorBlack(g_output_handle);

	do {
		printf("\n\n\tPlease input the student ID (input 0 to exit):\n");

		scanf_s("%d", &id);

		setTextColorRed(g_output_handle);

		if (id == 0) {
			return NULL;
		}
		else if (id < 0) {
			printf("\tInvalid student ID (smaller than zero)!");
			continue;
		}
		else if (headStudent == NULL) {
			printf("\tDatabase is empty, please create new records!");
			_getch();
			return NULL;
		}
		else if ((outputStudent = searchSameId(headStudent, id)) == NULL)
		{
			printf("\tStudent ID does not exist, please input again.");
			continue;
		}
		else{    // ID > 0 and student exist
			setTextColorBlack(g_output_handle);
		}

		// show the record of the student
		printf("\t\t---------------------------------------------------\n");
		printf("\t\t  | ID\t   | name\t  | money\t\n");
		printf("\t\t---------------------------------------------------\n");
		printf("\t\t  | %d\t   | %s\t  | %d\t\n", outputStudent->id, outputStudent->name, outputStudent->money);
		printf("\t\t---------------------------------------------------\n");
		_getch();
	} while (1);



}