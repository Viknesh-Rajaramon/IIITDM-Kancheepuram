#include<stdio.h>
#include<math.h>

int main()
{
	int a,b;
	printf("\nEnter the two numbers : ");
	scanf("%d %d",&a,&b);
	a=abs(a);
	b=abs(b);
	while(b!=0)
	{
			int temp=b;
			b=a%temp;
			a=temp;
	}
	printf("%d\n",a);
	return 0;
}
