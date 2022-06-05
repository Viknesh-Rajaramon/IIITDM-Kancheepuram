#include<bits/stdc++.h>

using namespace std;

int matrix_chain_order(int p[],int n)
{
	int M[n][n];
	for(int i=1;i<=n;++i)
	{
		M[i][i]=0;
	}
	for(int l=2;l<=n;++l)
	{
		for(int i=1;i<=n-l+1;++i)
		{
			int j=i+l-1;
			M[i][j]=INT_MAX;
			for(int k=i;k<=j-1;++k)
			{
				int q=M[i][k]+M[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<M[i][j])
				{
					M[i][j]=q;
				}
			}
		}
	}
	return M[1][n-1];
}

int main()
{
	int n;
	cout<<"\nEnter the number of matrices : ";
	cin>>n;
	int p[n+1];
	cout<<"\nEnter the values of pi's : ";
	for(int i=0;i<=n;++i)
	{
		cin>>p[i];
	}
	cout<<"\nMinimum number of multiplication : "<<matrix_chain_order(p,n+1)<<endl;
	return 0;
}
