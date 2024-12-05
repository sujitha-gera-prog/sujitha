#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	int fd=open("/dev/simple_device",O_RDWR);
	if(fd==-1)
		printf("failed to open file\n");
	static int n,buff,ch;
	printf("enter number:");
	scanf("%d",&n);
	write(fd,&n,sizeof(int));
	read(fd,&buff,sizeof(int));
	buff=buff+buff;
	int fd1=open("/dev/simple_device",O_RDWR);
	if(fd1==-1)
		printf("failed to open fd1 file \n");
	int res=write(fd1,&buff,sizeof(int));
	if(res==-1)
		printf("fd1 write failed\n");
	int r=read(fd1,&ch,sizeof(int));
	if(r==-1)
			printf("fd1 read failed\n");
	printf("doubled num received from kernel space=%d\n",ch);
	close(fd);
	close(fd1);
	return 0;
}
