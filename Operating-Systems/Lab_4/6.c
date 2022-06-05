#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<unistd.h>
#include<time.h>

void Matrix_multiply(int m,int p,int n)
{
	srand(time(NULL));
	int mat1[m][p],mat2[p][n];
	printf("\nMatrix 1 : \n");
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<p;++j)
		{
			mat1[i][j]=rand()%(m*n*3);
			printf("%d ",mat1[i][j]);
		}
		printf("\n");
	}
	printf("\nMatrix 2 : \n");
	for(int i=0;i<p;++i)
	{
		for(int j=0;j<n;++j)
		{
			mat2[i][j]=rand()%(m*n*3);
			printf("%d ",mat2[i][j]);
		}
		printf("\n");
	}
	int (*result)[m];
	int shm_id;
	key_t key=IPC_PRIVATE;
	shm_id=shmget(key,sizeof(int[m][n]),IPC_CREAT | 0666);
	if(shm_id<0)
	{
		printf("\nShared Memory Allocation Failed...\n");
		exit(0);
	}
	result=shmat(shm_id,0,0);
	if(result==(void *)-1)
	{
		printf("\nShared Memory Operations Failed...\n");
		exit(0);
	}
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			pid_t pid=fork();
			if(pid==0)
			{
				result[i][j]=0;
				for(int k=0;k<p;++k)
				{
					result[i][j]+=mat1[i][k]*mat2[k][j];
				}
				exit(0);
			}
			else if(pid<0)
			{
				printf("\nForking Failed...\n");
				exit(0);
			}
		}
	}
	for(int i=0;i<m*n;++i)
	{
		wait(NULL);
	}
	printf("Resultant Matrix : \n");
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			printf("%d   ",result[i][j]);
		}
		printf("\n");
	}
	if(shmdt(result)==-1)
	{
		printf("\nDetaching Shared Memory Failed...\n");
		exit(0);
	}
	if(shmctl(shm_id,IPC_RMID,NULL)==-1)
	{
		printf("\nRemoving Shared Memory Failed...\n");
		exit(0);
	}
	return;
}

int main()
{
	int m1,n1,m2,n2;
	printf("\nEnter the dimensions of Matrix 1(separated by space) : ");
	scanf("%d %d",&m1,&n1);
	printf("\nEnter the dimensions of Matrix 2(separated by space) : ");
	scanf("%d %d",&m2,&n2);
	if(n1!=m2)
	{
		printf("\nMatrix 1 and Matrix 2 are not suitable for multiplication....\n");
		return 0;
	}
	Matrix_multiply(m1,n1,n2);
	return 0;
}
