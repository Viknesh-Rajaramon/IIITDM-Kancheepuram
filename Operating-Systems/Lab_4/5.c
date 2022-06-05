#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<time.h>

#define MAXSIZE 1024

void Histogram_generator(char array[],char characters[],int freq[],int low,int high)
{
	int length=high-low+1;
	if(length==1)
	{
		++freq[array[low]];
		return;
	}
	else if(length==2)
	{
		++freq[array[low]];
		++freq[array[high]];
		return;
	}
	pid_t left_array_pid,right_array_pid;
	left_array_pid=fork();
	if(left_array_pid==0)
	{
		Histogram_generator(array,characters,freq,low,low+length/2-1);
		exit(0);
	}
	else if(left_array_pid>0)
	{
		right_array_pid=fork();
		if(right_array_pid==0)
		{
			Histogram_generator(array,characters,freq,low+length/2,high);
			exit(0);
		}
		else if(right_array_pid<0)
		{
			printf("Right child process creation Failed...\n");
			exit(0);
		}
	}
	else
	{
		printf("Left child process creation Failed...\n");
		exit(0);
	}
	int status;
	waitpid(left_array_pid,&status,0);
	waitpid(right_array_pid,&status,0);
}

int main()
{
	char array[MAXSIZE];
	char characters[256];
	printf("\nEnter the text : ");
	fgets(array,MAXSIZE,stdin);
	int length=strlen(array);
	int shm_id;
	key_t key=IPC_PRIVATE;
	size_t SHM_SIZE=sizeof(int)*(256);
	shm_id=shmget(key,SHM_SIZE,IPC_CREAT | 0666);
	if(shm_id<0)
	{
		printf("\nShared Memory Allocation Failed...\n");
		exit(0);
	}
	int *frequency;
	frequency=shmat(shm_id,NULL,0);
	if(frequency==(int *)-1)
	{
		printf("\nShared Memory Operations Failed...\n");
		exit(0);
	}
	for(int i=0;i<256;++i)
	{
		characters[i]=i;
		frequency[i]=0;
	}
	Histogram_generator(array,characters,frequency,0,length-1);
	printf("\n\t\tHistogram....\n");
	printf("\nCharacter\tFrequency\tChart\n\n");
	for(int i=0;i<256;++i)
	{
		if((frequency[i]!=0) && (characters[i]!='\n'))
		{
			printf("[%c]\t\t%d\t\t",characters[i],frequency[i]);
			for(int j=0;j<frequency[i];++j)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	if(shmdt(frequency)==-1)
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
