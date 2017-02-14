// Author: Nicholas LaJoie
// ECE 331 - Homework 4
// Date: February 10, 2017
// File: x_strstr.c
// Description: Implementation of the x_strstr() function.

#include <stdio.h>
#include "x_strstr.h"

char *x_strstr(const char *haystack, const char *needle)
{
    int i = 0, j = 0, nlen = 0, hlen = 0;
 
    // If arguments are NULL or the haystack is empty, return NULL
    if (haystack == NULL || needle == NULL) {
        return NULL;
    } else if (haystack[0] == '\0') {
        return NULL;
    } else if (needle[0] == '\0') {
        return (char *) haystack; // Return entire haystack if needle is ""
    }
    // Get length of needle 
    while (needle[nlen] != '\0') {
        nlen++; 
    }
    // Get length of haystack 
    while (haystack[hlen] != '\0') {
        hlen++;
    }
    // Find first instance of needle within the haystack 
    while (i < hlen) {
        if (haystack[i] == needle[j]) {
           if (j == nlen - 1) {
               return (char *) &haystack[i - nlen + 1]; 
           } else {
               j++;
           }
        } else {
            j = 0; 
        }
        i++;
    }
    return NULL; 
}
