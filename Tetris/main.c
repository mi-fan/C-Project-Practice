#include "common.h"

// global variable
int tmp, tmp1, tmp2;
int tTable[AREA_HEIGHT][AREA_WIDTH] = { 0 };
int tPiece[BLOCK_COUNT];

int main(void) {
	int mode;

	mode = NORMAL_GAME;

	while (1) {
		title(mode);
		mode = welcome(mode);
	}

	return 0;
}