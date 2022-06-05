#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int last=-1;
int position=0;
int least=0;

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void minimum(int temp[],int pointer[],int k,int check[])
{
	int i;
	for(i=0;i<k;++i)
	{
		if(check[i]==1)
		{
			break;
		}
	}
	least=temp[i];
	position=i;
	for(int j=i+1;j<k;++j)
	{
		if(check[j]==1)
		{
			if(least>temp[j])
			{
				least=temp[j];
				position=j;
			}
		}
	}
}	

int main()
{
	int k;
	cout<<"\nEnter the number of arrays : ";
	cin>>k;
	int ai[k][10000];
	int size[k];
	int total_size=0;
	int i,j;
	int pointer[k];
	int temp[k];
	int check[k];
	for(i=0;i<k;++i)
	{
		cout<<"\nEnter the size of array "<<i+1<<" : ";
		cin>>size[i];
		total_size+=size[i];
		cout<<"\nEnter the elements of array "<<i+1<<" : ";
		for(j=0;j<size[i];++j)
		{
			cin>>ai[i][j];
		}
	}
	int a[total_size];
	for(i=0;i<k;++i)
	{
		pointer[i]=0;
		temp[i]=ai[i][0];
		check[i]=1;
		last++;
	}
	for(i=0;i<total_size;++i)
	{
		minimum(temp,pointer,k,check);
		a[i]=least;
		if(pointer[position]<size[position]-1)
		{
			pointer[position]++;
			j=pointer[position];
			temp[position]=ai[position][j];
		}
		else
		{
			check[position]=0;
		}
	}
	cout<<"\nComplete Sorted Array : ";
	for(i=0;i<total_size;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
