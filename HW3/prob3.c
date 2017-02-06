// Author: Nicholas LaJoie
// ECE 331 - Homework 3
// Date: 2/9/17
// Description: Accepts a regular expression via stdin and prints entire lines that contain any matches 
// to stdout. Uses regcomp() and regexec()
// Sources: Valuable information obtained from linux.die.net/man/3/regcomp
//          Use of getline: c-for-dummies.com/blog/?p=1112
//          Removal of newline char: stackoverflow.com/questions/2693776/removing-trailing-newline-character
//          -from-fgets-input

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

int main(int argc, char * argv[])
{
    char *buffer; 
    size_t bufsize = 32; 
    size_t len; 

    // Allocate buffer memory 
    buffer = (char *) malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("Error allocating buffer memory.\n");
        return 1; 
    }
        
    // Regular Expression from problem 2
    
    // Read user input using stdin
    printf("Enter text: ");
    if (getline(&buffer, &bufsize, stdin) == -1) {
        perror("Failed to read input.\n");
        return 2;
    }
    else {
        len = strlen(buffer);
        // Remove additional newline character
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[--len] = '\0'; 
        }
        printf("This is what you entered: %s\n", buffer);
    }

    free(buffer); 

    return 0;
}
