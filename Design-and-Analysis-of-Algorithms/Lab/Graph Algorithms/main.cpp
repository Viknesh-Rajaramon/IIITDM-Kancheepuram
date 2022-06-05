#include<bits/stdc++.h>
#include<vector>

#include "graph.h"

# define input_size 10

int n;

using namespace std;

void print(int **adjmatrix,int n)
{
	cout<<"\nAdjacency Matrix : "<<endl;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cout<<*(*(adjmatrix+i)+j)<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	srand(time(NULL));
	n=rand()%input_size+2;
	cout<<"\nNumber of vertices : "<<n<<endl;
	int u,v,w;
	int connected=0;
	int *visited;
	visited=initialize_1d_array(n,0);
	int **adjmatrix;
	adjmatrix=initialize_adjmatrix(n);
	while(connected==0)
	{
		u=rand()%n;
		v=rand()%n;
		w=rand()%input_size+1;
		if((u==v) || ((*(*(adjmatrix+u)+v))!=0))
		{
			connected=0;
		}
		else
		{
			add_edge(adjmatrix,u,v,w);
			cout<<u<<" "<<v<<" "<<w<<endl;
			connected=check_connected(adjmatrix,u,n);
		}
	}
	print(adjmatrix,n);
	MST_youralgo(adjmatrix,n);
	return 0;
}
