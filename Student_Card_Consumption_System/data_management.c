#include "data_management.h"

/***********************************************************
 *
 *         Management of consumption information
 *
 ***********************************************************/
 /***********************************************************
  * Create new student consumption record
  ***********************************************************/
#if 1
Record create(void) {
	// get console handler
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	Record inputStu;

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
			setTextColorRed(handle);
			printf("\t Invalid student ID, input again!\n");
			setTextColorBlack(handle);

			continue;
		}

		//exclude existing student ID
		if (TRUE == searchSameId(headStudent, inputStu->id)){
			setTextColorRed(handle);
			printf("\t Existing student ID, input again!\n");
			setTextColorBlack(handle);

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
		g_record_len++;
		
	} while (1);

	// sort the link from initial position
	sortLink(headStudent);

	return headStudent;
}
#endif