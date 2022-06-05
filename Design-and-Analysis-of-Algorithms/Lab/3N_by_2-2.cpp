#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>

#define input_size 100 // Input Size

using namespace std;

int mini;//Calculating minimum in each sub-part
int maxi;//Storing maximum in each sub-part

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void minmax(int &a,int &b)
{
	if(a>b)
	{
		swap(a,b);
	}
}

void minimum(int a[],int size)
{
	mini=a[0];
	for(int i=2;i<size;i+=2)
	{
		if(mini>a[i])
		{
			mini=a[i];
		}
	}
	if(size%2!=0)
	{
		mini=mini>a[size]?a[size]:mini;
	}
}

void maximum(int a[],int size)
{
	maxi=a[1];
	for(int i=3;i<size;i+=2)
	{
		if(maxi<a[i])
		{
			maxi=a[i];
		}
	}
	if(size%2!=0)
	{
		maxi=maxi<a[size]?a[size]:maxi;
	}
}

int main()
{
	srand(time(NULL));
	int n=rand()%input_size+1;
	cout<<"\nSize of array : "<<n;
	int a[n];
	int i,j;
	cout<<"\nElements of the array : ";
	for(i=0;i<n;++i)
	{
		a[i]=rand()%input_size;
		cout<<a[i]<<" ";
	}
	for(i=0;i<n;i+=2)
	{
		if(n-i!=1)
		{
			minmax(a[i],a[i+1]);
		}
	}
	minimum(a,n);
	maximum(a,n);
	cout<<"\nMinimum = "<<mini<<"\nMaximum = "<<maxi;
	cout<<endl;
	return 0;
}
