#include<bits/stdc++.h>

using namespace std;

struct node
{
	int u;
	int v;
	int w;
};

void Bellman_Ford_algo(int n,vector<struct node> edges,int source)
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
	cout<<"\nVertex   Distance from Source\n";
	for(int i=0;i<n;++i)
	{
		if(i!=source)
		{
			if(dist[i]==INT_MAX)
			{
				cout<<i<<"\tPath does not exist"<<endl;
			}
			else
			{
				cout<<i<<'\t'<<dist[i]<<endl;
			}
		}
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
	int source;
	cout<<"\nEnter the source vertex : ";
	cin>>source;
	Bellman_Ford_algo(n,edges,source);
	return 0;
}
