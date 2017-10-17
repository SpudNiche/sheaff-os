// Author: Nicholas LaJoie
// ECE 331 - Project 1, Homework 9 
// Date: April 4, 2017
// Description: User space program for encoding morse code messages from the command line to the ECE 331 Expansion Board 

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h> 
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>

int main (int argc, char * argv[]) 
{
    // Variables
    int fd, ret, msg_len; 
    char *msg; 

    // Command line argument error checking 
    if (argc != 2) {
        perror("Usage: ./user \"Your Message\"\n"); 
        return 1; 
    }

    // Get user message and length 
    msg = argv[1]; 
    msg_len = strlen(msg); 

    // Open morse device special file 
    fd = open("/dev/morse", O_WRONLY); 
    
    // Open file error checking 
    if (fd < 0) {
        perror("Failed to open morse device!\n");
        return 2;
    }

    // Send message to kernel driver 
    ret = write(fd, msg, msg_len); 
    if (ret < 0) {
        perror("Failed to write to morse device!\n"); 
        return 3; 
    }

    // Clean up
    close(fd); 

    return 0; 
}
