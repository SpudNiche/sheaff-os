// Author: Nicholas LaJoie
// ECE 331 - Homework 3
// Date: 2/9/17
// Description: Accepts a regular expression via stdin and prints entire lines that contain any matches 
// to stdout. Uses regcomp() and regexec()
// Sources: Valuable information obtained from linux.die.net/man/3/regcomp
//          Use of getline: c-for-dummies.com/blog/?p=1112
//          Removal of newline char: stackoverflow.com/questions/2693776/removing-trailing-newline-character
//          -from-fgets-input
//          Use of regex: stackoverflow.com/questions/1085083/regular-expressions-in-c-examples

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

int main(int argc, char * argv[])
{
    char *buffer; 
    char *express = "Something"; 
    size_t bufsize = 32; 
    size_t len; 
    
    regex_t reg;
    int regflag; 
    char errbuf[100];

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
        // Process input using regex 
        regflag = regcomp(&reg, express, 0); 
        if (regflag) {
            perror("Error compiling regex\n");
            return 3;
        }
        regflag = regexec(&reg, buffer,0, NULL, 0);
        if (!regflag) {
            // There's a match!
        }
        else if (regflag == REG_NOMATCH) {
            // No match :/ 
        }
        else {
            regerror(regflag, &reg, errbuf, sizeof(errbuf));
            printf("Regex error: %s\n", errbuf);
            return 4;
        }
    }
    free(buffer); 

    return 0;
}
