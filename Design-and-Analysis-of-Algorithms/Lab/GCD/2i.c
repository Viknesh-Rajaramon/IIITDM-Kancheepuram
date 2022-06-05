#include<stdio.h>
#include<math.h>

int gcd(int a,int b)
{
	if(a==b)
	{
		return abs(a);
	}
	if(b>a)
	{
		b=b+a;
		a=b-a;
		b=b-a;
	}
	if(b==0)
	{
		return a;
	}
	for(int i=b;i>=1;--i)
	{
		if((a%i==0) &&  (b%i==0))
		{
			return i;
		}
	}
}

int main()
{
	int a,b;
	printf("\nEnter the two numbers : ");
	scanf("%d %d",&a,&b);
	a=abs(a);
	b=abs(b);
	printf("GCD = %d\n",gcd(a,b));
	return 0;
}
