#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
int main()
{
	int fd;
	fd=open("suji.txt",O_WRONLY | O_CREAT);
	char str[]="hello world";
	write(fd,str,strlen(str));
	close(fd);
	fd=open("suji.txt",O_RDONLY);
	read(fd,str,100);
	write(1,str,strlen(str));
	return 0;
}
