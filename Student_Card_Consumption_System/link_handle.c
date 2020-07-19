#include "link_handle.h"

/***********************************************************
 *
 *          Link list operation functions
 *
 ***********************************************************/
#if 1
/***********************************************************
 * Search the link for specific student ID
 ***********************************************************/
void initLink(void) {
	headStudent = (Record)malloc(sizeof(struct recordNode));
	currStudent = headStudent;
	g_record_len = 0;
}
#endif
#if 1
/***********************************************************
 * Search the link for specific student ID
 ***********************************************************/
int searchSameId(Record head, int id) {
	int result = FALSE;
	Record seek = head;

	// no same ID if link is empty
	if (head == NULL) {
		return result;
	}

	do {
		if (seek->id == id) {
			result = TRUE;
			break;
		}

		if (seek->next == NULL) {
			break;
		}

		seek = seek->next;
	} while (seek != NULL);

	return result;
}

/***********************************************************
 * Sort the link according to student ID (acceding)
 ***********************************************************/
void sortLink(Record head) {
	Record tmp1, tmp2;
	char tmpName[NAME_LEN];
	int tmpId;
	int i, j;

	tmp1 = head;

	for (i = 0; i < g_record_len - 1; i++) {
		for (j = i + 1; j < g_record_len; j++) {
			tmp2 = tmp1->next;

			if (tmp1->id > tmp2->id) {
				// exchange content
				tmpId = tmp1->id;
				tmp1->id = tmp2->id;
				tmp2->id = tmpId;
				strcpy_s(tmpName, NAME_LEN * sizeof(char), tmp1->name);
				strcpy_s(tmp1->name, NAME_LEN * sizeof(char), tmp2->name);
				strcpy_s(tmp2->name, NAME_LEN * sizeof(char), tmpName);
			}
			tmp1 = tmp2;
		}
	}
}
#endif