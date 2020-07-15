#pragma once
/***********************************************************
 *
 * Common declaration and definitions
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

/***********************************************************
 * FUNCTION DECLARATION
 ***********************************************************/

// Show the top menu for selection
void menu(void);

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
