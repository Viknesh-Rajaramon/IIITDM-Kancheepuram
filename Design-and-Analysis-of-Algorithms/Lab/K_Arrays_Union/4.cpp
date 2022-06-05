#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *lptr;
	struct node *rptr;
};

struct node *hptr=NULL;

void bstconstruct(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->lptr=temp->rptr=NULL;
	if(hptr==NULL)
	{
		hptr=temp;
	}
	else
	{
		struct node *thptr=hptr;
		struct node *pptr=NULL;
		while(thptr!=NULL)
		{
			pptr=thptr;
			if(temp->data>=thptr->data)
			{
				thptr=thptr->rptr;
			}
			else
			{
				thptr=thptr->lptr;
			}
		}
		if(pptr->data>temp->data)
		{
			pptr->lptr=temp;
		}
		else
		{
			pptr->rptr=temp;
		}
	}
}

void inorder(struct node *ptr)
{
	if(ptr==NULL)
	{
		return;
	}	
	inorder(ptr->lptr);
	printf("%d ",ptr->data);
	inorder(ptr->rptr);
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
	for(i=0;i<k;++i)
	{
		for(j=0;j<ai[i].size();++j)
		{
			a.push_back(ai[i][j]);
		}
	}
	for(i=0;i<a.size();++i)
	{
		bstconstruct(a[i]);
	}
	printf("\nComplete Sorted array : ");
	inorder(hptr);
	cout<<endl;
	return 0;
}
