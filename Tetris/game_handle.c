#include "game_handle.h"

extern int gameArea[AREA_HEIGHT][AREA_WIDTH];
extern int gamePiece[BLOCK_COUNT];

// decide whether the specific basic type can move
static int ifMovableSquare(struct Tetris* tet) {
	if ((gameArea[tet->x][tet->y + 1] == 0)
		&& (gameArea[tet->x + 2][tet->y] == 0)
		&& (gameArea[tet->x + 2][tet->y + 1] == 0))
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

//T-shape has 4 formations
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

//Z-shape has 2 formations
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
//Z-shape-inverted has 2 formations
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

//7-shape has 4 formations
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

//7-shape-inverted has 4 formations
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