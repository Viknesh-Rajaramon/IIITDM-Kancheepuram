//CALCULATING THE VALUE OF A POLYNOMIAL GIVEN THE VALUE OF X (STATIC MEMORY)

#include<stdio.h>
#include<math.h>

struct polynomial
{
	int c[100];
	int deg;
	int x;
	long ans;
	int size;
};

int insert(struct polynomial *p,int a,int pos)
{
	for(int i=p->size-1;i>=pos;--i)
	{
		p->c[i+1]=p->c[i];
	}
	p->c[pos]=a;
	return 0;
}

void coeff(struct polynomial *p)
{
	int a;
	p->size=0;
	for(int i=0;i<=p->deg;++i)
	{
		printf("\nEnter the coefficient of x^%d :",p->deg-i);
		scanf("%d",&a);
		p->size=(p->size)+1;
		insert(p,a,0);
	}
}

void calc(struct polynomial *p)
{
	for(int i=0;i<=p->deg;++i)
	{
		p->ans=((p->ans)+((p->c[i])*(pow(p->x,i))));
	}
}

int main()
{
	struct polynomial p1,*pp1;
	pp1=&p1;
	pp1->ans=0;
	printf("\nLet the polynomial be of the form an(x^n)+an-1(x^n-1)+...+a1(x)+a0");
	printf("\nEnter the degree of polynomial : ");
	scanf("%d",&p1.deg);
	coeff(pp1);
	printf("\nEnter the value of x = ");
	scanf("%d",&p1.x);
	calc(pp1);
	printf("\nThe value of polynomial for x=%d is : %ld\n",pp1->x,pp1->ans);
	return 0;
}