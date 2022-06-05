#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int shm_id;
	key_t key=IPC_PRIVATE;
	size_t SHM_SIZE=sizeof(int);
	shm_id=shmget(key,SHM_SIZE,IPC_CREAT | 0666);
	if(shm_id<0)
	{
		printf("\nShared Memory Allocation Failed...\n");
		exit(0);
	}
	int *count;
	count=shmat(shm_id,NULL,0);
	if(count==(int *)-1)
	{
		printf("\nShared Memory Operations Failed...\n");
		exit(0);
	}
	(*count)=1;
	pid_t pid;
	int status;
	pid=fork();
	if(pid==0)
	{
		while(1)
		{
			pid=fork();
			if(pid==0)
			{
				(*count)=(*count)+1;
				exit(0);
			}
			else if(pid<0)
			{
				exit(0);
			}
		}
	}
	else if(pid>0)
	{
		wait(NULL);
	}
	else
	{
		printf("\nForking failed...\n");
		exit(0);
	}
	printf("\nTotal number of processes : %d\n",*count);
	if(shmdt(count)==-1)
	{
		printf("\nDetaching Shared Memory Failed...\n");
		exit(0);
	}
	if(shmctl(shm_id,IPC_RMID,NULL)==-1)
	{
		printf("\nRemoving Shared Memory Failed...\n");
		exit(0);
	}
	return 0;
}
