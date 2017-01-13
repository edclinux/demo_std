#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    umask(0000);

    char str[10];

    int fd = open("file.txt",O_CREAT|O_RDONLY,0666);
    if(fd ==-1)
    {
        perror("file open error!\n");
        exit(1);
    }
    else
    {
        memset(str,0,10);
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

       close(fd);
    
    }
    return 0;

}
