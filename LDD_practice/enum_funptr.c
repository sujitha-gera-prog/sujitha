#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//enum declaration
enum fun
{
	add,sub,mul,max
};
//function to add 2 intergers
int Add(int a,int b)
{
	return a+b;
}
//function to substract 2 integers
int Sub(int a,int b)
{
	return a-b;
}
//function to multiply 2 integers
int Mul(int a,int b)
{
	return a*b;
}
struct abc
{
	int (*ptr[max])(int,int); //array of function pointer
};

int main(int argc,char *argv[])
{
	struct abc s;
	s.ptr[add]=Add; //assigning Add function to funtion pointer at index 0(add)
	s.ptr[sub]=Sub; //assigning Sub function to funtion pointer at index 1(sub)
    	s.ptr[mul]=Mul; //assigning Mul function to funtion pointer at index 2(mul)
	char *ch=argv[1]; //storing the 1st command line argument in the variable ch
        enum fun f;
	int x,y;
	int a=atoi(argv[2]); // converting 2nd argument to integer
	int b=atoi(argv[3]); //converting 3rd argument to interger
	if(strcmp(ch,"add")==0)//comparing ch will command line arguments
      	 	f=add;
    	else if(strcmp(ch,"sub")==0) 
       		f=sub;
    	else if(strcmp(ch,"mul")==0)
        	f=mul;
	else
		printf("invalid argument passed\n");
	int r=s.ptr[f](a,b);//calling the function at index f using function pointer and storing the result in r
	printf("%d\n",r);
	return  0;
}
