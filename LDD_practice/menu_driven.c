#include<stdio.h>
#include<stdlib.h>
//function to add 2 intergers
int add(int a,int b)
{
        return a+b;
}
//function to substract 2 integers
int sub(int a,int b)
{
        return a-b;
}
//function to multiply 2 integers
int mul(int a,int b)
{
        return a*b;
}

int main()
{
	int (*fun[3])(int,int)={add,sub,mul};//array of function pointer
	while(1)// starting an infinite loop for continuous user input
	{
		int a;
		printf("enter choice:\n");
		printf("1.add\n2.sub\n3.mul\n0.exit\n");
		scanf("%d",&a); //reading user choice
		int x,y;
		if(a==0)
			break;//exit the loop and end the program
		printf("enter x and y values:");
		scanf("%d %d",&x,&y);//reading the values of x and y
		if(a==1)
			printf("sum=%d\n",fun[0](x,y));//calling the add function
		else if(a==2)
			printf("sub=%d\n",fun[1](x,y));// calling sub function 
		else if(a==3)
			printf("mul=%d\n",fun[3](x,y));// calling mul function
	}
	return 0;
}	
