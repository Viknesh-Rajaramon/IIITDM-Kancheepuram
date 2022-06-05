#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

int no_of_readers,no_of_writers;
int data=1,rcount=0;
int count;

sem_t mutex,write_block,turns_tile;

void *reader(void *arg)
{
	for(int i=0;i<count;++i)
	{
		int f=*((int *)arg);
		sem_wait(&turns_tile);
		sem_post(&turns_tile);
		sem_wait(&mutex);
		rcount+=1;
		if(rcount==1)
		{
			sem_wait(&write_block);
		}
		sem_post(&mutex);
		printf("\nData read by the reader %d is : %d",f,data);
		sleep(1);
		sem_wait(&mutex);
		rcount-=1;
		if(rcount==0)
		{
			sem_post(&write_block);
		}
		sem_post(&mutex);
	}
}

void *writer(void *arg)
{
	for(int i=0;i<count;++i)
	{
		int f=*((int *)arg);
		sem_wait(&turns_tile);
		sem_wait(&write_block);
		data=data*2;
		printf("\nData written by the writer %d is : %d",f,data);
		sleep(1);
		sem_post(&turns_tile);
		sem_post(&write_block);
	}
}

int main()
{
	sem_init(&mutex,0,1);
	sem_init(&write_block,0,1);
	sem_init(&turns_tile,0,1);
	printf("\nEnter the number of readers : ");
	scanf("%d",&no_of_readers);
	printf("\nEnter the number of writers : ");
	scanf("%d",&no_of_writers);
	printf("\nEnter the number of times each reader and writer should enter Critical section : ");
	scanf("%d",&count);
	pthread_t read[no_of_readers];
	pthread_t write[no_of_writers];
	int r[no_of_readers];
	int w[no_of_writers];
	
	for(int i=0;i<no_of_readers;++i)
	{
		r[i]=i+1;
		pthread_create(&read[i],NULL,reader,&r[i]);
	}
	
	for(int i=0;i<no_of_writers;++i)
	{
		w[i]=i+1;
		pthread_create(&write[i],NULL,writer,&w[i]);
	}
	
	for(int i=0;i<no_of_writers;++i)
	{
		pthread_join(write[i],NULL);
	}
	
	for(int i=0;i<no_of_readers;++i)
	{
		pthread_join(read[i],NULL);
	}
	printf("\n");
	
	return 0;
}
