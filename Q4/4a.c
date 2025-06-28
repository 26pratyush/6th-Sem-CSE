//4-a) Write a C program to demonstrate the creation of soft links and hard links.

#include<stdio.h>
int main(){

        if( link("test1.txt","hardlink.txt")==0 ){
                printf("Hard Link Created Sucessfully\n");
        }
        else{
                perror("Error creating Soft Link\n");
        }

        if( symlink("test.txt","symlink.txt")==0 ){
                printf("Soft Link Created Successfully\n");
        }
        else{
                perror("Error creating Soft Link\n");
        }

        return 0;
}

/*Use ls -l command to confirm creation.
Hardlink has same inode/file number as test.txt and softlink -> test.txt */


