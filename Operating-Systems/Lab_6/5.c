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

int sort(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}

void *cal_mean(void *param)
{
	struct node *data=param;
	int sum=0;
	int n=data->num;
	for(int i=0;i<n;++i)
	{
		sum+=data->array[i];
	}
	float mean=((float)sum)/n;
	printf("\nMean = %f\n",mean);
}

void *cal_median(void *param)
{
	struct node *data=param;
	int n=data->num;
	int mid=n/2;
	float median;
	if(n%2!=0)
	{
		median=data->array[mid];
	}
	else
	{
		median=((float)data->array[mid-1]+(float)data->array[mid])/2;
	}
	printf("\nMedian = %f\n",median);
}

void *cal_mode(void *param)
{
	struct node *data=param;
	int n=data->num;
	int max_count=0,mode=0,count=0;
	for(int i=0;i<n;++i)
	{
		count=0;
		for(int j=0;j<n;++j)
		{
			if(data->array[i]==data->array[j])
			{
				++count;
			}
		}
		if(count>max_count)
		{
			max_count=count;
			mode=data->array[i];
		}
	}
	printf("\nMode = %d\n",mode);
}

int main()
{
	srand(time(0));
	int n;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;++i)
	{
		a[i]=rand()%10 + 1;
	}
	qsort(a,n,sizeof(int),sort);
	printf("\nArray elements : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	pthread_t tid[3];
	pthread_attr_t attr[3];
	for(int i=0;i<3;++i)
	{
		pthread_attr_init(&attr[i]);
	}
	struct node *data=(struct node *)malloc(sizeof(struct node));
	data->num=n;
	data->array=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;++i)
	{
		data->array[i]=a[i];
	}
	pthread_create(&tid[0],&attr[0],cal_mean,data);
	pthread_create(&tid[1],&attr[1],cal_median,data);
	pthread_create(&tid[2],&attr[2],cal_mode,data);
	for(int i=0;i<3;++i)
	{
		pthread_join(tid[i],NULL);
	}
	return 0;
}
