#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int fd, ret;
    char buf[4006];

    fd=open("/sys/class/gpio/export", O_WRONLY);
    if (fd<0) {
        perror("open 1");
        return 2;
    }
    sprintf(buf,"4");
    write(fd,buf,strlen(buf));
    close(fd);

    // Set initial values 
    sleep(1);
    fd=open("/sys/class/gpio/gpio4/direction", O_WRONLY);
    if (fd <

    //
    fd=open("/sys/class/gpio/gpio4/value", O_WRONLY);
    if (
        //error

    // Enable low    
    write(fd, "0", 1);

    ret = fcntl(fileno(stdin), F_SETFL, O_NONBLOCK); // Set non-blocking 

    while (fgets(bug, 256, stdin) == NULL) {
        write(fd, "1", 1);
        usleep(500000);
        write(fd,"0",1);
        usleep(500000);
    }}
    close(fd);

    //Release pin
}}
