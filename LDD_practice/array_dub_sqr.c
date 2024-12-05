#include<stdio.h>
#include<stdlib.h>
int dub(int n)
{
	return n+n;
}
int square(int n)
{
	return n*n;
}
int fun(int a[],int n,int(*ptr)(int))
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=ptr(a[i]);
	}
	return 0;
}
int main()
{
	int a[]={2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	printf("original array:");
        for(int i=0;i<n;i++)
                printf("%d ",a[i]);
        printf("\n");
	fun(a,n,dub);
	printf("array values after double:");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	fun(a,n,square);
	printf("array values after square:");
        for(int i=0;i<n;i++)
                printf("%d ",a[i]);
        printf("\n");
	return 0;
}
