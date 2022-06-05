#include<bits/stdc++.h>

#include "graph.h"

using namespace std;

int check_connected(int **adjmatrix,int u,int n)
{
	int *visited=initialize_1d_array(n,0);
	dfs(adjmatrix,visited,u,n);
	int connected=1;
	for(int i=0;i<n;++i)
	{
		if((*(visited+i))==0)
		{
			connected=0;
			break;
		}
	}
	return connected;
}

int check_connected_DAG(int **adjmatrix,int n)
{
	int i=0;
	int flag=1;
	int *visited;
	for(int i=0;i<n;++i)
	{
		visited=initialize_1d_array(n,0);
		flag=1;
		dfs(adjmatrix,visited,i,n);
		for(int j=0;j<n;++j)
		{
			if(visited[j]==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			break;
		}
	}
	if(flag==1)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

void add_edge(int **adjmatrix,int u,int v)
{
	(*(*(adjmatrix+u)+v))=1;
	(*(*(adjmatrix+v)+u))=1;
}

void add_edge(int **adjmatrix,int u,int v,int w)
{
	(*(*(adjmatrix+u)+v))=w;
	(*(*(adjmatrix+v)+u))=w;
}

void add_edge_directed(int **adjmatrix,int u,int v,int w)
{
	(*(*(adjmatrix+u)+v))=w;
}

void remove_edge(int **adjmatrix,int u,int v)
{
	(*(*(adjmatrix+u)+v))=0;
	(*(*(adjmatrix+v)+u))=0;
}

int* initialize_1d_array(int n,int value)
{
	int *arr=new int[n];
	for(int i=0;i<n;++i)
	{
		*(arr+i)=value;
	}
	return arr;
}

int **initialize_adjmatrix(int n)
{
	int **adjmatrix=new int* [n];
	for(int i=0;i<n;++i)
	{
		adjmatrix[i]=new int [n];
		for(int j=0;j<n;++j)
		{
			(*(*(adjmatrix+i)+j))=0;
		}
	}
	return adjmatrix;
}

int check_cycle(int **adjmatrix,int n,int u,int v)
{
	int flag=dfs(adjmatrix,u,v,n);
	return flag;
}
