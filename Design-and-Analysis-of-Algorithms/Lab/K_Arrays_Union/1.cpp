#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int> a,vector<int> b)
{
	int len1=a.size();
	int len2=b.size();
	int len=len1+len2;
	vector<int> c(len);
	int i=0,j=0,k=0;
	while((i<len1) && (j<len2))
	{
		if(a[i]<b[j])
		{
			c[k++]=a[i++];
		}
		else
		{
			c[k++]=b[j++];
		}
	}
	while(i<len1)
	{
		c[k++]=a[i++];
	}
	while(j<len2)
	{
		c[k++]=b[j++];
	}
	return c;
}

int main()
{
	vector<int> a;
	int k;
	cout<< "\nEnter the number of arrays : ";
	cin>>k;
	vector<int> ai[k];
	int i,j;
	int s;
	vector<int> size;
	for(i=0;i<k;++i)
	{
		cout<<"\nEnter the size of array "<< i+1 <<": ";
		cin>>s;
		size.push_back(s);
	}
	auto scan=size.begin();
	for(i=0;i<k;++i)
	{
		cout<<"\nEnter the elements of array "<<i+1<<" in sorted order : ";
		for(j=0;j<*(scan);++j)
		{
			int c;
			cin>>c;
			ai[i].push_back(c);
		}
		scan++;
	}
	a=merge(ai[0],ai[1]);
	for(i=2;i<k;++i)
	{
		a=merge(a,ai[i]);
	}
	printf("\nComplete Sorted array : ");
	for(i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
