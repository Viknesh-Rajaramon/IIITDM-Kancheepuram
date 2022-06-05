#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

#define MAX_THREADS 4

struct node
{
	int num;
	int *array;
	int split[5];
};

static int i=0;

void merge(struct node *data,int low,int mid,int high)
{
	int size=high-low+1;
	int array[size];
	int i=low;
	int j=mid+1;
	int k=0;
	while(i<=mid && j<=high)
	{
		if(data->array[i]<data->array[j])
		{
			array[k]=data->array[i];
			++i;
		}
		else
		{
			array[k]=data->array[j];
			++j;
		}
		++k;
	}
	while(i<=mid)
	{
		array[k]=data->array[i];
		++i;
		++k;
	}
	while(j<=high)
	{
		array[k]=data->array[j];
		++j;
		++k;
	}
	j=low;
	for(int i=0;i<size;++i)
	{
		data->array[j]=array[i];
		++j;
	}
}

void MERGE_SORT(struct node *data,int low,int high)
{
	int mid=low+(high-low)/2;
	if(low<high)
	{
		MERGE_SORT(data,low,mid);
		MERGE_SORT(data,mid+1,high);
		merge(data,low,mid,high);
	}
}

void *merge_sort(void *ptr)
{
	struct node *data=ptr;
	int low=data->split[i]+1;
	int high=data->split[i+1];
	++i;
	int mid=low+(high-low)/2;
	if(low<high)
	{
		MERGE_SORT(data,low,mid);
		MERGE_SORT(data,mid+1,high);
		merge(data,low,mid,high);
	}
}

int main()
{
	srand(time(0));
	int n;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	struct node *data=(struct node *)malloc(sizeof(struct node));
	data->num=n;
	data->array=(int *)malloc(sizeof(int)*n);
	printf("\nArray elements before sorting : ");
	for(int i=0;i<n;++i)
	{
		data->array[i]=rand()%(5*n)+1;
		printf("%d ",data->array[i]);
	}
	printf("\n");
	pthread_t tid[MAX_THREADS];
	pthread_attr_t attr[MAX_THREADS];
	data->split[4]=data->num-1;
	data->split[2]=(data->split[4]-data->split[0])/2;
	data->split[1]=data->split[0]+(data->split[2]-data->split[0])/2;
	data->split[3]=data->split[2]+(data->split[4]-data->split[2])/2;
	data->split[0]=-1;
	for(int i=0;i<MAX_THREADS;++i)
	{
		pthread_attr_init(&attr[i]);
		pthread_create(&tid[i],&attr[i],merge_sort,data);
	}
	for(int i=0;i<MAX_THREADS;++i)
	{
		pthread_join(tid[i],NULL);
	}
	merge(data,0,data->split[1],data->split[2]);
	merge(data,data->split[2]+1,data->split[3],data->split[4]); 
	merge(data,0,data->split[2],data->split[4]); 
	printf("\nArray elements after sorting : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",data->array[i]);
	}
	printf("\n");
	return 0;
}
