#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int hydrogen=0,oxygen=0;
int count=0;
sem_t mutex,hydroQueue,oxyQueue;

void *Hydrogen()
{
	while(1)
	{
		sem_wait(&mutex);
		hydrogen+=1;
		printf("\nHydrogen molecule number %d generated...",hydrogen);
		if((hydrogen>=2) &&(oxygen>=1))
		{
			++count;
			printf("\nHydrogen Bond.....Molecule number %d created...\n",count);
			sem_post(&hydroQueue);
			sem_post(&hydroQueue);
			hydrogen-=2;
			sem_post(&oxyQueue);
			oxygen-=1;
		}
		else
		{
			sem_post(&mutex);
		}
		sem_wait(&hydroQueue);
		sleep(random()%5);
	}
}

void *Oxygen()
{
	while(1)
	{
		sem_wait(&mutex);
		oxygen+=1;
		printf("\nOxygen molecule number %d generated...",oxygen);
		if(hydrogen>=2)
		{
			++count;
			printf("\nOxygen Bond.....Molecule number %d created...\n",count);
			sem_post(&hydroQueue);
			sem_post(&hydroQueue);
			hydrogen-=2;
			sem_post(&oxyQueue);
			oxygen-=1;
		}
		else
		{
			sem_post(&mutex);
		}
		sem_wait(&oxyQueue);
		sleep(random()%5);
		sem_post(&mutex);
	}
}

int main()
{
	sem_init(&mutex,0,1);
	sem_init(&oxyQueue,0,1);
	sem_init(&hydroQueue,0,1);
	pthread_t oxy,hydro1,hydro2;
	pthread_create(&oxy,NULL,Oxygen,NULL);
	pthread_create(&hydro1,NULL,Hydrogen,NULL);
	pthread_create(&hydro2,NULL,Hydrogen,NULL);
	pthread_join(oxy,NULL);
	pthread_join(hydro1,NULL);
	pthread_join(hydro2,NULL);
	return 0;
}
