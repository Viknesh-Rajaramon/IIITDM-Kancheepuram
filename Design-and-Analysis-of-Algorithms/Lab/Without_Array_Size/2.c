#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *a;
	int c1=0,c2=0;
	int i=0,j=1;
	a=(int *)malloc(sizeof(int));
	while((c2-c1)>=0)
	{
		c1=c2;
		scanf("%d",&c2);
		a=(int *)realloc(a,j*sizeof(int));
		*a=c2;
		++i;
		++j;
	}
	free(a);
	printf("Position = %d\n",i);
	return 0;	
}
