#include "display.h"

extern int tTable[AREA_HEIGHT][AREA_WIDTH];
extern int tPiece[BLOCK_COUNT];

// selection handle
// jump to corresponding game module
int selection(char ch) {
	int ret = NORMAL_GAME;
	switch (ch) {
	case 1:
		system("cls");
		drawGameFrame();     //show the game window
		ret = playGame();
		break;
	case 2:
		instruction();
		break;
	case 3:
		gameRule();
		break;
	case 4:
	default:
		break;
	}

	return ret;
}

// set the welcome title 
void title(int mode) {
	if (REPLAY_GAME == mode)
		return;

	color(15);
	gotoxy(29, 3);
	printf(" My Tetris Game\n");

	color(11);
	gotoxy(18, 5);
	printf("■");
	gotoxy(18, 6);
	printf("■■");
	gotoxy(18, 7);
	printf("■");

	color(14);
	gotoxy(26, 6);
	printf("■■");
	gotoxy(28, 7);
	printf("■■");

	color(10);
	gotoxy(36, 6);
	printf("■■");
	gotoxy(36, 7);
	printf("■■");

	color(13);
	gotoxy(45, 5);
	printf("■");
	gotoxy(45, 6);
	printf("■");
	gotoxy(45, 7);
	printf("■");
	gotoxy(45, 8);
	printf("■");

	color(12);
	gotoxy(52, 6);
	printf("■");
	gotoxy(52, 7);
	printf("■■■■");
}

// menue frame
int welcome(int mode) {
	int chs, ret;
	int k, l;

	ret = NORMAL_GAME;

	if (REPLAY_GAME != mode) {
		// the menu frame
		color(14);

		for (k = 9; k <= 20; k++) {
			for (l = 15; l <= 60; l++) {
				gotoxy(l, k);
				if ((k == 9) || (k == 20))
					printf("=");
				else if ((l == 15) || (l == 59))
					printf("||");
			}
		}

		// menu context
		color(12);
		gotoxy(25, 12);
		printf("1. Begin");
		gotoxy(40, 12);
		printf("2. Keyboard");
		gotoxy(25, 17);
		printf("3. Game Rule");
		gotoxy(40, 17);
		printf("4. Exit");

		color(3);
		gotoxy(21, 22);
		printf("Choose[1 2 3 4]:[ ]\b\b");

		color(14);
		scanf_s("%d", &chs);
	}
	else {
		chs = 1;
	}
	
	ret = selection(chs);

	return ret;
}

void drawGameFrame(void) {
	int i;

	gotoxy(FRAME_X + FRAME_WIDTH - 7, FRAME_Y - 2);
	color(11);
	printf("TTTTTTetris!");   // game window title

	gotoxy(FRAME_X + 2*FRAME_WIDTH + 3, FRAME_Y +7);
	color(2);
	printf("**********");     // top line for next piece area

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 13, FRAME_Y + 7);
	color(3);
	printf("NEXT PIECE");     // show text

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 13);
	color(2);
	printf("**********");     // bottom line for next piece area

	printf("NEXT PIECE");     // show text

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 15);
	color(14);
	printf("  ↑ : rotate");     // explaination

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 19);
	color(14);
	printf("SPACE: pause");      // explaination

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 17);
	color(14);
	printf(" ESC : exit");       // explaination

	tTable[FRAME_X][FRAME_Y + FRAME_HEIGHT] = 2;
	tTable[FRAME_X + 2*FRAME_WIDTH - 2][FRAME_Y + FRAME_HEIGHT] = 2;

	for (i = 1; i < 2 * FRAME_WIDTH -1; i++) {                  // print the top line of game area
		gotoxy(FRAME_X + i, FRAME_Y);
		printf("=");
	}

	for (i = 1; i < 2 * FRAME_WIDTH - 1; i++) {                                  // print the bottome line of game area
		gotoxy(FRAME_X + i, FRAME_Y + FRAME_HEIGHT);
		printf("=");
		tTable[FRAME_X + i][FRAME_Y + FRAME_HEIGHT] = FLAG_BOUNDRY;        // mark the bottom of game area, to keep pieces inside the boundry
	}

	for (i = 1; i < FRAME_HEIGHT; i++) {                                     // print the bottome line of game area
		gotoxy(FRAME_X, FRAME_Y + i);
		printf("‖");
		tTable[FRAME_X][FRAME_Y + i] = FLAG_BOUNDRY;                       // mark the left boundry of game area
	}

	for (i = 1; i < FRAME_HEIGHT; i++) {                                     // print the left line of game area
		gotoxy(FRAME_X + 2*FRAME_WIDTH - 2, FRAME_Y + i);
		printf("‖");
		tTable[FRAME_X + 2 * FRAME_WIDTH - 2][FRAME_Y + i] = FLAG_BOUNDRY; // mark the right boundry of game area
	}
}

