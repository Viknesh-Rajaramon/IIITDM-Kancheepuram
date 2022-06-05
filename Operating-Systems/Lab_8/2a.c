#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int N_ELVES,N_REINDEER;
int elves=0,reindeer=0;
sem_t mutex,santaSem,reindeerSem,elfTex;

void *Santa_Claus()
{
	printf("\nSanta Claus is SLEEPING");
	while(1)
	{
		sem_wait(&santaSem);
		sem_wait(&mutex);
		if(reindeer==N_REINDEER)
		{
			printf("\nSanta Claus is PREPARING the sleigh");
			for(int i=0;i<N_REINDEER;++i)
			{
				sem_post(&reindeerSem);
			}
			reindeer=0;
		}
		else if(elves==3)
		{
			printf("\nSanta Claus HELPING elves");
		}
		sem_post(&mutex);
	}
}

void *Reindeer(void *arg)
{
	int id=*((int *)arg);
	while(1)
	{
		sem_wait(&mutex);
		printf("\nThis is reindeer %d",id);
		++reindeer;
		if(reindeer==N_REINDEER)
		{
			sem_post(&santaSem);
		}
		sem_post(&mutex);
		sem_wait(&reindeerSem);
		printf("\nReindeer %d is getting hitched",id);
		sleep(20);
	}
}

void *Elves(void *arg)
{
	int id=*((int *)arg);
	while(1)
	{
		bool need_help=random()%100<50;
		if(need_help)
		{
			sem_wait(&elfTex);
			sem_wait(&mutex);
			printf("\nElf %d needs HELP",id);
			++elves;
			if(elves==3)
			{
				sem_post(&santaSem);
			}
			else
			{
				sem_post(&elfTex);
			}
			sem_post(&mutex);
			sleep(10);
			sem_wait(&mutex);
			printf("\nElf %d will get help from Santa Claus",id);
			--elves;
			if(elves==0)
			{
				sem_post(&elfTex);
			}
			sem_post(&mutex);
		}
		sleep(2+random()%5);
	}
}

int main()
{
	sem_init(&mutex,0,1);
	sem_init(&santaSem,0,0);
	sem_init(&reindeerSem,0,0);
	sem_init(&elfTex,0,1);
	
	printf("\nEnter the number of reindeers : ");
	scanf("%d",&N_REINDEER);
	printf("\nEnter the number of elves : ");
	scanf("%d",&N_ELVES);
	
	int r[N_REINDEER],e[N_ELVES];
	pthread_t santa_claus,reindeers[N_REINDEER],elf[N_ELVES];
	pthread_create(&santa_claus,NULL,Santa_Claus,NULL);
	
	for(int i=0;i<N_REINDEER;++i)
	{
		r[i]=i+1;
		pthread_create(&reindeers[i],NULL,Reindeer,&r[i]);
	}
	
	for(int i=0;i<N_ELVES;++i)
	{
		e[i]=i+1;
		pthread_create(&elf[i],NULL,Elves,&e[i]);
	}
	
	pthread_join(santa_claus,NULL);
	
	for(int i=0;i<N_REINDEER;++i)
	{
		pthread_join(reindeers[i],NULL);
	}
	
	for(int i=0;i<N_ELVES;++i)
	{
		pthread_join(elf[i],NULL);
	}
	
	return 0;
}
