#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int n;
	printf("\nEnter the number of terms in Fibonacci/Prime series : ");
	scanf("%d",&n);
	printf("\n");
	unsigned long int array[n];
	pid_t pid=fork();
	if(pid>0)
	{
		int count=2;
		array[0]=2;
		array[1]=3;
		for(int i=5;count<=n;++i)
		{
			int flag=0;
			if((i%2==0) || (i%3==0))
			{
				flag=1;
			}
			else
			{
				for(int j=5;j*j<=i;j=j+6)
				{
					if((i%j==0) || (i%(j+2)==0))
					{
						flag=1;
						break;
					}
				}
			}
			if(flag==0)
			{
				array[count]=i;
				++count;
			}
		}
	}
	else if(pid==0)
	{
		array[0]=0;
		array[1]=1;
		for(int i=2;i<n;++i)
		{
			array[i]=array[i-1]+array[i-2];
		}
	}
	else
	{
		printf("\nForking failed...\n");
	}
	if(pid==0)
	{
		printf("\nFibonacci");
	}
	else if(pid>0)
	{
		printf("\nPrime");
	}
	printf(" Series : ");
	for(int i=0;i<n;++i)
	{
		printf("%lu ",array[i]);
	}
	printf("\n");
	return 0;
}
