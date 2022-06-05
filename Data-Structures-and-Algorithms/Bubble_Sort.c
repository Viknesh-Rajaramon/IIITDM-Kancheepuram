//BUBBLE SORT IN CHARACTER ARRAY

#include<stdio.h>

void BubbleSort(char *p,int size)
{
	char *temp;
	for(int i=0;i<size-1;++i)
 	{
  		for(int j=0;j<size-i-1;++j)
  		{
   			if(*(p+j)>*(p+j+1))
   			{
				*temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=*temp;
			}
		}
	}
}

int main()
{
	char ar[100],c;
	int n=0;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	printf("\nEnter the elements of the array : ");
	for(int i=0;i<n;++i)
	{
		getchar();
		scanf("%c",&ar[i]);
	}
	printf("\nThe array before sorting : \n");
	for(int i=0;i<n;++i)
	{
		printf("%c  ",ar[i]);
	}
	BubbleSort(ar,n);
	printf("\nThe sorted array is : \n");
	for(int i=0;i<n;++i)
	{
		printf("%c  ",ar[i]);
	}
	printf("\n");
	return 0;
}