/******************************************
Author -- Nafees Noor
Net ID -- nn319918
This file implements the count function
*******************************************/

#include <stdio.h>
#include "macros.h"
#include "struct_def.h"

/******* Funtion Prototype *****************************/
FILE *open_data_file(char *);
FILE *open_schema_file(char *);
int tuplen_Query(struct node *, char *);
int count_Query(struct node *, char *);
/*******************************************************/

/********************************************************
   This function takes two parameters Table as database
   parameter_array as the parameter command from the
   query file then it goes through the database and
   look for the name, if it finds then printing out
   the size otherwise printing error and finishes
*********************************************************/

int count_Query(struct node *Table, char *parameter_array)
{
  int i = 0;
  int j = 0;
  int found = 0;
  long offset  = 0;
  FILE *fp;
  FILE *temp;
  int number = 0;
  char string[ARRAY_SIZE];
  char character_temp;
  int total = 0;
  long sum = 0;
  int num_Size = 0;
  int attribute = 0;


  for(i = 0; i < TABLE_SIZE; i++)
    {
      if((strcmp(Table[i].relation, parameter_array)) == RESULT_ZERO)      // checking if the relation name provided by parameter exist in the database or not
        {
	  temp = open_schema_file(parameter_array);
          fp  = open_data_file(parameter_array);                          // Openning the both data and schma file
	  
	  fscanf(temp, "%d", &attribute);                         
	  for(j = 0; j < attribute; j++)                                  // Looping until the attribute number of schmea
	    {
	      fscanf(temp, "%s %c %d", string, &character_temp, &num_Size);
	      number = num_Size;                                          // Adding up the size for each case
	      total += number;
	    }    
	  fseek(fp, RESULT_ZERO, SEEK_END);                           //Doing fseek to go all the at the end 
	  offset = ftell(fp);                                         //ftell to get the offset
	      
	  sum = offset / total;                                  // dividing the offset with the total
	      
	  printf("Number of tuples %ld\n", sum);                 // printing out the number of tuples
	  found = RESULT_ONE;
	  return found;
	  
	}     
    }  
  return found;                                                   // returning found which is a boolean to show if result is found or not
}
