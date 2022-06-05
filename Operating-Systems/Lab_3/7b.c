#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>

int sort(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}

int first_occurrence(int array[],int lower,int upper,int x)
{
	if(lower>upper)
	{
		return lower;
	}
	int mid=lower+(upper-lower)/2;
	if(array[mid]>=x)
	{
		return first_occurrence(array,lower,mid-1,x);
	}
	return first_occurrence(array,mid+1,upper,x);
}

int last_occurrence(int array[],int lower,int upper,int x)
{
	if(lower>upper)
	{
		return lower;
	}
	int mid=lower+(upper-lower)/2;
	if(array[mid]>x)
	{
		return last_occurrence(array,lower,mid-1,x);
	}
	return last_occurrence(array,mid+1,upper,x);
}

int main()
{
	srand(time(0));
	int n,x;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	int array[n];
	char string[7];
	printf("\nUnsorted Array elements : " );
	for(int i=0;i<n;++i)
	{
		array[i]=rand()%10+1;
		printf("%d ",array[i]);
	}
	printf("\n\nEnter the element to search for : ");
	scanf("%d",&x);
	printf("\n");
	int start=0,end=n;
	int first_pos=0,last_pos=0;
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		qsort(&(array[0]),n/2,sizeof(int),sort);
		first_pos=first_occurrence(array,0,n/2-1,x);
		last_pos=last_occurrence(array,0,n/2-1,x);
		strcpy(string,"First");
		end=n/2;
	}
	else if(pid==0)
	{
		qsort(&(array[n/2]),n-n/2,sizeof(int),sort);
		first_pos=first_occurrence(array,n/2,n-1,x);
		last_pos=last_occurrence(array,n/2,n-1,x);
		first_pos-=n/2;
		last_pos-=n/2;
		strcpy(string,"Second");
		start=n/2;
	}
	else
	{
		printf("\nforking Failed...\n");
	}
	printf("\nArray elements in %s Half : ",string);
	for(;start<end;++start)
	{
		printf("%d ",array[start]);
	}
	printf("\nNumber of occurrences in %s Half : %d\n",string,last_pos-first_pos);
	return 0;
}
