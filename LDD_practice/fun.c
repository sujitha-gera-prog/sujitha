#include<stdio.h>
#include<stdlib.h>
int add(int,int);
int main(int argc,char *argv[])
{
	int a,b;
	printf("enter a and b values:");
	scanf("%d %d",&a,&b);
		int r=add(a,b);
		printf("%d\n",r);
		return 0;
}
