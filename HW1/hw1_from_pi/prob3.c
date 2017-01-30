// Author: Nicholas LaJoie
// ECE 331 - Homework 1, Problem 3
// Date: 1/25/17
// Description: Program prints command line arguments passed by the user.

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
	int i; 

	if (argc < 2) {
		printf("No arguments passed!\n"); 
		return -1; 
	}
	for (i = 1; i < argc; i++) {
		printf("Argument: %s\n", argv[i]); 
	}

	return 0;
}
