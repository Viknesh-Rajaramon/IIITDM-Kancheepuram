#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<time.h>

#define MAX 1000

void Check_Magic_Square(int n)
{
	int a[n][n];
	printf("\nEnter the elements : \n");
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n");
	int shm_id;
	key_t key=IPC_PRIVATE;
	size_t SHM_SIZE=sizeof(int)*(4);
	shm_id=shmget(key,SHM_SIZE,IPC_CREAT | 0666);
	if(shm_id<0)
	{
		printf("\nShared Memory Allocation Failed...\n");
		exit(0);
	}
	int *flag;
	flag=shmat(shm_id,NULL,0);
	if(flag==(int *)-1)
	{
		printf("\nShared Memory Operations Failed...\n");
		exit(0);
	}
	pid_t prime_diagnol,secondary_diagnol,rows,columns;
	prime_diagnol=fork();
	if(prime_diagnol==0)
	{
		int prime_diagnol_sum=0;
		for(int i=0;i<n;++i)
		{
			prime_diagnol_sum=prime_diagnol_sum+a[i][i];
		}
		flag[0]=prime_diagnol_sum;
		exit(0);
	}
	else if(prime_diagnol>0)
	{
		secondary_diagnol=fork();
		if(secondary_diagnol==0)
		{
			int secondary_diagnol_sum=0;
			for(int i=0;i<n;++i)
			{
				secondary_diagnol_sum+=a[n-1-i][i];
			}
			flag[1]=secondary_diagnol_sum;
			exit(0);
		}
		else if(secondary_diagnol>0)
		{
			rows=fork();
			if(rows==0)
			{
				int sum_of_rows[n];
				for(int i=0;i<n;++i)
				{
					sum_of_rows[i]=0;
					for(int j=0;j<n;++j)
					{
						sum_of_rows[i]+=a[i][j];
					}
				}
				flag[2]=sum_of_rows[0];
				for(int i=1;i<n;++i)
				{
					if(sum_of_rows[i-1]!=sum_of_rows[i])
					{
						flag[2]=-1;
						break;
					}
				}
				exit(0);
			}
			else if(rows>0)
			{
				columns=fork();
				if(columns==0)
				{
					int sum_of_columns[n];
					for(int i=0;i<n;++i)
					{
						sum_of_columns[i]=0;
						for(int j=0;j<n;++j)
						{
							sum_of_columns[i]+=a[j][i];
						}
					}
					flag[3]=sum_of_columns[0];
					for(int i=1;i<n;++i)
					{
						if(sum_of_columns[i-1]!=sum_of_columns[i])
						{
							flag[3]=-1;
							break;
						}
					}
					exit(0);
				}
				else if(columns<0)
				{
					printf("Columns process creation Failed...\n");
					exit(0);
				}
			}
			else
			{
				printf("Rows process creation Failed...\n");
				exit(0);
			}
		}
		else
		{
			printf("Secondary Diagnol process creation Failed...\n");
			exit(0);
		}
	}
	else
	{
		printf("Prime Diagnol process creation Failed...\n");
		exit(0);
	}
	int status;
	waitpid(prime_diagnol,&status,0);
	waitpid(secondary_diagnol,&status,0);
	waitpid(rows,&status,0);
	waitpid(columns,&status,0);
	if((flag[0]==flag[1]) && (flag[1]==flag[2]) && (flag[2]==flag[3]))
	{
		printf("Magic Square\n");
	}
	else
	{
		printf("Not a Magic Square\n");
	}
	if(shmdt(flag)==-1)
	{
		printf("\nDetaching Shared Memory Failed...\n");
		exit(0);
	}
	if(shmctl(shm_id,IPC_RMID,NULL)==-1)
	{
		printf("\nRemoving Shared Memory Failed...\n");
		exit(0);
	}
}

int main()
{
	int n;
	printf("\nEnter the number of rows : ");
	scanf("%d",&n);
	Check_Magic_Square(n);
	return 0;
}
