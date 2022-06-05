#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int n;
	printf("\nEnter the number of terms in Odd/Even Series : ");
	scanf("%d",&n);
	int array[n];
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		int start=1;
		for(int i=0;i<n;++i)
		{
			array[i]=start;
			start+=2;
		}
		printf("\nOdd ");
	}
	else if(pid==0)
	{
		int start=2;
		for(int i=0;i<n;++i)
		{
			array[i]=start;
			start+=2;
		}
		printf("\nEven ");
	}
	else
	{
		printf("\nForking failed...\n");
	}
	printf("Series : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}
