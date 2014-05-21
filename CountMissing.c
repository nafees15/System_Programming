/*****************************************************
Author -- Nafees Noor
Net ID -- nn319918
It has the method named -- CountMissing Packet
This file is for Counting the missing packets
******************************************************/

#include <stdio.h>
#include "macros.h"

/******* Funtion Prototypes **************/
void CountMissingPacket(int [], int);
/*******************************************/

/* This function takes array and the maxPacket as a size
   loop through the array and find the missing packets
****************************************************/
void CountMissingPacket(int Array[], int size)
{
  int i = 0;   // Loop variable
  int lowerIndex = 0;  //variable to find the lowerIndex which would be first missing packet
  int upperIndex = 0;  // variable to find the uppoerIndex which would be last missing packet

  for(i = 0; i < size; i++) 
    {
      if(Array[i] == RESULT_ZERO) //Checking if the index of that array equal zero or not
	{                        // If it is a zero then that means it found the first missing packet
	  lowerIndex = i;       // setting that index to be the first lower index

	  while(Array[i] != RESULT_ONE) // this while loop is for looping until it finds a one 
	    {                           //couting up the counter to know how many are missing
	      i++; 
	    }

	  upperIndex = i - RESULT_ONE;  //Now setting up that to be my uppercase missing

	  if(lowerIndex == upperIndex)  //Checking if my lower or upper are same that means it missing just one packet
	    {
	      printf("%d, ", lowerIndex); //then just only printing out the number beause it's just missing one packet
	    }	  
	  
	  else if(lowerIndex + RESULT_ONE == upperIndex) // Checking if the next of my lower are upperindex
	    {                                           // In that case it means number are missing next to each other
	      printf("%d, %d, ",lowerIndex,upperIndex); // In that case prining a coma between those to numbers of missing packet
	    }

	  else                                          //For everything else it means there are more than one packet missing
	    {                                           //So it's printing the range of missing packet and putting - between it
	      printf("%d-%d, ", lowerIndex, upperIndex);
	    }	  
	}// end of if statement
    } // end of the for loop
 
  printf("\n"); //printing out a line
  
} // end of the function

