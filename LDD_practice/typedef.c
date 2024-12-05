#include<stdio.h>
typedef int (*fp)(int,int);
int add(int x,int y)
{
	return x*y;
}
int sub(int x,int y)
{
	return x-y;
}
int cal(int x,int y,fp callback)
{
	return (callback(x,y));
}
//int (*fp)(int,int);
int main()
{
	printf("%d\n",cal(2,3,add));
	return 0;
}
