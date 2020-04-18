#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "screen_handle.h"

// macro define
// display
#define FRAME_X        (13)
#define FRAME_Y        (3)
#define FRAME_HEIGHT   (20)
#define FRAME_WIDTH    (18)
// game area flag
#define FLAG_BOUNDRY   (2)
#define FLAG_BLOCK     (1)
#define FLAG_EMPTY     (0)

// structure define
struct Tetris
{
	int x;
	int y;
	int flag;
	int next;
	int speed;
	int number;
	int score;
	int level;
};

// console handle
HANDLE hOut;
