#pragma once
/***********************************************************
 *
 *         Common declaration and definitions
 *
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "data_management.h"
#include "display_handle.h"
#include "file_handle.h"
#include "link_handle.h"

/***********************************************************
 * MACRO DEFINITION
 ***********************************************************/
#define NAME_LEN     (20)
#define LEN          sizeof(struct scoreNode)
#define DEBUG

#ifndef TRUE
#define TRUE         (1)
#define FALSE        (0)
#endif // !TRUE

/***********************************************************
 * TYPE DEFINITION
 ***********************************************************/
struct recordNode
{
	int  id;                         // student ID
	int  money;                       // cost in consumption
	char name[NAME_LEN];             // student name
	struct recordNode* next;          // next node in link
};

typedef struct recordNode* Record;

typedef enum _Choice_t
{
	EXIT = 0,
	CREATE,
	LOAD,
	QUERY,
	DEL,
	ADD,
	PRINT,
	SAVE,
	CHOICE_MAX
}Choice_t;

/***********************************************************
 * FUNCTION DECLARATION
 ***********************************************************/
// Query student consumption record
Record query(Record head);

// Delete student consumption record
Record del(Record head);

// Show all records
void printAll(Record head);

// Save the records to local file
void saveToFile(Record node);

/***********************************************************
 * GLOBAL VARIABLES
 ***********************************************************/
// Output handler
HANDLE g_output_handle;

// Link head and current node
Record headStudent;
Record currStudent;
int g_record_len;