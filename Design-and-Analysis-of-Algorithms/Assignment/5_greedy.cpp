#include<bits/stdc++.h>

using namespace std;

struct node
{
	int u;
	int v;
	int w;
};

int min_distance(int *dist,bool sptset[],int n)
{
	int min=INT_MAX;
	int min_index;
	for(int i=0;i<n;++i)
	{
		if((sptset[i]==false) && (dist[i]<=min))
		{
			min=dist[i];
			min_index=i;
		}
	}
	return min_index;
}

void Dijkstra_algo(int **adjmatrix,int n,int source,int *dist)
{
	bool sptset[n];
	for(int i=0;i<n;++i)
	{
		dist[i]=INT_MAX;
		sptset[i]=false;
	}
	dist[source]=0;
	for(int i=0;i<n-1;++i)
	{
		int u=min_distance(dist,sptset,n);
		sptset[u]=true;
		for(int v=0;v<n;++v)
		{
			if((sptset[v]==false) && (dist[u]!=INT_MAX) && ((*(*(adjmatrix+u)+v))!=0) && (dist[v]>dist[u]+*(*(adjmatrix+u)+v)))
			{
				dist[v]=dist[u]+*(*(adjmatrix+u)+v);
			}
		}
	}
}

void Bellman_Ford_algo(int n,vector<struct node> edges,int source,int edge)
{
	int dist[n];
	for(int i=0;i<n;++i)
	{
		dist[i]=INT_MAX;
	}
	dist[source]=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<edges.size();++j)
		{
			int u=edges[j].u;
			int v=edges[j].v;
			int w=edges[j].w;
			if((dist[v]>dist[u]+w) && (dist[u]!=INT_MAX))
			{
				dist[v]=dist[u]+w;
			}
		}
	}
	for(int i=0;i<edges.size();++i)
	{
		int u=edges[i].u;
		int v=edges[i].v;
		int w=edges[i].w;
		if((dist[v]>dist[u]+w) && (dist[u]!=INT_MAX))
		{
			cout<<"\nGraph contains negative weight cycles";
			return;
		}
	}
	for(int i=0;i<edges.size();++i)
	{
		int u=edges[i].u;
		int v=edges[i].v;
		edges[i].w+=dist[u]-dist[v];
	}
	vector<struct node>::iterator it1,it2;
	it1=edges.begin()+edge;
	it2=edges.end();
	edges.erase(it1,it2);
	int distance_matrix[n-1][n-1];
	int **adjmatrix=new int* [n-1];
	for(int i=0;i<n;++i)
	{
		adjmatrix[i]=new int [n-1];
		for(int j=0;j<n-1;++j)
		{
			(*(*(adjmatrix+i)+j))=0;
			if(i==j)
			{
				distance_matrix[i][j]=0;
			}
			else
			{
				distance_matrix[i][j]=INT_MAX;
			}
		}
	}
	for(int i=0;i<edge;++i)
	{
		int u=edges[i].u;
		int v=edges[i].v;
		*(*(adjmatrix+u)+v)=edges[i].w;
	}
	for(int i=0;i<n-1;++i)
	{
		int *distance=new int [n-1];
		Dijkstra_algo(adjmatrix,n-1,i,distance);
		for(int j=0;j<n-1;++j)
		{
			distance_matrix[i][j]=distance[j];
		}
	}
	for(int i=0;i<edge;++i)
	{
		int u=edges[i].u;
		int v=edges[i].v;
		distance_matrix[u][v]+=dist[v]-dist[u];
	}
	cout<<"\nDistance Matrix : \n";
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-1;++j)
		{
			if(distance_matrix[i][j]==INT_MAX)
			{
				cout<<"- ";
			}
			else
			{
				cout<<distance_matrix[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

void add_vertex(int n,vector<struct node> edges,int edge)
{
	for(int i=0;i<n;++i)
	{
		edges.push_back(node());
		edges[edge+i].u=n;
		edges[edge+i].v=i;
		edges[edge+i].w=0;
	}
}

int main()
{
	int n;
	cout<<"\nEnter the number of vertices : ";
	cin>>n;
	vector<struct node> edges;
	int edge;
	cout<<"\nEnter the number of edges : ";
	cin>>edge;
	cout<<"\nEnter the edges with their respective weights : \n";
	for(int i=0;i<edge;++i)
	{
		edges.push_back(node());
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
	}
	add_vertex(n,edges,edge);
	Bellman_Ford_algo(n+1,edges,n,edge);
	return 0;
}
