
/******************************************
Author -- Nafees Noor
Net ID -- nn319918
This file implements the infattr function
*******************************************/

#include <stdio.h>
#include "macros.h"
#include "struct_def.h"
#include "stdlib.h"
#include <string.h>
#include <ctype.h>

/******* Funtion Prototype *****************************/
FILE *open_data_file(char *);
void project_Query(struct node *, char *, char *);
FILE *open_schema_file(char *);
/*******************************************************/

/********************************************************
   This function takes two parameters Table as database
   parameter_array as the parameter command from the
   query file then it goes through the database and
   look for the name and print out information about
   schema size and what type it is
*********************************************************/

void project_Query(struct node *Table, char *parameter_array, char *parameter_array_two)
{
  int i = 0;
  FILE *temp1;           // File pointer to open the schema file
  FILE *temp2;           // File pointer to open the binary file
  int attribute = 0;     // variable to get the attribute from the schema file
  //  int found = 0;         // Boolean value to check if it found the solution
  int j = 0;             // Loop variable
  char buffer[ARRAY_SIZE];
  int buffer2[ARRAY_SIZE];
  int num_Size = 0;
  char string[ARRAY_SIZE];
  char temp;
  int number = 0;
  int total = 0;


  for(i = 0; i < TABLE_SIZE; i++)
    {
      if((strcmp(Table[i].relation, parameter_array)) == 0)      // checking if the relation name provided by parameter exist in the database or not
        {
          temp1 = open_schema_file(parameter_array);             // Opening the schema file 
	  temp2 = open_data_file(parameter_array);               // Opening the data file to read through the information

          fscanf(temp1, "%d", &attribute);
	  
	  //	  printf("Error no attribute found\n");
	  // return ;

	  number = num_Size;
	  total += number;

          for(j = 0; j < attribute; j++)
            {
              fscanf(temp1, "%s %c %d", string, &temp, &num_Size);
	            
              if((strcmp(string, parameter_array_two)) == 0)
                {
		  if((isdigit(temp)) == 0)
		    {
		      fread(&buffer2, sizeof(buffer), RESULT_ONE, temp2);
		    }
		  else
		    {
		      
		      fread(&buffer, sizeof(buffer), RESULT_ONE, temp2);
		    }
		  fseek(temp2, total, SEEK_CUR);
		  printf("Total is %s\n", buffer); 		 
		  return ;
		}
	      
	    }
	}
    }
}
