/**********************************************************
Author -- Nafees Noor
NET ID -- nn319918
CSI 402 -- Assignment 3
It's the Open_Data file
This file opens the data file
then  return the file pointer to the main
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include <string.h>

/************* Function Prototype ***********************/
FILE *open_data_file(char *);
/********************************************************/

/****************************************************
  This file first string copy to the local array
then string concat to add the .dat extension and 
opening the file and returning the file pointer
****************************************************/
FILE *open_data_file(char *array)
{
  FILE *temp;   // Temp to use for the file pointer
  int i = 0;
  char data_Array[((strlen(array))+ number_to_add_extension)];  // Local array to get the file extension

  /* Initiliazing the array */
  for(i = 0; i <((strlen(array)) + number_to_add_extension); i++)
    {
      data_Array[i] = 0;             
    }

  strcpy(data_Array, array);
  strcat(data_Array, ".dat");                    // String concating and adding .dat file and then opening the file

  if((temp = fopen(data_Array, "r")) == NULL)
    {
      printf("Could not open the schema file \n");
      fflush(stdout);
      exit(1);
    }

  return temp;                                   // returning the file pointer back to the main
}
