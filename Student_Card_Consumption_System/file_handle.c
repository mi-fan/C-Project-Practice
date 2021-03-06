#include "common.h"

/***********************************************************
 *
 *          Functions for load and read file
 *
 ***********************************************************/
 /***********************************************************
  * Load all records from local file
  ***********************************************************/
Record load(Record head) {
	Record inputStudent;
	FILE* fp = NULL;
	char fileName[NAME_LEN];
	int i;

	system("CLS");

	setTextColorBlue(g_output_handle);

	printf("\n\n\t\t\t Load student consumption record from local file\n");

	setTextColorBlack(g_output_handle);

	printf("\n\n\t\t Please input <file path>:\n\n\t\t\t     ");

	setTextColorPink(g_output_handle);

	scanf_s("%s", &fileName);

	setTextColorBlack(g_output_handle);

	// error handle
	if (fopen_s(fp, fileName, "r+") != 0) {
		setTextColorRed(g_output_handle);

		printf("\n\n\t    Can not open file. File does not exist!\n");
		
		setTextColorBlack(g_output_handle);

		_getch();

		return NULL; //TODO
	}
	else {
		setTextColorPurple(g_output_handle);

		inputStudent = (Record)malloc(sizeof(struct recordNode));

		// Draw data in table
		printf("\t\t---------------------------------------------------\n");
		printf("\t\t  | ID\t   | name\t  | money\t\n");

		// Reset data link and update with file content
		headStudent = NULL;
		g_record_len = 0;

		// Read data till the end of file
		while (!feof(fp)) {
			// read record and get value
			fscanf_s(fp, "%d%s%d\n", &inputStudent->id, inputStudent->name, inputStudent->money);
			printf("\t\t  | %d\t   | %s\t   | %d\t\n", inputStudent->id, inputStudent->name, inputStudent->money);

			g_record_len++;
			if (g_record_len == 1) {
				headStudent = inputStudent;
			}

			currStudent = inputStudent;
			inputStudent->next = (Record)malloc(sizeof(struct recordNode));
			inputStudent = inputStudent->next;
		} 
		
		currStudent->next = NULL;

		printf("\t\t---------------------------------------------------\n");
		_getch();
		fclose(fp);

		return headStudent;
	}
}

/***********************************************************
 * Save data to local file
 ***********************************************************/
void saveToFile(Record pos) {
	FILE* fp = NULL;

	// create and open file first
	if (fopen_s(fp, "E:\\consumption", "wb") != 0) {
		setTextColorRed(g_output_handle);
		printf("Cannot open this file!\n");
	}
	else {
		while (pos != NULL){
			fprintf_s(fp, "%d,%s,%s,%d\t\t\t", pos->id, pos->name, pos->money);
			pos = pos->next;
		}
		printf("\t\tFile saved at E:\\\consume \n");
		_getch();
	}

	fclose(fp);
}