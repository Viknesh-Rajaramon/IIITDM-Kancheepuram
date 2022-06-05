#include<stdio.h>
#include<stdbool.h>
#include<pthread.h>
#include<stdlib.h>

#define CONSUMER 0
#define PRODUCER 1

int buffer_size,in=0,out=0,items=0,total=0,x=10;
bool flag[2];
int turn;

void *producer(void *param)
{
	srand(time(0));
	int *buffer=param;
	int y=0;
	while(x>0)
	{
		flag[PRODUCER]=true;
		turn=CONSUMER;
		while((flag[CONSUMER]==true) && (turn==CONSUMER))
		{
			;
		}
		y=rand()%buffer_size;
		for(int i=0;i<y;++i)
		{
			if(((in+1)%buffer_size)==out)
			{
				break;
			}
			else
			{
				printf("\nProducer produced item : %d\n",total);
				buffer[in]=total;
				in=(in+1)%buffer_size;
				++items;
				++total;
				--x;
			}
		}
		flag[PRODUCER]=false;
	}
}

void *consumer(void *param)
{
	srand(time(0));
	int *buffer=param;
	int y=0;
	while(x>0)
	{
		flag[CONSUMER]=true;
		turn=PRODUCER;
		while((flag[PRODUCER]==true) && (turn==PRODUCER))
		{
			;
		}
		y=rand()%buffer_size;
		for(int i=0;i<y;++i)
		{
			if(in==out)
			{
				break;
			}
			else
			{
				flag[PRODUCER]=false;
				printf("\nConsumer consumed item : %d\n",buffer[out]);
				out=(out+1)%buffer_size;
				--items;
				--x;
			}
		}
		flag[CONSUMER]=false;
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
	printf("^C\n");
	return 0;
}
