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
	pid_t pid=fork();
	if(pid==0)
	{
		qsort(array,n,sizeof(int),ascending);
		printf("\nAscending : ");
	}
	else if(pid>0)
	{
		qsort(array,n,sizeof(int),descending);
		printf("\nDescending : ");
	}
	else
	{
		printf("\nForking failed...\n");
	}
	for(int i=0;i<n;++i)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}
