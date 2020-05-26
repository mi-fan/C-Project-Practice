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
	FILE* fp;

	fp = fopen("data.txt", "a+");
	fscanf_s(fp, "%d", &highScore);
	fclose(fp);
}