// make the Tetris pieces
// 7 basic pieces
// 19 placing pieces 
// gamePiece[0] is central block of one game piece
void makeTetris(struct Tetris* tet) {
	tTable[tet->x][tet->y] = tPiece[0];       // set current piece central block coordinate to Tetris structure

	switch (tet->flag) {
	case T_SQUARE:
	{
		color(10);
		tTable[tet->x][tet->y - 1] = tPiece[1];   //set the other 3 blocks to game area
		tTable[tet->x + 2][tet->y - 1] = tPiece[2];
		tTable[tet->x + 2][tet->y] = tPiece[3];
		break;
	}
	case T_LINE_HORIZ:
	{
		color(13);
		tTable[tet->x - 2][tet->y] = tPiece[1];
		tTable[tet->x + 2][tet->y] = tPiece[2];
		tTable[tet->x + 4][tet->y] = tPiece[3];
		break;
	}
	case T_LINE_VERT:
	{
		color(13);
		tTable[tet->x][tet->y - 1] = tPiece[1];
		tTable[tet->x][tet->y + 1] = tPiece[2];
		tTable[tet->x][tet->y + 2] = tPiece[3];
		break;
	}
	case T_TSHAPE_DOWN:
	{
		color(11);
		tTable[tet->x - 2][tet->y] = tPiece[1];
		tTable[tet->x + 2][tet->y] = tPiece[2];
		tTable[tet->x][tet->y + 1] = tPiece[3];
		break;
	}
	case T_TSHAPE_LEFT:
	{
		color(11);
		tTable[tet->x - 2][tet->y] = tPiece[1];
		tTable[tet->x][tet->y - 1] = tPiece[2];
		tTable[tet->x][tet->y + 1] = tPiece[3];
		break;
	}
	case T_TSHAPE_UP:
	{
		color(11);
		tTable[tet->x - 2][tet->y] = tPiece[1];
		tTable[tet->x][tet->y - 1] = tPiece[2];
		tTable[tet->x + 2][tet->y] = tPiece[3];
		break;
	}
	case T_TSHAPE_RIGHT:
	{
		color(11);
		tTable[tet->x + 2][tet->y] = tPiece[1];
		tTable[tet->x][tet->y - 1] = tPiece[2];
		tTable[tet->x][tet->y + 1] = tPiece[3];
		break;
	}
	case T_ZSHAPE_LEFT:
	{
		color(14);
		tTable[tet->x - 2][tet->y] = tPiece[1];
		tTable[tet->x][tet->y + 1] = tPiece[2];
		tTable[tet->x + 2][tet->y + 1] = tPiece[3];
		break;
	}
	case T_ZSHAPE_UP:
	{
		color(14);
		tTable[tet->x][tet->y + 1] = tPiece[1];
		tTable[tet->x + 2][tet->y] = tPiece[2];
		tTable[tet->x + 2][tet->y - 1] = tPiece[3];
		break;
	}
	case T_ZINV_RIGHT:
	{
		color(15);
		tTable[tet->x + 2][tet->y] = tPiece[1];
		tTable[tet->x][tet->y + 1] = tPiece[2];
		tTable[tet->x - 2][tet->y + 1] = tPiece[3];
		break;
	}
	case T_ZINV_UP:
	{
		color(15);
		tTable[tet->x][tet->y - 1] = tPiece[1];
		tTable[tet->x + 2][tet->y] = tPiece[2];
		tTable[tet->x + 2][tet->y + 1] = tPiece[3];
		break;
	}
	case T_SEVEN_DOWN:
	{
		color(12);
		tTable[tet->x - 2][tet->y] = tPiece[1];
		tTable[tet->x][tet->y + 1] = tPiece[2];
		tTable[tet->x][tet->y + 2] = tPiece[3];
		break;
	}
	case T_SEVEN_LEFT:
	{
		color(12);
		tTable[tet->x][tet->y - 1] = tPiece[1];
		tTable[tet->x - 2][tet->y] = tPiece[2];
		tTable[tet->x - 4][tet->y] = tPiece[3];
		break;
	}
	case T_SEVEN_UP:
	{
		color(12);
		tTable[tet->x + 2][tet->y] = tPiece[1];
		tTable[tet->x][tet->y - 1] = tPiece[2];
		tTable[tet->x][tet->y - 2] = tPiece[3];
		break;
	}
	case T_SEVEN_RIGHT:
	{
		color(12);
		tTable[tet->x][tet->y + 1] = tPiece[1];
		tTable[tet->x + 2][tet->y] = tPiece[2];
		tTable[tet->x + 4][tet->y] = tPiece[3];
		break;
	}
	case T_SEVINV_DOWN:
	{
		color(13);
		tTable[tet->x + 2][tet->y] = tPiece[1];
		tTable[tet->x][tet->y + 1] = tPiece[2];
		tTable[tet->x][tet->y + 2] = tPiece[3];
		break;
	}
	case T_SEVINV_LEFT:
	{
		color(13);
		tTable[tet->x][tet->y + 1] = tPiece[1];
		tTable[tet->x - 2][tet->y] = tPiece[2];
		tTable[tet->x - 4][tet->y] = tPiece[3];
		break;
	}
	case T_SEVINV_UP:
	{
		color(13);
		tTable[tet->x - 2][tet->y] = tPiece[1];
		tTable[tet->x][tet->y - 1] = tPiece[2];
		tTable[tet->x][tet->y - 2] = tPiece[3];
		break;
	}
	case T_SEVINV_RIGHT:
	{
		color(13);
		tTable[tet->x][tet->y - 1] = tPiece[1];
		tTable[tet->x + 2][tet->y] = tPiece[2];
		tTable[tet->x + 4][tet->y] = tPiece[3];
		break;
	}
	default:
		break;
	}
}

