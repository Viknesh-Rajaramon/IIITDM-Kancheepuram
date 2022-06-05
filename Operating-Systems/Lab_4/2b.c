#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<time.h>

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int low,int high)
{
	int pivot_element=arr[high];
	int i=low-1;
	for(int j=low;j<high;++j)
	{
		if(arr[j]<pivot_element)
		{
			++i;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}
void Quick_Sort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid=partition(arr,low,high);
		pid_t left_child_pid,right_child_pid;
		left_child_pid=fork();
		if(left_child_pid==0)
		{
			Quick_Sort(arr,low,mid-1);
			exit(0);
		}
		else if(left_child_pid>0)
		{
			right_child_pid=fork();
			if(right_child_pid==0)
			{
				Quick_Sort(arr,mid+1,high);
				exit(0);
			}
			else if(right_child_pid<0)
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
		waitpid(left_child_pid,&status,0);
		waitpid(right_child_pid,&status,0);
	}
}

int main()
{
	int n;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int shm_id;
	key_t key=IPC_PRIVATE;
	size_t SHM_SIZE=sizeof(int)*n;
	shm_id=shmget(key,SHM_SIZE,IPC_CREAT | 0666);
	if(shm_id<0)
	{
		printf("\nShared Memory Allocation Failed...\n");
		exit(0);
	}
	int *array;
	array=shmat(shm_id,NULL,0);
	if(array==(int *)-1)
	{
		printf("\nShared Memory Operations Failed...\n");
		exit(0);
	}
	srand(time(NULL));
	printf("\nArray elements before sorting : ");
	for(int i=0;i<n;++i)
	{
		array[i]=rand()%(3*n);
		printf("%d ",array[i]);
	}
	printf("\n");
	Quick_Sort(array,0,n-1);	
	printf("\nArray elements after sorting : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	if(shmdt(array)==-1)
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
