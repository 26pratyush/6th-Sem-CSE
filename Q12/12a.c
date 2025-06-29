//12.a) Write a program to demonstrate the zombie state of a process and provide the solution for the same.  

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child (PID %d) exiting...\n", getpid());	
        return 0;                                            // Child exits before parent can reap
    } 
    else {
      
        // Parent sleeps to allow child to become zombie
        printf("Parent (PID %d) sleeping for 5 seconds...\n", getpid());
        sleep(1);
        printf("Zombie process created.\n");
        sleep(5);
      
        // Check ps -el | grep Z in another terminal during this time to see zombie (Z)
        // Now reaping the zombie

        wait(NULL);
        printf("Parent reaped the child.\n");
    }
    return 0;	
}
