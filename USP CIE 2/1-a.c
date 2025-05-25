//1.a) Write a C program to display the file content in reverse order using lseek system call.

#include <fcntl.h>
#include <unistd.h>

int main() {
    int file = open("test.txt", O_RDONLY);    	        // Open the file in read-only mode

    off_t pos = lseek(file, 0, SEEK_END);          	// Move to end to get file size
    char c;

    while (pos-- > 0) {                          	// Loop from end of file to start
        lseek(file, pos, SEEK_SET);                	// Move to byte position i
        read(file, &c, 1);                       	// Read one character
        write(1, &c, 1);                     		// Write it to stdout (1 = STDOUT)
    }

    close(file);                                 	// Close the file
    return 0;                                  		// Exit
}
