//10.b) Demonstrate the working of wait and waitpid system calls with a program.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t c1 = fork();

    if (c1 == 0) {
        printf("Child 1 (PID %d) running...\n", getpid());
        sleep(1);
        return 1;  // Exit with status 1
    }

    pid_t c2 = fork();

    if (c2 == 0) {
        printf("Child 2 (PID %d) running...\n", getpid());
        sleep(2);
        return 2;  // Exit with status 2
    }

    int status;

    // Wait for any one child to finish
    wait(&status);
    printf("wait: Child with PID %d exited with status %d\n",c1, WEXITSTATUS(status));

    // Wait specifically for c2
    waitpid(c2, &status, 0);
    printf("waitpid: Child 2 PID %d exited with status %d\n",c2, WEXITSTATUS(status));

    return 0;
}
