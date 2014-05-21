/*******************************************************************
Author -- Nafees Noor
Net ID -- nn319918
Programming Assignment 5a
This is the first part of the programming assignment
This program implements the unix function tar
which compress many files into one single file
and extract them from one file to many files
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

/********* Function prototype ************/
void error_check();
/******************************************/
/* Struct node definition to hold each inode from the archive file */
struct i_node
{
  char *filename;                                  // To hold the  S
  int filename_length;                             // To hold the L
  int size;                                        // To hold the Z
  struct i_node *next;
}file[FILE_SIZE];                                  // Declaring the file as array with size 255 to hold maximum number of files

/* Main  function begins */
int main(int argc, char *argv[])
{
  int i = 0;
  int j = 0;                                       // Loop variables
  int a = 0;
  int b = 0;                                       // Loop variables
  char flag_array[FLAG_SIZE];                      // Array to keep the flag
  int total_length = 0;                            // variable to find the total number of file it has
  unsigned char t_len = 0;                         // Used to create the total length write to the archive file as a character
  int L = 0;                                       // Used for to get the number character in the name of the file
  int Z = 0;                                       // Used to hold how many bits in the file
  struct stat num;                                 // Used to get the Z
  int size;                                        // Used to get the size of the file
  int file_descripter = 0;                         // variable to have file descripter when creating the archive file
  int file_descripter_Two = 0;                     // Variable to have file descripter when creating the archive file
  char buffer[BUFFER_SIZE];                        // Used to create a buffer array to get the bytes of the file
  int fd_read = 0;
  int fd_close_two = 0;                            // Used to check to close the archive file properly
  char len;                                        // Used to convert the length from integer to character
  
  int archive_opener = 0;                          // Variable to used as file discrepter to open archive file for reading
  char archive_buffer[BUFFER_SIZE];                // Array being used to hold data from archive file and write to the individual files
  int archive_file_opener = 0;                     // Varaible is being used as file descripter to open or make individual file from the archive file
  char archchar_N;                                 // To get the N from the archive file which tells how many files are there in the archive files
  int arch_N = 0;                                  // This is the integer version of the N so can loop that many times to open up the files from archive
  int arc_file_descripter = 0;                     // this is the file descripter to open or create each file from the archive files
  int c = 0;
  int d = 0;                                       // Looping variable
  int arch_fd_read= 0;
  char archchar_L = 0;                             // Varaible to hold the L or size of name of the file from the archive file
  int arch_L = 0;                                  // integer version of L
  int how_many_to_get = 0;                         // Varaible defining how many bytes to get from the archive file to write to the each files

  /********************************** All the variable declarations are above ************************************************************************/

  strcpy(flag_array, argv[ARG_TWO]);               // Copying the flag into the array to check later to see which flag is given
  
  if((strcmp(flag_array, "-c")) == 0)              // Flag to check if it's -c, in this case it needs right parameter and to compress the files
    {
      if(argc < CHECK_ARG)
	{
	  printf("Please provide right numbers of argument\n");
	  fflush(stdout);
	  exit(1);
	}
      
      /**********************************************************************
	For other cases, going through all the file and getting information
	to save each file's information about L, S and Z 
      ***********************************************************************/
      
      total_length = (argc - GET_LENGTH);                         // Getting the total length of the file in the command line arguments
      
      i = GET_LENGTH;                                            // i to start from three so it would skip the name and flag in the command line
      a = GET_LENGTH;

      if((file_descripter  = open(argv[ARGV_TWO], O_RDWR | O_CREAT, PERMS)) == -1)  // Opening the archive file to write
	{
	  printf("Error opening the file\n");
	  fflush(stdout);
	  exit(1);
	}
      
      t_len = ((char)total_length);                             // making the total length to character and write to the archive file
      write(file_descripter, &t_len, sizeof(char));             // Writing N or the total number of files to the archive file
      
      while(j <  total_length)                                  // Looping until the total many of files
	{	  
	  L = strlen(argv[i]);                                  // Each time getting the total size of the name in the file
	  len = ((unsigned char)L);                             // converting the L to character into len to write to the archive
	  size = stat(argv[i], &num);                            // getting the stat of the file
	  Z = num.st_size;                                       // Getting the stat or size of the file
	
	  write(file_descripter, &len, sizeof(char));            // writing the L to the file 
	  write(file_descripter, argv[i], strlen(argv[i]));      // writing the S to the file
	  write(file_descripter, &Z, sizeof(int));               // writing the Z to the file
	  i++;
	  j++;
	}
      
      while(b < total_length)
	{
	  if((file_descripter_Two = open(argv[a], O_RDONLY)) < 0) //Opening each file from the command line argument
	    {
	      printf("Could not open in the file from the command line argument\n");
	      fflush(stdout);
	      exit(1);
	    }
	  
	  while((fd_read = read(file_descripter_Two, buffer, BUFFER_TO_GET)) == BUFFER_TO_GET)
	    {                                                   // reading each of the command line files	      
	      if(fd_read == -1)                                 // Checking if error occurs in reading files
		{
		  printf("Error reading the argument files\n");
		  fflush(stdout);
		  exit(1);
		}
	      write(file_descripter, buffer, BUFFER_TO_GET);        // Writing out to the each file into the archive file	      
	    }
	  
	  if(fd_read != 0)                                         // Checking if the fd_reach is not zero then there's more thing
	    {
	      write(file_descripter, buffer, fd_read);             // to write into the archive file
	    }
	  
	  a++;                                                  // incrementing the file and variable counter
	  b++;	  
	} 
      if((fd_close_two = close(file_descripter_Two)) != 0)        // Closing the archive files
	{
	  printf("Error closing the archive file\n");
	}
    }  

  /* Else for the extracting part */
  else if ((strcmp(flag_array, "-x")) == 0)                         // Checking if the flag is -x or not
    {
      if(argc < CHECK_ARG_TWO)                                      // IN that case checking if the right number of argument was provided or not
	{
	  printf("Please provide the right number of arguments\n");
	  fflush(stdout);                                           // If not then showing the error and exiting out
	  exit(1);
	}
      if((archive_opener  = open(argv[ARGV_TWO], O_RDONLY)) == -1)  // Opening the archive file to read
        {
          printf("Error opening the file\n");
          fflush(stdout);
          exit(1);
        }
      if((arc_file_descripter = read(archive_opener, &archchar_N, sizeof(char))) == -1) // reading the archive file to get N from it
	{
	  printf("Error reading from the archive file\n");
	  fflush(stdout);
	  exit(1);
	}
     
      arch_N = ((int)archchar_N);                             // Getting the N and casting it to integer N

      for(c = 0; c < arch_N; c++)                             // Looping that many of N
	{
	  arch_fd_read = read(archive_opener, &archchar_L, sizeof(char));
	  if(arch_fd_read == -1 || arch_fd_read == 0)
	    {
	      printf("Error reading L from the file\n");
	      fflush(stdout);
	      exit(1);
	    }
	  
	  arch_L = ((int) archchar_L);                        // Getting the L and casting it to integer L
	  file[c].filename_length = arch_L;        
	  
	  if(( file[c].filename = malloc(arch_L + RESULT_ONE)) == NULL)  // Mallocing that many to get the file name
	    {
	      printf("Allocation failed\n");                  
	      fflush(stdout);
	      exit(1);
	    }
	  
	  read(archive_opener, file[c].filename, archchar_L);          // Reading the file name
	  read(archive_opener, &file[c].size, sizeof(int));            // Reading the size of Z
	}
      /*****************************************************************
	Using for loop to go through each file in the archive file
	 for each case opening up the file and writing the files content
	 from archive file to individual file itself
      *******************************************************************/
      for(d = 0; d < arch_N; d++)
	{
	  /* Opening / Creating the file from the archive file */
	  if((archive_file_opener  = open(file[d].filename, O_WRONLY | O_CREAT | O_TRUNC , PERMS)) == -1)  // Opening the file from the archive file
	    {
	      printf("Error opening the file\n");
	      fflush(stdout);
	      exit(1);
	    }
	 
	  how_many_to_get = file[d].size;                              // variable to know how many to read or write from the archive file	  
	
	  if(ARCHIVE_TO_GET <= how_many_to_get)                         // Here starting from one byte looping until the file size
	    {
	      while(ARCHIVE_TO_GET <= how_many_to_get)
		{
		  if((fd_read = read(archive_opener, archive_buffer, ARCHIVE_TO_GET)) == -1) // Each case reading that file
		    {
		      printf("Error reading from the archive files to the each file\n");
		      fflush(stdout);
		      exit(1);
		    }
		  write(archive_file_opener, archive_buffer, ARCHIVE_TO_GET);          // And writing that byt of the file from the archive buffer array
		  how_many_to_get -= ARCHIVE_TO_GET;                                  // Decreasing each time to meet the file size starting at one byte
		}  // End of while loop 
	    }   // End of if statement

	} // ENd of for loop
    }    // End of the else if -x flag

  else                                                          // Dealing with all other flags user might provide
    {
      error_check();                                            // Calling the error check function
    }
  // End of the main function
  return 0;
}
