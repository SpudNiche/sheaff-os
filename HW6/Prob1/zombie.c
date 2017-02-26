// Author: Nicholas LaJoie 
// ECE 331 - Homework 6
// February 26, 2017
// Description: A C program that creates zombies by calling fork().

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <signal.h> 

int main(int argc, char * argv[]) 
{

    pid_t child; 

    // Create child 
    child = fork(); 
    if (child < 0) {
        perror("Couldn't create child...\n");
        return 1; 
    }

    return 0; 
}
