//6.b) Consider the last 100 bytes as a region. Write a C program to check whether the region is locked or not. 
//If the region is locked, print pid of the process which has locked. 
//If the region is not locked, lock the region with an exclusive lock, read the last 50 bytes and unlock the region.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./a.out filename.txt\n");
        return 1;
    }

    int file = open(argv[1], O_RDWR);

    printf("My PID: %d\n", getpid());  // Helpful for debugging

    struct flock lock = {
        .l_type = F_WRLCK,
        .l_whence = SEEK_END,
        .l_start = -100,
        .l_len = 100
    };

    printf("Press ENTER to check if region is locked and try locking it...\n");
    getchar();

    // Get lock properties / info
    fcntl(file, F_GETLK, &lock);

    if (lock.l_type != F_UNLCK) {                                        //if file is not unlocked
        printf("Region is already locked by PID: %d\n", lock.l_pid);
        close(file);
        return 0;                                                        //program exits
    }

    lock.l_type = F_WRLCK;                //if file is unlocked, we set the lock
    fcntl(file, F_SETLK, &lock);
    printf("Region locked.\n");

    char buf[100];                        //read last 50 bytes
    lseek(file, -50, SEEK_END);
    read(file, buf, 50);
    buf[50]='\0';
    printf("Last 50 bytes of file are: %s\n", buf);

    printf("Press ENTER to unlock:\n");
    getchar();

    lock.l_type = F_UNLCK;                //unlocking the file
    fcntl(file, F_SETLK, &lock);

    printf("Region Unlocked.\n");
    close(file);
    return 0;
}

//Make test.txt with atleast 2 lines of text.

/*How to Test (Two Terminals):

Terminal 1:
gcc 6b.c -o locktest
./lock_check test.txt
Output from terminal 1:
My PID: 41670
Press ENTER to check if region is locked and try locking it...        //press Enter once
Region locked.
Last 50 bytes of file are:  ipsum varius vulputate a vitae lectus.

Terminal 2
go to same directory:
./lock_check test.txt
Output from terminal 2:
My PID: 41850
Press ENTER to check if region is locked and try locking it...        //press Enter once
Region is already locked by PID: 41670

Now go back to Terminal 1
Output from terminal 1:
Press ENTER to unlock:                                                //press Enter once
Region Unlocked.

First process to run will lock the region and display the last 50 bytes.
Second process will detect the lock and print the PID of the locker.*/
