/**********************************************************
Author -- Nafees Noor
NET ID -- nn319918
CSI 402 -- Assignment 4
It's the main function file
This program creates a infile which contains
TMIPS codes and it assemblees it and produces
any error if found
***********************************************************/

#include <stdio.h>
#include "macros.h"
#include <string.h>
#include <stdlib.h>

struct node_symbol_table                     // Linked list to create the symbol table
{
  char label_name[LABEL_SIZE];               // array to hold the label name
  int symbol_counter;                        // counter to keep track everytime label is found
  struct node_symbol_table *next;          
};

struct node_symbol_table *head = NULL;      // Pointer to keep track of head and tail of the list
struct node_symbol_table *tail = NULL;
struct node_symbol_table *node = NULL; 
struct node_symbol_table *temp = NULL;

/********* Funtion Prototype **************/
int check_the_opcode(char *);
/*****************************************/

int main(int argc, char *argv[])
{
  FILE *fp;                              // File pointer to take the input file
  char input_array[ARRAY_SIZE];         //  array to hold each line strings 
  char input_temp_array[ARRAY_SIZE];   // Array to keep the string so the original input array does not destroy with string token
  int lineNumber = 0;
  int bool_check = 0;
  char *pointer;
  char *temp_pointer;
  int LC = 0;
  
  if((fp = fopen(argv[COMMAND_LINE_ARGUMENT], "r"))== NULL)
    {
      printf("Could not open the file\n");
      fflush(stdout);
      exit(1);
    }

  while((fgets(input_array, SIZE_TO_GET, fp)) != NULL)
    {
      strcpy(input_temp_array, input_array);
      lineNumber++;
      
      pointer = strtok(input_temp_array, "  \t");

      if((strchr(pointer, '#')) != NULL)
        {
          //printf("The line has comment and the line is  %s\n", input_temp_array);
          //strtok(input_temp_array, " #\t\n");
	}
      
      else if((strchr(pointer, ':')) != NULL)
	{	  
	  if(head == NULL)                                             // Checking if the head is empty or not if the head is empty then there's no list yet
	    {
	      if((node = (struct node_symbol_table *) malloc(sizeof(struct node_symbol_table))) == NULL)
		{
		  printf("Malloc allocation is failed\n");
		  exit(1);
		}
	      pointer = strtok(NULL, ":");                             // string toking to get the opcode                
	      temp_pointer = strtok(input_temp_array, ":");            // string toking to get rid off the : to add the label
	      strcpy(node -> label_name, input_temp_array);            // putting the label into the list
	      node -> next = NULL;                              
	      head = node;                                             // Making the head and tail point to the list
	      tail = node;
	    }
	  else
	    {                 /* Else there's already a list exist, so just adding the new node end of the list */
	      if((node = (struct node_symbol_table *) malloc(sizeof(struct node_symbol_table))) == NULL)
                {
                  printf("Malloc allocation is failed\n");
                  exit(1);
                }
	      pointer = strtok(NULL, " :");                          // stringtoken to get rid off the space and get the opcode
	      temp_pointer =  strtok(input_temp_array, ":");                         // string toking to get rid off the : sign from the label
	      tail -> next = node; 
	      strcpy(node -> label_name, temp_pointer);           // putting the label into the list
	      tail = node;
	      node -> next = NULL;                                    // Making head and tail according to the noded	      
	    }	  
	}
      
      pointer =  strtok(pointer, " \t");                           // stringtoking to get rid off the all the tabs
      if((strchr(pointer, '\n')) != NULL)                          // Dealing with if i see a new line to get rid off all the lines
	{
	  continue;                                                // using this function to skip that line	  
	}
      
      else if((strchr(pointer, '#')) != NULL)                    // Dealing with comments
	{
	  continue;                                               // Using to skip that line if the comment is found
	}
      
      else if(((strcmp(pointer, ".data") || (strcmp(pointer, ".word")) || (strcmp(pointer, ".resw")))) != NULL)  // Dealing with .data/ .resw if found
	{  
	  pointer = strtok(input_temp_array, " \t");

	  printf("pointer is HERE %s\n", pointer);

	  bool_check = check_the_opcode(pointer);
	  if(bool_check == RESULT_ONE)
	    {
	      //      printf("This opcode exist %s\n", pointer);
	    }
	  else
	    {
	      // printf("This opcode does not exist %s\n", pointer);
	    }
	  //continue;
	}      
    }

  rewind(fp);
  
  /*  while((fgets(input_array, SIZE_TO_GET, fp)) != NULL)
    {
      strcpy(input_temp_array, input_array);
      
      pointer = strtok(input_temp_array, "  \t");


      LC++;
      
      if(bool_check == RESULT_ONE)
	{
	  //  printf("THe opcode exist %s\n", pointer);
	}
      else
	{
	  //printf("The opcode does not exist %s\n", pointer);
	  
	}
      
    } //end of the while loops
  */
  return 0;
}
