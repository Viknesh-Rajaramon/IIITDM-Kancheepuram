#include<stdio.h>
#include<stdlib.h>

#define hsize 10

struct node
{
	int data;
	struct node *nptr;
};

struct node *p[hsize]={NULL};

int hash(int data)
{
	return data % hsize;
}

void insert(int num,int key)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	temp->nptr=NULL;
	if(p[key]==NULL)
	{
		p[key]=temp;
	}
	else
	{
		struct node *thptr=p[key];
		while(thptr->nptr!=NULL)
		{
			thptr=thptr->nptr;
		}
		thptr->nptr=temp;
	}
}

void search(int num,int key)
{
	if(p[key]==NULL)
	{
		printf("\nElement not in Hash Table");
	}
	else
	{
		struct node *thptr=p[key];
		while(thptr!=NULL)
		{
			if(thptr->data==num)
			{
				printf("\nElement found in Hash Table");
				break;
			}
			thptr=thptr->nptr;
		}
		if(thptr==NULL)
		{
			printf("\nElement not found in Hash Table");
		}
	}
}

void delete(int num,int key)
{
	if(p[key]==NULL)
	{
		printf("\nElement not in Hash Table");
	}
	else
	{
		struct node *ptr=NULL;
		struct node *thptr=p[key];
		while(thptr!=NULL)
		{
			if(thptr->data==num)
			{
				ptr->nptr=thptr->nptr;
				printf("\nElement deleted from Hash Table");
				break;
			}
			ptr=thptr;
			thptr=thptr->nptr;
		}
		if(thptr==NULL)
		{
			printf("\nElement not in Hash Table");
		}
	}
}

void print()
{
	for(int i=0;i<hsize;++i)
	{
		if(p[i]!=NULL)
		{
			struct node *thptr=p[i];
			while(thptr!=NULL)
			{
				printf("->%d ",thptr->data);
				thptr=thptr->nptr;
			}
		}
		printf("\n");
	}
}

int main()
{
	int n;
	int a;
	int choice;
	for(int i=0;i<hsize;++i)
	{
		insert(i,i);
	}
	printf("\n1. Insertion\n2. Search\n3. Deletion\nEnter your choice : ");
	scanf("%d",&choice);
	while((choice>=1) && (choice<=3))
	{
		switch(choice)
		{
			case 1 :
				printf("\nEnter the number of elements to be inserted : ");
				scanf("%d",&n);
				for(int i=0;i<n;++i)
				{
					printf("\nElement %d : ",i+1);
					scanf("%d",&a);
					insert(a,hash(a));
				}
				printf("\nThe elements in Hash Table...\n");
				print();
				break;
			case 2 :
				printf("\nEnter the element to be searched for : ");
				scanf("%d",&a);
				search(a,hash(a));
				break;
			case 3 :
				printf("\nEnter the element to be deleted : ");
				scanf("%d",&a);
				delete(a,hash(a));
				printf("\nThe elements in Hash Table...\n");
				print();
				break;
		}
		printf("\n1. Insertion\n2. Search\n3. Deletion\n4.Exit\nEnter your choice : ");
		scanf("%d",&choice);
	}
	return 0;
}