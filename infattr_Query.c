/******************************************
Author -- Nafees Noor
Net ID -- nn319918
This file implements the infattr function
*******************************************/

#include <stdio.h>
#include "macros.h"
#include "struct_def.h"

/******* Funtion Prototype *****************************/
FILE *open_schema_file(char *);
int infattr_Query(struct node *, char *);
/*******************************************************/


/********************************************************
   This function takes two parameters Table as database
   parameter_array as the parameter command from the
   query file then it goes through the database and
   look for the name, if it finds then printing out
   the size otherwise printing error and finishes
*********************************************************/
int tuplen_Query(struct node *Table, char *parameter_array)
{
  
 
}
