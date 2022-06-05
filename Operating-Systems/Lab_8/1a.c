#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

#define THINKING 0
#define HUNGRY 1
#define EATING 2

#define LEFT (ph_num+4)%n
#define RIGHT (ph_num+1)%n

int n;
int *state;
int *phil_num;

sem_t mutex;
sem_t *S;

void test(int ph_num)
{
	if((state[ph_num]==HUNGRY) && (state[LEFT]!=EATING) && (state[RIGHT]!=EATING))
	{
		state[ph_num]=EATING;
		sleep(2);
		printf("\nPhilosopher %d takes fork %d and %d",ph_num+1,LEFT+1,ph_num+1);
		printf("\nPhilosopher %d is EATING",ph_num+1);
		sem_post(&S[ph_num]);
	}
}

void take_fork_left(int ph_num)
{
	sem_wait(&mutex);
	state[ph_num]=HUNGRY;
	printf("\nPhilosopher %d is HUNGRY",ph_num+1);
	test(ph_num);
	sem_post(&mutex);
	sem_wait(&S[ph_num]);
	sleep(1);
}

void put_fork_left(int ph_num)
{
	sem_wait(&mutex);
	state[ph_num]=THINKING;
	printf("\nPhilosopher %d putting fork %d and %d down",ph_num+1,LEFT+1,ph_num+1);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}

void *philosopher_left(void *num)
{
	while(1)
	{
		int *i=num;
		sleep(1);
		take_fork_left(*i);
		sleep(0);
		put_fork_left(*i);
	}
}

void take_fork_right(int ph_num)
{
	sem_wait(&mutex);
	state[ph_num]=HUNGRY;
	printf("\nPhilosopher %d is HUNGRY",ph_num+1);
	test(ph_num);
	sem_post(&mutex);
	sem_wait(&S[ph_num]);
	sleep(1);
}

void put_fork_right(int ph_num)
{
	sem_wait(&mutex);
	state[ph_num]=THINKING;
	printf("\nPhilosopher %d putting fork %d and %d down",ph_num+1,ph_num+1,LEFT+1);
	test(RIGHT);
	test(LEFT);
	sem_post(&mutex);
}

void *philosopher_right(void *num)
{
	while(1)
	{
		int *i=num;
		sleep(1);
		take_fork_right(*i);
		sleep(0);
		put_fork_right(*i);
	}
}

int main()
{
	printf("\nEnter the number of philosophers : ");
	scanf("%d",&n);
	sem_init(&mutex,0,1);
	
	pthread_t tid[n];
	S=(sem_t *)malloc(sizeof(sem_t)*n);;
	phil_num=(int *)malloc(sizeof(int)*n);
	state=(int *)malloc(sizeof(int)*n);
	
	for(int i=0;i<n;++i)
	{
		sem_init(&S[i],0,0);
		phil_num[i]=i;
	}
	
	for(int i=0;i<n-1;++i)
	{
		pthread_create(&tid[i],NULL,philosopher_left,&phil_num[i]);
		printf("\nPhilosopher %d is THINKING",i+1);
	}
	pthread_create(&tid[n-1],NULL,philosopher_right,&phil_num[n-1]);
	printf("\nPhilosopher %d is THINKING",n);
	for(int i=0;i<n;++i)
	{
		pthread_join(tid[i],NULL);
	}
	return 0;
}
