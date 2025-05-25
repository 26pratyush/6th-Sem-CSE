//5-a) Write a program to copy access and modification time of a file to another file using utime function.

#include <stdio.h>
#include <utime.h>
#include <sys/stat.h>

int main() {
    const char *src = "source.txt";
    const char *dest = "dest.txt";

    struct stat st;
    struct utimbuf new_times;

    stat(src, &st);

    new_times.actime = st.st_atime;   // Access time
    new_times.modtime = st.st_mtime;  // Modification time

    utime(dest, &new_times);

    printf("Timestamps copied from %s to %s\n", src, dest);
    return 0;
}

//Use ls -li to confirm.
