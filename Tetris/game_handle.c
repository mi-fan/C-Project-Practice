#include "game_handle.h"

extern int tTable[AREA_HEIGHT][AREA_WIDTH];
extern int tPiece[BLOCK_COUNT];

void makeTetris(struct Tetris* tet);

// decide whether the specific basic type can move
// SQUARE cannot rotate
static int ifMovableSquare(struct Tetris* tet) {
	if ((tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x + 2][tet->y] == 0) && (tTable[tet->x + 2][tet->y + 1] == 0))
		return TRUE;
	else
		return FALSE;
}

// LINE has 2 formations
static int ifMovableLine(struct Tetris* tet) {
	if (tet->flag == T_LINE_HORIZ){
		if ((tTable[tet->x + 2][tet->y] == 0) && (tTable[tet->x + 4][tet->y] == 0) && (tTable[tet->x - 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else {
		if ((tTable[tet->x][tet->y - 1] == 0) && (tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x][tet->y + 2] == 0))
			return TRUE;
		else
			return FALSE;
	}
}

// T-shape has 4 formations
static int ifMovableTShape(struct Tetris* tet) {
	if (tet->flag == T_TSHAPE_DOWN) {
		if ((tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x + 2][tet->y] == 0) && (tTable[tet->x - 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_TSHAPE_LEFT) {
		if ((tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x][tet->y - 1] == 0) && (tTable[tet->x - 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_TSHAPE_RIGHT) {
		if ((tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x ][tet->y - 1] == 0) && (tTable[tet->x + 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else{
		if ((tTable[tet->x - 2][tet->y] == 0) && (tTable[tet->x + 2][tet->y] == 0) && (tTable[tet->x][tet->y - 1] == 0))
			return TRUE;
		else
			return FALSE;
	}
}

// Z-shape has 2 formations
static int ifMovableZShape(struct Tetris* tet) {
	if (tet->flag == T_ZSHAPE_LEFT) {
		if ((tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x + 2][tet->y + 1] == 0) && (tTable[tet->x - 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else {
		if ((tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x + 2][tet->y] == 0) && (tTable[tet->x + 2][tet->y - 1] == 0))
			return TRUE;
		else
			return FALSE;
	}
}
// Z-shape-inverted has 2 formations
static int ifMovableZSInv(struct Tetris* tet) {
	if (tet->flag == T_ZINV_RIGHT) {
		if ((tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x - 2][tet->y + 1] == 0) && (tTable[tet->x + 2][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else {
		if ((tTable[tet->x][tet->y - 1] == 0) && (tTable[tet->x + 2][tet->y] == 0) && (tTable[tet->x + 2][tet->y + 1] == 0))
			return TRUE;
		else
			return FALSE;
	}
}

// 7-shape has 4 formations
static int ifMovableSeven(struct Tetris* tet) {
	if (tet->flag == T_SEVEN_DOWN) {
		if ((tTable[tet->x - 2][tet->y] == 0) && (tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x][tet->y + 2] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_SEVEN_LEFT) {
		if ((tTable[tet->x][tet->y - 1] == 0) && (tTable[tet->x - 2][tet->y] == 0) && (tTable[tet->x - 4][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_SEVEN_UP) {
		if ((tTable[tet->x + 2][tet->y] == 0) && (tTable[tet->x][tet->y - 1] == 0) && (tTable[tet->x][tet->y - 2] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else {
		if ((tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x + 2][tet->y] == 0) && (tTable[tet->x + 4][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
}

// 7-shape-inverted has 4 formations
static int ifMovableSevenInv(struct Tetris* tet) {
	if (tet->flag == T_SEVINV_DOWN) {
		if ((tTable[tet->x + 2][tet->y] == 0) && (tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x][tet->y + 2] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_SEVINV_LEFT) {
		if ((tTable[tet->x][tet->y + 1] == 0) && (tTable[tet->x - 2][tet->y] == 0) && (tTable[tet->x - 4][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else if (tet->flag == T_SEVINV_UP) {
		if ((tTable[tet->x - 2][tet->y] == 0) && (tTable[tet->x][tet->y - 1] == 0) && (tTable[tet->x][tet->y - 2] == 0))
			return TRUE;
		else
			return FALSE;
	}
	else {
		if ((tTable[tet->x][tet->y - 1] == 0) && (tTable[tet->x + 2][tet->y] == 0) && (tTable[tet->x + 4][tet->y] == 0))
			return TRUE;
		else
			return FALSE;
	}
}

// decide whether one piece can move
int ifMovable(struct Tetris* tet) {
	int ret = FALSE;

	if (tTable[tet->x][tet->y] != 0) {
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
		tPiece[i] = FLAG_EMPTY;
	}

	makeTetris(tet);  // draw an blank area with empty gamePiece

	for (i = tet->x - 4; i <= tet->x + 4; i+=2) {                       // search the surrounding area
		for (j = tet->y - 2; j <= tet->y + 2; j++) {
			if ((tTable[i][j] == FLAG_EMPTY) && (j > FRAME_Y)) {      // if the pixel is empty and inside game area
				gotoxy(i, j);
				printf("  ");
			}

		}
	}
}

// decide whether a line is full, and delete the full lines
// a line is full when pixels with same Y coordinate inside game area are all blocks
void delFullLine(struct Tetris* pTet) {
	int i, j, k, l, delRows = 0;

	for (j = FRAME_Y + FRAME_HEIGHT - 1; j > FRAME_Y; j--) {
		k = 0;
		for (i = FRAME_X + 2; i < FRAME_X + 2 * FRAME_WIDTH; i += 2) {
			if (tTable[i][j] == FLAG_BLOCK) {
				k++;
				if (k == FRAME_WIDTH - 2) {                                                // if line is full
					for (k = FRAME_X + 2; k < FRAME_X + 2 * FRAME_WIDTH - 2; k += 2) {     // delete the blocks in line
						tTable[k][j] = FLAG_EMPTY;
						gotoxy(k, j);
						printf("  ");
					}

					for (k = j - 1; k > FRAME_Y; k--) {                // if there are valid blocks above the deledted line
						for (l = FRAME_X + 2; l < FRAME_X + 2 * FRAME_WIDTH - 2; l += 2) {
							if (tTable[l][k] == FLAG_BLOCK) {
								tTable[l][k] = FLAG_EMPTY;       // set old pixel empty
								gotoxy(l, k);
								printf("  ");
								tTable[l][k - 1] = FLAG_BLOCK;   // set upper pixel valid
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
	pTet->score += 100 * delRows;
	if ((delRows > 0) && ((pTet->score % 1000 == 0) || (pTet->score / 1000 > pTet->level - 1))) {
		pTet->speed -= 20;     // if get 1000 score, level up and reduce falling time-step by 20 ms
		pTet->level++;
	}
}

// Generate random tetris pieces
void genRandTetris(struct Tetris* tet) {
	tet->number++;
	srand(time(NULL));
	if (tet->number == 1) {
		tet->flag = rand() % T_TOTAL;     // init the first piece 
	}
	tet->next = rand() % T_TOTAL;         // generate the next piece shown in NEXT window
}

// play the game
void playGame(void) {
	int n, state, tmpx, tmpf;
	UINT32 pauseTime;
	char ch;
	struct Tetris tet, tNext;
	struct Tetris* pTet;
	struct Tetris* pNext;

	pTet = &tet;              // init
	pTet->number = 0;              
	pTet->speed = 300;
	pTet->score = 0;
	pTet->level = 1;

	pNext = &tNext;

	// main loop of game
	while (1) {
		genRandTetris(pTet);                          // generate new piece
		memcpy((INT8*)pNext, (INT8*)pTet, sizeof(struct Tetris));

		pNext->x = FRAME_X + 2 * FRAME_WIDTH + 6;     // get the NEXT window coordinate
		pNext->y = FRAME_Y + 10;
		pNext->flag = pTet->next;
		printTetris(pNext);

		pTet->x = FRAME_X + FRAME_WIDTH;              // get the game table coordinate
		pTet->y = FRAME_Y - 1;
	
		while (1) {                       // operation on the generated piece
			printTetris(pTet);
			Sleep(pTet->speed);           // delay between moving steps
			cleanTetris(pTet);            // clean current piece
			
			tmpx = pTet->x;
			tmpf = pTet->flag;

			state = NORMAL_GAME;

			if (_kbhit()) {                // detect keyboard hit
				ch = _getch();             // should confirm the validation of input

				switch (ch)
				{
				case KES:                                // exit game
				{
					system("cls");
					memset(tTable, 0, 6400 * sizeof(int));
					state = EXIT_GAME;
					break;
				}
				case KBS:                               // pause
				{
					printTetris(pTet);
					pauseTime = 0x0FFFFFFF;
					while (pauseTime--) {
						if (_kbhit()) {
							ch = _getch();
							if (KBS == ch) {
								state = RESUME_GAME;
								break;
							}
							else if (KES == ch) {
								state = EXIT_GAME;      // exit game during pause
								break;
							}
						}
					}
					break;
				}
				case KLT:                              // move and rotate
				{
					pTet->x -= 2;
					break;
				}
				case KRT:
				{
					pTet->x += 2;
					break;
				}
				case KDW:
				{
					if (TRUE == ifMovable(pTet)) {
						pTet->y += 2;
					}
					break;
				}
				case KUP:
				{
					if ((T_LINE_HORIZ <= pTet->flag) && (T_LINE_VERT >= pTet->flag)) {
						pTet->flag++;
						if (T_LINE_VERT < pTet->flag)
							pTet->flag = T_LINE_HORIZ;
					}
					else if ((T_TSHAPE_DOWN <= pTet->flag) && (T_TSHAPE_RIGHT >= pTet->flag)) {
						pTet->flag++;
						if (T_TSHAPE_RIGHT < pTet->flag)
							pTet->flag = T_TSHAPE_DOWN;
					}
					else if ((T_ZSHAPE_LEFT <= pTet->flag) && (T_ZSHAPE_UP >= pTet->flag)) {
						pTet->flag++;
						if (T_ZSHAPE_UP < pTet->flag)
							pTet->flag = T_ZSHAPE_LEFT;
					}
					else if ((T_ZINV_RIGHT <= pTet->flag) && (T_ZINV_UP >= pTet->flag)) {
						pTet->flag++;
						if (T_ZINV_UP < pTet->flag)
							pTet->flag = T_ZINV_RIGHT;
					}
					else if ((T_SEVEN_DOWN <= pTet->flag) && (T_SEVEN_RIGHT >= pTet->flag)) {
						pTet->flag++;
						if (T_SEVEN_RIGHT < pTet->flag)
							pTet->flag = T_SEVEN_DOWN;
					}
					else{
						pTet->flag++;
						if (T_SEVINV_RIGHT < pTet->flag)
							pTet->flag = T_SEVINV_DOWN;
					}
					break;
				}
				default:
					break;
				}

				if (RESUME_GAME == state) {
					continue;
				}
				else if (EXIT_GAME == state) {
					return;                          // return main loop must enter welcome window
				}

				if (FALSE == ifMovable(pTet)) {      // if cannot move to new position, reset the piece
					pTet->x = tmpx;
					pTet->flag = tmpf;
				}
			}
			pTet->y++;
			if (FALSE == ifMovable(pTet)) {
				pTet->y--;
				printTetris(pTet);
				delFullLine(pTet);
				break;
			}
		}
	
	}
}