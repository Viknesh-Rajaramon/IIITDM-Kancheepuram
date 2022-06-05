#include<stdio.h>
#include<stdbool.h>
#include<pthread.h>

int favoured_thread=0;
bool thread_enter[2];
int COUNT=1;

void *thread_0()
{
	for(int i=0;i<COUNT;++i)
	{
		thread_enter[0]=true;
		while(thread_enter[1]==true)
		{
			if(favoured_thread==1)
			{
				thread_enter[0]=false;
			}
			while(favoured_thread==1)
			{
				;
			}
			thread_enter[0]=true;
		}
		
		printf("\nThread 0 in Critical Section");
		
		favoured_thread=1;
		thread_enter[0]=false;
	}
}

void *thread_1()
{
	for(int i=0;i<COUNT;++i)
	{
		thread_enter[1]=true;
		while(thread_enter[0]==true)
		{
			if(favoured_thread==0)
			{
				thread_enter[1]=false;
			}
			while(favoured_thread==0)
			{
				;
			}
			thread_enter[1]=true;
		}
		
		printf("\nThread 1 in Critical Section");
		
		favoured_thread=0;
		thread_enter[1]=false;
	}
}

int main()
{
	pthread_t tid[2];
	thread_enter[0]=false;
	thread_enter[1]=false;
	printf("\nEnter the number of times to run the threads : ");
	scanf("%d",&COUNT);
	pthread_create(&tid[0],NULL,thread_0,NULL);
	pthread_create(&tid[1],NULL,thread_1,NULL);
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	printf("\n");
	return 0;
}
