#include<stdio.h>
#include<stdlib.h>
// function to compare two integers for ascending order
int asc(int a,int b)
{
	return a-b;
}
// Function to compare two integers for descending order
int dec(int a,int b)
{
	return b-a;
}
// function to sort an array using a comparison function 
int sort(int a[],int n,int(*ptr)(int,int))
{
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(ptr(a[i],a[j])>0)
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	return 0;
}
int main()
{
	int n;
	printf("enter array size:");
	scanf("%d",&n);
	int a[n];
	printf("enter array elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,n,asc);
	printf("Sorted in ascending order:");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	sort(a,n,dec);
	printf("Sorted in decending order:");
        for(int i=0;i<n;i++)
                printf("%d ",a[i]);
	printf("\n");
	return 0;
}

