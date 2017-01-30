// Author: Nicholas LaJoie
// ECE 331 - Homework 1, Problem 4
// Date: 1/25/17
// Description: Measure the speed (in nanoseconds) of memory for a buffer size passed as a command line argument
// "inttypes" library and usage found at jhshi.me/2014/07/11/print-uint64-t-properly-in-c/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <inttypes.h>

#define __STDC_FORMAT_MACROS
#define VALUE 17

int main(int argc, char * argv[])
{
	int *buffer, bufsize;
    struct timespec start, stop; 

	if (argc < 2) {
    	printf("No buffer size specified.\n");
        return -1; 
	}
	if (argc > 2) {
    	printf("Too many arguments!\n"); 
        return -2; 
	}

    // Convert command line argument string to an int
	bufsize = atoi(argv[1]);  
	if (bufsize <= 0) {
    	printf("Invalid buffer size.\n"); 
        return -3;
	}
	buffer = (int *)malloc(bufsize); 
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        return -4;
    }
    
    // Start timer
	clock_gettime(CLOCK_MONOTONIC, &start);
    
    memset(buffer, VALUE, bufsize);
    
    // Stop timer
	clock_gettime(CLOCK_MONOTONIC, &stop);

    free(buffer); 

    // Output data to a file in the format: buffer size, start time, stop time
    FILE *f = fopen("hw1_data.csv", "a");  
    if (f == NULL) {
        printf("File could not be opened!\n");
        return -5;
    }
    fprintf(f, "%d, %"PRIu64", %"PRIu64"\n", bufsize, (uint64_t)start.tv_nsec, (uint64_t)stop.tv_nsec); 
    fclose(f); 
    
    // Print to the console (so Sheaff can see it)
    printf("Buffer Size: %d Start: %"PRIu64" Stop: %"PRIu64"\n", bufsize, (uint64_t)start.tv_nsec, (uint64_t)stop.tv_nsec); 
	return 0; 
}

