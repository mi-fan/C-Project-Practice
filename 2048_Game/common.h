#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include "game_handle.h"
#include "screen_Handle.h"

typedef enum __gameChoice_t
{
	CHC_BEGIN = 1,
	CHC_RULE,
	CHC_INSTRUCT,
	CHC_EXIT,
	CHC_INVALID,
}gameChoice_t;

typedef enum __gameStatus_t
{
	GS_NORM,
	GS_INVALID,
}gameStatus_t;

typedef struct __gameInfo_t
{
	int score;
	int step;
	int time;
}gameInfo_t;