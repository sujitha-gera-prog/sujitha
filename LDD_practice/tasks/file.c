#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	int fd=open("file.txt",O_RDWR|O_CREAT);
	if(fd==-1)
		printf("open failed\n");
	int w=write(fd,"hello",6);
	write(1,"hello",6);
	close(fd);
}
