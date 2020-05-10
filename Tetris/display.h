#pragma once
#include "common.h"

void title(int mode);
int  welcome(int mode);
void drawGameFrame(void);
void makeTetris(struct Tetris* tet);
void printTetris(struct Tetris* tet);
void instruction(void);
void gameRule(void);
void flushGameTable(void);