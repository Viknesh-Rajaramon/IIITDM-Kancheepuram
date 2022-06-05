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
	int min;
	for(int i=0;i<n-1;++i)
	{
		min=i;
		for(int j=i+1;j<n;++j)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		int temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	printf("\nThe sorted array : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
