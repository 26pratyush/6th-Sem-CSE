//10-a) Write a C program such that it initializes itself as a Daemon Process.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<syslog.h>
#include<sys/stat.h>

void create_daemon()
{
        if(fork()>0)
                exit(0);

        setsid();
        umask(0);
        chdir("/");

        int fd=open("/dev/null", O_RDWR);
        if(fd!=-1)
        {
                dup2(fd, STDIN_FILENO);
                dup2(fd, STDOUT_FILENO);
                dup2(fd, STDERR_FILENO);
                if(fd>2)
                        close(fd);
        }
}

int main()
{
        create_daemon();
        openlog("daemon", LOG_PID, LOG_DAEMON);
    
        while(1)
        {
                syslog(LOG_NOTICE, "Daemon is running...");
                sleep(15);
        }
    
        closelog();
        return 0;
}

/* To Run:
gcc 10a.c -o daemon             //Compile the daemon program
./daemon &                      //Run the daemon in the background
ps aux | grep daemon            //Verify that the daemon is running: Look for '?' in TTY / 7th column
pgrep daemon                    //(Optional) Get only the PID of the daemon
sudo tail -f /var/log/syslog    //View log messages in real-time (you'll see "Daemon is running...")
sudo pkill daemon               //Kill the daemon process
ps aux | grep daemon            //This time the same pid and "?" should not be present */


