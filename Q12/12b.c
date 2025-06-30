//12-b) Write a C program to perform the following operations
//i) To create a child and parent process with the use of an echoall file.
//ii) The Child should execute a process that prints the user defined values of environment variables
//iii) The Parent should execute a process that prints default values for the environment variables.

//main.c
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
        char *env[] = {"USER=customer_user", "PATH=/custom", (char *)NULL};          // Custom environment variables for child

        pid_t pid = fork();                                                 

        if (pid == 0)                              
                execle("./echoall", "echoall", "arg1", "arg2", (char *)NULL, env);   // Execute echoall with custom env (ensure 2nd prog name is echoall.c)
                
        else {
                wait(NULL);                         
                execlp("./echoall", "echoall", "default_arg", (char *)NULL);         // Execute echoall with inherited env (if changing prog name, change this)
        }

        return 0;                                  
}


//echoall.c
#include <stdio.h> 

int main(int argc, char *argv[], char *env[])            // command-line and environment arguments
{
        for(int i = 0; i < argc; i++)                    
                printf("argv[%d]= %s\n", i, argv[i]);    // Print each argv[i]

        for(int i = 0; env[i] != NULL; i++)              
                printf("env[%d]= %s\n", i, env[i]);      // Print each environment variable

        return 0;                                        
}


//To run:
gcc -o main main.c
gcc -o echoall echoall.c
./main
