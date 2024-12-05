#include<stdio.h>
#include<stdlib.h>
int add(int a,int b)
{
        int c=a+b;
        return c;
}
int sub(int a,int b)
{
        int c=a-b;
        return c;
}
int mul(int x,int y)
{
        int z=x*y;
        return z;
}
void fun(int (*ptr)(int,int),int a,int b)
{
	printf("%d\n",ptr(a,b));
}
void main(int argc,char *argv[])
{
	int a,b;
	printf("enter a and b values:");
	scanf("%d %d",&a,&b);
	char c=*argv[1];
	if(c=='+')
		fun(add,a,b);
	else if(c=='-')
		fun(sub,a,b);
	else if(c=='*')
		fun(mul,a,b);
}
