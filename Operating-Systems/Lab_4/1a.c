#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		printf("Child %d has started...\n",getpid());
		printf("Child %d has parent as %d\n",getpid(),getppid());
		sleep(7);
		printf("Child %d has parent as %d\n",getpid(),getppid());
		printf("Process %d corresponds to Reaper process...\n",getppid());
	}
	else if(pid>0)
	{
		printf("Parent %d has started...\n",getpid());
		printf("Parent %d has ended...\n",getpid());
	}
	else
	{
		printf("Forking failed...\n");
	}
	return 0;
}
