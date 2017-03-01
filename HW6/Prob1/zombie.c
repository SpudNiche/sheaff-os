// Author: Nicholas LaJoie 
// ECE 331 - Homework 6
// February 26, 2017
// Description: A C program that creates zombies by calling fork().
// Sources: http://askubuntu.com/questions/111422/how-to-find-zombie-process, http://stackoverflow.com/questions/6501522/how-to-kill-a-child-process-by-the-parent-process, http://man7.org/linux/man-pages/man2/kill.2.html

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <signal.h> 

int main(int argc, char * argv[]) 
{

    pid_t child; 

    // Create child process 
    child = fork(); 

    // Create a Zombie 
    if (child > 0) {
         // Parent sends a term signal to child, sleeps 
        kill(child, SIGTERM); 
        sleep(10);
    } else if (child == 0) {
        // Child sleeps in endless loop
        while (1) {
            sleep(1);
        }
    } else {
        perror("Failure on fork()\n");
        return 1; 
    }
    return 0; 
}
