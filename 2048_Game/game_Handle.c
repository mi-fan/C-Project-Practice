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
// Add the numbers in one row or column
// Align the non-zero number to high grid
//****************************************
int* nums_AddandAlign(int* line) {
	extern gameInfo_t g_gameInfo;

	int i, j;

	// add the adjacent and equal numbers
	// the sum shows in higher grid
	for (i = LEN - 1; i > 0 ; i--) {
		if (line[i - 1] == line[i]) {
			line[i] = (line[i] << 1);
			line[i - 1] = 0;
			g_gameInfo.score += line[i];
		}
	}

	// the valid number should move to end of the line
	for (i = LEN - 1; i > 0; i--) {
		// exchange higher hole with lower valid number
		if (line[i] == 0) {
			j = i - 1;
			// find valid number
			while ((line[j] == 0)&&(j >= 0)) {
				j--;
			}

			if (j < 0) {
				break;
			}
			line[i] = line[j];
			line[j] = 0;
		}
	}

	return line;
}


