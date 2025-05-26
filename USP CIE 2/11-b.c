/*11.b) Write a program to perform the following operations:
i) To create a child process.
ii)The child process should execute a separate program (using exec() function) that calculates 
the addition of two numbers by passing two integer values.
iii) Parent process should wait for the child to complete.*/

1.//main.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s num1 num2\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        execl("./p23", "p23", argv[1], argv[2], NULL);
        exit(1);  // Only reached if execl fails
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
    return 0;
}

2.//child.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) return 1;

    int sum = atoi(argv[1]) + atoi(argv[2]);
    printf("Sum: %d\n", sum);
    return 0;
}

//To run:
cc -o main main.c
cc -o child child.c
./main 5 6
