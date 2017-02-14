// Author: Nicholas LaJoie
// ECE 331 - Homework 4 
// Date: February 10, 2017 
// File: prob3.c 
// Description: Testing implementation of the x_strstr() function.  
// Sources: https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm

#include <stdio.h> 
#include "x_strstr.h"

int main(int argc, char * argv[]) 
{
    const char *haystack;
    const char *needle;
    char *p;

    // Receive command line arguments 
    if (argc == 3) {
        needle = argv[2];
        haystack = argv[1];
    } else if (argc == 2) {
        needle = ""; 
        haystack = argv[1];
    } else if (argc == 1) {
        needle = ""; 
        haystack = "";
    } else {
        perror("Invalid number of arguments passed"); 
        return 1;
    }

    // Process input 
    p = x_strstr(haystack, needle);
    if (p != NULL) {
        printf("%s\n", p);
    } else {
        printf("Returned NULL\n");
    }

    return 0; 
}
