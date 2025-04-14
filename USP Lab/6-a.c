//6.a) Write a C program to demonstrate the usage of umask and chmod functions.

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    umask(0022);  // Set umask so files are created with 644 permissions by default

    int file = open("demo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    close(file);
  
    chmod("demo.txt", 0704);  // Change permissions to 704 explicitly

    printf("File 'demo.txt' created with umask, then chmod changed it to 704.\n");

    return 0;
}     
