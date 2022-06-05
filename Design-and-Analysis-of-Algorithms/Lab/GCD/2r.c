#include<stdio.h>

int gcd(int a,int b,int x)
{
	if(a==0)
	{
		return b;
	}
	else if(b==0)
	{
		return a;
	}
	else if((a%x==0) && (b%x==0))
	{
		return x;
	}
	else
	{
		return gcd(a,b,--x);
	}	
}

int main()
{
	int a,b,x=0;
	printf("\nEnter the two numbers : ");
	scanf("%d %d",&a,&b);
	a=abs(a);
	b=abs(b);
	if(b>a)
	{
		b=b+a;
		a=b-a;
		b=b-a;
	}
	x=b;
	printf("%d\n",gcd(a,b,x));
}
