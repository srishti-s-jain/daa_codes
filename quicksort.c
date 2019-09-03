#include<stdio.h>
void swap(int *x, int*y)
{
	int c=*x;
	*x=*y;
	*y=c;
}
int partition(int *a, int start,int end)
{
	int pivot=a[end];
	int pi=start;
	for(int i=start;i<=end-1;i++)
	{
		if(a[i]<=pivot)
		{
			swap(&a[pi],&a[i]);
			pi++;
		}
	}
	swap(&a[pi],&a[end]);
	return(pi);
}
void quicksort(int *a,int start,int end)
{
	if(start<end)
	{
		int p= partition(a,start,end);
		quicksort(a,start,p-1);
		quicksort(a,p+1,end);
	}
}
int main()
{
	int n;
	printf("enter the size of array");
	scanf("%d", &n);
	int a[n];
	printf("enter values in the given array");
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}	
	quicksort(a,0,n-1);
	printf("the sorted array is :");
	for(int i=0;i<=n-1;i++)
	{
		printf("%d",a[i]);
	}	
	return 0;
}