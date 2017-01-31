// Author: Nicholas LaJoie
// File: prob4.c
// Date: 1/25/17
// Description: Print total number of BLOCKS used by list of files passed on command line. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	int i, status, blocksum; 
	char command[1000];
    struct stat s; 

	if (argc < 2) {
		perror("No arguments passed.\n"); 
		return -1; 
	}
    // Call each command line argument with 'stat' and parse data for # of blocks 
	for (i = 1; i < argc; i++) {
		//printf("%s\n", command);
        if (stat(argv[i], &s) == -1) {
            perror("Stat error"); 
        }
        else {
            blocksum += (int) s.st_blocks; 
        }
        snprintf(command, sizeof(command), "stat %s", argv[i]); 
        status = system(command); 
		if (status == -1) {
			perror("System call failure.\n");
			return -2;
		}
	}	
    printf("%d\n", blocksum); 	

	return 0; 
}