void printTetris(struct Tetris* tet) {
	int i, j;
	for (i = 0; i < 4; i++) {
		tPiece[i] = 1;                 // four blocks in one piece are all valid
	}
	makeTetris(tet);

	for (i = tet->x - 2; i <= tet->x + 4; i += 2) {                    // scan all pixels the blocks can appear
		for (j = tet->y - 2; j <= tet->y + 1; j++) {
			if ((tTable[i][j] == FLAG_BLOCK) && (j > FRAME_Y)) {        // if a block exist in the pixel
				gotoxy(i, j);
				printf("■");
			}
		}
	}

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 1);          // print the game level
	color(4);
	printf("level : ");
	color(12);
	printf("%d", tet->level);

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 3);          // print the game score
	color(4);
	printf("score : ");
	color(12);
	printf("%d", tet->score);

	gotoxy(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 5);          // print the game speed
	color(4);
	printf("speed : ");
	color(12);
	printf("%d", tet->speed);
}

// keyboard instruction
void instruction(void) {
	int i, j;
	
	system("cls");

	color(13);
	gotoxy(32, 3);
	printf("keyboard instruction");

	color(2);
	for (i = 6; i <= 16; i++) {
		for (j = 15; j <= 60; j++) {
			gotoxy(j, i);
			if (i == 6 || i == 16)
				printf("=");
			else if (j == 16 || j == 59)
				printf("||");
		}
	}

	color(3);
	gotoxy(18, 7);
	printf("**** press  ← →  to move");
	color(10);
	gotoxy(18, 9);
	printf("**** press ↑ to rotate");
	color(14);
	gotoxy(18, 11);
	printf("**** press ↓ to move faster");
	color(11);
	gotoxy(18, 13);
	printf("**** press SPACE to pause");
	color(4);
	gotoxy(18, 15);
	printf("**** press ESC to exit");
	color(8);
	gotoxy(18, 19);
	printf("press anykey to continue...");
	_getch();
	system("cls");
	return;
}

// game rule
void gameRule(void) {
	int i, j;

	system("cls");

	color(13);
	gotoxy(34, 3);
	printf("Game Rule");

	color(2);
	for (i = 6; i <= 16; i++) {
		for (j = 12; j <= 70; j++) {
			gotoxy(j, i);
			if (i == 6 || i == 16)
				printf("=");
			else if (j == 12 || j == 69)
				printf("||");
		}
	}

	color(12);
	gotoxy(18, 9);
	printf("####   Clear one line get 100 pts");
	color(14);
	gotoxy(18, 11);
	printf("####   Get 1000 pts will level up");
	color(11);
	gotoxy(18, 13);
	printf("####   Level up will speed up");
	color(8);
	gotoxy(18, 17);
	printf("press anykey to continue...");
	_getch();
	system("cls");
	return;
}