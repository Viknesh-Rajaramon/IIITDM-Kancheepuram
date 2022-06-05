#include<bits/stdc++.h>

#include "graph.h"

using namespace std;

int Test_bipartite(int **adjmatrix,int n)
{
	srand(time(NULL));
	int *color;
	color=initialize_1d_array(n,-1);//Initially the color of all the vertices are -1
	int u=rand()%n;
	cout<<"\nThe source vertex : "<<u<<endl;
	color[u]=1;//Color of source is 1 whereas color of neighbourhood vertices is 0
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int i=0;i<n;++i)
		{
			if(((*(*(adjmatrix+u)+i))!=0) && (color[i]==-1))
			{
				color[i]=1-color[u];
				q.push(i);
			}
			else
			{
				if((*(*(adjmatrix+u)+i))!=0)
				{
					if(color[i]==color[u])
					{
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

void APutil(int u,int *visited,int *disc,int *low,int *parent,int *ap,int **adjmatrix,int n)
{
	static int time=0;
	int children=0;
	*(visited+u)=1;
	disc[u]=low[u]=++time;
	for(int i=0;i<n;++i)
	{
		if((*(*(adjmatrix+u)+i))!=0)
		{
			int v=i;
			if(visited[v]==0)
			{
				children++;
				parent[v]=u;
				APutil(v,visited,disc,low,parent,ap,adjmatrix,n);
				low[u]=(low[u]<low[v])?low[u]:low[v];
				if((parent[u]==0) && (children>1))
				{
					ap[u]=1;
				}
				if((parent[u]!=0) && (low[v]>=disc[u]))
				{
					ap[u]=1;
				}
			}
			else
			{
				if(v!=parent[u])
				{
					low[u]=(low[u]<disc[v])?low[u]:disc[v];
				}
			}
		}
	}
}

void Test_articulationpoints(int **adjmatrix,int n)
{
	int *visited=initialize_1d_array(n,0);
	int *disc=initialize_1d_array(n,0);
	int *low=initialize_1d_array(n,0);
	int *parent=initialize_1d_array(n,0);
	int *ap=initialize_1d_array(n,0);
	for(int i=0;i<n;++i)
	{
		if(visited[i]==0)
		{
			APutil(i,visited,disc,low,parent,ap,adjmatrix,n);
		}
	}
	cout<<"\nArticulation Points : ";
	for(int i=0;i<n;++i)
	{
		if(ap[i]==1)
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;
}

void Bridgeutil(int u,int *visited,int *disc,int *low,int *parent,int **adjmatrix,int n)
{
	static int time=0;
	*(visited+u)=1;
	disc[u]=low[u]=++time;
	for(int i=0;i<n;++i)
	{
		if((*(*(adjmatrix+u)+i))!=0)
		{
			int v=i;
			if(visited[v]==0)
			{
				parent[v]=u;
				Bridgeutil(v,visited,disc,low,parent,adjmatrix,n);
				low[u]=(low[u]<low[v])?low[u]:low[v];
				if(low[v]>disc[u])
				{
					cout<<u<<" "<<v<<" "<<*(*(adjmatrix+u)+i)<<endl;
				}
			}
			else
			{
				if(v!=parent[u])
				{
					low[u]=(low[u]<disc[v])?low[u]:disc[v];
				}
			}
		}
	}
}

void Test_bridges(int **adjmatrix,int n)
{
	int *visited=initialize_1d_array(n,0);
	int *disc=initialize_1d_array(n,0);
	int *low=initialize_1d_array(n,0);
	int *parent=initialize_1d_array(n,0);
	cout<<"\nBridges in graph : "<<endl;
	for(int i=0;i<n;++i)
	{
		if(visited[i]==0)
		{
			Bridgeutil(i,visited,disc,low,parent,adjmatrix,n);
		}
	}
}
