// Author: Nicholas LaJoie
// File: prob4.c

//#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <time.h>

int main(int argc, char * argv[])
{
	int *buffer; 
	int bufsize, i, value = 17; 
	// struct timespec start, stop; 

	if (argc < 2) {
		printf("No buffer size specified.\n");
	}
	else if (argc > 2) {
		printf("Too many arguments!\n"); 
	}
	else {
		bufsize = atoi(argv[1]);  
		if (bufsize <= 0) {
			printf("Invalid buffer size.\n"); 
		}
		else {
			// Start clock here
			buffer = (int *)malloc(bufsize); 
			//printf("A buffer of size %d was created!\n", bufsize);
			//error check for malloc 
			for (i = 0; i < bufsize; i++) {
				buffer[i] = value;
			}
			free(buffer); 
			// Stop clock here 	
		}
	}

	
	//clock_gettime(CLOCK_MONOTONIC, &start);
	//clock_gettime(CLOCK_MONOTONIC, &end); 

	return 0; 
}
