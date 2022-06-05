#include<bits/stdc++.h>

using namespace std;

void coin_change(int d[],int k,int x)
{
	int M[x+1];
	M[0]=0;
	for(int i=1;i<=x;++i)
	{
		M[i]=INT_MAX;
	}
	for(int i=1;i<=x;++i)
	{
		for(int j=0;j<k;++j)
		{
			if(d[j]<=i)
			{
				int r=M[i-d[j]];
				if((r!=INT_MAX) && (r+1<M[i]))
				{
					M[i]=r+1;
				}
			}
		}
	}
	cout<<"\nMinimum number of coins = "<<M[x]<<endl;
}

int main()
{
	int k;
	cout<<"\nEnter the number of denominations : ";
	cin>>k;
	int d[k];
	int min_d=INT_MAX;
	cout<<"\nEnter the denominations : ";
	for(int i=0;i<k;++i)
	{
		cin>>d[i];
		if(d[i]<min_d)
		{
			min_d=d[i];
		}
	}
	int x;
	cout<<"\nEnter an integer x : ";
	cin>>x;
	if(x<min_d)
	{
		cout<<"\nChange does not exist...";
		return 0;
	}
	coin_change(d,k,x);
	return 0;
}
