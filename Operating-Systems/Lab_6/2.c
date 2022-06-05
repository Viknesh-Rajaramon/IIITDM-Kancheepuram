#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

struct node
{
	int num;
	int *array;
};

int ascending(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}

int descending(const void *a,const void *b)
{
	return (*(int *)b - *(int *)a);
}

void *asc_sort(void *param)
{
	struct node *data=param;
	qsort(data->array,data->num,sizeof(int),ascending);
}

void *des_sort(void *param)
{
	struct node *data=param;
	qsort(data->array,data->num,sizeof(int),descending);
}

int main()
{
	srand(time(0));
	int n;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	int a[n];
	printf("\nArray elements : ");
	for(int i=0;i<n;++i)
	{
		a[i]=rand()%1000 + 1;
		printf("%d ",a[i]);
	}
	printf("\n");
	pthread_t tid[2];
	pthread_attr_t attr[2];
	pthread_attr_init(&attr[0]);
	pthread_attr_init(&attr[1]);
	struct node *data1=(struct node *)malloc(sizeof(struct node));
	struct node *data2=(struct node *)malloc(sizeof(struct node));
	data1->num=data2->num=n;
	data1->array=(int *)malloc(sizeof(int)*n);
	data2->array=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;++i)
	{
		data1->array[i]=a[i];
		data2->array[i]=a[i];
	}
	pthread_create(&tid[0],&attr[0],asc_sort,data1);
	pthread_create(&tid[1],&attr[1],des_sort,data2);
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	printf("\nAscending Order Sort : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",data1->array[i]);
	}
	printf("\n");
	printf("\nDescending Order Sort : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",data2->array[i]);
	}
	printf("\n");
	return 0;
}
