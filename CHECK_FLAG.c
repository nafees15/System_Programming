/*******************************************************************************
Author -- Nafees Noor
Net ID -- nn319918
Assignment 5  -- Part A
This is the second file of part A
This file has a function named error_check
which check if the correct flag was given
in the command line argument if it did then outputing an error
*******************************************************************************/

#include <stdio.h>
#include "macros.h"
#include <stdlib.h>

/****** Function Prototype ********/
void error_check();
/**********************************/

/************************************************************************
This function checks each of the flag for Part A of this assignment
If any flag is not recognized in the command line argument then it 
prints out an error message saying the command does not recognized
************************************************************************/
void error_check()
{
  printf("Wrong command line flag\n");           // For every cases if the flag is not recognized 
  fflush(stdout);                                // It's printing it out and exiting from the program
  exit(1);
}                                               // End of the function
