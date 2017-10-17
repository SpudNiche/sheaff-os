// Author: Nicholas LaJoie
// ECE 331 - Homework 5
// Date: February 20, 2017
// File: encoding.h
// Description: Header file for encoding morse code in C

#ifndef ENCODING_H
#define ENCODING_H

struct morse_s {
	unsigned int bin;
	int len;
};

extern struct morse_s list[256];
extern struct morse_s preamble;
extern struct morse_s three_units;
extern struct morse_s one_unit;

#endif
