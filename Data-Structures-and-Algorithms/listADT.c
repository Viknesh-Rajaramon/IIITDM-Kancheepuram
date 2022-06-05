#include<stdio.h>
#include<stdlib.h>
struct List
{

	int a[100];
	int lsize;
};

void Insert(struct List *pl1,int x,int pos)
{
	for(int i=pl1->lsize-1;i>=pos;i--)
		{
			pl1->a[i+1]=pl1->a[i];
		}
	pl1->a[pos]=x;
	pl1->lsize=pl1->lsize+1;
}

int delete(struct List *pl1, int pos)
{
	int x;
	x=pl1->a[pos];
	for(int i = pos + 1; i<pl1->lsize; i++)
			pl1->a[i-1] = pl1->a[i];
	pl1->lsize = pl1->lsize-1;
	return x;
}
int isempty(struct List *pl1)
{
	if(pl1->lsize==0)
		return 1;
	else
		return 0;
}
int isfull(struct List *pl1)
{
	if(pl1->lsize==100)
		return 1;
	else
		return 0;
}
int search(struct List *pl1, int x)
{
	int flag=0;
	for(int i=0; i<pl1->lsize; i++)
		if(pl1->a[i]==x)
		{
			flag++;
			return 1;
		}
	if(flag==0)
		return 0;
}
int main()
{
	struct List l1,*pl1;
	int x;
	pl1=&l1;
	l1.lsize=0;//Empty List is created
	Insert(pl1,5,0);
	Insert(pl1,4,1);
	Insert(pl1,15,0);
	Insert(pl1,5,1);
	for(int i=0;i<pl1->lsize;i++)
	{
		printf("%d ",pl1->a[i]);
	}	
	delete(pl1, 2);
	printf("\n");
	for(int i=0;i<pl1->lsize;i++)
	{
		printf("%d ",pl1->a[i]);
	}
	delete(pl1, 1);
	delete(pl1, 0);
	delete(pl1, 2);
	printf("\n%d", isempty(pl1));
	printf("\n%d", isfull(pl1));
	Insert(pl1,5,0);
	Insert(pl1,4,1);
	Insert(pl1,15,0);
	Insert(pl1,5,1);		
	printf("Enter number to search\n");
	scanf("%d",&x);	
	if(search(pl1, x))
		printf("\nNumber found");
	else
		printf("\nNumber not found");
	return 0;
}
