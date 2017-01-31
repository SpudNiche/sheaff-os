// Author: Nicholas LaJoie
// File: prob4.c
// Date: 1/25/17
// Description: Print total number of BLOCKS used by list of files passed on command line. 

#include <stdio.h>
#include <string.h> 

int main(int argc, char * argv[])
{
	int i, status; 
	char *command[argc];  

	if (argc < 2) {
		perror("No arguments passed!\n"); 
		return -1; 
	}
	for (i = 1; i < argc; i++) {
		command[i] = argv[i]; 
		printf("%s\n",command[i]);
		status = system(command[i]); 
		if (status == -1) {
			perror("System call failure.\n");
			return -2;
		}
	}	
	
	return 0; 
}
