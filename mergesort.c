#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int start, int mid, int end)
{
	int i,j,k;
	//for size of the sub arrays
	int nl=mid-start+1;
	int nr=end-mid;
	//sub arrays left and right
	int left[nl], right[nr];
	//left sub array
	for(i=0;i<nl;i++)
	{
		left[i]=a[start+i];
	}
	for(j=0;j<nr;j++)
	{
		right[j]=a[mid+1+j];
	}
	//comparing the two sub arrays
	i=0;j=0;k=start;
	while(i<nl && j<nr)
	{
		if(left[i]<= right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}k++;

	} 	
	while(i<nl)
	{
		a[k]=left[i];
		i++;
		k++;	
	}
	while(j<nr)
	{
		a[k]=right[j];
		j++;
		k++;
	}
}
void mergesort(int a[],int start, int end)
{
	if(start<end)
	{
		int mid=(start+(end-1)/2);
		//sort left and right halves
		mergesort(a,start,mid);
		mergesort(a,mid+1,end);
		merge(a,start,mid,end);
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
	mergesort(a,0,n-1);
	printf("the sorted array is :");
	for(int i=0;i<=n-1;i++)
	{
		printf("%d ,",a[i]);
	}	
	return 0;
}