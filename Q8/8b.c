//8.b) Write a C program to perform the following operations
//i. To create a child process
//ii. The child process should execute a program (using exec( )) to show the use of the access function
//iii. The parent process should wait for the child process to exit
//iv. Also print the necessary process IDs

//main.c
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
        pid_t pid=fork();

        if(pid==0)
        {
                printf("Child process created. PID: %d\n", getpid());
                execl("./p1", "p1", "example.txt", (char *)NULL );
        }
        else
        {
                printf("Parent process. PID: %d\n", getpid());
                wait(NULL);
                printf("Child process exited. PID: %d\n", pid);
        }
        return 0;
}

//p1.c
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
        if(access(argv[1], F_OK)==0 )
                printf("File exists.\n");
            
        else
                printf("File doesn't exist.\n");
    
        return 0;
}

create example.txt with one line text!

/* To run:
gcc -o p1 p1.c
gcc -o main main.c
./main

Working:
main.c:
Creates a child process using fork().
Child uses execl() to run p1 and checks if a file exists using access().
Parent waits for the child using wait(NULL).
Both print their process IDs.

p1.c:
Takes a filename from argv[1].
Uses access(filename, F_OK) to check if the file exists.The access() function in C is used to check a file's accessibility (not to open it). 
It lets a program determine if it can read, write, or execute a file, or whether the file exists.
Prints result. */
