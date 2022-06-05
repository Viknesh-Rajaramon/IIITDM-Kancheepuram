#include<bits/stdc++.h>

using namespace std;

int z;

void sconquer(int a[],int l,int ai[][1000],int size[])
{
	z=0;
	if(l==0)
	{
		z=0;
	}
	else
	{
		for(int i=0;i<l;++i)
		{
			z+=size[i];
		}
	}
	for(int i=0;i<size[l];++i)
	{
		a[z]=ai[l][i];
		z++;
	}
	
}

void bconquer(int a[],int l,int r,int ai[][1000],int size[])
{
	z=0;
	if(l==0)
	{
		z=0;
	}
	else
	{
		for(int i=0;i<l;++i)
		{
			z+=size[i];
		}
	}
	int i=0,j=0;
	while((i!=size[l]) && (j!=size[r]))
	{
		if(ai[l][i]<ai[r][j])
		{
			a[z]=ai[l][i];
			++i;
		}
		else
		{
			a[z]=ai[r][j];
			++j;
		}
		++z;
	}
	while(i!=size[l])
	{
		a[z]=ai[l][i];
		++z;
		++i;
	}
	while(j!=size[r])
	{
		a[z]=ai[r][j];
		++z;
		++j;
	}	
}

void conquer(int a[],int size[],int l,int m,int r)
{
	z=0;
	if(l==0)
	{
		z=0;
	}
	else
	{
		for(int i=0;i<l;++i)
		{
			z+=size[i];
		}
	}
	int s1=0,s2=0;
	int p=0,q=0;
	for(int i=l;i<=m;++i)
	{
		s1+=size[i];
	}
	for(int i=m+1;i<=r;++i)
	{
		s2+=size[i];
	}
	int t1[s1],t2[s2];
	for(int j=z;j<s1;++j)
	{
		t1[p]=a[j];
		++p;
	}
	for(int j=s1;j<s1+s2;++j)
	{
		t2[q]=a[j];
		++q;
	}
	int i=0,j=0;
	while((i!=p) && (j!=q))
	{
		if(t1[i]<t2[j])
		{
			a[z]=t1[i];
			++i;
		}
		else
		{
			a[z]=t2[j];
			++j;
		}
		++z;
	}
	while(i!=p)
	{
		a[z]=t1[i];
		++z;
		++i;
	}
	while(j!=q)
	{
		a[z]=t2[j];
		++z;
		++j;
	}
}

void divide(int a[],int ai[][1000],int l,int r,int size[])
{
	if(l==r)
	{
		sconquer(a,l,ai,size);
		return;
	}
	if(r-l==1)
	{
		bconquer(a,l,r,ai,size);
		return;
	}
	int m=((l+r)/2);
	divide(a,ai,l,m,size);
	divide(a,ai,m+1,r,size);
	conquer(a,size,l,m,r);
	return;
}


int main()
{
	int k;
	cout<<"\nEnter the number of arrays : ";
	cin>>k;
	int ai[k][1000];
	int size[k];
	int total_size=0;
	int i,j;
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
	divide(a,ai,0,k-1,size);
	cout<<"\nSorted array : ";
	for(i=0;i<total_size;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
