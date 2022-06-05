#include<bits/stdc++.h>

using namespace std;

void all_pairs_spath(int **graph,int n)
{
	int dist[n][n];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			dist[i][j]=*(*(graph+i)+j);
		}
	}
	for(int k=0;k<n;++k)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(((dist[i][k]+dist[k][j]<dist[i][j])) && (dist[i][k]!=INT_MAX) && (dist[k][j]!=INT_MAX))
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	cout<<"\nDistance Matrix : \n";
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(dist[i][j]==INT_MAX)
			{
				cout<<"- ";
			}
			else
			{
				cout<<dist[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	cout<<"\nEnter the number of vertices : ";
	cin>>n;
	int edge;
	cout<<"\nEnter the number of edges : ";
	cin>>edge;
	int **graph=new int* [n];
	for(int i=0;i<n;++i)
	{
		graph[i]=new int [n];
		for(int j=0;j<n;++j)
		{
			if(i!=j)
			{
				(*(*(graph+i)+j))=INT_MAX;
			}
			else
			{
				(*(*(graph+i)+j))=0;
			}
		}
	}
	int u,v,w;
	cout<<"\nEnter the edges along with their weights : \n";
	for(int i=0;i<edge;++i)
	{
		cin>>u>>v>>w;
		*(*(graph+u)+v)=w;
	}
	all_pairs_spath(graph,n);
	return 0;
}
