#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>

void pascal_triangle(unsigned long int array[], int n)
{
	unsigned long int c=1;
	for(unsigned long int i=1;i<=n;++i)
	{
		array[i-1]=c;
		c=c*(n-i)/i;
	}
}

void fibonacci(unsigned long int fib[],int n)
{
	pid_t pid;
	unsigned long int array[n][n];
	for(int i=1;i<=n;++i)
	{
		unsigned long int a[i];
		memset(a,0,i);
		pascal_triangle(a,i);
		for(int j=0;j<i;++j)
		{
			array[i-1][j]=a[j];
		}
	}
	pid=vfork();
	if(pid==0)
	{
		for(int i=0;i<n;i+=2)
		{
			fib[i]=0;
			for(int j=0;j<=i/2;++j)
			{
				fib[i]+=array[i-j][j];
			}
		}
		exit(0);
	}
	else if(pid>0)
	{
		for(int i=1;i<n;i+=2)
		{
			fib[i]=0;
			for(int j=0;j<=i/2;++j)
			{
				fib[i]+=array[i-j][j];
			}
		}
	}
	else
	{
		printf("\nForking Failed...\n");
	}
}

int main()
{
	int n;
	printf("\nEnter the number of terms in Fibonacci Series : ");
	scanf("%d",&n);
	unsigned long int fib[n];
	fibonacci(fib,n);
	printf("\nFibonacci Series : ");
	for(int i=0;i<n;++i)
	{
		printf("%lu ",fib[i]);
	}
	printf("\n");
	return 0;
}
