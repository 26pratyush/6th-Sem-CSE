//6-a) Write a program to read n characters from a file and append them back to the same file using dup2 function.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
        int file=open("test.txt", O_RDWR);        

        char buf[10];

        int n=read(file,buf,5);                   //read first five bytes into buf

        buf[n]='\0';                              //null terminator

        lseek(file, 0, SEEK_END);                 //go to end of file

        dup2(file, STDOUT_FILENO);                //redirect stdout to the file      

        printf("%s", buf);                        //write onto file

        close(file);

        return 0;
}
