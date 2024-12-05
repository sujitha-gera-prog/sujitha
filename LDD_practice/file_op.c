#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	FILE *fd=fopen("write.txt","w");
	int f=fileno(fd);
	char ch;
	write(f,"hello",5);
	fclose(fd);
	fd=fopen("write.txt","r");
	int f1=fileno(fd);
	int r=read(f1,&ch,1);
	while(r!=0)
	{
		write(1,&ch,1);
		r=read(f1,&ch,1);
	}
	return 0;
}
