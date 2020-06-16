#pragma once
#include <stdio.h>
#include <windows.h>

/****************************************************************
* Macro definition
*****************************************************************/
#define YEAR_START    (1840)           // available year start from 1840
#define YEAR_END      (2100)           // available year ends to 2100

/****************************************************************
* Structure definition
*****************************************************************/
typedef struct _LONGTIME {             // descriptor for time
	int year;
	int month;
	int dayOfWeek;
	int day;
	int hour;
	int minute;
	int second;
	int msecond;
}_LONGTIME_T;

typedef struct _TRADDATE{              // descriptor for traditional calendar
	long int year;
	int month;
	int day;
	bool isLeap;                       // flag for leap month                   
}_TRADDATE_T;

/****************************************************************
* Global variables
*****************************************************************/