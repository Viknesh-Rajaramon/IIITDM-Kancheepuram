#include<stdio.h>

int adj_mat[20][20] = {0}, v, e, visit[20] = {0}, arr[20], add = 0, last = -1, first = 0, cycle_flag = 0;

void check_connected ();
void check_cycle ();
void push (int);
int pop ();

void main()
{
	printf("\nEnter number of vertices\n");
	scanf("%d", &v);
	printf("Enter number of edges\n");
	scanf("%d", &e);
	printf("Enter the edges\n");
	for(int i=0;i<e;i++)
	{
		int v1,v2;
		scanf("%d %d", &v1, &v2);
		adj_mat[v1][v2]=1;
		adj_mat[v2][v1]=1;
	}	
	for(int i=0;i<v;i++)
	{
		printf("\n");
		for(int j=0;j<v;j++)
		{
			printf("%d ",adj_mat[i][j]);
		}
	}
	printf("\n\n");
	check_cycle();
	if(cycle_flag==1)
	{
		printf("Cycle Exists\n");
	}
	else
	{
		printf("Cycle Does Not Exist\n");
	}
	check_connected();	
}

void push(int x)
{
	arr[add]=x;
	add++;
}

int pop()
{
	int temp=arr[add-1];
	add--;
	return temp;
}

int check_dup(int x)
{
	for(int i=0;i<add;i++)
	{
		if(arr[i]==x)
		{
			return 1;
		}
	}
	return 0;
}

void check_connected()
{
	for(int i=0;i<v;i++)
	{
		int flag = 0;
		for(int j = 0; j < v; j++)
		{
			if(adj_mat[i][j] == 1)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			printf("Graph Not Connected\n");
			return;
		}		
	}
	printf("Graph Connected\n");
}

void check_cycle (int adr)
{
	visit[adr] = 1;
	for(int j = 0; j < v; j++)
	{
		if( adj_mat[adr][j] == 1)
		{
			if( visit[j] == 1)
			{
				cycle_flag = 1;
				return;
			}
			else
			{
				if(check_dup(j) == 0)
				{
					push(j);
				}
			}
		}
	}
	while(add != 0)
	{
		check_cycle(pop());
	}
}