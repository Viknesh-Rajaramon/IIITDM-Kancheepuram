#include<stdio.h>

int gcd(int a,int b)
{
	if(a==0)
	{
		return b;
	}
	else if(b==0)
	{
		return a;
	}
	else
	{
		while(a!=b)
		{
			if(a>b)
			{
				a=a-b;
			}
			else
			{
				b=b-a;
			}
		}
		return a;
	}
}

int main()
{
	int a,b,c;
	printf("\nEnter the two numbers : ");
	scanf("%d %d",&a,&b);
	a=abs(a);
	b=abs(b);
	printf("%d\n",gcd(a,b));
	return 0;
}
