//IMPLEMENTATION OF CIRCULAR QUEUE

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int num;
	struct node *nptr;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->num=x;
	if(temp==NULL)
	{
		printf("\nList is full");
	}
	else if(rear==NULL)
	{
		front=rear=temp;
		temp->nptr=front;
	}
	else 
	{
		temp->nptr=front;
		rear->nptr=temp;
		rear=temp;
	}
}

int dequeue()
{
	int x;
	if(front==NULL)
	{
		printf("\nList is empty");
	}
	else if(front==rear)
	{
		x=front->num;
		front=rear=NULL;
	}
	else
	{
		x=front->num;
		front=front->nptr;
		rear->nptr=front;
	}
	return x;
}

void print()
{
	struct node *thptr=front;
	if(front!=NULL)
	{
		if((thptr->nptr)==front)
		{
			printf("%d\t",thptr->num);
		}
		else
		{
			do
			{
				printf("%d\t",thptr->num);
				thptr=thptr->nptr;
			}while(thptr!=front);
		}
	}
}

int main()
{
	enqueue(10);
	printf("\nThe list is : ");
	print();
	enqueue(1);
	printf("\nThe list is : ");
	print();
	enqueue(2);
	printf("\nThe list is : ");
	print(); 
	enqueue(7);
	printf("\nThe list is : ");
	print();
	dequeue();
	printf("\nThe list is : ");
	print();
	dequeue();
	printf("\nThe list is : ");
	print();
	dequeue();
	printf("\nThe list is : ");
	print();
	dequeue();
	printf("\nThe list is : ");
	print();
	dequeue();
	printf("\nThe list is : ");
	print();
	dequeue();
	printf("\nThe list is : ");
	print();
	printf("\n");
}