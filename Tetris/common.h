#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "screen_handle.h"

// macro define
#define FRAME_X        (13)
#define FRAME_Y        (3)
#define FRAME_HEIGHT   (20)
#define FRAME_WIDTH    (18)

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
