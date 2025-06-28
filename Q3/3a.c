//3.a) Write a C program to remove empty files from the given directory.

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>

int main()

{
        DIR *directory=opendir(".");
        struct dirent *entry;
        int file_desc;

        if(directory)                                                      //if valid directory
        {
                while((entry=readdir(directory))!=NULL)                    //as long as files remain
                {
                        file_desc=open(entry->d_name, O_RDONLY);           //open each
                        if(file_desc!=1)                                   //if they open correctly 
                        {
                                if(lseek(file_desc,0,SEEK_END)==0)         //if file length==0
                                {
                                        unlink(entry->d_name);             //remove
                                }
                                close(file_desc);
                        }
                }
        }
        return 0;
}
