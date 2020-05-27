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