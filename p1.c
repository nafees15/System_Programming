/****************************************************
Author -- Nafees Noor
Unix ID -- nn319918
This program compares two hash functions
and compare the size of the hash table
number of non empty list in the hash table
Maximum number of entries in a list
Minimum number of entries in a non-empty list
Average size of a non-empty list
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#define THREE 3
#define IN_FILE_ARG 1
#define IN_FILE_ARG2 2
#define ARRAY_SIZE 10000
#define SIZE 16

/* Funtion Prototype */
int hash_example_one(char *, int );
int hash_example_two(char *, int );


/* Struct node for linked list */
struct node {
  char data[SIZE];
  struct node *next;
};

int main(int argc, char *argv[])
{
 
  int size;
  //  void *pointer;
  struct node **table;
  struct node **tableTwo;
  FILE *file;
  FILE *file2;
  char array[SIZE];
  int index;
  struct node *temp;
  struct node *temp2; //for the second hash
  struct node *LP;
  struct node *LP2;  //for the second hash
  int indexTwo;
  struct node *current;  //  Temorary struct variable to use
  struct node * current2;
  struct node *current3;
  struct node *current4;
  //struct node *test;
  int nonEmpty = 0;  // Variable to count non empty list
  int nonEmpty2= 0;
  int CRvalue= 0;
  int CRvalue2 =0;
  int CRvalue3= 0;
  int CRvalue4=0;
  int maximum = 0;  // variable to count maxi and minimum
  int maximum2=0;
  int minimum = 0;
  int minimum2=0;
  double avg = 0;
  double avg2=0;
  int i =0;
  int j = 0;   //Loop variable
  int k = 0;
  int m = 0;
  int n = 0;
  int p = 0;
  int z = 0;
  int test = 0;
  int test2 = 0;


  if(argc != THREE)  // Comparing if the command line is not three then showing error 
    {
      printf("Command line argument is not equal three\n");
      fflush(stdout);
      exit(1);
    }

  if((file = fopen(argv[IN_FILE_ARG], "r")) == NULL)  //Checking if the first file could open or no 
    {
      printf("Couldn't open up the file for reading \n");
      fflush(stdout);
      exit(1);
    }


  if((file2 = fopen(argv[IN_FILE_ARG2], "w")) == NULL) // Checking if the output file can be open or not
    {
      printf("Couldn't open the second file for reading n");
      fflush(stdout);
      exit(1);
    }
 
  /* Getting the first line to get the size */
  fscanf(file,"%d",  &size);


  /* Allocating malloc to to create the table */
  if((table = (struct node **) malloc(sizeof(struct node) *(size))) == NULL)
    {
      printf("Allocation failed!\n");
      fflush(stdout);
      exit(1);
    } 

  if((tableTwo = (struct node **) malloc(sizeof(struct node) *(size))) == NULL)
    {
      printf("Malloc allocation for HashtableTwo failed\n");
      fflush(stdout);
      exit(1);

    }

  //Initilize the array
  for(i =0; i <size; i++)
    {
      table[i] = NULL;
      tableTwo[i] = NULL;
    }
 

  /* While loop to get the index and add to the hash table */
  while(fscanf(file,"%s", array)!=EOF)
    {
      index = hash_example_one(array, size);
      indexTwo = hash_example_two(array,size);

      /*Here checking first if the index which was provided by the Professor Ravi's file */
      /*If it's null or not. If it's null that means there's no exist node thus creating */
      /* a new node and saving the string int that node and point to that node */
      if(table[index] == NULL)
	{
	  if((temp = (struct node *) malloc(sizeof(struct node))) == NULL)
	    {
	      printf("Malloc allocation failed!\n");
	      fflush(stdout);
	      exit(1);
	    }	
	  strcpy(temp -> data,array );  //Adding the first node to the list, coping the string into hash table
	  table[index] = temp;     //temp be the first node of the list
	  temp ->next = NULL;
	 
	}

      else
	{    /*Else means there is already a node in the list so it will just add at the end of the list a new node */
	  LP = table[index];
	  if((temp = (struct node *)malloc(sizeof(struct node))) == NULL)
	    {
	      printf("Malloc for else allocation failed !\n");
	      fflush(stdout);
	      exit(1);
	    }

	  while(LP != NULL)  /*Here looping until null to reach the last node of the list so can add the new node at the end of the list */
	    {	      
	      LP = LP -> next;
	      if(LP==NULL){
		break;
	      }
	    }	  
	  strcpy(temp -> data, array);
	  temp = LP -> next;                   //Same as before coping the string and making the temp be the last node of the list 
	  temp -> next = NULL;
	  
	} //end of else


      /***** For the second hash function ******/

      if(tableTwo[indexTwo] == NULL)  //Here cheking the same thing as hash table one if it's null or not if it's null then it means no node in the list 
        {

          if((temp2 = (struct node *) malloc(sizeof(struct node))) == NULL)
            {
              printf("Malloc allocation failed!\n");
              fflush(stdout);
              exit(1);
            }
          strcpy(temp2 ->data, array );  //In that case adding the first node in the list
          tableTwo[indexTwo] = temp2;
          temp2 ->next = NULL;
        }

      else
        {   // Else it's adding the the new node to the end of the list in hash function 2
          LP2 = tableTwo[indexTwo];
          if((temp2 = (struct node *)malloc(sizeof(struct node))) == NULL)
            {
              printf("Malloc for else allocation failed !\n");
              fflush(stdout);
              exit(1);
            }

	  while(LP2 != NULL)  //Looping until reach to the last node and add the new node at the end
	      {
		LP2 = LP2 -> next;
		if(LP2==NULL){
		  break;
		}
	      }
	   
	  strcpy(temp -> data, array);
          LP2  = temp2;                     //Copying down the string and making the temp2 be the new last node of the list
          temp2 -> next = NULL;
	}
    } //End of while loop


  /****************** Counting for first table for Numbers of non-Emtpy list********************/
  for(i = 0; i <size; i++)
    {
      if(table[i] != NULL)  //Here loping the first hash function to count total non empty list there 
	{
	  nonEmpty++;
	}
    }
     /**** For the second table ***/
  for(j = 0; j < size; j++)
    {
      if(tableTwo[j] != NULL)  // here looping so can find the total non empty list for the second hash function
	{
	  nonEmpty2++;
	}
    }



  ///////////// DEBUGGING
  for(test = 0; test <size; test++)
    {
      printf("Checking lines %s\n", table[test]-> data);
    }

  for(test2= 0; test2 < size; test2++)
    {
      if(tableTwo[test2] -> data == NULL)
	{
	  printf("It became NULL \n");
	  break;
	}
      printf("Checking lines for Hash Table 2 %s\n", tableTwo[test2] -> data);
    }


  /***********Counting the maximum number of entries  for the First table****************/
  current = table[index];
  for(k = 0; k < size; k++)
    {
      while(current != NULL)   // Here counting the maximum number
	{
	  current = current -> next;
	  CRvalue++;
	  if(CRvalue > maximum)
	    {
	      maximum = CRvalue;
	    }
	  
	} //End of while loop
      
      //  test = table[k];
    }
  
  /*************** Counting the maximm number of entries for second hash table **************/
  current2 = tableTwo[indexTwo];
  for(m = 0; m < size; m++)
    {
      while(current2 != NULL)
	{
	  CRvalue2++;
	  current2 = current2 -> next;
	}

      if(CRvalue2 > maximum2)
      {
	maximum2 = CRvalue2;
      }
    }
	 	
  /************ Counting the minimum number of entries **************/
  current3 = table[index];
  for(n= 0; n <size; n++)  // counting the minimum  number
    {
      while(current3 != NULL)
        {
          CRvalue3++;
          current3 = current3 -> next;
        }
      if(CRvalue3 < minimum)
	{
	  minimum = CRvalue3;
	}
    } 

  /************ Counting the minimum for the second table **********/	    
  current4 = tableTwo[indexTwo];
  for(p= 0; p <size; p++)  // counting the minimum  number
    {
      while(current4 != NULL)
        {
          CRvalue4++;
          current4 = current4 -> next;
        }
      if(CRvalue4 < minimum2)
        {
          minimum2 = CRvalue4;
        }
    }

  fprintf(file2,"Results for Hash Function I\n");
  fprintf(file2,"---------------------------\n");
  fprintf(file2,"Hash table size = %d\n", size);
  fprintf(file2,"Number of non-empty lists = %d\n", nonEmpty);
  fprintf(file2,"Maximum number of entries in a list = %d\n", maximum);
  fprintf(file2,"Minimum number of entries in a non-empty list = %d\n", minimum);
  fprintf(file2,"Average number of entries in a non empty list = %.2f\n", avg);


  fprintf(file2,"Results for Hash Funtion II \n");
  fprintf(file2,"----------------------------\n");  
  fprintf(file2,"Hash table size = %d\n", size);
  fprintf(file2,"Number of non-empty lists = %d\n", nonEmpty2);
  fprintf(file2,"Maximum number of entries in a list = %d\n", maximum2);
  fprintf(file2,"Minimum number of entries in a non-empty list = %d\n", minimum2);
  fprintf(file2,"Average number of entries in a non empty list = %.2f\n", avg2);

  return 0; 
 
}
