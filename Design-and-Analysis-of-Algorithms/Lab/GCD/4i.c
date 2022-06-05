#include<stdio.h>
#include<math.h>

int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return gcd(b,a%b);
	}
}

int main()
{
	int k;
	printf("\nEnter the number of elements : ");
	scanf("%d",&k);
	int a[k];
	for(int i=0;i<k;++i)
	{
		scanf("%d",&a[i]);
	}
	int g=a[0];
	for(int i=1;i<k;++i)
	{
		g=abs(gcd(g,a[i]));
		if(g==1)
		{
			break;
		}
	}
	printf("%d\n",g);
}
