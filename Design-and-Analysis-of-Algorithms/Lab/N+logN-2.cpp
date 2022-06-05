#include<bits/stdc++.h>
#include<cstdlib>
#include<iostream>

# define input_size 10

using namespace std;

struct node
{
	int data;
	struct node *lptr;
	struct node *rptr;
};

struct node *new_node(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->lptr=temp->rptr=NULL;
	return temp;
}

void traverse_height(struct node *ptr,int a[],int &res)
{
	if((ptr==NULL) || ((ptr->lptr==NULL) && (ptr->rptr==NULL)))
	{
		return;
	}
	if((res>a[(ptr->lptr)->data]) && ((ptr->lptr)->data != ptr->data))
	{
		res=a[(ptr->lptr)->data];
		traverse_height(ptr->rptr,a,res);
	}
	else if((res>a[(ptr->rptr)->data]) && ((ptr->rptr)->data != ptr->data))
	{
		res=a[(ptr->rptr)->data];
		traverse_height(ptr->lptr,a,res);
	}
}

void secondmin(int a[],int n)
{
	list<node *>l;
	struct node *root=NULL;
	for(int i=0;i<n;i+=2)
	{
		node *t1=new_node(i);
		node *t2=NULL;
		if(i+1<n)
		{
			t2=new_node(i+1);
			root=a[i]<a[i+1]?new_node(i):new_node(i+1);
			root->lptr=t1;
			root->rptr=t2;
			l.push_back(root);
		}
		else
		{
			l.push_back(t1);
		}
	}
	int size=l.size();
	while(size!=1)
	{
		int last=(size&1)?(size-2):(size-1);
		for(int i=0;i<last;i+=2)
		{
			node *f1=l.front();
			l.pop_front();
			node *f2=l.front();
			l.pop_front();
			root=(a[f1->data]<a[f2->data])?new_node(f1->data):new_node(f2->data);
			root->lptr=f1;
			root->rptr=f2;
			l.push_back(root);
		}
		if(size&1)
		{
			l.push_back(l.front());
			l.pop_front();
		}
		size=l.size();
	}
	int res=INT_MAX;
	traverse_height(root,a,res);
	cout<<"\n\nSecond minimum : "<<res<<endl;
}

int main()
{
	srand(time(NULL));
	int n=rand()%input_size+1;
	cout<<"\nSize of array : "<<n;
	int a[n];
	cout<<"\n\nThe elements of array : ";
	for(int i=0;i<n;++i)
	{
		a[i]=rand()%input_size;
		cout<<a[i]<<" ";
	}
	if(n==1)
	{
		cout<<"\n\nSecond Minimum does not exist"<<endl;
	}
	else
	{
		secondmin(a,n);
	}
	return 0;
}
