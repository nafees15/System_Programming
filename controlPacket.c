/***************************************
Author -- Nafees Noor
Net ID -- nn319918
This file is for Control Packet
This file finds the total control packet
It has methods -- Numbers of packet
****************************************/

#include <stdio.h>
#include "macros.h"


/************* Function prototype ***************/
int Number_Of_Control_Packet(int [], int);
/************************************************/

int Number_Of_Control_Packet(int controlPacket[], int AR_size)
{
  int total_packet = 0; //  variable to count the total control packet
  int i = 0;            // Loop variable

  for(i = 0; i < AR_size; i++)
    {                           // Looping through and checking if the array has one or not
      if(controlPacket[i] == RESULT_ONE) // If it finds one that means it received a packet
	{
	  total_packet++;        // couting the total packet
	}
    } //end of for lop

  return total_packet; //returning the total packet found
}


