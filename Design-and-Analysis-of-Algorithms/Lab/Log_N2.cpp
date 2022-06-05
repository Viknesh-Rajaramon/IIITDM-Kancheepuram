#include<bits/stdc++.h>
#include<cstdlib>
#include<iostream>

#define dec_size 100

using namespace std;

void correct(int sum[],int size)
{
	for(int i=0;i<size;++i)
	{
		while(sum[i]>1)
		{
			sum[i+1]+=sum[i]>=2?1:0;
			sum[i]-=2;
		}
	}
}

int main()
{
	srand(time(NULL));
	int n=rand()%dec_size;//Generating decimal number within 100
	cout<<"\nNumber in decimal : "<<n<<endl;
	cout<<"\nProduct of number in decimal : "<<n*n<<endl;
	int binary[n]={0};
	int i=0;
	while(n!=0)
	{
		binary[i]=n%2;
		n/=2;
		++i;
	}
	cout<<"\nThe number in binary : ";
	for(int j=i-1;j>=0;--j)
	{
		cout<<binary[j]<<" ";
	}
	cout<<endl;
	int size=i;
	int sum[2*size]={0};
	for(i=0;i<size;++i)
	{
		for(int j=0;j<size;++j)
		{
			sum[j+i]+=binary[i]*binary[j];
		}
	}
	correct(sum,2*size);
	cout<<"\nThe product in binary = ";
	for(i=2*size-1;i>=0;--i)
	{
		cout<<sum[i]<<" ";
	}
	cout<<endl;
	return 0;
}
