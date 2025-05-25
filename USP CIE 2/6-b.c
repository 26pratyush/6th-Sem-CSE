//6.b) Consider the last 100 bytes as a region. Write a C program to check whether the region is locked or not. 
//If the region is locked, print pid of the process which has locked. 
//If the region is not locked, lock the region with an exclusive lock, read the last 50 bytes and unlock the region.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDWR);

    struct flock lock;
    char buf[101] = {0};

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_END;
    lock.l_start = -100;
    lock.l_len = 100;

    printf("Press Enter to try locking the last 100 bytes...\n");
    getchar();

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        fcntl(fd, F_GETLK, &lock);
        printf("Region is locked by process PID: %d\n", lock.l_pid);
        close(fd);
        return 0;
    }

    printf("Region locked.\n");

    lseek(fd, -50, SEEK_END);
    read(fd, buf, 50);
    printf("Last 50 bytes of file:\n%s\n", buf);

    printf("Press Enter to unlock...\n");
    getchar();

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    fcntl(fd, F_SETLK, &lock);
    
    printf("Region unlocked.\n");
    close(fd);
    return 0;
}

//Make test.txt with atleast 2 lines of text.

/*How to Test (Two Terminals)
Terminal 1:
cc lock_check.c -o lock_check
./lock_check test.txt

Terminal 2
./lock_check test.txt

First process to run will lock the region and display the last 50 bytes.
Second process will detect the lock and print the PID of the locker.*/
