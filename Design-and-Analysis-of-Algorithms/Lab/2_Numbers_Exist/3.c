#include<stdio.h>
#include<math.h>

int main()
{
	int p,q,r;
	int i;
	int n;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the value of p : ");
	scanf("%d",&p);
	printf("\nEnter the elements of the array : ");
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	int max=a[0];
	int min=a[0];
	for(i=1;i<n;++i)
	{
		max=max<a[i]?a[i]:max;
		min=min>a[i]?a[i]:min;
	}
	min=abs(min);
	int b[max];
	int pos;
	for(i=0;i<n;++i)
	{
		pos=a[i]+2*min;
		b[pos]=a[i];
	}
	int *ptr1=&a[0];
	
	return 0;
}
