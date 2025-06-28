//3.b) Write a C program to implement ls  –li command which lists the files in a specified directory.
//Your program should Print 5 attributes of files.

#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>

int main()
{
        DIR *directory=opendir(".");
        struct dirent *entry;
        struct stat st;

        printf("Size\tLinks\tAccess Time\tInode Num\tFile Name\n");

        while((entry=readdir(directory))!=NULL){
                stat(entry->d_name, &st);
                printf("%ld\t %ld\t %ld\t %ld\t\t %s\n",
                                st.st_size,
                                st.st_nlink,
                                st.st_atime,
                                st.st_ino,
                                entry->d_name
                      );
        }

        closedir(directory);
        return 0;
}
