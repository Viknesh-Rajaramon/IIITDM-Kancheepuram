#include<stdio.h>
#include<math.h>

struct heap
{
		int p[100];
		int e[100];
		int last;
};

struct heap H;

int a[2];

void insert(int x,int y)
{
		H.last++;
		H.p[H.last]=x;
		H.e[H.last]=y;
		int t=H.last;
		while((t/2>=1) && (H.e[t]<=H.e[t/2]))
		{
				H.p[t]=H.p[t]+H.p[t/2];
				H.p[t/2]=H.p[t]-H.p[t/2];
				H.p[t]=H.p[t]-H.p[t/2];
				H.e[t]=H.e[t]+H.e[t/2];
				H.e[t/2]=H.e[t]-H.e[t/2];
				H.e[t]=H.e[t]-H.e[t/2];
				t/=2;
		}
}

int *delete()
{
		a[0]=H.p[1];
		H.p[1]=H.p[H.last];
		a[1]=H.e[1];
		H.e[1]=H.e[H.last];
		H.last--;
		int t=1;
		int mi;
		while(2*t <= H.last)
		{
				if(H.last >= 2*t+1)
				{
						if(H.e[2*t] < H.e[2*t+1])
						{
								mi=2*t;
						}
						else
						{
								mi=2*t+1;
						}
				}
				else
				{
						mi=2*t;
				}
				if(H.e[t] > H.e[mi])
				{
						H.p[t]=H.p[t]+H.p[mi];
						H.p[mi]=H.p[t]-H.p[mi];
						H.p[t]=H.p[t]-H.p[mi];
						H.e[t]=H.e[t]+H.e[mi];
						H.e[mi]=H.e[t]-H.e[mi];
						H.e[t]=H.e[t]-H.e[mi];
						t=mi;
				}
				else
				{
						break;
				}
		}
		int *p=a;
		return p;
}

void ext()
{	
		int x=0;
		for(int i=pow(2,x);i<pow(2,x+1),i<=H.last;++i)
		{
				if(x==0)
				{
						x++;
						continue;
				}
				else
				{
						for(int j=i;j<pow(2,x+1),j<=H.last;++j)
						{
								if(H.e[i]>H.e[j])
								{
										H.p[i]=H.p[i]+H.p[j];
										H.p[j]=H.p[i]-H.p[j];
										H.p[i]=H.p[i]-H.p[j];
										H.e[i]=H.e[i]+H.e[j];
										H.e[j]=H.e[i]-H.e[j];
										H.e[i]=H.e[i]-H.e[j];
								}
						}
						x++;
				}
		}
}

void print()
{
		for(int i=1;i<=H.last;++i)
		{
				printf("\nProcess id : %d",H.p[i]);
				printf("\nExecution time :%d",H.e[i]);
		}
		printf("\n");		
}

int main()
{
		H.last=0;
		int n;
		int x,y;
		printf("\nEnter the number of processes : ");
		scanf("%d",&n);
		printf("\nEnter the processes....");
		for(int i=1;i<=n;++i)
		{
				printf("\nEnter process id : ");
				scanf("%d",&x);
				printf("\nEnter process execution time : ");
				scanf("%d",&y);
				insert(x,y);
		}
		ext();
		int *p=delete();
		ext();
		printf("\nProcess id of the deleted process : %d",*(p));
		printf("\nExecution time of the deleted process : %d\n",*(p+1));
		print();
		return 0;
}
