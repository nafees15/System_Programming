/******************************************
Author -- Nafees Noor
Net ID -- nn319918
This file implements the nattr function
*******************************************/

#include <stdio.h>
#include "macros.h"
#include "struct_def.h"

/******* Funtion Prototype *****************************/
FILE *open_schema_file(char *);
void select_Query(struct node *, char *);
/*******************************************************/

/********************************************************
   This function takes two parameters Table as database
   parameter_array as the parameter command from the
   query file then it goes through the database and
   look for the name, if it finds then printing out
   the size otherwise printing error and finishes
*********************************************************/
void select_Query(struct node *Table, char *parameter_array)
{
  
  int i = 0;
  //  int j = 0;             // Loop variable
  //int found = 0;         // variable to keep track if the name is found in the database or not
  FILE *temp1;           // File pointer to open the schema file
  int attribute = 0;     // variable to get the attribute from the schema file
  //  int number  = 0;
  //int num_Size = 0;
  // char string[ARRAY_SIZE];
  // char temp;
  //  int total = 0;         // Variable to count the total size for each tuple from the database



  for(i = 0; i < COMMAND_ARRAY_SIZE; i++)
    {
      if((strcmp(Table[i].relation, parameter_array))== 0)
        {
          temp1 = open_schema_file(parameter_array);

          fscanf(temp1, "%d", &attribute);

	  printf("Error: No attribute found\n");
	  return;

	}}
}
