//8.b) Write a C program to perform the following operations
//i. To create a child process
//ii. The child process should execute a program (using exec( )) to show the use of the access function
//iii. The parent process should wait for the child process to exit
//iv. Also print the necessary process IDs

//main.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child (PID: %d)\n", getpid());
        execl("./p1", "p1", "example.txt", NULL);
    } else {
        printf("Parent (PID: %d)\n", getpid());
        wait(NULL);
        printf("Child (PID: %d) exited\n", pid);
    }

    return 0;
}

//p1.c
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (access(argv[1], F_OK) == 0)
        printf("File '%s' exists.\n", argv[1]);
    else
        printf("File '%s' does not exist.\n", argv[1]);

    return 0;
}

create example.txt with one line text!!

//To run:
cc -o p1 p1.c
cc -o main main.c
./main

