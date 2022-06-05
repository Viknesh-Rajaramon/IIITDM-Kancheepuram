#include<stdio.h>
#include<pthread.h>

int buffer_size,in=0,out=0,items=0,total=0;

void *producer(void *param)
{
	int *buffer=param;
	while(1)
	{
		while(((in+1)%buffer_size)==out)
		{
			;
		}
		printf("\nProducer produced item : %d\n",total);
		buffer[in]=total;
		in=(in+1)%buffer_size;
		++items;
		++total;
	}
}

void *consumer(void *param)
{
	int *buffer=param;
	while(1)
	{
		while(in==out)
		{
			;
		}
		printf("\nConsumer consumed item : %d\n",buffer[out]);
		out=(out+1)%buffer_size;
		--items;
	}
}

int main()
{
	pthread_t tid_producer,tid_consumer;
	printf("\nEnter the buffer size : ");
	scanf("%d",&buffer_size);
	int buffer[buffer_size];
	pthread_create(&tid_producer,NULL,producer,buffer);
	pthread_create(&tid_consumer,NULL,consumer,buffer);
	pthread_join(tid_producer,NULL);
	pthread_join(tid_consumer,NULL);
	return 0;
}
