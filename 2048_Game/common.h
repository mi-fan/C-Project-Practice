#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include "game_handle.h"
#include "screen_Handle.h"

enum gameChoice
{
	GAME_BEGIN = 1,
	GAME_RULE,
	GAME_INSTRUCT,
	GAME_EXIT,
	GAME_INVALID
};