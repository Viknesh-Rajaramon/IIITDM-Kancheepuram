#include<stdio.h>
#include<math.h>

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
	else if((a-b) > 0)
	{
		return gcd(b,a-b);
	}
	else
	{
		return gcd(a,b-a);
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
}
