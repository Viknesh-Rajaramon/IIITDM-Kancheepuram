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
		printf("Child %d has finished...\n",getpid());
		exit(0);
	}
	else if(pid>0)
	{
		printf("Parent %d has started...\n",getpid());
		sleep(10);
		printf("Parent %d has finished...\n",getpid());
	}
	else
	{
		printf("Forking failed...\n");
	}
	return 0;
}
