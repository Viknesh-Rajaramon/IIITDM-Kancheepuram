#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int start=0;
int end=0;
int a[10000];

int power(int n)
{
	if(n==0)
	{
		return 1; 
	}
	else if(n==1)
	{
		return 2;
	}
	else
	{
		int r=power(n/2);
		if(n%2==0)
		{
			return (r*r);
		}
		else
		{
			return (r*r*2);
		}
	}
}

int check()
{
	int i=0;
	while(a[start]!=-1)
	{
		start+=power(i);
		++i;
	}
	--i;
	end=start;
	start-=power(i);
	if((end-start)==1)
	{
		return end+1;
	}
	else
	{
		return check();
	}
}

int main()
{
	srand(time(0));
	int n=(rand() % (20))+1;
	printf("\nSize of array : %d",n);
	printf("\nEnter the elements : ");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i=n;i<10000;++i)
	{
		a[i]=-1;
	} 
	printf("\nPosition = %d\n",check());
	return 0;
}
