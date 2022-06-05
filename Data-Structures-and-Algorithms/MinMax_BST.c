#include<stdio.h>
#include<stdlib.h>

int min1=0,min2=0,max1=0,max2=0;

struct node
{
	struct node *lptr;
	int data;
	struct node *rptr;
};

struct node *tptr=NULL;

void insert(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->lptr=temp->rptr=NULL;
	if(tptr==NULL)
	{
		tptr=temp;
	}
	else
	{
		struct node *ptr=tptr;
		struct node *pptr=NULL;
		while(ptr!=NULL)
		{
			pptr=ptr;
			if(x<pptr->data)
			{
				ptr=ptr->lptr;
			}
			else
			{
				ptr=ptr->rptr;
			}
		}
		if(x<pptr->data)
		{
			pptr->lptr=temp;
		}
		else
		{
			pptr->rptr=temp;
		}
	}
}

void minimum(struct node *ptr)
{
	if(min1==0)
	{
		min1=ptr->data;
		min2=ptr->data;
	}
	else if((min1==min2) && (ptr->data>min1))
	{
		min2=ptr->data;
	}
	else if((min1==min2) && (ptr->data<min1))
	{
		min2=min1;
		min1=ptr->data;
	}
	else
	{}
}

void traverse_min(struct node *ptr)
{
	if(ptr != NULL)
	{
		traverse_min(ptr->lptr);
		minimum(ptr);
		traverse_min(ptr->rptr);
	}
}

void maximum(struct node *ptr)
{
	if(max1==0)
	{
		max1=ptr->data;
		max2=ptr->data;
	}
	else if((max1==max2) && (ptr->data<max1))
	{
		max2=ptr->data;
	}
	else if((max1==max2) && (ptr->data>max1))
	{
		max2=max1;
		max1=ptr->data;
	}
	else
	{}
}

void traverse_max(struct node *ptr)
{
	if(ptr != NULL)
	{
		traverse_max(ptr->rptr);
		maximum(ptr);
		traverse_max(ptr->lptr);
	}
} 
  
void main()
{
	int a,n; 
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	printf("\nEnter the elements : ");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a);
		insert(a);
	}
	traverse_min(tptr);
	if(min1!=0)
	{
		printf("\nMinimum 1 : %d",min1);
		if(min2!=0)
		{
			printf("\nMinimum 2 : %d",min2);
		}
		else
		{
			printf("\nMinimum 2 does not exist...");
		}
	}
	else
	{
		printf("\nMinimum 1 does not exist...");
		printf("\nMinimum 2 does not exist...");
	} 
	traverse_max(tptr);
	if(max1!=0)
	{
		printf("\nMaximum 1 : %d",max1);
		if(max2!=0)
		{
			printf("\nMaximum 2 : %d",max2);
		}
		else
		{
			printf("\nMaximum 2 does not exist...");
		}
	}
	else
	{
		printf("\nMaximum 1 does not exist...");
		printf("\nMaximum 2 does not exist...");
	} 
}