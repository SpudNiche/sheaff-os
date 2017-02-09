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
//          Reading from stdin: stackoverflow.com/questions/22340845/c-piping-file-from-command-line-to-c-program-with-the-use-of-strtok

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

void rm_newline(char* str); 

int main(int argc, char * argv[])
{
    char *line; 
    size_t len = 0; 
    
    regex_t reg;
    int regflag; 
    char errbuf[100];

    // Validate proper command line argument
    if (argc != 2) {
        perror("Invalid arguments.\n");
	    return 1;
    }
    // Load Regular Expression 
    printf("Regex: %s\n", argv[1]);
    regflag = regcomp(&reg, argv[1], REG_EXTENDED); 
    if (regflag) {
        perror("Error compiling regex\n");
        return 2;
    }
    // Allocate input line memory 
    line = (char *) malloc(len * sizeof(char));
    if (line == NULL) {
        perror("Error allocating line memory.\n");
        return 3; 
    }
    // Read user input using stdin
    while (getline(&line, &len, stdin) != -1) {
        // Remove newline character at the end of the line
        rm_newline(line); 
        // Process line using regex
        regflag = regexec(&reg, line, 0, NULL, 0);
        if (!regflag) {
            printf("%s\n", line); 
        } else if (regflag == REG_NOMATCH) {
            continue;  
        } else {
            regerror(regflag, &reg, errbuf, sizeof(errbuf));
            printf("Regex error: %s\n", errbuf);
            return 4;
        }
    }
    free(line);

    return 0;
}

void rm_newline(char* str)
{ 
    int len = strlen(str); 

    if (len > 0 && str[len - 1] == '\n') {
        str[--len] = '\0'; 
    }
}
