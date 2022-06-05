//SIMPLIFICATION OF P/Q RATIO OF RATIONAL NUMBER

#include<stdio.h>

struct rational
{
	int num;
	int dem;
};

int gcd(int n,int d)
{
	int g;
	for(int i=1;i<=n && i<=d;++i)
	{
		g=i;
	}
 	return g;
}

int main()
{
	struct rational r1;
	printf("\nEnter the numerator of the rational number : ");
	scanf("%d",&r1.num);
	printf("\nEnter the denominator of the rational number : ");
	scanf("%d",&r1.dem);
	int gcdm=gcd(r1.num,r1.dem);
	if((r1.dem/gcdm)==1)
	{
		printf("\nThe simplified rational number = %d\n",r1.num/gcdm);
	}
	else
	{
		printf("\nThe simplified rational number = %d/%d\n",r1.num/gcdm,r1.dem/gcdm);
	}
	return 0;
}