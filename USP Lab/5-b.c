//5.b) Write a program to differentiate between dup and dup2 functions

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>   

int main() {   
    int file = open("test.txt", O_WRONLY | O_TRUNC);    //Assuming blank file test.txt already created 
                                                                                                                                                                                                                                                       
    int dup_file = dup(file);        // Using dup() - Duplicates the file descriptor (gets the smallest available file)

    write(dup_file, "Written using dup()\n", 20); 
    close(dup_file);

    int dup2_file = dup2(file, 3);  // Using dup2() - Duplicates the file desc and explicitly specifies the target (file 3)

    write(dup2_file, "Written using dup2()\n", 20);  
    close(dup2_file);

    close(file);

    return 0;
}           
