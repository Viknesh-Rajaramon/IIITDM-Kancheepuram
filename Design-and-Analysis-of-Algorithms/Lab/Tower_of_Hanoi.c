#include<stdio.h>

void towerofhanoi(int n,char from_rod,char to_rod,char inter_rod)
{
	if(n==1)
	{
		printf("\nMove disk 1 from %c to %c",from_rod,to_rod);
		return;
	}
	towerofhanoi(n-1,from_rod,inter_rod,to_rod);
	printf("\nMove disk %d from %c to %c",n,from_rod,to_rod);
	towerofhanoi(n-1,inter_rod,to_rod,from_rod);
}

int main()
{
	int n;
	printf("\nEnter the number of disks : ");
	scanf("%d",&n);
	char from_rod='A';
	char to_rod='C';
	char inter_rod='B';
	towerofhanoi(n,from_rod,to_rod,inter_rod);
	return 0;
}
