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
        //snprintf(command, sizeof(command), "stat %s", argv[i]); 
		//printf("%s\n", command);
        stat(argv[i], &s); 
        printf("Stat blocksize: %lld\n", (long long) s.st_blocks); 
        //status = system(command); 
		//if (status == -1) {
		//	perror("System call failure.\n");
		//	return -2;
		//}

	}	
	
	return 0; 
}
