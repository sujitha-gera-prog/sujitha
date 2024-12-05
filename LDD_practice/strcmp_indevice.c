#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fd=open("/dev/simple_device",O_RDWR);
	if(fd==-1)
		printf("open failed\n");
	static int num1,num2;
	static int knum1,knum2;
	printf("enter num1 and num2 values:");
	scanf("%d %d",&num1,&num2);
//	char str[10];
//	printf("enter string:");
//	scanf("%s",str);
	int w1=write(fd,&num1,sizeof(int));
	if(w1==-1)
		printf("w1 failed\n");
	int w2=write(fd,&num2,sizeof(int));
	if(w2==-1)
		printf("w2 failed\n");
//	int w3=write(fd,str,strlen(str));
//	if(w3==-1)
  //              printf("w3 failed\n");
	read(fd1,&knum1,sizeof(int));
	printf("knum1=%d\n",knum1);
	read(fd1,&knum2,sizeof(int));
        printf("knum1=%d\n",knum2);
	close(fd);
	return 0;
}
