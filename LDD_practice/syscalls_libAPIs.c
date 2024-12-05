// log messages into a log file using both system calls and libc APIs.
#include<stdio.h>//for functions like printf, scanf, etc
#include<stdlib.h>// for memory allocation, exit, etc.
#include<unistd.h>//for open, write, close 
#include<fcntl.h>//for file control operations like open()
#include<string.h>//for string manipulation functions like strlen

// Function to log message using system calls (low lwvwl I/O)
void systemcall(const char *msg)
{
	int fd=open("log.txt",O_WRONLY | O_CREAT);//opening log.txt file for writing
	if(fd==-1)//checking if the open is failed
		printf("failed to open file\n");
	write(fd,msg,strlen(msg));//writing the msg to the file
	close(fd);//closing the descriptor after writing
	printf("msg logged using system call\n");
}

// Function to log message using C library API (high level I/O)
void lib_API(const char *msg)
{
	FILE *fd;//declaring file pointer
	fd=fopen("log.txt","a");// open "log.txt" in append mode, to add messages at the end of the file
	fprintf(fd,"%s",msg);//writing the msg to the file
	fclose(fd);//closing the descriptor after writing
	printf("msg logged using lib API's\n");
}

int main()
{
	char msg[100];//declaring the array store user input
	printf("enter message to log:");
	scanf("%[^\n]s",msg);
	int choice;
	printf("choose login method \n 1.system calls \n 2.Lib API's\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			systemcall(msg);//calling the systemcall function to log the msg
			break;
		case 2:
			lib_API(msg);//calling the lib_API function to log the msg
			break;
	}
	return 0;
}
