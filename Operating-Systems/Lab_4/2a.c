#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<time.h>

void merge(int a[],int low,int mid,int high)
{
	int size=high-low+1;
	int array[size];
	int i=low;
	int j=mid+1;
	int k=0;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			array[k]=a[i];
			++i;
		}
		else
		{
			array[k]=a[j];
			++j;
		}
		++k;
	}
	while(i<=mid)
	{
		array[k]=a[i];
		++i;
		++k;
	}
	while(j<=high)
	{
		array[k]=a[j];
		++j;
		++k;
	}
	j=low;
	for(int i=0;i<size;++i)
	{
		a[j]=array[i];
		++j;
	}
}

void Merge_Sort(int a[],int low,int high)
{
	int i;
	int length=high-low+1;
	if(length==1)
	{
		return;
	}
	else if(length==2)
	{
		if(a[low]>a[high])
		{
			int temp=a[low];
			a[low]=a[high];
			a[high]=temp;
		}
		return;
	}
	pid_t left_child_pid,right_child_pid;
	left_child_pid=fork();
	if(left_child_pid==0)
	{
		Merge_Sort(a,low,low+length/2-1);
		exit(0);
	}
	else if(left_child_pid>0)
	{
		right_child_pid=fork();
		if(right_child_pid==0)
		{
			Merge_Sort(a,low+length/2,high);
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
	merge(a,low,low+length/2-1,high);
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
	Merge_Sort(array,0,n-1);
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
