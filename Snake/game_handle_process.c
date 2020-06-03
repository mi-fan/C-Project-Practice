#include "game_handle_process.h"

//*********************************************//
//                                             //
// Functions control the game flow             //
// Eat food, game status determination         //
//                                             //
//*********************************************//

/*************************************
* Snake move up
**************************************/
void snakeMoveUp(snake_t* nextHead) {
	int ret;

	// X keeps the same, y--
	nextHead->x = head->x;
	nextHead->y = head->y - 1;
	
	// move head one step
	nextHead->next = head;
	head = nextHead;

	// if there is food in new position, add score and create new food
	ret = checkEatFood(head);
	snakeMovePosition(ret);
}

/*************************************
* Snake move down
**************************************/
void snakeMoveDown(snake_t* nextHead) {
	int ret;

	// X keeps the same, y--
	nextHead->x = head->x;
	nextHead->y = head->y + 1;

	// move head one step
	nextHead->next = head;
	head = nextHead;

	// if there is food in new position, add score and create new food
	ret = checkEatFood(head);
	snakeMovePosition(ret);
}

/*************************************
* Snake move left
**************************************/
void snakeMoveLeft(snake_t* nextHead) {
	int ret;

	// X keeps the same, y--
	nextHead->x = head->x - 2;
	nextHead->y = head->y;

	// move head one step
	nextHead->next = head;
	head = nextHead;

	// if there is food in new position, add score and create new food
	ret = checkEatFood(head);
	snakeMovePosition(ret);
}

/*************************************
* Snake move right
**************************************/
void snakeMoveRight(snake_t* nextHead) {
	int ret;

	// X keeps the same, y--
	nextHead->x = head->x + 2;
	nextHead->y = head->y;

	// move head one step
	nextHead->next = head;
	head = nextHead;

	// if there is food in new position, add score and create new food
	ret = checkEatFood(head);
	snakeMovePosition(ret);
}

/*************************************
* Snake move without keyboard control
**************************************/
void snakeMove(void) {
	snake_t* nextHead;
	int result;

	nextHead = (snake_t*)malloc(sizeof(snake_t));

	switch (directionStatus)
	{
	case UP:
		snakeMoveUp(nextHead);
		break;
	case DOWN:
		snakeMoveDown(nextHead);
		break;
	case LEFT:
		snakeMoveLeft(nextHead);
		break;
	case RIGHT:
		snakeMoveRight(nextHead);
		break;
	default:
		break;
	}

	if (TRUE == biteSelf() || TRUE == hitWall()) {
		gameResult = G_FAIL;
	}
	else if (TRUE == growMax()) {
		gameResult = G_WIN;
	}
}

/*************************************
* Snake move with keyboard control
* endless move until game ends
**************************************/
void keyboardControl(void) {
	int ch;

	directionStatus = RIGHT; // set default direction to right

	while (TRUE) {
		showGameInfo();

		// GetAsyncKeyState to determine the status of specific virtual key
		// key input only works when it is not the opposite of current direction
		if (GetAsyncKeyState(VK_UP) && (directionStatus != DOWN)) {
			directionStatus = UP;           // if current direction is not down, and get up key
		}
		else if (GetAsyncKeyState(VK_DOWN) && (directionStatus != UP)) {
			directionStatus = DOWN;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && (directionStatus != LEFT)) {
			directionStatus = RIGHT;
		}
		else if (GetAsyncKeyState(VK_LEFT) && (directionStatus != RIGHT)) {
			directionStatus = LEFT;
		}

		// if get SPACE key, pause the game
		if (GetAsyncKeyState(VK_SPACE)) {
			while (TRUE){
				Sleep(300);
				if (GetAsyncKeyState(VK_SPACE)) {     // pause SPACE again to resume
					break;
				}
				else if (GetAsyncKeyState(VK_ESCAPE)) {
					gameResult = G_QUIT;
					return;
				}
			}
		}
		else if (GetAsyncKeyState(VK_ESCAPE)) {
			gameResult = G_QUIT;
			return;
		}
		else if (GetAsyncKeyState(0x31)) {
			speedUp();
		}
		else if (GetAsyncKeyState(0x32)) {
			speedDown();
		}
		Sleep(sleepTime);
		snakeMove();

		if ((gameResult == G_FAIL) || (gameResult == G_WIN)) {
			return;
		}
	}
}