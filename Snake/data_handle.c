#include "data_handle.h"

//*********************************************//
//                                             //
// Define functions on file data write/read    //
//                                             //
//*********************************************//

/*******************************
* Read data from local file
*******************************/
void File_Out(void) {
	FILE* fp = NULL;
	errno_t err;

	err = fopen_s(&fp, "snake_data.txt", "a+");
	fscanf_s(fp, "%d", &highScore);
	fclose(fp);
}

/*******************************
* Save data to local file
*******************************/
void File_In(void) {
	FILE* fp = NULL;
	errno_t err;

	err = fopen_s(&fp, "snake_data.txt", "w+");
	fprintf_s(fp, "%d", score);
	fclose(fp);
}