//2.b) Write a C program to simulate system function. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int my_sys(const char *cmd) {
    if (!cmd) return -1;

    pid_t pid = fork();
    if (pid == 0) {
        execl("/bin/sh", "sh", "-c", cmd, (char *)NULL);
        exit(1);
    }

    int status;
    if (pid > 0 && waitpid(pid, &status, 0) != -1 && WIFEXITED(status))
        return WEXITSTATUS(status);

    return -1;
}

int main() {
    int res = my_sys("ls -li");
    printf("Exit status: %d\n", res);
    return 0;
}

//Removed all error handling and messages

