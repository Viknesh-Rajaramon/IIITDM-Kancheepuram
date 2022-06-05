#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>

int ascending(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}

int descending(const void *a,const void *b)
{
	return (*(int *)b - *(int *)a);
}

int main()
{
	srand(time(0));
	int n;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	int array[n];
	printf("\nArray elements : ");
	for(int i=0;i<n;++i)
	{
		array[i]=rand()%1000 + 1;
		printf("%d ",array[i]);
	}
	printf("\n");
	int size1=n/2;
	int size2=n-size1;
	pid_t pid=vfork();
	if(pid==0)
	{
		qsort(&(array[0]),size1,sizeof(int),ascending);
		exit(0);
	}
	else if(pid>0)
	{
		qsort(&(array[size1]),size2,sizeof(int),descending);
	}
	else
	{
		printf("\nForking failed...\n");
	}
	printf("\nArray : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}
