#include "common.h"

gameInfo_t g_GameInfo;
int g_GameTable[LEN][LEN];

int main(void) {
	draw_Title();
	menu();
	return 0;
}