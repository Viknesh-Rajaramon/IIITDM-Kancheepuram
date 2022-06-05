#include<stdio.h>

int main()
{
	int n;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the elements of the array : ");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	int key;	
	for(int i=1;i<n;++i)
	{
		key=arr[i];
		int j=i-1;
		while((j>=0) && (a[j]>key))
		{
			a[j+1]=a[j];
			--j;
		}
		a[j+1]=key;
	}
	printf("\nThe sorted array : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
