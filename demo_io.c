#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    //umask
    umask(0000);

    char str[10];
    //open
    int fd = open("file.txt",O_CREAT|O_RDONLY,0666);
    if(fd ==-1)
    {
        perror("file open error!\n");
        exit(1);
    }
    else
    {
        memset(str,0,10);
        //read from file.txt
        int ret =  read(fd,str,10);
        if(ret == -1)
        {
            printf("file read error!\n");
            exit(1);
        }
        else{
            printf("str len = %d",(int)strlen(str));
            puts(str);
       }
       //close file.txt
       close(fd);
    
    }
    return 0;

}
