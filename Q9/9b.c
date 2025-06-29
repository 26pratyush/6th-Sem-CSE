//9.b) Write a C program
//i.	To read the first 20 characters from a file
//ii.	Seek to 10th byte from the beginning and display 20 characters from there 
//iii.	Seek 10 bytes ahead from the current file offset and display 20 characters
//iv.	Display the file size             

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
        int file=open("test.txt", O_RDONLY);

        char buf[21];                                            //20 + null terminator

        read(file, buf, 20);                                     //First 20 chars
        buf[20]='\0';
        printf("First 20 chars: %s\n", buf);

        lseek(file, 10, SEEK_SET);                               //After 10 bytes from start
        read(file, buf, 20);
        buf[20]='\0';
        printf("After 10 bytes from beginning: %s\n", buf);

        lseek(file, 10, SEEK_CUR);                               //After 10 bytes from current file offset
        read(file, buf, 20);
        buf[20]='\0';
        printf("After 10 bytes from file offset: %s\n", buf);

        struct stat st;
        stat(file, &st);
        printf("File Size: %d\n", st.st_size);                   //File size

        close(file);
        return 0;
}

//Have a test.txt file with atleast 2 lines of text.
