#include<stdio.h> 
#include<stdlib.h> 

struct node  
{
	struct node *lptr;
	int data;  
	struct node *rptr; 
};

struct node *tptr=NULL;

int number_of_nodes=0;

int height(struct node *node)  
{
	if (node==NULL)
	{
		return 0;
	}
	else
	{
		int l_height = height(node->lptr);
		int r_height = height(node->rptr);
		if (l_height > r_height)
		{
			return (l_height+1);
		}
		else
		{
			return (r_height+1);
		}
	}
}

int insert(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	number_of_nodes++;
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

int main()
{
	int a,n;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		printf("\nEnter element %d : ",i);
		scanf("%d",&a);
		insert(a);
	}
	printf("\nNumber of nodes in Binary Search Tree = %d\n",number_of_nodes);
	printf("\nHeight of Binary Search Tree = %d\n",height(tptr));
	return 0;
}