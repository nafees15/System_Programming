/************************************************** 
Author -- Nafees Noor 
Net ID -- nn319918
This function finds the total data packet
This file is for Data Packet
It has methods -- Numbers of packet
***************************************************/

#include <stdio.h>
#include "macros.h"

/********* Function Prototype ****************/
int Number_Of_Data_Packet(int [], int);
/*********************************************/

/*This function takes array and the size from the main function
  then calculate if the data packet found in the array or not
  if it is found then it calculates the total data packet
  and returns the total packet found */

int Number_Of_Data_Packet(int dataPacket[], int AR_size)
{
  int total_packet = 0; // variable to count the total packet
  int i = 0; //loop variable
  
  for(i = 0; i < AR_size; i++)
    {
      if(dataPacket[i] != RESULT_ZERO)  // Checking if there's a zero inside array in that case the data packet is found
	{
	  total_packet++;   //counting the total data packet found
	}
    }
  return total_packet;  // returning the total data packet found 
}
