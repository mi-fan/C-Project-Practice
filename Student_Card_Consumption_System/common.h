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
struct scoreNode
{
	int  id;                         // student ID
	int  cost;                       // cost in consumption
	char name[NAME_LEN];             // student name
	struct scoreNode *next;          // next node in link
};

typedef struct scoreNode *Score;

typedef enum _Choice_t
{
	CREATE = 0,
	LOAD,
	QUERY,
	DEL,
	ADD,
	PRINT,
	SAVE,
	EXIT,
	CHOICE_MAX
}Choice_t;

/***********************************************************
 * FUNCTION DECLARATION
 ***********************************************************/
// Create student consumption record
Score create(void);

// Load student consumption record
Score load(Score head);

// Query student consumption record
Score query(Score head);

// Delete student consumption record
Score del(Score head);

// Add student consumption record
Score add(Score head);

// Show all records
void printAll(Score head);

// Save the records to local file
void saveToFile(Score node);

/***********************************************************
 * GLOBAL VARIABLES
 ***********************************************************/
// Link head and current node
Score headStudent;
Score currStudent;