//1-b) Write a C program to create a child process and show how parent and child processes will share the text file 
//and justify that both parent and child share the same file offset. 

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h> 

int main() {
    int fd = open("test.txt", O_RDONLY);     	        // Open file in read-only mode
    char buf[21];                            			// Buffer for reading

    if (fork() == 0) 
   {                       					// Child process
        read(fd, buf, 5);                    			// Read first 5 bytes
        buf[5] = '\0';
        printf("Child read: %s\n", buf);
    } 
     else 
   {                                 				// Parent process
        wait(NULL);                          			// Wait for child to finish
        read(fd, buf, 7);                    			// Read next 7 bytes (shared offset)
        buf[7] = '\0';
        printf("Parent read: %s\n", buf);
    }

    return 0;
}


