/**********************************************************
Author -- Nafees Noor
NET ID -- nn319918
CSI 402 -- Assignment 4
It's the check opcode function file
This function opens the opcode table file
and check whether the opcode is valid or not provided 
from the main function
***********************************************************/

#include <stdio.h>
#include "macros.h"
#include <string.h>
#include <stdlib.h>

/************* Funtion Prototype ****************/
int check_the_opcode(char *);
/***********************************************/

/*********************************************************
This function opens the opcode table file
and check whether the opcode is valid or not provided
from the main function
**********************************************************/

int check_the_opcode(char *pointer)
{
  FILE *fp;                               // file pointer to open up the opcode file
  int check = 0;                          // boolean variable to send back if the opcode is valid or not
  int number = 0;
  char arg1[ARRAY_SIZE];                        // Array to get the string from the opcdoe table
  char arg2[ARRAY_SIZE];
  
  if((fp = fopen("Opcode_Table.txt", "r")) == NULL)
    {
      printf("Could not open the opcode table file\n");
      fflush(stdout);
      exit(1);
    } 
  
  while((fscanf(fp, "%d %s %s", &number, arg1, arg2)) != EOF)
    { 
      if((strcmp(pointer, arg1)) == 0)
	{
	  check = RESULT_ONE;
	}
      else
	{
	  check = 0;
	}
    }
  
  return check;
}
