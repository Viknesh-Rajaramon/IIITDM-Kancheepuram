#include<bits/stdc++.h>

#include "graph.h"

using namespace std;

void dfs(int **adjmatrix,int *visited,int u,int n)
{
	stack<int> s;
	s.push(u);
	while(!s.empty())
	{
		u=s.top();
		s.pop();
		if(visited[u]==0)
		{
			visited[u]=1;
		}
		for(int i=0;i<n;++i)
		{
			if(((*(*(adjmatrix+u)+i))!=0) && ((*(visited+i))==0))
			{
				s.push(i);
			}
		}
	}
}

void dfs(int **adjmatrix,int n)
{
	int *visited=initialize_1d_array(n,0);
	int u=rand()%n;
	cout<<"\nStarting vertex of DFS : "<<u<<endl;
	dfs(adjmatrix,visited,u,n);
}

int dfs(int **adjmatrix,int u,int v,int n)
{
	int *visited=initialize_1d_array(n,0);
	dfs(adjmatrix,visited,u,n);
	if((*(visited+v))==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
