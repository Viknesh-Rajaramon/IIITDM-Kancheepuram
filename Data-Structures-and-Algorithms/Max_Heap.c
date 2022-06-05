#include<stdio.h>
#include<stdlib.h>

struct Heap
{
	int arr[50];
	int last; 
};

struct Heap H;
void insert(int p);
int delete();

void main()
{
	H.last = 0;
	insert(15);
	insert(500);
	insert(50);
	insert(70);
	insert(1);
	insert(5);
	for(int i = 1;i <= H.last;++i)
	{
		printf("%d ", H.arr[i]);
	}
	printf("\n%d\n", delete());
	for(int i = 1;i <= H.last;++i)
	{
		printf("%d ", H.arr[i]);
	}
}

void insert(int p)
{
	H.last++;
	H.arr[H.last] = p;
	int t = H.last;
	while((t/2 >= 1) && (H.arr[t] >= H.arr[t / 2]))
	{
		H.arr[t] = H.arr[t] ^ H.arr[t/2];
		H.arr[t/2] = H.arr[t] ^ H.arr[t/2];
		H.arr[t] = H.arr[t] ^ H.arr[t/2];
		t /= 2;
	}
}

int delete()
{
	int x = H.arr[1];
	H.arr[1] = H.arr[H.last];
	H.last--;
	int t = 1;
	int mi;
	while(2*t  <= H.last)
	{
		if(H.last >= 2*t+1)
		{
			if(H.arr[2*t] > H.arr[2*t+1])
			{
				mi = 2*t;
			}
			else 
			{
				mi = 2*t+1;
			}
		}
		else 
		{
			mi = 2*t;
		}
		if(H.arr[t] < H.arr[mi])
		{
			H.arr[t] = H.arr[t] ^ H.arr[mi];
			H.arr[mi] = H.arr[t] ^ H.arr[mi];
			H.arr[t] = H.arr[t] ^ H.arr[mi];
			t = mi;
		}
		else
		{
			break;
		}
	}
	return x;
}