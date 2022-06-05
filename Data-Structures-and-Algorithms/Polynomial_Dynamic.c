//CALCULATING THE VALUE OF A POLYNOMIAL GIVEN THE VALUE OF X (DYNAMIC MEMORY)

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct polynomial
{
	int c;
	int power;
	truct polynomial *nptr;
};

struct polynomial *hptr=NULL;

void insert(int a,int p,int pos)
{
	struct polynomial *temp=(struct polynomial *) malloc(sizeof(struct polynomial));
	struct polynomial *thptr=hptr;
	temp->c=a;
	temp->power=p;
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

int calc(int x)
{
	int ans=0;
	struct polynomial *thptr=hptr;
	while(thptr!=NULL)
	{
		ans+=((thptr->c)*(pow(x,(thptr->power))));
		thptr=thptr->nptr;
	}
	return ans;
}

int main()
{
	int x,n,a;
	int ans=0;
	printf("\nLet the polynomial be of the form an(x^n)+an-1(x^n-1)+...+a1(x)+a0");
	printf("\nEnter the degree of polynomial : ");
	scanf("%d",&n);
	for(int i=0;i<=n;++i)
	{
		printf("\nEnter the coefficient of x^%d :",i);
		scanf("%d",&a);
		insert(a,i,i);
	}
	printf("\nEnter the value of x : ");
	scanf("%d",&x);
	printf("\nThe value of polynomial for x=%d is : %d\n",x,calc(x));
	return 0;
}