#include "common.h"

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