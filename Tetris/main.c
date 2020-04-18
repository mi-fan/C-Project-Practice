#include "common.h"

// global variable
int tmp, tmp1, tmp2;
int gameArea[80][80] = { 0 };
int gamePiece[4];

void flag(struct Tetris *);
void makeTetris(struct Tetris *);
void printTetris(struct Tetris *);
void cleanTetris(struct Tetris *);
int ifMove(struct Tetris*);
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