//2.b) Write a C program to simulate system function. 

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int my_sys(const char *cmd)
{
    if (!cmd)
        return -1;

    pid_t childpid = fork();

    if (childpid == 0) {
        execl("/bin/sh", "sh", "-c", cmd, (char *)NULL);
        perror("execl failed");
        exit(1);
    }

    int exit_status;
    waitpid(childpid, &exit_status, 0);

    if (WIFEXITED(exit_status))
        return WEXITSTATUS(exit_status);

    return -1;
}

int main(){
        const char *cmd="ls -li";
        int res=my_sys(cmd);
        printf("Exit Status: %d\n", res);
        return 0;
}

// The child process uses execl() to run a shell: /bin/sh and pass cmd to it via the -c option. "sh" is argv[0] and can be anything.
// The parent process waits for the child to finish. The status of the child process is stored in exit_status.
// WIFEXITED(status) checks if the child exited normally (not killed by signal).
// WEXITSTATUS(status) extracts the actual exit code from the child process (e.g., 0 = success).
