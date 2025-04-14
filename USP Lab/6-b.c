//6.b) Write a C program
//i.	To read the first 20 characters from a file
//ii.	Seek to 10th byte from the beginning and display 20 characters from there 
//iii.	Seek 10 bytes ahead from the current file offset and display 20 characters
//iv.	Display the file size             

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int file = open("test.txt", O_RDONLY);

    char buf[21]; // 20 chars + null terminator

    read(file, buf, 20);           // i. Read first 20 characters
    buf[20] = '\0';
    printf("First 20 chars     : %s\n", buf);

    lseek(file, 10, SEEK_SET);     // ii. Seek to 10th byte and read 20 characters
    read(file, buf, 20);
    buf[20] = '\0';
    printf("From 10th byte     : %s\n", buf);

    lseek(file, 10, SEEK_CUR);     // iii. Seek 10 bytes ahead from current and read 20 characters
    read(file, buf, 20);
    buf[20] = '\0';
    printf("10 bytes ahead     : %s\n", buf);

    struct stat st;                // iv. Get and print file size
    stat(file, &st);
    printf("File size          : %ld bytes\n", st.st_size);

    close(file);
    return 0;
}
