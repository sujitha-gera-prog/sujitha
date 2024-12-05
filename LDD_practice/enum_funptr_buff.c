#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum fun
{
	add,sub,mul,max
};

int Add(int a,int b)
{
	return a+b;
}

int Sub(int a,int b)
{
	return a-b;
}

int Mul(int a,int b)
{
	return a*b;
}
struct abc
{
	int (*ptr[max])(int,int);
};

int main(int argc,char *argv[])
{
	struct abc s;
	s.ptr[add]=Add;
	s.ptr[sub]=Sub;
    	s.ptr[mul]=Mul;
	char *ch=argv[1];
        enum fun f;
	int x,y;
	int a=atoi(argv[2]);
	int b=atoi(argv[3]);
	if (strcmp(ch,"add")==0)
      	 	f=add;
    	else if(strcmp(ch,"sub")==0) 
       		f=sub;
    	else if(strcmp(ch,"mul")==0)
        	f=mul;
	int r=s.ptr[f](a,b);
	printf("%d\n",r);
//	if(ch=="add");
//	{
//		int r=s.ptr[0]=Add(2,3);
//		printf("%d\n",r);
//	}
	return  0;
}
