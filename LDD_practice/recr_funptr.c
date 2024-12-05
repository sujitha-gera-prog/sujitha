#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fact(int num,int x)
{
        if(num==0 || num==1)
                return 1;
        else
                return num*fact(num-1,0);
}
int fib(int n,int x)
{
        if(n<=1)
                return n;
        else
                return fib(n-1,0)+fib(n-2,0);
}
int pwr(int x,int n)
{
        if(n!=0)
                return x*(pwr(x,n-1));
        else
                return 1;
}

int main(int argc,char *argv[])
{
	int (*ptr[3])(int,int)={fact,fib,pwr};
	char *ch=argv[1];
	int a;
	printf("enter a value:");
	if(strcmp(ch,"fact")==0)//comparing ch will command line arguments
	{
		scanf("%d",&a);
		printf("%d\n",ptr[0](a,0));
	}
	else if(strcmp(ch,"fib")==0)
	{
		scanf("%d",&a);
                printf("%d\n",ptr[1](a,0));
	}
	else if(strcmp(ch,"pwr")==0)
	{
		scanf("%d",&a);
		int b;
		printf("enter b values:");
		scanf("%d",&b);
                printf("%d\n",ptr[2](a,b));
	}
	return 0;
}
