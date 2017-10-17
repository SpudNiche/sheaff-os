// Author: Nicholas LaJoie 
// ECE 331 - Homework 5, Problem 3
// Date: February 19, 2017
// Description: Receives a valid string as a command line argument, encodes it in morse code, and prints to the console 
// Sources: http://stackoverflow.com/questions/18921559/initializing-array-of-structures,    http://stackoverflow.com/questions/8206014/passing-an-array-of-structs-in-c

#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include "encoding.h"

void print_morse(const struct morse_s x);

int main (int argc, char * argv[]) 
{
    int i; 

    // Verify command line argument 
    if (argc != 2) {
        printf("Usage: %s \"<Input String>\"\n", argv[0]); 
        return 1; 
    }

    // Process input and print morse encoding
    char *str = argv[1];
    for (i = 0; i < strlen(str); i++) {
        // Each encoding can be accessed using list[str[i]] 
        print_morse(list[(int)toupper(str[i])]);
        // Print three Morse time units between characters (not at the end, however)
        if ((i != (strlen(str) - 1)) && (str[i + 1] != ' ') && (str[i] != ' ')) {
            printf("___");
        }
    }
    // Finish with a newline
    printf("\n");
    return 0; 
}

// Function prints morse_s struct in morse code ('*' for 1, '_' for 0)
void print_morse(const struct morse_s x)
{
    int i, mask = 0b1; 

    // Print the binary value using a mask 
    for (i = 0; i < x.len; i++) {
        printf("%c", ((x.bin & mask) == 0) ? '_':'*');
        mask <<= 1; 
    }
}
