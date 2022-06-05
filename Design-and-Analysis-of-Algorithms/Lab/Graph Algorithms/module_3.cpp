#include<bits/stdc++.h>

#include "graph.h"

using namespace std;

int min_distance(int *dist,int *sptset,int n)
{
	int min=INT_MAX;
	int index;
	for(int i=0;i<n;++i)
	{
		if((sptset[i]==0) && (dist[i]<=min))
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}

void BFS_SPATH(int **adjmatrix,int n,int u,int flag)
{
	if((flag==0) || (flag==1))
	{
		cout<<"\nSource vertex : "<<u<<endl;
		int *dist=initialize_1d_array(n,INT_MAX);
		int *sptset=initialize_1d_array(n,0);
		dist[u]=0;
		for(int i=0;i<n-1;++i)
		{
			int v=min_distance(dist,sptset,n);
			sptset[v]=1;
			for(int j=0;j<n;++j)
			{
				if((sptset[j]==0) && ((*(*(adjmatrix+v)+j))!=0) && (dist[v]!=INT_MAX) && (dist[v]+(*(*(adjmatrix+v)+j))<dist[j]))
				{
					dist[j]=dist[v]+(*(*(adjmatrix+v)+j));
				}
			}
		}
		cout<<"\nVertex\tDistance from Source\n";
		for(int i=0;i<n;++i)
		{
			if(u!=i)
			{
				if(dist[i]!=INT_MAX)
				{
					cout<<i<<'\t'<<dist[i]<<endl;
				}
				else
				{
					cout<<i<<"\tPath does not exist"<<endl;
				}
			}
		}
	}
	else
	{
		return;
	}
}

std::pair<int,int> bfs(int **adjmatrix,int n,int u)
{
	int *dis=initialize_1d_array(n,INT_MIN);
	queue<int> q;
	q.push(u);
	dis[u]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<n;++i)
		{
			if((*(*(adjmatrix+u)+i))!=0)
			{
				int v=i;
				if(dis[v]==INT_MIN)
				{
					q.push(v);
					dis[v]=dis[u]+(*(*(adjmatrix+u)+i));
				}
			}
		}
	}
	int max_distance=0;
	int index=0;
	for(int i=0;i<n;++i)
	{
		if(max_distance<dis[i])
		{
			max_distance=dis[i];
			index=i;
		}
	}
	return make_pair(index,max_distance);
}

void topological_sort(int **adjmatrix,int n,int u,int *visited,int *stack,int &top)
{
	visited[u]=1;
	for(int i=0;i<n;++i)
	{
		if((*(*(adjmatrix+u)+i))!=0)
		{
			if(visited[i]==0)
			{
				topological_sort(adjmatrix,n,i,visited,stack,top);
			}
		}
	}
	top++;
	stack[top]=u;
}

void LPATH(int **adjmatrix,int n,int u,int flag)
{
	if(flag==0)
	{
		pair<int,int> t1,t2;
		t1=bfs(adjmatrix,n,u);
		t2=bfs(adjmatrix,n,t1.first);
		cout<<"\nLongest path is from "<<t1.first<<" to "<<t2.first<<" of length "<<t2.second<<endl;
	}
	else if(flag==1)
	{
		int *stack=initialize_1d_array(n,0);
		int top=-1;
		int *dis=initialize_1d_array(n,INT_MIN);
		int *visited=initialize_1d_array(n,0);
		dis[u]=0;
		int v=u;
		for(int i=0;i<n;++i)
		{
			if(visited[i]==0)
			{
				topological_sort(adjmatrix,n,i,visited,stack,top);
			}
		}
		while(top!=-1)
		{
			u=stack[top];
			top--;
			if(dis[u]!=INT_MIN)
			{
				for(int i=0;i<n;++i)
				{
					if((*(*(adjmatrix+u)+i))!=0)
					{
						if(dis[i]<(dis[u]+(*(*(adjmatrix+u)+i))))
						{
							dis[i]=dis[u]+(*(*(adjmatrix+u)+i));
						}
					}
				}
			}
		}
		cout<<"\nSource vertex : "<<v;
		cout<<"\nDistance of all the other vertices from source vertex";
		cout<<"\nVertex\tDistance from source vertex"<<endl;
		for(int i=0;i<n;++i)
		{
			if(i!=v)
			{
				cout<<i<<'\t';
				(dis[i]==INT_MIN)?cout<<"No path exists":cout<<dis[i]<<" ";
				cout<<endl;
			}
		}
	}
	else
	{
		return;
	}
}

void MAX_Weight_MST(int **adjmatrix,int n)
{
	int u=rand()%n;
	int v=0;
	int front=0;
	int max;
	cout<<"\nRoot of MAX Weight MST : "<<u<<endl;
	int arr[n];
	int *visited=initialize_1d_array(n,0);;
	arr[front]=u;
	front++;
	visited[u]=1;
	cout<<"\nEdges of MAX Weight MST with weights: "<<endl;
	cout<<"\nu"<<" v "<<"w"<<endl<<endl;
	while(front!=n)
	{
		max=INT_MIN;
		for(int i=0;i<front;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(((*(*(adjmatrix+arr[i])+j))!=0) && ((*(*(adjmatrix+arr[i])+j))>max) && (arr[i]!=j) && (visited[j]==0))
				{
					max=*(*(adjmatrix+arr[i])+j);
					u=arr[i];
					v=j;
				}
			}
		}
		arr[front]=v;
		front++;
		visited[v]=1;
		visited[u]=1;
		cout<<u<<" "<<v<<" "<<max<<endl;
	}
}

struct edge
{
	int w;
	int u;
	int v;
};

bool reverse_sort(struct edge a,struct edge b)
{
	if(a.w!=b.w)
	{
		return a.w>b.w;
	}
}

void MST_youralgo(int **adjmatrix,int n)
{
	int *visited;
	visited=initialize_1d_array(n,0);
	vector<struct edge> edges;
	int **mstmatrix=initialize_adjmatrix(n);	
	int size=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if((*(*(adjmatrix+i)+j)!=0))
			{
				edges.push_back(edge());
				edges[size].u=i;
				edges[size].v=j;
				edges[size].w=*(*(adjmatrix+i)+j);
				size++;
				add_edge(mstmatrix,i,j,(*(*(adjmatrix+i)+j)));
			}
		}
	}
	sort(edges.begin(),edges.end(),reverse_sort);
	cout<<"\nMST using my Algorithm : "<<endl;
	for(int i=0;i<size;++i)
	{
		remove_edge(mstmatrix,edges[i].u,edges[i].v);
		if(check_connected(mstmatrix,edges[i].u,n)==0)
		{
			add_edge(mstmatrix,edges[i].u,edges[i].v,edges[i].w);
			cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].w<<endl;
		}
	}
}
