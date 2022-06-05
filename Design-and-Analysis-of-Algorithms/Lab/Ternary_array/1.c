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
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-i-1;++j)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\nThe sorted array : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
