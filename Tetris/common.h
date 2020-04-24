#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "screen_handle.h"
#include "display.h"

// macro define
#define FALSE (0)
#define TRUE  (1)
// display
#define FRAME_X        (13)
#define FRAME_Y        (3)
#define FRAME_HEIGHT   (20)
#define FRAME_WIDTH    (18)
// game area flag
#define FLAG_BOUNDRY   (2)
#define FLAG_BLOCK     (1)
#define FLAG_EMPTY     (0)
// game area pixel
#define AREA_HEIGHT    (80)
#define AREA_WIDTH     (80)
// block counts in one Tetris piece
#define BLOCK_COUNT    (4)
// ASCII of input char
#define KBS            (32)
#define KES            (27)
#define KUP            (72)
#define KLT            (75)
#define KRT            (77)
#define KDW            (80)
// game status
#define NORMAL_GAME      (0)
#define RESUME_GAME      (1)
#define EXIT_GAME        (2)
#define REPLAY_GAME      (3)

enum tetrisType {
	T_SQUARE = 0,
	T_LINE_HORIZ,
	T_LINE_VERT,
	T_TSHAPE_DOWN,
	T_TSHAPE_LEFT,
	T_TSHAPE_UP,
	T_TSHAPE_RIGHT,
	T_ZSHAPE_LEFT,
	T_ZSHAPE_UP,
	T_ZINV_RIGHT,
	T_ZINV_UP,
	T_SEVEN_DOWN,
	T_SEVEN_UP,
	T_SEVEN_LEFT,
	T_SEVEN_RIGHT,
	T_SEVINV_DOWN,
	T_SEVINV_LEFT,
	T_SEVINV_UP,
	T_SEVINV_RIGHT,
	T_TOTAL
};

// structure define
// game handler structure
struct Tetris
{
	int x;
	int y;
	enum tetrisType flag;
	int next;
	int speed;
	int number;
	int score;
	int level;
};

// console handle
HANDLE hOut;
