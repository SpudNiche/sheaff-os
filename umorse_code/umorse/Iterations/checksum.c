// Author: Nicholas LaJoie 
// ECE 331 - Homework 5, Problem 6
// Date: February 19, 2017
// Description: Receives a valid string as a command line argument, encodes it in morse code, and prints to the console - includes a preamble and 8-bit checksum 
// Sources: http://stackoverflow.com/questions/18921559/initializing-array-of-structures,     http://stackoverflow.com/questions/8206014/passing-an-array-of-structs-in-c

#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include "encoding.h"

int print_morse(const struct morse_s x);

int main (int argc, char * argv[]) 
{
    int i, sum = 0; 
    struct morse_s preamble = {0b0100, 4};
    struct morse_s checksum; 

    // Verify command line argument 
    if (argc != 2) {
        printf("Usage: %s \"<Input String>\"\n", argv[0]); 
        return 1; 
    }

    // Print preamble
    sum += print_morse(preamble);
    // Process input and print morse encoding
    char *str = argv[1];
    for (i = 0; i < strlen(str); i++) {
        // Each encoding can be accessed using list[(int)str[i]] 
        sum += print_morse(list[(int)toupper(str[i])]);
        // Print three Morse time units between characters (not at the end, however)
        if ((i != (strlen(str) - 1)) && (str[i + 1] != ' ') && (str[i] != ' ')) {
            printf("___");
        } 
    }
    // Finish it off with the 0, checksum, and newline 
    printf("_");
    checksum.bin = ~sum; 
    checksum.len = 8;
    print_morse(checksum);
    printf("\n");

    return 0; 
}

// Function prints morse_s struct in morse code ('*' for 1, '_' for 0)
// Returns the number of '1's printed (used for the checksum) 
int print_morse(const struct morse_s x)
{
    int i, ones = 0, mask = 0b1; 

    // Print the binary value using a mask 
    for (i = 0; i < x.len; i++) {
        if ((x.bin & mask) != 0) {
            printf("*");
            ones++;
        } else {
            printf("_");
        }
        mask <<= 1; 
    }
    return ones; 
}
