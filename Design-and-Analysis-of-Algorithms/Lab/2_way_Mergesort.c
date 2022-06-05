#include<stdio.h>

void merge(int a[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(int i=0;i<n1;++i)
	{
		L[i]=a[l+i];
	}
	for(int i=0;i<n2;++i)
	{
		R[i]=a[m+1+i];
	}
	int k=l;
	int i=0;
	int j=0;
	while((i<n1) && (j<n2))
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			++i;
		}
		else
		{
			a[k]=R[j];
			++j;
		}
		++k;
	}
	for(;i<n1;++i)
	{
		a[k]=L[i];
		++k;
	}
	for(;j<n2;++j)
	{
		a[k]=R[j];
		++k;
	}
}

void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=(l+(r-1))/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}

void print(int a[],int size)
{
	for(int i=0;i<size;++i)
	{
		printf("%d ",a[i]);
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
	printf("\nArray before sorting : ");
	print(a,n);
	mergesort(a,0,n-1);
	printf("\nArray after sorting : ");
	print(a,n);
	printf("\n");
	return 0;
}
