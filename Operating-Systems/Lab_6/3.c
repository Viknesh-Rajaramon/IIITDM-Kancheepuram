#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

struct node
{
	int num;
	int *array;
	int x;
	int count;
};

int sort(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}

int first_occurrence(int array[],int lower,int upper,int x)
{
	if(lower>upper)
	{
		return lower;
	}
	int mid=lower+(upper-lower)/2;
	if(array[mid]>=x)
	{
		return first_occurrence(array,lower,mid-1,x);
	}
	return first_occurrence(array,mid+1,upper,x);
}

int last_occurrence(int array[],int lower,int upper,int x)
{
	if(lower>upper)
	{
		return lower;
	}
	int mid=lower+(upper-lower)/2;
	if(array[mid]>x)
	{
		return last_occurrence(array,lower,mid-1,x);
	}
	return last_occurrence(array,mid+1,upper,x);
}

void *binary_search(void *ptr)
{
	struct node *data=ptr;
	qsort(data->array,data->num,sizeof(int),sort);
	int last_pos=last_occurrence(data->array,0,data->num-1,data->x);
	int first_pos=first_occurrence(data->array,0,data->num-1,data->x);
	data->count=last_pos-first_pos;
}

int main()
{
	srand(time(0));
	int n,x;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	int array[n];
	printf("\nUnsorted Array elements : " );
	for(int i=0;i<n;++i)
	{
		array[i]=rand()%10+1;
		printf("%d ",array[i]);
	}
	printf("\n\nEnter the element to search for : ");
	scanf("%d",&x);
	pthread_t tid[2];
	struct node arg[2];
	for(int i=0;i<2;++i)
	{
		arg[i].num=n/2+((n%2)*i);
		arg[i].array=array+(i*n/2);
		arg[i].x=x;
		arg[i].count=0;
	}
	for(int i=0;i<2;++i)
	{
		pthread_create(&tid[i],NULL,binary_search,&arg[i]);
	}
	for(int i=0;i<2;++i)
	{
		pthread_join(tid[i],NULL);
		printf("\nOccurrence of %d in Half %d = %d\n",x,i+1,arg[i].count);
	}
	return 0;
}
