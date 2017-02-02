// Author: Nicholas LaJoie
// File: prob5.c
// Date: 1/31/17
// Description: Print total number of BLOCKS used by single glob passed on command line. 
// Sources: https://linux.die.net/man/2/stat and https://linux.die.net/man/3/glob

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glob.h>

int main(int argc, char * argv[])
{
	int i, blocksum = 0; 
    struct stat s; 
    glob_t g; 

    // Only one command line argument is passed - a single glob. 
	if (argc != 2) {
		perror("Incorrect number of arguments passed.\n"); 
		return 1; 
	}
    // Call single glob, call each result with 'stat' for # of blocks 
    if (glob(argv[1], GLOB_DOOFFS, NULL, &g) != 0) {
        perror("Glob error");
    }
    else {
    	for (i = 0; i < g.gl_pathc; i++) {
            if (stat(g.gl_pathv[i], &s) == -1) {
                perror("Stat error"); 
            }   
            else {
                blocksum += (int) s.st_blocks; 
            }
	    }
    }
    printf("%d\n", blocksum); 	

	return 0; 
}
