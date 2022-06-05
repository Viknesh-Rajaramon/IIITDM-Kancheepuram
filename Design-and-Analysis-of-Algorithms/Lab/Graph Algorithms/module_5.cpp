#include<bits/stdc++.h>

#include "graph.h"

using namespace std;

struct node
{
	int w;
	int u;
	int v;
};

void mst_prim(int **adjmatrix,int n)
{
	int u=rand()%n;
	int v=0;
	int front=0;
	int min;
	cout<<"\nRoot of MST : "<<u<<endl;
	int arr[n];
	int *visited;
	visited=initialize_1d_array(n,0);
	arr[front]=u;
	front++;
	visited[u]=1;
	cout<<"\nEdges of MST with weights: "<<endl;
	cout<<"\nu"<<" v "<<"w"<<endl<<endl;
	while(front!=n)
	{
		min=INT_MAX;
		for(int i=0;i<front;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(((*(*(adjmatrix+arr[i])+j))!=0) && ((*(*(adjmatrix+arr[i])+j))<min) && (arr[i]!=j) && (visited[j]==0))
				{
					min=*(*(adjmatrix+arr[i])+j);
					u=arr[i];
					v=j;
				}
			}
		}
		arr[front]=v;
		front++;
		visited[v]=1;
		visited[u]=1;
		cout<<u<<" "<<v<<" "<<min<<endl;
	}
}

bool edge_sort(struct node a,struct node b)
{
	if(a.w!=b.w)
	{
		return a.w<b.w;
	}
}

void mst_kruskal(int **adjmatrix,int n)
{
	int *visited;
	visited=initialize_1d_array(n,0);
	vector<struct node> edges;
	int size=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if((*(*(adjmatrix+i)+j)!=0))
			{
				edges.push_back(node());
				edges[size].u=i;
				edges[size].v=j;
				edges[size].w=*(*(adjmatrix+i)+j);
				size++;
			}
		}
	}
	sort(edges.begin(),edges.end(),edge_sort);
	cout<<"\nMST using Kruskal's Algorithm : "<<endl;
	int **matrix;
	matrix=initialize_adjmatrix(n);
	for(int i=0;i<size;++i)
	{
		if(check_cycle(matrix,n,edges[i].u,edges[i].v)==0)
		{
			add_edge(matrix,edges[i].u,edges[i].v,edges[i].w);
			cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].w<<endl;
		}
	}
}
