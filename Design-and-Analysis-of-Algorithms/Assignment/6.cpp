#include<bits/stdc++.h>

using namespace std;

void profit_knapsack(int w[],int p[],int n,int W)
{
	int M[n+1][W+1];
	for(int i=0;i<=W;++i)
	{
		M[0][i]=0;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=W;++j)
		{
			if(j<w[i-1])
			{
				M[i][j]=M[i-1][j];
			}
			else
			{
				M[i][j]=max(M[i-1][j],p[i-1]+M[i-1][j-w[i-1]]);
			}
		}
	}
	cout<<"\nTable : "<<endl;
	for(int i=n;i>=0;--i)
	{
		for(int j=0;j<=W;++j)
		{
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	int OPT[3]={INT_MIN,0,0};
	bool solution[n]={false};
	for(int i=n;i>0;--i)
	{
		if(OPT[0]<M[i][W])
		{
			OPT[0]=M[i][W];
			OPT[1]=i;
			OPT[2]=W;
		}
	}
	int i=OPT[1];
	int j=OPT[2];
	while((i>0) && (j>0))
	{
		if(M[i-1][j]>p[i-1]+M[i-1][j-w[i-1]])
		{
			solution[i-1]=false;
			i=i-1;
		}
		else
		{
			solution[i-1]=true;
			j=j-w[i-1];
			i=i-1;
		}
	}
	cout<<"\nSolution Set : ";
	for(int i=0;i<n;++i)
	{
		if(solution[i])
		{
			cout<<1<<" ";
		}
		else
		{
			cout<<0<<" ";
		}
	}
	cout<<endl;
}

int main()
{
	int n;
	cout<<"\nEnter the number of objects : ";
	cin>>n;
	cout<<"\nThe objects are numbered from "<<0<<" to "<<n-1<<endl;
	int w[n];
	int p[n];
	cout<<"\nEnter the weights and the respective profits of the objects : \n";
	for(int i=0;i<n;++i)
	{
		cin>>w[i]>>p[i];
	}	
	int W=5;
	cout<<"\nEnter the capacity of Knap Sack : ";
	cin>>W;
	profit_knapsack(w,p,n,W);
	return 0;
}
