#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "data_handle.h"
#include "display_handle.h"
#include "game_handle_basic.h"
#include "game_handle_process.h"
#include "screen_handle.h"

/***********************
* Macro define
***********************/
#define SCORE_STEP     (10)

/***********************
* Enum
***********************/
typedef enum __direction_t
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT,
}direction_t;

typedef enum __selection_t
{
	S_START = 1,
	S_INSTRUCT,
	S_QUIT,
	S_INVALID,
}selection_t;

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

/***********************
* Structure
***********************/
// Defines one node of the whole snake
typedef struct __snake_t
{
	int x;                            // x coordinate
	int y;                            // y coordinate
	struct __snake_t* next;           // next node
}snake_t;

/***********************
* Global variables
***********************/
snake_t* head;                // snake head
snake_t* food;                // food position
snake_t* seek;                // seek the body

int score;
int highScore;
int status;
int sleepTime;
int gameResult;

HANDLE hOut;
