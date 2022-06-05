#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

struct node
{
	int *array;
	int low;
	int high;
};

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(struct node *data,int low,int high)
{
	int pivot_element=data->array[high];
	int i=low-1;
	for(int j=low;j<high;++j)
	{
		if(data->array[j]<pivot_element)
		{
			++i;
			swap(&data->array[i],&data->array[j]);
		}
	}
	swap(&data->array[i+1],&data->array[high]);
	return (i+1);
}

void Quick_Sort(struct node *data,int low,int high)
{
	if(low<high)
	{
		int pivot=partition(data,low,high);
		Quick_Sort(data,low,pivot-1);
		Quick_Sort(data,pivot+1,high);
	}
}

void *quick_sort(void *ptr)
{
	struct node *data=ptr;
	if(data->low<data->high)
	{
		int pivot=partition(data,data->low,data->high);
		pthread_t tid[2];
		struct node *temp=malloc(sizeof(data));
		temp->array=data->array;
		temp->low=pivot+1;
		temp->high=data->high;
		data->high=pivot-1;
		pthread_create(&tid[0],NULL,quick_sort,data);
		pthread_create(&tid[1],NULL,quick_sort,temp);
		pthread_join(tid[0],NULL);
		pthread_join(tid[1],NULL);
	}
}

int main()
{
	srand(time(NULL));
	struct node *data=(struct node *)malloc(sizeof(struct node));
	int n;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	data->low=0;
	data->high=n-1;
	data->array=(int *)malloc(sizeof(int)*n);
	printf("\nArray elements before sorting : ");
	for(int i=0;i<n;++i)
	{
		data->array[i]=rand()%(5*n)+1;
		printf("%d ",data->array[i]);
	}
	printf("\n");
	
	pthread_t tid;
	pthread_create(&tid,NULL,quick_sort,data);
	pthread_join(tid,NULL);
	printf("\nArray elements after sorting : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",data->array[i]);
	}
	printf("\n");
	return 0;
}
