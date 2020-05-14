#include "common.h"

//**************************************
// Run game option according to choice
//**************************************
int game_main(int choice) {
	gameStatus_t status = GS_NORM;

	switch (choice)
	{
	case CHC_BEGIN:
		draw_GameTable();
		break;
	case CHC_RULE:
		break;
	case CHC_INSTRUCT:
		break;
	case CHC_EXIT:
		exit(0);
		break;
	default:
		status = GS_INVALID;
		break;
	}

	if (GS_INVALID == status) {
		return status;
	}

}

//****************************************
// Align the non-zero number to high grid
// e.g. 2 0 2 4 ----> 0 2 2 4
//****************************************
int nums_Align(int* line) {
	int i, j;
	int ret = FALSE;
	
	j = LEN - 1;
	// the valid number should move to end of the line
	for (i = LEN - 1; i > 0; i--) {
		// exchange higher hole with lower valid number
		if (line[i] == 0) {
			j = (j - 1 < i - 1)? (j - 1):(i -1);
			// find valid number
			while ((line[j] == 0) && (j >= 0)) {
				j--;
			}

			if (j < 0) {
				break;
			}
			line[i] = line[j];
			line[j] = 0;
			ret = TRUE;   // effective movement is possible
		}
	}

	return ret;
}

//********************************************
// Add the numbers in one row or column
// Return value indicates the move capability
//********************************************
int nums_Add(int* line) {
	extern gameInfo_t g_GameInfo;
	int i, j;
	int ret = FALSE;

	// e.g. 2 0 4 4 --->  0 2 4 4
	ret |= nums_Align(line);

	// add the adjacent and equal numbers
	// the sum shows in higher grid
	// e.g. 0 2 4 4 ----> 0 2 0 8
	for (i = LEN - 1; i > 0 ; i--) {
		if (line[i - 1] == line[i]) {
			line[i] = (line[i] << 1);
			line[i - 1] = 0;
			g_GameInfo.score += line[i];
			ret = TRUE;
		}
	}

	// e.g. 0 2 0 8 ----> 0 0 2 8
	ret |= nums_Align(line);

	return ret;
}
//********************************************
// Divide the game table into 4 lines
//********************************************
inline void divide_RowColumn(int dir, int fix, int arg, int* line, int* table[]) {
	switch (dir)
	{
	case D_UP:
		line[arg] = table[LEN - 1 - arg][fix];
		break;
	case D_LEFT:
		line[arg] = table[fix][LEN - 1 - arg];
		break;
	case D_RIGHT:
		line[arg] = table[fix][arg];
		break;
	case D_DOWN:
		line[arg] = table[arg][fix];
		break;
	default:
		break;
	}
}

//********************************************
// Combine the 4 lines to game table
//********************************************
inline void combine_RowColumn(int dir, int fix, int arg, int* line, int* table[]) {
	switch (dir)
	{
	case D_UP:
		table[LEN - 1 - arg][fix] = line[arg];
		break;
	case D_LEFT:
		table[fix][LEN - 1 - arg] = line[arg];
		break;
	case D_RIGHT:
		table[fix][arg] = line[arg];
		break;
	case D_DOWN:
		table[arg][fix] = line[arg];
		break;
	default:
		break;
	}
}

//********************************************
// Try to move in specific direction
//********************************************
int move_Try(int dir) {
	extern int g_GameTable[LEN][LEN];
	int line[LEN] = { 0, 0, 0, 0 };
	int i, j;
	int ret = FALSE;


	for (i = 0; i < LEN; i++) {
		for (j = 0; j < LEN; j++) {
			divide_RowColumn(dir, i, j, line, g_GameTable);   	
		}

		ret |= nums_Add(line);        // try to add and align numbers

		for (j = 0; j < LEN; j++) {
			combine_RowColumn(dir, i, j, line, g_GameTable);    
		}
	}

	return ret;
}


