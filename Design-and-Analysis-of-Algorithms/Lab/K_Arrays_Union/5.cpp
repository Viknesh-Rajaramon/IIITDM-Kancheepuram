#include<iostream>
#include<vector>
#include <bits/stdc++.h>

#define max 10000000

using namespace std;

int position;

struct node
{
	int data;
	int pos;
};

struct heap
{
	struct node arr[50];
	int last;
};

struct heap H;

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void insert(int x,int i)
{
	H.last++;
	H.arr[H.last].data=x;
	H.arr[H.last].pos=i;
	int t=H.last;
	while((t/2>=1) && (H.arr[t].data <= H.arr[t/2].data))
	{
		swap(H.arr[t].data,H.arr[t/2].data);
		swap(H.arr[t].pos,H.arr[t/2].pos);
		t/=2;
	}
}

int del()
{
	int x=H.arr[1].data;
	H.arr[1].data=H.arr[H.last].data;
	position=H.arr[1].pos;
	H.arr[1].pos=H.arr[H.last].pos;
	H.last--;
	int t=1;
	int min;
	while((2*t)<=H.last)
	{
		if(H.last >= 2*t+1)
		{
			if(H.arr[2*t].data < H.arr[2*t+1].data)
			{
				min=2*t;
			}
			else
			{
				min=2*t+1;
			}
		}
		else
		{
			min=2*t;
		}
		if(H.arr[t].data > H.arr[min].data)
		{
			swap(H.arr[t].data,H.arr[min].data);
			swap(H.arr[t].pos,H.arr[min].pos);
			t=min;
		}
		else
		{
			break;
		}
	}
	return x;
}

int main()
{
	int k;
	cout<<"\nEnter the number of array : ";
	cin>>k;
	int size[k];
	int pointer[k]={0};
	int ai[k][1000];
	int n;
	int total_size=0;
	for(int i=0;i<k;++i)
	{
		cout<<"\nEnter the size of array "<<i+1<<" : ";
		cin>>n;
		cout<<"\nEnter the elements of array "<<i+1<<" : ";
		for(int j=0;j<n;++j)
		{
			cin>>ai[i][j];
			total_size++;
		}
		size[i]=n;
	}
	H.last=0;
	int a[total_size];
	for(int i=0;i<k;++i)
	{
		n=pointer[i];
		insert(ai[i][n],i);
	}
	for(int i=0;i<total_size;++i)
	{
		a[i]=del();
		if(pointer[position]<size[position]-1)
		{
			pointer[position]++;
			n=pointer[position];
			insert(ai[position][n],position);
		}
	}
	printf("\nComplete Sorted array : ");
	for(int i=0;i<total_size;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;	
	return 0;
}
