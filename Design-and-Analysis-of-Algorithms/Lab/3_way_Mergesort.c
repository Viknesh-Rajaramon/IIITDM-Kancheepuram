#include<stdio.h>

void merge(int a[],int l,int m1,int m2,int r)
{
	int n1=m1-l+1;
	int n2=m2-m1;
	int n3=r-m2;
	int L[n1],M[n2],R[n3];
	int i=0,j=0,k=0;
	for(i=0;i<n1;++i)
	{
		L[i]=a[l+i];
	}
	for(j=0;j<n2;++j)
	{
		M[j]=a[m1+1+j];
	}
	for(k=0;k<n3;++k)
	{
		R[k]=a[m2+1+k];
	}
	i=0;
	j=0;
	k=0;
	int p=l;
	while((i<n1) && (j<n2) && (k<n3))
	{
		if((M[j]<=R[k]) && (L[i]<=R[k]))
		{
			if(L[i]<=M[j])
			{
				a[p]=L[i];
				++i;
			}
			else
			{
				a[p]=M[j];
				++j;
			}
		}
		else if((L[i]<=M[j]) && (R[k]<=M[j]))
		{
			if(L[i]<=R[k])
			{
				a[p]=L[i];
				++i;
			}
			else
			{
				a[p]=R[k];
				++k;
			}
		}
		else
		{
			if(M[j]<=R[k])
			{
				a[p]=M[j];
				++j;
			}
			else
			{
				a[p]=R[k];
				++k;
			}
		}
		++p;
	}
	while((i<n1) && (j<n2))
	{
		if(L[i]<=M[j])
		{
			a[p]=L[i];
			++i;
		}
		else
		{
			a[p]=M[j];
			++j;
		}
		++p;
	}
	while((k<n3) && (j<n2))
	{
		if(M[j]<=R[k])
		{
			a[p]=M[j];
			++j;
		}
		else
		{
			a[p]=R[k];
			++k;
		}
		++p;
	}
	while((k<n3) && (i<n1))
	{
		if(L[i]<=R[k])
		{
			a[p]=L[i];
			++i;
		}
		else
		{
			a[p]=R[k];
			++k;
		}
		++p;
	}
	for(;i<n1;++i)
	{
		a[p]=L[i];
		++p;
	}
	for(;j<n2;++j)
	{
		a[p]=M[j];
		++p;
	}
	for(;k<n3;++k)
	{
		a[p]=R[k];
		++p;
	}
}

void mergesort(int a[],int l,int r)
{
	if(r-l<2)
	{
		return;
	}
	int m1=l+((r-l)/3);
	int m2=(m1+1)+((r-l)/3);
	mergesort(a,l,m1);
	mergesort(a,m1+1,m2);
	mergesort(a,m2+1,r);
	merge(a,l,m1,m2,r);
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
	return 0;
}
