#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include "game_handle.h"
#include "screen_Handle.h"

#define ST_FAIL      (0)
#define ST_RUN       (1 << 0)
#define ST_WIN       (1 << 1)
#define ST_ILLEGAL   (1 << 2)
#define ST_RESUME    (1 << 3)
#define ST_QUIT      (1 << 4)

#define NUM_COUNT (11)    // total 11 valid game number
#define LEN       (4)     // game table width and height
#define D_UP      (72)    // keyboard up
#define D_LEFT    (75)    // keyboard left
#define D_RIGHT   (77)    // keyboard right
#define D_DOWN    (80)    // keyboard down
#define ESC       (27)    // keyboard ESC

typedef enum __gameChoice_t
{
	CHC_BEGIN = 1,
	CHC_RULE,
	CHC_INSTRUCT,
	CHC_EXIT,
	CHC_INVALID,
}gameChoice_t;

typedef enum __color_t
{
	BLACK,
	BLUE_DEEP,
	GREEN_DEEP,
	BL_GR_DEEP,
	RED_DEEP,
	PURPLE,
	YELLOW_DARK,
	WHITE,
	GRAY,
	BLUE_LIGHT,
	GREEN_LIGTH,
	BL_GR_LIGHT,
	RED,
	PINK,
	YELLOW,
	WHITE_LIGHT
}color_t;

typedef struct __gameInfo_t
{
	int score;
	int step;
	int time;
}gameInfo_t;