#include<stdio.h>

int count=0;

void dc(int a[],int l,int r)
{
	if(l<r)
	{
		int m=(l+(r-1))/2;
		dc(a,l,m);
		dc(a,m+1,r);
	}
	if(l==r)
	{
		if(a[l]==1)
		{
			count++;
		}
	}
}

int main()
{
	int n;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the elements of the array : ");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	dc(a,0,n-1);
	printf("\nNumber of 1's = %d\n",count);
	return 0;
}
