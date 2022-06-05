//EVALUATION OF POSTFIX EXPRESSION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node 
{ 
	int data; 
	struct node *nptr;
};

struct node *tptr=NULL;

void push(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->nptr=tptr;
	tptr=temp;
}

int pop()
{
	int x=tptr->data;
	tptr=tptr->nptr;
	return x;
}

int main()
{
	char ar[100];
	int x;
	printf("\nEnter a postfix expression : ");
	gets(ar);
	for(int i=0;ar[i]!='\0';++i)
	{
		if(isdigit(ar[i]))
		{
			x=ar[i]-48;
			push(x);
		}
		else
		{
			int x2=pop();
			int x1=pop();
			switch(ar[i])
			{
				case '+':
					x=x1+x2;
					push(x);
					break;
				case '-':
					x=x1-x2;
					push(x);
					break;
				case '*':
					x=x1*x2;
					push(x);
					break;
				case '/':
					x=x1/x2;
					push(x);
					break;
			}
		}
	}
	x=pop();
	if(tptr!=NULL)
	{
		printf("\nInvalid postfix expression");
	}
	else
	{
		printf("\nThe value after evaluation : %d\n",x);
	}
	return 0;
}