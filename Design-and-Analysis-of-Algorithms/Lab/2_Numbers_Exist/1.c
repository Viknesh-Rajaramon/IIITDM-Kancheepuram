#include<stdio.h>
#include<stdlib.h>

int comparator(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int n;
	int i,j;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int a[n];
	int p,q,r;
	printf("\nEnter the value of p : ");
	scanf("%d",&p);
	printf("\nEnter the elements of the array : ");
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(a[0]),comparator);
	for(q=0,r=n-1;q<r;)
	{
		if(a[q]+a[r]==p)
		{
			printf("q and r exists");
			return 0;
		}
		else if(a[q]+a[r]>p)
		{
			r--;
		}
		else
		{
			q++;
		}
	}
	printf("q and r does not exist");
	return 0;
}
