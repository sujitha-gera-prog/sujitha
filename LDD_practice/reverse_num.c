#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,n=12345;
	printf("enter value how many time you want to reverse the number:");
	scanf("%d",&a);
	int r=0;
	while(a>0)
	{
		r=r*10+n%10;
		n=n/10;
		a--;
	}
	int x=0;
	while(r>0)
	{
		x=x*10+r%10;
		r=r/10;
	}
	printf("%d",x);
	printf("%d\n",n);
	return 0;
}
