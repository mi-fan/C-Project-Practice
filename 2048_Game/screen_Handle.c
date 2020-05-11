#include "screen_Handle.h"

//**************************************
// Print the game logo "2048"
//**************************************
void title(void) {
	color(11);
	gotoxy(19, 2);
	printf("¡ö¡ö¡ö     ¡ö¡ö¡ö¡ö     ¡ö  ¡ö     ¡ö¡ö¡ö¡ö");
	gotoxy(19, 3);
	printf("    ¡ö     ¡ö    ¡ö     ¡ö  ¡ö     ¡ö    ¡ö");
	gotoxy(19, 4);
	printf("¡ö¡ö¡ö     ¡ö    ¡ö     ¡ö  ¡ö     ¡ö¡ö¡ö¡ö");
	gotoxy(19, 5);
	printf("¡ö         ¡ö    ¡ö     ¡ö¡ö¡ö     ¡ö    ¡ö");
	gotoxy(19, 6);
	printf("¡ö¡ö¡ö     ¡ö¡ö¡ö¡ö         ¡ö     ¡ö¡ö¡ö¡ö");
}