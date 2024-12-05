#include<stdio.h>
#include<stdlib.h>
int (*ptr)(int,int);
struct student
{
	int a;
	char b;
	int (*ptr)(int,int);
};
int add(int a,int b)
{
	return a+b;
}
int main()
{
	struct student s={1,'s',add};
//	int r=s.ptr(2,3);
	s.ptr=add;
	printf("%d\n",s.a);
	printf("%c\n",s.b);
//	printf("%d\n",r);
	printf("%d\n",s.ptr(2,3));
	return 0;
}
