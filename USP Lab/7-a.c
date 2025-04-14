//7.a) Demonstrate the working of wait and waitpid system calls with a program
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t c1 = fork();

    if (c1 == 0) {
        printf("Child 1 (PID %d) running...\n", getpid());
        sleep(1);
        return 1;  // Child 1 exits
    }

    pid_t c2 = fork();

    if (c2 == 0) {
        printf("Child 2 (PID %d) running...\n", getpid());
        sleep(2);
        return 2;  // Child 2 exits
    }

    int status;

    wait(&status);  					// Wait for any child
    printf("wait: Child exited with status %d\n", WEXITSTATUS(status));

    waitpid(c2, &status, 0);  				// Wait specifically for child 2
    printf("waitpid: Child 2 exited with status %d\n", WEXITSTATUS(status));

    return 0;
}
