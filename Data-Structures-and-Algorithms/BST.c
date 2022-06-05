//INSERTION, DELETION & SEARCH OF BINARY SEARCH TREE

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node* lptr;
	int data;
	struct node* rptr;
};

struct node* tptr = NULL;

void insert(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->lptr = temp->rptr = NULL;
	if(tptr == NULL)
	{
		tptr = temp;
	}
	else
	{
		struct node* ptr = tptr;
		struct node* pptr = NULL;		
		while(ptr != NULL)
		{
			pptr = ptr;
			if(x<ptr->data)
			{
				ptr = ptr->lptr;
			}
			else 
			{
				ptr = ptr->rptr;
			}
		}
		if(x<pptr->data)
		{
			pptr->lptr = temp;
		}
		else 
		{
			pptr->rptr = temp;
		}
	}
}

void inorder(struct node* ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr->lptr);
		printf("%d ",ptr->data);
		inorder(ptr->rptr);
	}
}

void postorder(struct node* ptr)
{
	if(ptr != NULL)
	{
		postorder(ptr->lptr);
		postorder(ptr->rptr);
		printf("%d ",ptr->data);
	}
}

void preorder(struct node* ptr)
{
	if(ptr != NULL)
	{
		printf("%d ",ptr->data);
		preorder(ptr->lptr);
		preorder(ptr->rptr);
	}
}

int delete(int x)
{
	struct node *ptr=tptr,*pptr=NULL;
	while(ptr->data!=x)
	{
		pptr=ptr;
		if(x<ptr->data)
		{
			ptr=ptr->lptr;
		}
		else
		{
			ptr=ptr->rptr;
		}
	}
	if((ptr->lptr==NULL) && (ptr->rptr==NULL))
	{
		if(x<pptr->data)
		{
			pptr->lptr=NULL;
		}
		else
		{
			pptr->rptr=NULL;
		}
	}
	else if((ptr->lptr!=NULL) && (ptr->rptr!=NULL))
	{
		struct node *xsucc=ptr->rptr,*pxsucc=ptr;
		while(xsucc->lptr!=NULL)
		{
			pxsucc=xsucc;
			xsucc=xsucc->lptr;
		}
		ptr->data=xsucc->data;
		if(xsucc->data<pxsucc->data)
		{
			pxsucc->lptr=xsucc->rptr;
		}
		else
		{
			pxsucc->rptr=xsucc->rptr;
		}
	}
	else
	{
		if(ptr->lptr!=NULL)
		{
			if(x<pptr->data)
			{
				pptr->lptr=ptr->lptr;
			}
			else
			{
				pptr->rptr=ptr->lptr;
			}
		}
		else
		{
			if(x<pptr->data)
			{
				pptr->lptr=ptr->rptr;
			}
			else
			{
				pptr->rptr=ptr->rptr;
			}
		}
	}
	return x;
}

int search(int x)
{
	struct node *ptr=tptr;
	while(ptr!=NULL)
	{
		if(x==ptr->data)
		{
			return 1;
		}
		else if(x<ptr->data)
		{
			ptr=ptr->lptr;
		}
		else
		{
			ptr=ptr->rptr;
		}
	}
	return 0;
}

void main()
{
	int n;
	int a;
	printf("\nEnter the number of elements to be inserted in BST : ");
	scanf("%d",&n);
	printf("\nEnter the elements : ");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a);
		insert(a);
	}
	printf("\nEnter the element to be searched : ");
	scanf("%d",&a);
	int flag=search(a);
	if(flag==1)
	{
		printf("\nElement found...");
	}
	else
	{
		printf("\nElement not found...");
	}
	printf("\nEnter the element to be deleted : ");
	scanf("%d",&a);
	printf("\nElement deleted : %d",delete(a));
	printf("\nIn order ");
	inorder(tptr);
	printf("\nPost order ");
	postorder(tptr);
	printf("\nPre order ");
	preorder(tptr);
}