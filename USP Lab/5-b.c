//5.b) Write a program to differentiate between dup and dup2 functions

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>   
#include<string.h>

int main() {   
    int file = open("test.txt", O_WRONLY | O_TRUNC);    //Assuming blank file test.txt already created 
                                                                                                                                                                                                                                                       
    int dfile = dup(file);        // Using dup() - Duplicates the file descriptor (gets the smallest available file)

    char text[]="written using dup";
    write(dfile, text, strlen(text));
    close(dfile);

    int d2file = dup2(file, 3);  // Using dup2() - Duplicates the file desc and explicitly specifies the target (file 3)

    char text1[]="written using dup2";
    write(d2file, text1, strlen(text1)); 
    close(d2file);

    close(file);

    return 0;
}           
