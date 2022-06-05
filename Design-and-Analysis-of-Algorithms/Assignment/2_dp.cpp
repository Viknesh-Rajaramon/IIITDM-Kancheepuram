#include<bits/stdc++.h>

using namespace std;

void coins_change(int d[],int limit[],int k,int x)
{
	int coins[x+1];
	int spent[x+1][k]={0};
	coins[0]=0;
	for(int i=1;i<=x;++i)
	{
		coins[i]=INT_MAX;
	}
	for(int i=1;i<=x;++i)
	{
		for(int j=0;j<k;++j)
		{
			if(d[j]<=i)
			{
				int r=coins[i-d[j]];
				if((r!=INT_MAX) && (r+1<coins[i]) && (limit[j]-spent[i-d[j]][j]>0))
				{
					coins[i]=r+1;
					spent[i][j]=spent[i-d[j]][j]+1;
					for(int p=0;p<k;++p)
					{
						if(p!=j)
						{
							spent[i][p]=spent[i-d[j]][p];
						}
					}
				}
			}
		}
	}
	cout<<"\nCoins    Number of Coins"<<endl;
	for(int i=0;i<k;++i)
	{
		cout<<d[i]<<"\t\t"<<spent[x][i]<<endl;
	}
}

int main()
{
	int k;
	cout<<"\nEnter the number of coins : ";
	cin>>k;
	int d[k];
	int limit[k];
	int min_d=INT_MAX;
	cout<<"\nEnter the (denominations,limit) : \n";
	for(int i=0;i<k;++i)
	{
		cin>>d[i]>>limit[i];
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
	coins_change(d,limit,k,x);
	return 0;
}
