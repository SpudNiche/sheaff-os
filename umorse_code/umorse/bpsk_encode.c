// Author: Nicholas LaJoie 
// ECE 331 - Homework 5, Problem 7
// Date: February 21, 2017
// Description: Receives a valid string as a command line argument, encodes it in morse code, and prints to the console - includes a preamble and 8-bit checksum 
// BPSK Encoding: Uses GPIO 4 as Enable Output, GPIO 17 as Morse Code data BPSK encoded
// Note: Utilizing code I had written for 471 last semester 
// Sources: http://stackoverflow.com/questions/18921559/initializing-array-of-structures, http://stackoverflow.com/questions/8206014/passing-an-array-of-structs-in-c, http://elinux.org/RPi_GPIO_Code_Samples 

#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include "encoding.h"
#include <fcntl.h>  /* open() */
#include <unistd.h> /* close() */

#define MORSE_TIME_UNIT 120000 // microseconds
#define ENABLE_PIN 4 
#define BPSK_PIN 17

void pin_high(int fd, const int pin);
void pin_low(int fd, const int pin);
int bpsk_encode(int fd, const struct morse_s x); 

int main (int argc, char * argv[]) 
{
    int i, fd, sum = 0; 
    char buffer[4006];
    // struct morse_s preamble = {0b0100, 4};
    // struct morse_s three_units = {0b000, 3};
    // struct morse_s one_unit = {0b0, 1};
    struct morse_s checksum; 

    // Verify command line argument 
    if (argc != 2) {
        printf("Usage: %s \"<Input String>\"\n", argv[0]); 
        return 1; 
    }

    /* GPIO Set Up --------------------------------------------------------------*/
    // Enable GPIO Pin 4
    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
        perror("Error enabling GPIO 4\n");
        return 1; 
    }
    sprintf(buffer, "4");
    write(fd, buffer, strlen(buffer));
    close(fd);
    
    // Set GPIO Pin 4 direction to out
    fd = open("/sys/class/gpio/gpio4/direction", O_WRONLY);
    if (fd < 0) {
        perror("Error setting direction of GPIO 4\n");
        return 2;
    }
    sprintf(buffer, "out");
    write(fd, buffer, strlen(buffer)); 
    close(fd);    

    // Enable GPIO Pin 17 and set to out
    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
        perror("Error enabling GPIO 17\n");
        return 3; 
    }
    sprintf(buffer, "17");
    write(fd, buffer, strlen(buffer));
    close(fd);

    // Set GPIO Pin 17 direction to out
    fd = open("/sys/class/gpio/gpio17/direction", O_WRONLY);
    if (fd < 0) {
        perror("Error setting direction of GPIO 17\n");
        return 4;
    }
    sprintf(buffer, "out");
    write(fd, buffer, strlen(buffer)); 
    close(fd); 
    
    // Enable line (GPIO 4) is active low, set high
    pin_high(fd, ENABLE_PIN); 

    // Set Morse encode line (GPIO 17) to low
    pin_low(fd, BPSK_PIN); 
    /* Completed GPIO Set Up ----------------------------------------------------*/

    /* Encoding Process */ 
    // Set Enable Low (1 morse time unit) 
    pin_low(fd, ENABLE_PIN); 
    printf("ENABLE SET LOW\n");
    usleep(MORSE_TIME_UNIT);

    // Encode preamble
    sum += bpsk_encode(fd, preamble);
    
    // Encode input
    char *str = argv[1];
    for (i = 0; i < strlen(str); i++) {
        // Each encoding can be accessed using list[(int)str[i]] 
        sum += bpsk_encode(fd, list[(int)toupper(str[i])]);
        // Encode three Morse time units between characters (not at the end, however)
        if ((i != (strlen(str) - 1)) && (str[i + 1] != ' ') && (str[i] != ' ')) {
            bpsk_encode(fd, three_units);
        } 
    }

    // Finish it off with the 0, checksum, and newline 
    bpsk_encode(fd, one_unit);
    checksum.bin = ~sum; 
    checksum.len = 8;
    bpsk_encode(fd, checksum);
    printf("\n");

    // Return BPSK_Pin to low
    pin_low(fd, BPSK_PIN);

    // Set Enable High (Encoding complete)
    usleep(MORSE_TIME_UNIT);
    pin_high(fd, ENABLE_PIN); 
    printf("ENABLE SET HIGH\n");
    /* Encoding complete */ 

    return 0; 
}

// Function sets the given GPIO pin high 
void pin_high(int fd, const int pin)
{
   char buf[10];
   char path[30];

   snprintf(path, 30, "/sys/class/gpio/gpio%d/value", pin);
   fd = open(path, O_WRONLY);
   if (fd < 0) {
       printf("Error setting pin %d high.\n", pin);
       return;
   }
   sprintf(buf, "1");
   write(fd, buf, strlen(buf)); 
   close(fd); 
}

// Function sets the given GPIO pin low
void pin_low(int fd, const int pin)
{
   char buf[10];
   char path[30];

   snprintf(path, 30, "/sys/class/gpio/gpio%d/value", pin);
   fd = open(path, O_WRONLY);
   if (fd < 0) {
       printf("Error setting pin %d low.\n", pin);
       return;
   }
   sprintf(buf, "0");
   write(fd, buf, strlen(buf)); 
   close(fd); 
}

// Function encodes a character and returns the number of '1's encoded (used for the checksum)
int bpsk_encode(int fd, const struct morse_s x) 
{
    // Track phase and last value (0 or 1) 
    // Phase 0 -> low to high, Phase 1 -> high to low
    int i, cur_val, mask = 0b1, ones = 0;
    static int phase = 0;

    for (i = 0; i < x.len; i++) {
        // Get current value 
        if ((x.bin & mask) == 0) {
            cur_val = 0;
        } else {
            cur_val = 1;
            ones++;
        }

        // If current value is 1, toggle phase 
        if (cur_val == 1) {
            phase ^= 1; 
        }

        // Print based on phase
        if (phase == 0) {
            // Go low
            pin_low(fd, BPSK_PIN); 
            printf("_");
            usleep(MORSE_TIME_UNIT / 2);
            // Go high
            pin_high(fd, BPSK_PIN);
            printf("-");
            usleep(MORSE_TIME_UNIT / 2); 
        } else if (phase == 1) {
            // Go high
            pin_high(fd, BPSK_PIN);
            printf("-");
            usleep(MORSE_TIME_UNIT / 2); 
            // Go low
            pin_low(fd, BPSK_PIN);
            printf("_");
            usleep(MORSE_TIME_UNIT / 2); 
        }
        // Shift mask
        mask <<= 1; 
    }

    // Completed character encoding
    return ones;
}
