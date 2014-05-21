/********************************************************************************
Author -- Nafees Noor
Net ID -- nn319918
Programming Assignment 5 b
This is part b of programming assignment 5
This is the second file of server side
This program has function called check_arg which takes two parameter
and check wheter there were right flag were provided for the part b
**********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

/********* Function Prototype ************/
void check_arg(int);
/*****************************************/
/*
This program has function called check_arg which takes two parameter
and check wheter there were right flag were provided for the part b
*/

void check_arg(int num)
{
  if(num != RESULT_FIVE)                          // Checking if the proper flag was given or not 
    {
      printf("Correct flag is not given!\n");      // otherwise giving the error and exiting out

      printf("Please provide the correct number of flag\n");
      fflush(stdout);
      exit(1);
    }
}
