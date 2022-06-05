#include<bits/stdc++.h>
#include<list>

#include "graph.h"

using namespace std;

void bfs(int **adjmatrix,int *visited,int u,int n)
{
	int queue[n];
	int front=0,rear=0;
	*(visited+u)=1;
	queue[rear]=u;
	while(rear<=front)
	{
		u=queue[front];
		front++;
		for(int i=(**(adjmatrix+u));i<n;++i)
		{
			if(((*(visited+i))==0) && ((*(*(adjmatrix+u)+i))!=0))
			{
				*(visited+i)=1;
				queue[rear]=i;
				rear++;
			}
		}
		
	}	
}

void bfs(int **adjmatrix,int *visited,int n)
{
	int u=rand()%n;
	cout<<"\nStarting vertex of BFS : "<<u<<endl;
	bfs(adjmatrix,visited,u,n);
}

int bfs(int **adjmatrix,int *visited,int u,int v,int n)
{
	bfs(adjmatrix,visited,u,n);
	if((*(visited+v))==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
