#include "common.h"


int selection(void);
void illegal_Notice(void);

int main(void) {

	system("mode con cols=100 lines=30");       // set size of console
	
	drawSnakeLogo();

	drawMenu();

	selection();

	return 0;
}

/***********************************
* Run the selected module
***********************************/
int selection(void) {
	int sel;
	int status = TRUE;

	// receive input selection
	do {
		color(GRAY);
		scanf_s("%d", &sel);

		switch (sel)
		{
		case S_START:
			break;
		case S_INSTRUCT:
			break;
		case S_QUIT:
			break;
		default:
			illegal_Notice();
			break;
		}
	} while (status == TRUE);

}

void illegal_Notice(void) {
	color(RED);
	gotoxy(29, 28);
	printf("Please input 1, 2 or 3 ...");
}