#include "common.h"


int selection(void);
void illegal_Notice(void);

int main(void) {

	system("mode con cols=100 lines=30");       // set size of console

	gameResult = G_NORMAL;
	
	while (gameResult != G_QUIT) {
		drawSnakeLogo();

		File_Out();

		drawMenu();

		selection();

		showGameEndWindow();
	}

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

		status = TRUE;

		switch (sel)
		{
		case S_START:
			system("CLS");
			drawMap();
			showGameInfo();
			createSnake();
			createFood();
			keyboardControl();
			break;
		case S_QUIT:
			break;
		default:
			illegal_Notice();
			status = FALSE;
			break;
		}
	} while (status == FALSE);

}

void illegal_Notice(void) {
	color(RED);
	gotoxy(29, 28);
	printf("Please input 1, 2 or 3 ...");
}