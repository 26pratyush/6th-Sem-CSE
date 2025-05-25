//10-a) Write a C program such that it initializes itself as a Daemon Process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/stat.h>

void create_daemon() {
    if (fork() > 0) exit(0);          // Parent exits
    setsid();                         // Create new session
    umask(0);                         // Reset file mode mask
    chdir("/");                       // Change working directory
    close(STDIN_FILENO);              // Close standard file descriptors
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    open("/dev/null", O_RDONLY);      // Redirect stdin
    open("/dev/null", O_WRONLY);      // Redirect stdout
    open("/dev/null", O_RDWR);        // Redirect stderr
}

int main() {
    create_daemon();
    openlog("daemon_ex", LOG_PID, LOG_DAEMON);
    while (1) {
        syslog(LOG_NOTICE, "Daemon is running...");
        sleep(30);
    }
    closelog();
    return 0;
}

//To Execute
gcc zombie.c
./a.out
ps aux                    (question mark depicts a daemon process)
tail -f /var/log/syslog   (optional to print log statement)
