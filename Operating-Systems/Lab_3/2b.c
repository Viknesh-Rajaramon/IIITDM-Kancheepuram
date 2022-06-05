#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>

int main()
{
	srand(time(0));
	int n;
	printf("\nEnter the number of terms in Odd/Even Series : ");
	scanf("%d",&n);
	int array[n];
	printf("\nArray Elements : ");
	for(int i=0;i<n;++i)
	{
		array[i]=rand()%1000+1;
		printf("%d ",array[i]);
	}
	printf("\n");
	pid_t pid;
	pid=fork();
	int sum=0;
	if(pid>0)
	{
		printf("\nOdd Series Elements : ");
		for(int i=0;i<n;++i)
		{
			if(array[i]%2==1)
			{
				printf("%d ",array[i]);
				sum+=array[i];
			}
		}
		printf("\nOdd ");
	}
	else if(pid==0)
	{
		printf("\nEven Series Elements : ");
		for(int i=0;i<n;++i)
		{
			if(array[i]%2==0)
			{
				printf("%d ",array[i]);
				sum+=array[i];
			}
		}
		printf("\nEven ");
	}
	else
	{
		printf("\nForking failed...\n");
	}
	printf("Series Sum : %d\n",sum);
	return 0;
}
