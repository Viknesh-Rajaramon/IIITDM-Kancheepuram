#include<stdio.h>
#include<stdlib.h>

int comparator(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int n=0;
	int sum=0;
	int sum1=0,sum2=0;
	int i,j;
	int pos1=0,pos2=0;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int a[n];
	int a1[n];
	int a2[n];
	int flag=0;
	printf("\nEnter the elements of the array : ");
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	qsort(a,n,sizeof(a[0]),comparator);
	for(i=0;i<n;++i)
	{
		if(i%2==0)
		{
			a1[pos1++]=a[i];
			sum1+=a[i];
		}
		else
		{
			a2[pos2++]=a[i];
			sum2+=a[i];
		}
	}
	if(sum1==sum2)
	{
		goto print;
	}
	else if(sum1>sum2)
	{
		for(i=0;i<pos1;++i)
		{
			for(j=0;j<pos2;++j)
			{
				if(((sum2+a2[i]-a1[j])==sum/2) || ((sum2+a2[i]-a1[j])==(sum/2+1)) || ((sum2+a1[i]-a2[j])==sum/2) || ((sum2+a1[i]-a2[j])==(sum/2+1)))
				{
					a1[i]=a1[i]+a2[j];
					a2[j]=a1[i]-a2[j];
					a1[i]=a1[i]-a2[j];
					flag=1;
					break;
				} 
			}
			if(flag==1)
			{
				break;
			}
		}
		goto print;
	}
	else
	{
		for(i=0;i<pos2;++i)
		{
			for(j=0;j<pos1;++j)
			{
				if(((sum1+a2[i]-a1[j])==sum/2) || ((sum1+a2[i]-a1[j])==((sum/2)+1)))
				{
					a2[i]=a2[i]+a1[j];
					a1[j]=a2[i]-a1[j];
					a2[i]=a2[i]-a1[j];
					flag=1;
					break;
				} 
			}
			if(flag==1)
			{
				break;
			}
		}
	}
	print:
	printf("\nArray 1 : ");
	for(i=0;i<pos1;++i)
	{
		printf("%d  ",a1[i]);
	}
	printf("\nArray 2 : ");
	for(i=0;i<pos2;++i)
	{
		printf("%d  ",a2[i]);
	}
	printf("\n");
	return 0;
}
