#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<pthread.h>

struct thread_node
{
	int lower;
	int upper;
};

struct node
{
	int num;
	int sum_of_digits;
};

void *get_sum(void *param)
{
	struct node *data=param;
	int sum,x,digits;
	x=data->num;
	sum=0;
	digits=(int) log10(x)+1;
	while(x)
	{
		int r=x%10;
		x/=10;
		sum+=pow(r,digits);
	}
	data->sum_of_digits=sum;
}

void *Armstrong(void *ptr)
{
	pthread_t tid;
	pthread_attr_t attr;
	struct thread_node *data=ptr;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	for(int i=data->lower;i<=data->upper;++i)
	{
		temp->num=i;
		temp->sum_of_digits=0;
		pthread_create(&tid,&attr,get_sum,temp);
		pthread_join(tid,NULL);
		if(temp->num==temp->sum_of_digits)
		{
			printf("%d\n",temp->num);
		}
	}
}

int main()
{
	pthread_t tid;
	pthread_attr_t attr;
	int a,b;
	int sum=0,x=0;
	int digits=0;
	printf("\nEnter the lower bound of range : ");
	scanf("%d",&a);
	printf("\nEnter the upper bound of range : ");
	scanf("%d",&b);
	printf("\nArmstrong numbers between %d and %d : \n",a,b);
	struct thread_node *data=(struct thread_node *)malloc(sizeof(struct thread_node));
	data->lower=a;
	data->upper=b;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,Armstrong,data);
	pthread_join(tid,NULL);
	return 0;
}
