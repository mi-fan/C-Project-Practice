#include "game_handle.h"

extern int gameArea[AREA_HEIGHT][AREA_WIDTH];
extern int gamePiece[BLOCK_COUNT];

void makeTetris(struct Tetris* tet);

// decide whether the specific basic type can move
// SQUARE cannot rotate
static int ifMovableSquare(struct Tetris* tet) {
	if ((gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x + 2][tet->y] == 0) && (gameArea[tet->x + 2][tet->y + 1] == 0))
		return TRUE;
	else
		return FALSE;
}

// LINE has 2 formations
static int ifMovableLine(struct Tetris* tet) {
	if (tet->flag == T_LINE_HORIZ){
		if ((gameArea[tet->x + 2][tet->y] == 0) && (gameArea[tet->x + 4][tet->y] == 0) && (gameArea[tet->x - 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else {
		if ((gameArea[tet->x][tet->y - 1] == 0) && (gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x][tet->y + 2] == 0))
			return TRUE;
		else
			return FALSE;
	}
}

// T-shape has 4 formations
static int ifMovableTShape(struct Tetris* tet) {
	if (tet->flag == T_TSHAPE_DOWN) {
		if ((gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x + 2][tet->y] == 0) && (gameArea[tet->x - 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_TSHAPE_LEFT) {
		if ((gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x][tet->y - 1] == 0) && (gameArea[tet->x - 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_TSHAPE_RIGHT) {
		if ((gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x ][tet->y - 1] == 0) && (gameArea[tet->x + 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else{
		if ((gameArea[tet->x - 2][tet->y] == 0) && (gameArea[tet->x + 2][tet->y] == 0) && (gameArea[tet->x][tet->y - 1] == 0))
			return TRUE;
		else
			return FALSE;
	}
}

// Z-shape has 2 formations
static int ifMovableZShape(struct Tetris* tet) {
	if (tet->flag == T_ZSHAPE_LEFT) {
		if ((gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x + 2][tet->y + 1] == 0) && (gameArea[tet->x - 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else {
		if ((gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x + 2][tet->y] == 0) && (gameArea[tet->x + 2][tet->y - 1] == 0))
			return TRUE;
		else
			return FALSE;
	}
}
// Z-shape-inverted has 2 formations
static int ifMovableZSInv(struct Tetris* tet) {
	if (tet->flag == T_ZINV_RIGHT) {
		if ((gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x - 2][tet->y + 1] == 0) && (gameArea[tet->x + 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else {
		if ((gameArea[tet->x][tet->y - 1] == 0) && (gameArea[tet->x + 2][tet->y] == 0) && (gameArea[tet->x + 2][tet->y + 1] == 0))
			return TRUE;
		else
			return FALSE;
	}
}

// 7-shape has 4 formations
static int ifMovableSeven(struct Tetris* tet) {
	if (tet->flag == T_SEVEN_DOWN) {
		if ((gameArea[tet->x - 2][tet->y] == 0) && (gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x][tet->y + 2] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_SEVEN_LEFT) {
		if ((gameArea[tet->x][tet->y - 1] == 0) && (gameArea[tet->x - 2][tet->y] == 0) && (gameArea[tet->x - 4][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_SEVEN_UP) {
		if ((gameArea[tet->x + 2][tet->y] == 0) && (gameArea[tet->x][tet->y - 1] == 0) && (gameArea[tet->x][tet->y - 2] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else {
		if ((gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x + 2][tet->y] == 0) && (gameArea[tet->x + 4][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
}

// 7-shape-inverted has 4 formations
static int ifMovableSevenInv(struct Tetris* tet) {
	if (tet->flag == T_SEVINV_DOWN) {
		if ((gameArea[tet->x + 2][tet->y] == 0) && (gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x][tet->y + 2] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_SEVINV_LEFT) {
		if ((gameArea[tet->x][tet->y + 1] == 0) && (gameArea[tet->x - 2][tet->y] == 0) && (gameArea[tet->x - 4][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_SEVINV_UP) {
		if ((gameArea[tet->x - 2][tet->y] == 0) && (gameArea[tet->x][tet->y - 1] == 0) && (gameArea[tet->x][tet->y - 2] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else {
		if ((gameArea[tet->x][tet->y - 1] == 0) && (gameArea[tet->x + 2][tet->y] == 0) && (gameArea[tet->x + 4][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
}

// decide whether one piece can move
int ifMovable(struct Tetris* tet) {
	int ret = FALSE;

	if (gameArea[tet->x][tet->y] != 0) {
		return FALSE;
	}

	switch (tet->flag) {
	case T_SQUARE:
		ret = ifMovableSquare(tet);
		break;
	case T_LINE_HORIZ:
	case T_LINE_VERT:
		ret = ifMovableLine(tet);
		break;
	case T_TSHAPE_DOWN:
	case T_TSHAPE_LEFT:
	case T_TSHAPE_UP:
	case T_TSHAPE_RIGHT:
		ret = ifMovableTShape(tet);
		break;
	case T_ZSHAPE_LEFT:
	case T_ZSHAPE_UP:
		ret = ifMovableZShape(tet);
		break;
	case T_ZINV_RIGHT:
	case T_ZINV_UP:
		ret = ifMovableZSInv(tet);
		break;
	case T_SEVEN_DOWN:
	case T_SEVEN_UP:
	case T_SEVEN_LEFT:
	case T_SEVEN_RIGHT:
		ret = ifMovableSeven(tet);
		break;
	case T_SEVINV_DOWN:
	case T_SEVINV_LEFT:
	case T_SEVINV_UP:
	case T_SEVINV_RIGHT:
		ret = ifMovableSevenInv(tet);
		break;
	default:
		ret = FALSE;
		break;
	}

	return ret;
}

// clean the print of falling Tetris piece
void cleanTetris(struct Tetris* tet) {
	int i, j;

	for (i = 0; i < BLOCK_COUNT; i++) {
		gamePiece[i] = FLAG_EMPTY;
	}

	makeTetris(tet);  // draw an blank area with empty gamePiece

	for (i = tet->x - 4; i <= tet->x + 4; i+=2) {                       // search the surrounding area
		for (j = tet->y - 2; j <= tet->y + 2; j++) {
			if ((gameArea[i][j] == FLAG_EMPTY) && (j > FRAME_Y)) {      // if the pixel is empty and inside game area
				gotoxy(i, j);
				printf("  ");
			}

		}
	}
}

// decide whether a line is full, and delete the full lines
// a line is full when pixels with same Y coordinate inside game area are all blocks
void delFullLine(struct Tetris* tet) {
	int i, j, k, l, delRows = 0;

	for (j = FRAME_Y + FRAME_HEIGHT - 1; j > FRAME_Y; j--) {
		k = 0;
		for (i = FRAME_X + 2; i < FRAME_X + 2 * FRAME_WIDTH; i += 2) {
			if (gameArea[i][j] == FLAG_BLOCK) {
				k++;
				if (k == FRAME_WIDTH - 2) {                                                // if line is full
					for (k = FRAME_X + 2; k < FRAME_X + 2 * FRAME_WIDTH - 2; k += 2) {     // delete the blocks in line
						gameArea[k][j] = FLAG_EMPTY;
						gotoxy(k, j);
						printf("  ");
					}

					for (k = j - 1; k > FRAME_Y; k--) {                // if there are valid blocks above the deledted line
						for (l = FRAME_X + 2; l < FRAME_X + 2 * FRAME_WIDTH - 2; l += 2) {
							if (gameArea[l][k] == FLAG_BLOCK) {
								gameArea[l][k] = FLAG_EMPTY;       // set old pixel empty
								gotoxy(l, k);
								printf("  ");
								gameArea[l][k - 1] = FLAG_BLOCK;   // set upper pixel valid
								gotoxy(l, k - 1);
								printf("¡ö");
							}
						}
					}
					j++;              // consider the new bottom line
					delRows++;
				}
			}
		}
	}
	tet->score += 100 * delRows;
	if ((delRows > 0) && ((tet->score % 1000 == 0) || (tet->score / 1000 > tet->level - 1))) {
		tet->speed -= 20;     // if get 1000 score, level up and reduce falling time-step by 20 ms
		tet->level++;
	}
}