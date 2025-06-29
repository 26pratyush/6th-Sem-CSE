//7.b) C program to simulate copy command by accepting the filenames
//from the command line. Report all errors. (3 errors included).

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
        if(argc<3)
                printf("Usage: ./a.out src.txt dest.txt\n");

        int src=open(argv[1],O_RDONLY);
        if(src<0)
                printf("Error: Cannot open source");

        int dest=open(argv[2],O_WRONLY | O_TRUNC, 0644);
        if(dest<0)
                printf("Error: Cannot open dest");

        char buf[100];
        int n;

        while((n=read(src,buf,50))>0)
                write(dest, buf, n);

        printf("Copied Successfully");
        close(src);
        close(dest);
        return 0;
}

gcc 7b.c
./a.out src.txt dest.txt  //Put some text in source & it will get copied to dest
