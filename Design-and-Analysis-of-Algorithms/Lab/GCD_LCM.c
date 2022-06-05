#include<stdio.h>

int gcd_lcm[2]={0,0};

int gcdcal(int a,int b)
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
		return gcdcal(b,a%b);
	}
}

int dc(int a[],int l,int r)
{
	if(r-l>1)
	{
		int m=(l+(r-1))/2;
		int p=dc(a,l,m);
		int x=gcd_lcm[1];
		int q=dc(a,m+1,r);
		int y=gcd_lcm[1];
		gcd_lcm[0]=gcdcal(p,q);
		gcd_lcm[1]=((x*y)/gcdcal(x,y));
		return gcd_lcm[0];
	}
	else if(l==r)
	{
		gcd_lcm[0]=a[l];
		gcd_lcm[1]=a[l];
		return gcd_lcm[0];
	}
	else
	{
		gcd_lcm[0]=gcdcal(a[l],a[r]);
		gcd_lcm[1]=((a[l]*a[r])/gcd_lcm[0]);
		return gcd_lcm[0];
	}
}

int main()
{
	int n;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the elements of the array : ");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	int s=dc(a,0,n-1);
	printf("\nGCD = %d",gcd_lcm[0]);
	printf("\nLCM = %d\n",gcd_lcm[1]);
	return 0;
}
