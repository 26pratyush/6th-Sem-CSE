//4-b) Write a program to read n characters from a file and append them back to the same file using dup2 function.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int file = open("test.txt", O_RDWR);

    char buf[10];  				            // buffer to read up to 10 characters
    int n = read(file, buf, 5);  			// read up to 5 characters

    buf[n] = '\0';  				        // null-terminate the string

    lseek(file, 0, SEEK_END);  		        // move file offset to end

    dup2(file, STDOUT_FILENO);  		    // redirect stdout to file

    printf("%s", buf);  			        // this goes to the file, not the terminal

    close(file);
    return 0;
}
