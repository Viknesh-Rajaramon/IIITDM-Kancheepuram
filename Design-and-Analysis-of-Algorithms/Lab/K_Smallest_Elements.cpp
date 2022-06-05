#include<bits/stdc++.h>
#include<cstdlib>
#include<iostream>

# define size 10

using namespace std;

void swap(int &a,int &b)//Swapping two numbers
{
	int temp=a;
	a=b;
	b=temp;
}

int partition(int a[],int l,int r)//Splitting the array into large window and small window
{
	int pivot=a[r];//Pivot element as last element in the array
	int sw=l-1;//Index of small window
	for(int j=l;j<r;++j)
	{
		if(a[j]<=pivot)
		{
			++sw;
			swap(a[sw],a[j]);
		}
	}
	sw++;
	swap(a[sw],a[r]);//Swapping pivot element and the first element in the large window
	return (i+1);
}

void kth_index(int a[],int l,int r,int k)
{
	if(l<r)
	{
		int p=partition(a,l,r);
		if(p==k)
		{
			return;
		}
		else if(p>k)
		{
			kth_index(a,l,p-1,k);
			return;
		}
		else
		{
			kth_index(a,p+1,r,k);
			return;
		}
	}
}

int main()
{
	srand(time(NULL));
	int n=rand()%size+1;
	int k=rand()%n+1;
	cout<<"\nSize of array : "<<n;
	cout<<"\n\nValue of k : "<<k;
	int a[n];
	cout<<"\n\nThe elements of array : ";
	for(int i=0;i<n;++i)
	{
		a[i]=rand()%size;
		cout<<a[i]<<" ";
	}
	kth_index(a,0,n-1,k-1);
	cout<<"\n\nK smallest elements : ";
	for(int i=0;i<k;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
