// Author: Nicholas LaJoie
// ECE 331 - Homework 7, Problem 4
// File: prob4_usage.c
// Date: March 14, 2017
// Description: Prints the resident set size of the running program itself by calling getrusage()

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main (int argc, char * argv[]) 
{
    struct rusage use; 

    int result = getrusage(RUSAGE_SELF, &use); // Get usage for program itself

    if (result == 0) {
        printf("Resident Set Size: %ld\n", use.ru_maxrss); // On success, print set size
    } else {
        perror("Error getting usage.\n"); // Error checking 
        return 1; 
    }

    return 0; 
}
