#include "common.h"

gameInfo_t g_GameInfo;
int g_GameTable[LEN][LEN];

int main(void) {
	int choice = 0;
	int status;

	// run game branch
	while (TRUE)
	{
		// draw the menu with frame
		draw_Title();
		draw_Menu();

		// keyboard input
		gotoxy(21, 22);
		color(PURPLE);
		printf("Your choice is ... ");

		scanf_s("%d", &choice);

		status = game_Route(choice);

		// handle the invalid choice
		if (FALSE == status) {
			gotoxy(21, 23);
			color(RED);
			printf("Input a integer of 1, 2, 3, 4 ...  \b");
		}
		else {
			color(GRAY);
			printf("\n\n\npress any key to continue...");
			_getch();
			continue;
		}
	}

	return 0;
}