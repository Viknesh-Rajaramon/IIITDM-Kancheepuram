#include<stdio.h>

void pattern1(int n,int a[])
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n-i;++j)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}
}

void pattern2(int n,int a[])
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<i;++j)
		{
			printf("  ");
		}
		for(j=i;j<n;++j)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}
}

void pattern3(int n,int a[])
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<=i;++j)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}
}

void pattern4(int n,int a[])
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n-i-1;++j)
		{
			printf("  ");
		}
		for(j=n-i-1;j<n;++j)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}
}

void pattern5(int n,int a[])
{
	int i,j;
	for(i=0;i<((n/2)+(n%2));++i)
	{
		for(j=0;j<i;++j)
		{
			printf("  ");
		}
		for(j=i;j<n-i;++j)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}
	for(i=n/2-1;i>=0;--i)
	{
		for(j=i-1;j>=0;--j)
		{
			printf("  ");
		}
		for(j=i;j<n-i;++j)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}
}

int main()
{
	int n;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;++i)
	{
		a[i]=i+1;
	}
	printf("\nPattern 1 : \n");
	pattern1(n,a);
	printf("\nPattern 2 : \n");
	pattern2(n,a);
	printf("\nPattern 3 : \n");
	pattern3(n,a);
	printf("\nPattern 4 : \n");
	pattern4(n,a);
	printf("\nPattern 5 : \n");
	pattern5(n,a);
	return 0;
}
