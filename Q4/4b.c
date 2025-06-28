//4.b) Write a C program to
//i. To create a child process.
//ii. The child should execute an interpreter file by passing a few arguments
//iii. Create an interpreter file that has the path of echoall.c file and pass one argument
//iv. Create echoall.c file which prints the arguments received from both child process and
//interpreter file.

1. /*************** echoall.c ***************/
#include<stdio.h>

int main(int argc, char *argv[])
{
        for(int i=0; i<argc; i++)
        {
                printf(" argv[%d] = %s\n", i, argv[i]);
        }
        return 0;
}


2. /*************** inter.c ***************/
#include<sys/wait.h>
#include<unistd.h>

int main(){
        if (fork()==0)
        {
                execl("./textinterpreter", "dummy", "arg1", "arg2", "arg3", (char *)0);
        }
        else
        {
                wait(NULL);
        }
        return 0;
}

3. /*************** textinterpreter ***************/
//vi textinterpreter (Shell Script): 
    
#!/bin/bash
$(realpath ./echoall) my2 "$@"   
  

/*Instructions to Build and Run: Save each block above into its own file
echoall.c , inter.c , textinterpreter

Make the script executable:
chmod +x textinterpreter

Compile the C files:
gcc -o echoall echoall.c
gcc -o inter inter.c

Run the program:
./inter */
