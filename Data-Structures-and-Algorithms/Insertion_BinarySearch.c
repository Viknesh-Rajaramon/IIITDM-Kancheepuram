//INSERTION SORT USING BINARY SEARCH

#include<stdio.h>

int Insertion(int *p,int size,int x)
{
	int beg=0,end=size-1;
	int mid,pos;
	while(beg!=end)
	{
		mid=(beg+end)/2;
		if((x >= *(p+mid)) && (x <= *(p+mid+1)))
		{
			pos=mid+1;
			break;
		}
		else if(x < *(p+mid))
		{
			if(x >= *(p+mid-1))
			{
				pos=mid;
				break;
			} 
			else
			{
				end=mid-1;
			} 
		}
		else
		{
			beg=mid+1;
		}
	}
	for(int i=size-1;i>=pos;--i)
	{
		*(p+i+1)=*(p+i);
	}
	*(p+pos)=x; 
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
		printf("%d   ",ar[i]);
	}
	printf("\n");
	return 0;
}