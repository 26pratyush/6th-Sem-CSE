//12-b) Write a C program to perform the following operations
//i) To create a child and parent process with the use of an echoall file.
//ii) The Child should execute a process that prints the user defined values of environment variables
//iii) The Parent should execute a process that prints default values for the environment variables.

//main.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;
    char *env[] = { "USER=custom_user", "PATH=/custom", NULL };

    pid = fork();

    if (pid == 0) {
        // Child: run echoall with custom environment
        execle("./echoall", "echoall", "arg1", "arg2", NULL, env);
        exit(1);  // if execle fails
    } else {
        wait(NULL);  // Wait for child
        // Parent: run echoall with inherited environment
        execlp("./echoall", "echoall", "default_arg", NULL);
        exit(1);  // if execlp fails
    }

    return 0;
}

//echoall.c
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    for (int i = 0; i < argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);

    for (int i = 0; envp[i] != NULL; i++)
        printf("envp[%d] = %s\n", i, envp[i]);

    return 0;
}

//To run:
cc -o main main.c
cc -o echoall echoall.c
./main
