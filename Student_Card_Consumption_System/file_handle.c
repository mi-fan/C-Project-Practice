#include "common.h"

/***********************************************************
 *
 *          Functions for load and read file
 *
 ***********************************************************/
 /***********************************************************
  * Load records from local file
  ***********************************************************/
Record load(Record head) {
	Record inputStudent;
	FILE* fp;
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
	if ((fp = fopen(fileName, "r+")) == NULL) {
		setTextColorRed(g_output_handle);

		printf("\n\n\t    Can not open file. File does not exist!\n");
		
		setTextColorBlack(g_output_handle);

		getch();

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
		getch();
		fclose(fp);

		return headStudent;
	}
}