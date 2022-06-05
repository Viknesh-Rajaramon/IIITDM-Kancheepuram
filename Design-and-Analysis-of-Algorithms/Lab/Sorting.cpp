#include<iostream>
#include<bits/stdc++.h>

#define size 1000
#define max 10
#define dividesize 9

using namespace std;

void insertionsort(int a[],int l,int r)//Performing Insertion sort at the bottom of the Recursion Tree
{
	for(int i=l+1;i<=r;++i)
	{
		int key=a[i];
		int j=i-1;
		while((j>=l) && (a[j]>key))
		{
			a[j+1]=a[j];
			--j;
		}
		a[j+1]=key;
	}
}

void merge(int a[],int l,int m[],int r)//Using MERGE Routine to merge the sub-part in the Recursion tree
//Logic implemented by maintaining 10 pointers each for one sub-part
{
	int n[dividesize+1]={0};
	n[0]=m[0]-l+1;
	int maxsize=n[0];
	for(int i=1;i<dividesize;++i)
	{
		n[i]=m[i]-m[i-1];
		if(n[i]>maxsize)
		{
			maxsize=n[i];
		}
	}
	n[dividesize]=r-m[dividesize-1];
	if(n[dividesize]>max)
	{
		maxsize=n[dividesize];
	}
	int flag=1;
	int p[dividesize+1];
	int k=l;
	int ai[10][maxsize];
	int check[10];
	p[0]=0;
	check[0]=1;
	for(int i=0;i<n[0];++i)
	{
		ai[0][i]=a[l+i];
	}
	for(int i=1;i<=dividesize;++i)
	{
		for(int j=0;j<n[i];++j)
		{
			ai[i][j]=a[m[i-1]+1+j];
		}
		p[i]=0;
		check[i]=1;
	}
	int min=0;
	while(flag==1)
	{
		int i;
		for(i=0;i<10;++i)
		{
			flag=1;
			if(check[i]!=0)
			{
				break;
			}
			else
			{
				flag=0;
			} 
		}
		if(flag==0)
		{
			break;
		}
		min=i;
		for(i=min;i<=dividesize;++i)
		{
			if((p[i]<n[i]) && (ai[min][p[min]]>ai[i][p[i]]))
			{
					min=i;
			}
		}
		a[k]=ai[min][p[min]];
		k++;
		p[min]++;
		if(p[min]==n[min])
		{
			check[min]=0;
		}
	}
}

void divide(int a[],int l,int r)//Reducing the problem size into 10 parts
{
	if(r-l<max) //Base Case
	{
		insertionsort(a,l,r);
		return;
	}
	int m[dividesize]={0};
	m[0]=l+((r-l)/(dividesize+1));
	for(int i=1;i<dividesize;++i)
	{
		m[i]=(m[i-1]+1)+((r-l)/(dividesize+1));
	}
	divide(a,l,m[0]);
	for(int i=1;i<dividesize;++i)
	{
		divide(a,m[i-1]+1,m[i]);
	}
	divide(a,m[8]+1,r);
	merge(a,l,m,r);
}

int main()
{
	srand(time(NULL));
	int a[size];
	cout<<"\nSize of array = "<<size<<endl;
	for(int i=0;i<size;++i)
	{
		a[i]=rand()%size;
	}
	cout<<"\nArray before sorting : ";
	for(int i=0;i<size;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	divide(a,0,size-1);
	cout<<"\nArray after sorting : ";
	for(int i=0;i<size;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
