//INSERTION SORT USING LINEAR SEARCH

#include<stdio.h>

int Insertion(int *p,int size,int a)
{
	int pos,temp;
	if(a >= *(p+size-1))
	{
		pos=size;
	}
	else if(a <= *(p))
	{
		pos=0;
	}
	else
	{
		for(int i=0;i<size-1;++i)
		{ 
			if((a > *(p+i)) && (a < *(p+i+1)))
			{
				pos=i+1;
				break;
			}
		}
	}
	for(int i=size-1;i>=pos;--i)
	{
		*(p+i+1)=*(p+i);
	}
	*(p+pos)=a; 
	return 0;
}

int main()
{
	int ar[100],x,n;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	printf("\nEnter the elements of the array in ascending order: ");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&ar[i]);
	}
	printf("\nEnter the element to be inserted : ");
	scanf("%d",&x);
	Insertion(ar,n,x);
	n++;
	printf("\nThe sorted array is :\n");
	for(int i=0;i<n;++i)
	{
		printf("%d  ",ar[i]);
	}
	printf("\n");
	return 0;
}