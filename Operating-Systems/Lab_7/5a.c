#include<stdio.h>
#include<stdbool.h>

#define SIZE 1000

int main()
{
	int p,r;
	int count=0,system=0;
	printf("\nEnter the number of processes : ");
	scanf("%d",&p);
	printf("\nEnter the number of resources : ");
	scanf("%d",&r);
	
	int max_claim[p][SIZE];
	int curr[p][SIZE];
	int avl[r];
	int alloc[p];
	int max_res[r];
	int running[p];
	int safe_sequence[p];
	printf("\nEnter MAX Claim table\n");
	for(int i=0;i<p;++i)
	{
		printf("For process %d : ",i);
		for(int j=0;j<r;++j)
		{
			scanf("%d",&max_claim[i][j]);
		}
		running[i]=1;
		count++;
	}
	
	printf("\nEnter ALLOCATION Resource table\n");
	for(int i=0;i<p;++i)
	{
		printf("For process %d : ",i);
		for(int j=0;j<r;++j)
		{
			scanf("%d",&curr[i][j]);
		}
	}
	
	printf("\nEnter Claim vector : ");
	for(int i=0;i<r;++i)
	{
		scanf("%d",&max_res[i]);
	}
	
	printf("\nMAX Matrix\tALLOCATION Matrix\n");
	for(int i=0;i<p;++i)
	{
		for(int j=0;j<r;++j)
		{
			printf("%d ",max_claim[i][j]);
		}
		printf("\t\t");
		for(int j=0;j<r;++j)
		{
			printf("%d ",curr[i][j]);
		}
		printf("\n");
	}
	
	for(int i=0;i<p;++i)
	{
		for(int j=0;j<r;++j)
		{
			alloc[j]+=curr[i][j];
		}
	}
	
	for(int i=0;i<r;++i)
	{
		avl[i]=max_res[i]-alloc[i];
	}
	
	while(count!=0)
	{
		bool safe=false;
		printf("\nAvailable vector : ");
		for(int i=0;i<r;++i)
		{
			printf("%d ",avl[i]);
		}
		
		printf("\nNeed Matrix\n");
		for(int i=0;i<p;++i)
		{
			if(running[i]==1)
			{
				for(int j=0;j<r;++j)
				{
					printf("%d ",max_claim[i][j]-curr[i][j]);
				}
			}
			else
			{
				for(int j=0;j<r;++j)
				{
					printf("0 ");
				}
			}
			printf("\n");
		}
		
		for(int i=0;i<p;++i)
		{
			if(running[i]==1)
			{
				int flag=1;
				for(int j=0;j<r;++j)
				{
					if(max_claim[i][j]-curr[i][j]>avl[j])
					{
						flag=0;
						break;
					}
				}
				
				if(flag==1)
				{
					printf("\nProcess %d runs to completion!!!\n",i);
					running[i]=0;
					safe_sequence[p-count]=i;
					--count;
					safe=true;
					
					for(int j=0;j<r;++j)
					{
						avl[j]+=curr[i][j];
					}
					break;
				}
			}
		}
		
		if(!safe)
		{
			printf("\nThe processes are in UNSAFE state!!!");
			system=1;
			break;
		}
	}
	
	printf("\nAvailable vector : ");
	for(int i=0;i<r;++i)
	{
		printf("%d ",avl[i]);
	}
	
	if(system==0)
	{
		printf("\nSafe Sequence : ");
		for(int i=0;i<p-1;++i)
		{
			printf("P%d->",safe_sequence[i]);
		}
		printf("P%d\n",safe_sequence[p-1]);
	}
	
	return 0;
}
