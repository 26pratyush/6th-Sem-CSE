//7.b) C program to simulate copy command by accepting the filenames
//from the command line. Report all errors. (I have not included any error messages)

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int src = open(argv[1], O_RDONLY);
    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    char buf[BUFFER_SIZE];
    ssize_t n;
    while ((n = read(src, buf, BUFFER_SIZE)) > 0)
        write(dest, buf, n);

    close(src);
    close(dest);
    return 0;
}

gcc program_name.c
./a.out src.txt dest.txt  //Put some text in source & it will get copied to dest
