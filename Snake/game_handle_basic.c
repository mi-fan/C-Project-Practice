#include "game_handle_basic.h"

//*********************************************//
//                                             //
// Define basic functions used in game control //
// don not care about game rule                //
//                                             //
//*********************************************//

/***********************************
* Create food at random position
***********************************/
void createFood(void) {
	int status = FALSE;
	snake_t* food_tmp;

	do {
		srand((unsigned)time(NULL));
		food_tmp = (snake_t*)malloc(sizeof(snake_t));

		food_tmp->x = rand() % 52 + 2;
		food_tmp->x &= ~((int)0x1);               //x coordinate must be even
		food_tmp->y = rand() % 24 + 1;

		seek = head;

		// seek the snake body, avoid food created in body
		while (seek != NULL) {
			if ((seek->x == food_tmp->x) && (seek->y == food_tmp->y)) {
				free(food_tmp);         // free current temp food
				status = FALSE;         // create temp food again
				break;
			}

			if (seek->next != NULL) {
				seek = seek->next;      // move to next body piece
			}
			else {
				status = TRUE;
				break;
			}
		}
	} while (status == FALSE);

	// print the food 
	food = food_tmp;

	gotoxy(food->x, food->y);
	color(GREEN_LIGTH);
	printf("¡î");
}

/*******************************
* Draw the original snake
*******************************/
void createSnake(void) {
	int i;
	snake_t* tail;

	length = 0;  // init snake length

	tail = (snake_t*)malloc(sizeof(snake_t));

	// assign the starting tail position
	tail->x = 24;
	tail->y = 5;
	tail->next = NULL;

	// grow from tail to head, just need to allocate head buffer each cycle
	for (i = 0; i < 4; i++) {
		head = (snake_t*)malloc(sizeof(snake_t));
		head->next = tail;
		head->x = 26 + 2 * i;
		head->y = 5;
		tail = head;
		length++;
	}

	i = 0;

	// draw the snake from head to tail
	while (tail != NULL) {
		gotoxy(tail->x, tail->y);
		color(YELLOW);

		if (i == 0) {
			printf("¡ñ");     // use ¡ñ to mark the snake head
			i++;
		}
		else {
			printf("¡ö");
		}

		tail = tail->next;
	}
}

/*******************************
* Check if head bite the body
*******************************/
int biteSelf(void) {
	snake_t* self;

	self = head->next;

	while (self != NULL) {
		if ((self->x == head->x) && (self->y == head->y)) {
			return TRUE;
		}
		if (self->next != NULL) {
			self = self->next;
		}
		else{
			break;
		}
	}

	return FALSE;
}

/*******************************
* Check if head hit the wall
*******************************/
int hitWall(void) {
	if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26) {
		return TRUE;
	}
	
	return FALSE;
}

/*************************************
* Check if snake grows to max length
**************************************/
int growMax(void) {

	// if there are rarely space for snake to move
	// player should be winner
	if (length >= (MAP_TOTAL_PIXEL - 2)) {
		return TRUE;
	}

	return FALSE;
}

/*******************************
* Speed up 
*******************************/
void speedUp(void) {
	if (sleepTime >= 50) {
		sleepTime -= 10;
		scoreStep += 2;
	}
}

/*******************************
* Speed down
*******************************/
void speedDown(void) {
	if (sleepTime < 350) {
		sleepTime += 30;
		scoreStep -= 2;

		if (sleepTime == 350) {
			scoreStep = 1;
		}
	}
}

/*******************************
* Check if snake eats the food
*******************************/
int checkEatFood(snake_t* nextHead) {
	if ((nextHead->x == food->x) && (nextHead->y == food->y)) {
		length++;       // if eat food, snake length plus one
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/*******************************
* Check if snake eats the food
*******************************/
void snakeMovePosition(BOOLEAN eatFlag) {
	snake_t* last = head;

	// draw the head
	color(YELLOW);
	gotoxy(head->x, head->y);
	printf("¡ñ");

	seek = head->next;

	// draw the body except tail
	while (seek->next != NULL) {
		gotoxy(seek->x, seek->y);
		printf("¡ö");

		if (seek->next != NULL) {
			last = seek;
			seek = seek->next;
		}
		else {
			break;
		}
	}

	// seek points to tail, last points to the last but one
	// if eats food, keep the old tail and snake get one piece longer
	if (TRUE == eatFlag) {
		gotoxy(seek->x, seek->y);
		printf("¡ö");
		score += scoreStep;
	}
	else {        // clear and free old tail
		color(BLACK);
		gotoxy(seek->x, seek->y);
		printf("  ");
		last->next = NULL;   // update tail
		free(seek);
	}
}