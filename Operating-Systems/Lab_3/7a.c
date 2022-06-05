#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>

int sort(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}
int binary_search(int array[],int lower,int upper,int search_element)
{
	if(upper>=lower)
	{
		int mid=lower+(upper-lower)/2;
		if(array[mid]==search_element)
		{
			return mid;
		}
		if(array[mid]>search_element)
		{
			return binary_search(array,lower,mid-1,search_element);
		}
		return binary_search(array,mid+1,upper,search_element);
	}
	return -1;
}

int main()
{
	srand(time(0));
	int n,x;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	int array[n];
	printf("\nArray elements : " );
	for(int i=0;i<n;++i)
	{
		array[i]=rand()%1000+1;
		printf("%d ",array[i]);
	}
	printf("\nEnter the element to search for : ");
	scanf("%d",&x);
	printf("\n");
	int size=n/2;
	int pos;
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		qsort(&(array[0]),size,sizeof(int),sort);
		printf("\nSorted Array (First Half) : ");
		for(int i=0;i<size;++i)
		{
			printf("%d ",array[i]);
		}
		printf("\n");
		pos=binary_search(array,0,size-1,x);
		printf("First Half Position : ");
	}
	else if(pid==0)
	{
		qsort(&(array[size]),n-size,sizeof(int),sort);
		printf("\nSorted Array (Second Half) : ");
		for(int i=size;i<n;++i)
		{
			printf("%d ",array[i]);
		}
		printf("\n");
		pos=binary_search(array,size,n-1,x);
		pos-=size;
		printf("Second Half Position : ");
	}
	else
	{
		printf("\nforking Failed...\n");
	}
	if(pos<0)
	{
		printf("%d not found\n",x);
	}
	else
	{
		printf("%d\n",pos);
	}
	return 0;
}
