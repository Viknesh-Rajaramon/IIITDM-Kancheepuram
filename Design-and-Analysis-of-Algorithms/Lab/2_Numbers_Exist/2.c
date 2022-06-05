#include<stdio.h>

int main()
{
	int n;
	int i,j;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int a[n];
	int p;
	printf("\nEnter the value of p : ");
	scanf("%d",&p);
	printf("\nEnter the elements of the array : ");
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-2;++i)
	{
		for(j=i+1;j<n;++j)
		{
			if(a[i]+a[j]==p)
			{
				printf("q and r exists\n");
				return 0;
			}
		}
	}
	printf("q and r does not exist\n");
	return 0;
}
