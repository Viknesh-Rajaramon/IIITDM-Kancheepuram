#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_THREADS 4

static int x=0;

struct thread_node
{
	int *prime_array;
	int num;
};

void *prime(void *ptr)
{
	struct thread_node *data=ptr;
	int i=x;
	++x;
	int flag;
	while(i<data->num)
	{
		flag=0;
		for(int j=2;j<=i/2;++j)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if((flag==0) && (i>1))
		{
			data->prime_array[i]=1;
		}
		i+=MAX_THREADS;
	}
}

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("\nTry ./a.out <number>\n");
		exit(0);
	}
	int n=atoi(argv[1]);
	pthread_t tid[MAX_THREADS];
	pthread_attr_t attr[MAX_THREADS];
	struct thread_node *data=(struct thread_node *)malloc(sizeof(struct thread_node));
	data->prime_array=(int *)malloc(sizeof(int)*n);
	data->num=n;
	struct node *ptr[n];
	for(int i=0;i<MAX_THREADS;++i)
	{
		pthread_attr_init(&attr[i]);
		pthread_create(&tid[i],&attr[i],prime,data);
	}
	for(int i=0;i<MAX_THREADS;++i)
	{
		pthread_join(tid[i],NULL);
	}
	printf("\nPrime Numbers\n\n");
	for(int i=0;i<n;++i)
	{
		if(data->prime_array[i]==1)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}
