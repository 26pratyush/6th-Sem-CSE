Total set of imports to be made:

#include <stdio.h>
For standard input/output functions like printf(), perror(), fopen(), etc.

#include <unistd.h>
For system calls like fork(), read(), write(), close(), lseek(), sleep(), dup(), dup2().

#include <fcntl.h>
For file control options like O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC.

#include <sys/stat.h>
For stat structure and file type/mode macros like S_ISREG, S_ISDIR, etc.

#include <sys/wait.h>
For wait(), waitpid(), and macros like WEXITSTATUS().

#include <dirent.h>
For directory operations like opendir(), readdir(), closedir().

#include <utime.h>
For utime() function and struct utimbuf.
