#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *a;
	int c=1;
	int i=0,j=1;
	a=(int *)malloc(sizeof(int));
	while(c!=-1)
	{
		scanf("%d",&c);
		a=(int *)realloc(a,j*sizeof(int));
		*a=c;
		++i;
		++j;
	}
	free(a);
	printf("Position = %d\n",i);
	return 0;	
}
