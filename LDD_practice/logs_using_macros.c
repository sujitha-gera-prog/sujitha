// log messages into a log file using both system calls and libc APIs 
#include<stdio.h>//for printf() and scanf()
#include<stdlib.h>//for exit()
#include<unistd.h>//for open(), write() and close()
#include<fcntl.h>//for file control functions like open()
#include<string.h>//for string manipulations like strlen()
#define DATE __DATE__ //macro to get current DATE at compile time
#define TIME __TIME__ //macro to get current TIME at compile time
#define FIL __FILE__ //macro to get current FILE NAME at compile time
#define LINE __LINE__ //macro to get current LINE NUMBER at compile time
#define func __func__ // to get FUNCTION NAME

//function to log msg using system calls (low level I/O)
void systemcall(const char *msg)
{
	int fd=open("log.txt",O_WRONLY | O_CREAT);
	if(fd==-1)
		printf("failed to open file\n");
	char str[200];
	snprintf(str,sizeof(str),"DATE:%s\nTIME:%s\nFILE:%s\nLINE:%d\nFUNC_NAME:%s\n",DATE,TIME,FIL,LINE,func);
//	write(fd,DATE,strlen(DATE));
//	write(fd,TIME,strlen(TIME));
//	write(fd,FIL,strlen(FIL));
//	write(fd,LINE,sizeof(LINE));
//	write(fd,func,strlen(func));
	write(fd,str,strlen(str));//writing the formatted log information(date,time,file,line and function name) into file
	write(fd,msg,strlen(msg));//wrting user msg into file
	close(fd);//closing the after writing
	printf("msg logged using system call\n");
}

//function to log msg using lib_API (high level I/O)
void lib_API(const char *msg)
{
	FILE *fd;
	fd=fopen("log.txt","a");//opening log.txt in append mode
	char str[500];
        snprintf(str,sizeof(str),"\nDATE:%s\nTIME:%s\nFILE:%s\nLINE:%d\nFUNC_NAME:%s\n",DATE,TIME,FIL,LINE,func);
	fprintf(fd,"%s",str);//writing the formatted log information to file
	fprintf(fd,"%s",msg);//writng the user msg to file
	fclose(fd);//closing the file after writing
	printf("msg logged using lib API's\n");
}

int main()
{
	char msg[100];//array to take user input
	printf("enter message to log:");
	scanf("%[^\n]s",msg);
	int choice;
	printf("choose login method \n 1.system calls \n 2.Lib API's\n");
	scanf("%d",&choice);//choice for to choose log type
	switch(choice)
	{
		case 1:
			systemcall(msg);//calling systemcall function to log msg
			break;
		case 2:
			lib_API(msg);//calling lib_API function to log msg
			break;
	}
	return 0;
}
