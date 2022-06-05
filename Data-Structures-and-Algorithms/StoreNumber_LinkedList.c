#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node *nptr;
};

struct node *hptr=NULL;

void insert(int x,int pos)
{
	struct node *temp=(struct node *) malloc(sizeof(struct node));
	struct node *thptr=hptr;
	temp->num=x;
	if(pos==0)
	{
		temp->nptr=hptr;
		hptr=temp;
	}
	else
	{
		for(int i=0;i<pos-1;++i)
		{
			thptr=thptr->nptr;
		}
		temp->nptr=thptr->nptr;
		thptr->nptr=temp;
	}
}

void print()
{
	struct node *thptr=hptr;
	while(thptr!=NULL)
	{
		printf("%d",thptr->num);
		thptr=thptr->nptr;
	}
	printf("\n");
}

int main()
{
	int dig,num;
	printf("\nEnter the number of digits : ");
	scanf("%d",&dig);
	for(int i=0;i<dig;++i)
	{
		printf("\nEnter digit %d : ",i+1);
		scanf("%d",&num);
		insert(num,i);
	}
	printf("\nThe number is : ");
	print();
	return 0;
}