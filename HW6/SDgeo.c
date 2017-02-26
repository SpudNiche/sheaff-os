// Author: Nicholas LaJoie
// ECE 331 - Homework 6 
// February 26, 2017
// Description: C program that prints the geometry of an SD cad using HDIO_GETGEO
// Sources: 

#include <stdio.h>
#include <linux/hdreg.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[]) 
{
   struct hd_geometry geo; 
   int fd, result; 

   // Open SD card partition file 
   fd = open("/dev/mmcblk0p2", O_RDONLY); 
   if (fd < 0) {
       perror("Error getting file descriptor to SD card.\n"); 
       return 1; 
   }

   // Get geometry of sd card 
   result = ioctl(fd, HDIO_GETGEO, &geo);
   if (result == -1) {
       perror("Error calling HDIO_GETGEO.\n");
       return 2;
   }

   // Print geometry of sd card 
   printf("Heads: %u\nSectors: %u\nCylinders: %hu\nStart: %lu\n", geo.heads, geo.sectors, geo.cylinders, geo.start);

   return 0; 
}  
