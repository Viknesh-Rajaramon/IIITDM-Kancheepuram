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
		tptr = temp;	
	else
	{
		struct node* ptr = tptr;
		struct node* pptr = NULL;		
		while(ptr != NULL)
		{
			pptr = ptr;
			if(x<ptr->data)
				ptr = ptr->lptr;
			else 
				ptr = ptr->rptr;
		}
		if(x<pptr->data)
			pptr->lptr = temp;
		else 
			pptr->rptr = temp;
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

void main()
{
	int a[20];
	printf("enter the no of nodes ");
	int n;
	scanf("%d",&n);
	printf("enter the postorder");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		insert(a[n-i-1]);
	}
	inorder(tptr);
}