#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

int iterations;

struct node
{
	int points_inside_square;
	int points_inside_circle;
};

double pi;

void *monte_carlo(void *ptr)
{
	struct node *data=ptr;
	double x,y,dist;
	for(int i=0;i<iterations;++i)
	{
		x=(double)(rand()%(iterations+1))/iterations;
		y=(double)(rand()%(iterations+1))/iterations;
		dist=x*x+y*y;
		++data->points_inside_square;
		if(dist<=1)
		{
			++data->points_inside_circle;
		}
	}
}

int main(int argc,char *argv[])
{
	srand(time(NULL));
	if(argc!=2)
	{
		printf("\nTry ./a.out <number_of_iterations>\n");
		return(0);
	}
	iterations=atoi(argv[1]);
	struct node *data=(struct node *)malloc(sizeof(struct node));
	data->points_inside_square=0;
	data->points_inside_circle=0;
	pthread_t tid[iterations];
	for(int i=0;i<iterations;++i)
	{
		pthread_create(&tid[i],NULL,monte_carlo,data);
	}
	for(int i=0;i<iterations;++i)
	{
		pthread_join(tid[i],NULL);
	}
	pi=(double)(4*data->points_inside_circle)/data->points_inside_square;
	printf("\nNumber of iterations = %d\n",iterations);
	printf("\nEstimated value of PI = %lf\n",pi);
	return 0;
}
