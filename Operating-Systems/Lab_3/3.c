#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<math.h>

int main()
{
	pid_t pid;
	int a,b;
	int sum=0,x=0;
	int digits=0;
	printf("\nEnter the lower bound of range : ");
	scanf("%d",&a);
	printf("\nEnter the upper bound of range : ");
	scanf("%d",&b);
	printf("\nArmstrong numbers between %d and %d : \n",a,b);
	for(int i=a;i<=b;++i)
	{
		pid=vfork();
		if(pid==0)
		{
			x=i;
			sum=0;
			digits=(int) log10(x)+1;
			while(x)
			{
				int r=x%10;
				x/=10;
				sum+=pow(r,digits);
			}
			exit(0);
		}
		else if(pid>0)
		{
			if(sum==i)
			{
				printf("%d\n",i);
			}
		}
		else
		{
			printf("\nForking error...\n");
		}
	}
	return 0;
}
