#pragma once
#include "common.h"

void createFood(void);
void createSnake(void);
void speedUp(void);
void speedDown(void);
int biteSelf(void);
int hitWall(void);
int checkEatFood(snake_t* nextHead);
void snakeMovePosition(BOOLEAN eatFlag);
