#include "common.h"

// global variable
int tmp, tmp1, tmp2;
int gameArea[AREA_HEIGHT][AREA_WIDTH] = { 0 };
int gamePiece[BLOCK_COUNT];

void flag(struct Tetris *);

void cleanTetris(struct Tetris *);

void delFullLine(struct Tetris*);
void gamePlay(void);
void regulation(void);
void explation(void);
void replay(struct Tetris*);
void flower(void);
void close(void);

// function definition




int main(void) {
	title();

	welcome();
	
	return 0;
}