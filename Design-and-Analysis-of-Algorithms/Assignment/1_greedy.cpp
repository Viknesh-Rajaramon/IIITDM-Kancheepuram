#include<bits/stdc++.h>

using namespace std;

int comparator(const void *a, const void *b)
{
	return(*(int*)a-*(int*)b);
}

void coin_change(int d[],int k,int x)
{
	qsort(d,k,sizeof(int),comparator);
	int coins[k]={0};
	for(int i=k-1;i>=0;--i)
	{
		while(x>=d[i])
		{
			x-=d[i];
			coins[i]++;
		}
	}
	if(x==0)
	{
		cout<<"\nCoins    Number of Coins"<<endl;
		for(int i=k-1;i>=0;--i)
		{
			if(coins[i]!=0)
			{
				cout<<d[i]<<"\t\t"<<coins[i]<<endl;
			}
		}
	}
	else
	{
		cout<<"\nChange is not possible witn the given denominations...\n";
	}
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
