/**********************************************************
Author -- Nafees Noor
NET ID -- nn319918
CSI 402 -- Assignment 3 
It's the main function file
This program creates a rational database
takes config file and query file and  
***********************************************************/


#include <stdio.h>
#include "macros.h"
#include "struct_def.h"
#include <string.h>

/****************** Function Prototype ****************/
FILE *open_schema_file(char *);
FILE *open_data_file(char *);
int nattr_Query(struct node *, char * , int);
int tuplen_Query(struct node *, char *);
int infattr_Query(struct node *,  char *, char *);
int count_Query(struct node *, char *);
void project_Query(struct node *, char *, char *);
void select_Query(struct node *, char *, char *);
/*******************************************************/

int main(int argc, char* argv[])
{
  FILE *fp;
  FILE *fp_arg2;                                                           // Used to get the first file from the command line argument
  FILE *fp2;
  FILE *fp3;
  char input_array[ARRAY_SIZE];                                           // Array to used to get the relation name from the config File
  char query_commands_array[COMMAND_ARRAY_SIZE];                         // Array to used to get the command from the query file
  char parameter_Array[PARAMETER_ARRAY_SIZE];                            // Array to used to get the parameter of the command from query file
  char parameter_Array_two[PARAMETER_ARRAY_SIZE];
  int i =0;                                                             // Used for loop variable
  int j = 0;
  int tuplen = 0;
  int count = 0;
  int row = 0;
  int check = 0;  // variable to check what the nttr query command's function return

  int number_of_attribute = 0;
  int config_file_number = 0;
  struct node table[TABLE_SIZE];
  
  /******************** All the variable declaration above *******************/
  
  /* Checking for the right amount of command line argument */
  if((argc != IN_FILE_ARG_SIZE))
    {
      printf("Does not have three argument, please provide three arguments\n");
      fflush(stdout);
      exit(1);
    }


  /* Checking for the first command line argument file */  
  if((fp = fopen(argv[IN_FILE_ARG_ONE], "r")) == NULL)
    {
      printf("Could not open the config file\n");
      fflush(stdout);
      exit(1);
    }
    
  if((fp_arg2 = fopen(argv[IN_FILE_ARG_TWO], "r")) == NULL)
    {
      printf("Could not open the query file\n");
      fflush(stdout);
      exit(1);
    }

  for(i = 0; i < COMMAND_ARRAY_SIZE; i++)
    {
      query_commands_array[i] = '\0';
    }


  /*********************************************************************************************************/ 
  fscanf(fp, "%d", &config_file_number);                               // Getting the number from the config file

  for( j = 0; j < config_file_number; j++)                             // Looping until that number of config file and getting and opening rest of the files
    {
      fscanf(fp, "%s", input_array);                                   //Getting the name from the config file
      strcpy(table[j].relation, input_array);


      fp2 = open_schema_file(input_array);                             //Opening the config file   
      fp3 = open_data_file(input_array);                               //Opening the data file
      
      fscanf(fp2, "%d", &number_of_attribute);                         //Getting the number of attribute 

      for(row = 0; row < number_of_attribute; row++)
	{
	  fscanf(fp2, "%s %c %d", table[row].name, &table[row].type, &table[row].size);      //Getting the information about the attribute
	  strcpy(table[row].relation, input_array);       // Copying from the input array to relation which tells the relation's name    
	}      
      fclose(fp2);
      fclose(fp3);
    } //End of main for loop


  /****************************************************************
    In this while loop, it's looping until end of the file
    and getting all the commands from the query file and proccessing
    each of the query commands based on the query file commands
  ****************************************************************/
  while((fscanf(fp_arg2, "%s", query_commands_array)) != EOF)
    {
      if((strcmp(query_commands_array, "quit")) == 0)
	{
	  exit(1);
	}

      else if((strcmp(query_commands_array, "nattr"))== 0)   //Checking if the the command is nattr
	{
	  fscanf(fp_arg2,"%s", parameter_Array);             //Getting the parameter based on the commands
	
	  check = nattr_Query(table, parameter_Array, count);   // Calling the nattr_Query to get the nattr value
	  if(check != RESULT_ONE)
	    {                                                  //Here if the function returns not equal one then it prints the error message
	      printf("No relations in the database\n");
	      fflush(stdout);
	    }
	} // end for nattr command


      else if((strcmp(query_commands_array, "tuplen")) == 0)
	{
	  fscanf(fp_arg2,"%s", parameter_Array);
	  
	  tuplen  = tuplen_Query(table, parameter_Array);
	  
	}  // End of the tuplen command
      

      else if((strcmp(query_commands_array, "infattr")) == 0)
	{
	  fscanf(fp_arg2, "%s", parameter_Array);
	  fscanf(fp_arg2, "%s", parameter_Array_two);
	  
	  check = infattr_Query(table, parameter_Array, parameter_Array_two);
	  
	  if(check != RESULT_ONE)
            {
              printf("Error: Invalid attribute -- %s\n", parameter_Array_two);
              fflush(stdout);
            }
	}    // End of the infattr comand

      else if((strcmp(query_commands_array, "count")) == 0)
	{
	  fscanf(fp_arg2,"%s", parameter_Array);
	  check  = count_Query(table, parameter_Array);

	  if(check != RESULT_ONE)
            {
              printf("Error: Invalid relation -- %s \n", parameter_Array);
              fflush(stdout);
            }
	} // End of count command

      
      else if((strcmp(query_commands_array, "project")) == 0)
	{
	  fscanf(fp_arg2, "%s", parameter_Array);
	  fscanf(fp_arg2, "%s", parameter_Array_two);
	  
	  project_Query(table, parameter_Array, parameter_Array_two);
	}


      else if((strcmp(query_commands_array, "select")) == 0)
        {
          fscanf(fp_arg2, "%s", parameter_Array);
          fscanf(fp_arg2, "%s", parameter_Array_two);

          select_Query(table, parameter_Array, parameter_Array_two);
        }

      
    } //End of while loop
  return 0;
}
