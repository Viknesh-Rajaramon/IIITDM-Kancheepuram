//BINARY SEARCH IN CHARACTER ARRAY

#include<stdio.h>

int BinarySearch(char *p,int size,char x)
{
	int beg=0,end=size-1,flag=0;
	int mid;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(x==*(p+mid))
		{
			flag=1;
			break;
		}
  		else if(x<*(p+mid))
		{
			end=mid-1;
		}
		else
		{
			beg=mid+1;
		}
	}
	return flag;
}

int main()
{
	char ar[100],s;
	int n=0,f;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	printf("\nEnter the elements of the array : ");
	for(int i=0;i<n;++i)
	{
		getchar();
		scanf("%c",&ar[i]);
	}
	printf("\nEnter the element to search for : ");
	getchar();
	scanf("%c",&s);
	f=BinarySearch(ar,n,s);
	if(f==1)
	{
		printf("\nElement found in the array");
	}
	else
	{
		printf("\nElement not found in the array");
	}
	return 0;
}