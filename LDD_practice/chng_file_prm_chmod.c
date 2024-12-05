#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	struct stat file_stat;
	int res=stat("file",&file_stat);
	if(res==-1)
		printf("file can't be accessed\n");
	printf("file permisions before change: ");
	printf("%o\n",file_stat.st_mode & 0777);
	res=chmod("file",0666);
	if(res==-1)
		printf("chmod failed\n");
	if(stat("file",&file_stat)==-1)
		printf("file can't be accessed\n");
	printf("file permisions after change: ");
	printf("%o\n",file_stat.st_mode & 0777);
	return 0;
}
