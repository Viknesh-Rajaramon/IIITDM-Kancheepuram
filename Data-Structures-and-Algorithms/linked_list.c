#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *nptr;
};
struct node *hptr=NULL;
void insert(int x,int pos);
void print();
int main()
{
	insert(2,0);	
	insert(20,1);
	insert(10,1);
	insert(12,3);
	insert(23,1);
	insert(25,0); 
	print();
	return 2110;
}
void insert(int x, int pos)
{
	struct node *temp =(struct node *) malloc(sizeof(struct node));
	int i=0;
	struct node *thptr=hptr;
	temp->data= x;
	if(pos==0)
	{	
		temp->nptr= hptr;
		hptr=temp;	
	}	
	else
	{
		while(i<pos-1)	
		{		
			thptr=thptr->nptr;
			i++;
		}
		temp->nptr=thptr->nptr;
		thptr->nptr=temp;
	}
}
void print()
{
	struct node *thptr = hptr;
		
	while(thptr != NULL)
	{
		printf("%d\t",thptr->data);
		thptr = thptr -> nptr;
	}
}
