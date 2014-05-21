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
int tuplen_Query(struct node *, char *);
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

  int i = 0; 
  int j = 0;             // Loop variable
  int found = 0;         // variable to keep track if the name is found in the database or not
  FILE *temp1;           // File pointer to open the schema file
  int attribute = 0;     // variable to get the attribute from the schema file
  int number  = 0;      
  int num_Size = 0;
  char string[ARRAY_SIZE];
  char temp;
  int total = 0;         // Variable to count the total size for each tuple from the database
  
  /*********************************************************************************************
    Looping through the whole database and checking if the relation exist in the database or not
    If it does then printing out the length of each tuple from the database 
  ***********************************************************************************************/
  for(i = 0; i < COMMAND_ARRAY_SIZE; i++)
    {
      if((strcmp(Table[i].relation, parameter_array))== 0)
        {
	  temp1 = open_schema_file(parameter_array);

	  fscanf(temp1, "%d", &attribute);
	  
	  for(j = 0; j < attribute; j++)
	    {
	      fscanf(temp1, "%s %c %d", string, &temp, &num_Size);   // getting the information from the schema file

	      number = num_Size;
	      total += number;
	    }
	      printf("Length of the tuple : %d\n", total);
	      found = RESULT_ONE;                          //Making the found to be 1 so it would say it was found in the database
	      fclose(temp1);
	      return total;
	}

    }                                                     // End of for loop
  if(found != RESULT_ONE)
    {
      printf("Error: Invalid relation -- Badrelation\n");
      fflush(stdout);
    }


  return total;
} // End of the function
