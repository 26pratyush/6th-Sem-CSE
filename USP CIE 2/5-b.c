//5-b) Write a C program using sigaction system call which calls a signal
//handler on SIGINT signal and then reset the default action of the
//SIGINT signal.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("\ncaught sigint %d\n", sig);

    struct sigaction sa = {0};
    sa.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa, NULL);  // Reset to default
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        printf("press CTRL+C to trigger\n");
        pause();
    }

    return 0;
}

gcc sigreset.c           
./a.out                 
//Press CTRL+C once: custom message is printed
//Press CTRL+C again: program terminates (default behavior restored)

