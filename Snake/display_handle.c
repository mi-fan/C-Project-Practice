#include "display_handle.h"

//*********************************************//
//                                             //
// Define the functions used for display       //
// pictures, shapes and words                  //
//                                             //
//*********************************************//

/***********************************
* Draw one snake in welcome window
***********************************/
void drawSnakeLogo(void) {
	color(PURPLE);
	gotoxy(35, 1);
	printf("/^\\/^\\");

	gotoxy(34, 2);
	printf("|__|  0|");

	color(GREEN_DEEP);
	gotoxy(33, 2);
	printf("_");

	color(RED);
	gotoxy(25, 3);
	printf("\\/");

	color(GREEN_DEEP);
	gotoxy(31, 3);
	printf("/");

	color(YELLOW_DARK);
	gotoxy(37, 3);
	printf("\\_/");

	color(GREEN_LIGTH);
	gotoxy(41, 3);
	printf(" \\");

	color(RED);
	gotoxy(26, 4);
	printf("\\____");

	color(RED);
	gotoxy(32, 4);
	printf("__________/");

	color(GREEN_DEEP);
	gotoxy(31, 4);
	printf("|");

	color(GREEN_LIGTH);
	gotoxy(43, 4);
	printf("\\");

	color(GREEN_DEEP);
	gotoxy(32, 5);
	printf("\\______");

	color(GREEN_LIGTH);
	gotoxy(44, 5);
	printf("\\");

	gotoxy(39, 6);
	printf("|     |                 \\");

	gotoxy(38, 7);
	printf("/     /                   \\");

	gotoxy(37, 8);
	printf("/     /                    \\ \\");

	gotoxy(35, 9);
	printf("/     /                      \\  \\");

	gotoxy(34, 10);
	printf("/     /                        \\  \\");

	gotoxy(33, 11);
	printf("/     /          _----_          \\  \\");

	gotoxy(32, 12);
	printf("/     /       _-~       ~-_        |  |");

	gotoxy(31, 13);
	printf("(     (     _-~   _--_    ~-_      _/  |");

	gotoxy(32, 14);
	printf("\\   ~-_____-~   _-~   ~-_   ~-_-~     /");

	gotoxy(33, 15);
	printf("~-_           _-~       ~-_       _-~");

	gotoxy(35, 16);
	printf("~--______-~             ~-___-~");
}

/***********************************
* Draw the menu 
***********************************/
void drawMenu(void) {
	int i, j;

	color(BL_GR_LIGHT);
	gotoxy(43, 18);
	printf("Snake Likes Eating");

	// draw the top and bottom frame
	color(YELLOW);
	for (i = 20; i <= 26; i+=6) {
		for (j = 27; j <= 74; j++) {
			gotoxy(j, i);
			if (i == 20 || i == 26) {
				printf("=");
			}
		}
	}

	color(WHITE);
	gotoxy(35, 23);
	printf("1. Start Game");

	gotoxy(55, 23);
	printf("2. Quit");

	color(PINK);
	gotoxy(29, 27);
	printf("Please select [1/2/3] : [ ]\b\b");
}

/*******************************
* Draw the game map
*******************************/
void drawMap(void) {
	int i, j;

	// draw the top and bottom walls
	color(PURPLE);
	for (i = 0; i < 58; i += 2) {
		gotoxy(i, 0);
		printf("■");
		gotoxy(i, 26);
		printf("■");
	}

	// draw the left and right walls
	for (i = 0; i < 26; i++) {
		gotoxy(0, i);
		printf("■");
		gotoxy(56, i);
		printf("■");
	}

	// draw the grid
	/*
	for (i = 2; i < 56; i += 2) {
		for (j = 1; j < 26; j++) {
			gotoxy(i, j);
			color(3);
			printf("□");
		}
	}
	*/
}

/*******************************
* Show the real-time game info
*******************************/
void showGameInfo(void) {
	color(BL_GR_LIGHT);
	gotoxy(64, 4);
	printf("# High Score # : %d", highScore);

	color(YELLOW);
	gotoxy(64, 8);
	printf("Current score: %d", score);

	color(PINK);
	gotoxy(60, 12);
	printf("*------------------------------*");
	gotoxy(64, 14);
	printf("Hints: ");
	gotoxy(64, 15);
	printf("1. Don't crash to the wall");
	gotoxy(64, 16);
	printf("2. Press 1 to speed up");
	gotoxy(64, 17);
	printf("3. Press 2 to speed down");
	gotoxy(60, 19);
	printf("*------------------------------*");
}

/*******************************
* Show the game end window
*******************************/
void showGameEndWindow(void) {
	system("CLS");

	gotoxy(35, 9);

	// show the text according to game result
	switch (gameResult)
	{
	case G_FAIL:
		color(GRAY);
		printf("Game Over!");
		break;
	case G_QUIT:
		color(RED);
		printf("Please be more patient...");
		break;
	case G_WIN:
		color(YELLOW);
		printf("Congratulations! You are the winner!");
		break;
	default:
		break;
	}

	gotoxy(43, 12);
	color(BL_GR_LIGHT);
	printf("Your final score is %d", score);

	// print highscore
	gotoxy(33, 16);
	if (score > highScore) {
		color(PINK);
		printf("New Highscore! Great Job!");
		File_In();
	}
	else {
		color(GREEN_LIGTH);
		printf("Keep playing, you need %d to update highscore", highScore - score);
	}
}

/***********************************
* Show further selection after end
***********************************/
int selectionAfterEnd(void) {
	int select;

	gotoxy(25, 23);
	printf("Play again[1]");

	gotoxy(52, 23);
	printf("Quit[2]");
	
	gotoxy(46, 25);
	color(BLUE_LIGHT);
	printf("You choose...");

	do 
	{
		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
			return G_RESUME;
		case 2:
			return G_QUIT;
		default:
			color(GRAY);
			gotoxy(46, 27);
			printf("Please choose valid number[1/2] ... ");
			break;
		}
	} while (TRUE);
}