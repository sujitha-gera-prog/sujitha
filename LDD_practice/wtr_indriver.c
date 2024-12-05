#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
int main()
{
	int fd=open("/dev/simple_device",O_RDWR);
	if(fd==-1)
		printf("failed to open fail\n");
	char str[100];
	printf("enter the msg:");
	scanf("%[^\n]s",str);
	write(fd,str,strlen(str));
	char buff;
	int res=read(fd,&buff,1);
	while(res!=0)
	{
		write(1,&buff,1);
		res=read(fd,&buff,1);
	}
	printf("\n");
	close(fd);
	return 0;
}
