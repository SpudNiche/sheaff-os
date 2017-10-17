#!/usr/bin/perl
# Author: Nicholas LaJoie
# ECE 331 - Homework 5, Problem 2 - Version2
# Date: February 20, 2017
# File: morse_encode.pl
# Description: Perl script converts ASCII Morse data to C source and header files
# Input: morse_chars.txt
# Output: encoding.c encoding.h
# Sources: perldoc.perl.org, perlmaven.com/how-to-sort-a-hash-in-perl 

use POSIX;

# Open input file
open(IN, "morse_chars.txt") or die "Cannot open \"morse_chars.txt\", must be in the current directory.\n";

# Open output files 
open(my $outc, ">", "encoding.c") or die "Failed to create \"encoding.c\"\n";
open(my $outh, ">", "encoding.h") or die "Failed to create \"encoding.h\"\n";

# Predefined strings 
my $header_comments = "// Author: Nicholas LaJoie\n// ECE 331 - Homework 5\n// Date: February 20, 2017\n"; 

# Create encoding.h file
print $outh "$header_comments// File: encoding.h\n// Description: Header file for encoding morse code in C\n\n"; 
print $outh "#ifndef ENCODING_H\n#define ENCODING_H\n\n";
print $outh "struct morse_s {\n\tunsigned int bin;\n\tint len;\n};\n\n";
print $outh "extern struct morse_s list[256];\n";
print $outh "extern struct morse_s preamble;\n";
print $outh "extern struct morse_s three_units;\n";
print $outh "extern struct morse_s one_unit;\n\n";
print $outh "#endif\n";

# Create encoding.c file 
print $outc "$header_comments// File: encoding.c\n// Description: Implementation for encoding morse code in C\n\n";
print $outc "#include <stdio.h>\n#include \"encoding.h\"\n\n";
print $outc "struct morse_s list[256] = {\n";

# Create a hash of characters => binary encoding (in reverse)
# Matches valid input lines (<Character> <Morse Code Encoding>)
my %encoding; 
my $bin;
while (<IN>) {
    chomp; 
    if (/(^.{1})\s([\s*-]+$)/) {
        my $rev = reverse $2;
        foreach $c (split //, $rev) {
            if ($c =~ m/[*-]/) {
                $bin .= "1";
            } else {
                $bin .= "0";
            }
        }
        $encoding{$1} = "0b$bin";
        $bin = ""; 
    }
}

# Sort hash by value of char 
foreach my $char (sort (keys(%encoding))) {}

# Print to encoding.c 
# If the hash exists, encode it, else encode a 0b0 with length 0 (covers all 256 bytes) 
for (my $i = 0; $i < 256; $i++) {
    if (exists $encoding{chr($i)}) {
        print $outc "\t{$encoding{chr($i)}, " . (length($encoding{chr($i)}) - 2) . "},\n";
    } else {
        print $outc "\t{0b0, 0}";
        if ($i != 255) {
            print $outc ",\n";
        } else {
            print $outc "\n";
        }
    }
}

# Conclude struct array initialization 
print $outc "};\n\n";

# Add additional special case struct initializations
print $outc "struct morse_s preamble = {0b0100, 4};\n\n";
print $outc "struct morse_s three_units = {0b000, 3};\n\n";
print $outc "struct morse_s one_unit = {0b0, 1};\n";

# Close files
close IN;
close $outh;
close $outc;
