#include<stdio.h>

struct hashnode
{
	int data;
	struct hashnode *nptr;
};

int HashTable[hsize];

int hash(int key)
{
	return key % hsize;
}

void insert(int data)
{

	HashTable[hash(data)] = data;
}

void delete(int data)
{
	HashTable[hash(data)] = 0;
}

int search(int data)
{
	if(HashTable[hash(data)] != 0)
		return 1;
	else 
		return 0;
}

void main()
{
	int hsize;
	printf("\nEnter the size for Hash Table : ");
	scanf("%d",&hsize);
	int HashTable[hsize];
	for(int i = 0; i< hsize;++i)
		HashTable[i]= 0;
	pritf("\nEnter the elements to be inserted : ");
	for(int i=0;i<hsize;++i)
	{
		printf("\nElement %d : ",i+1);
		scanf("%d",&a);
		insert(a);
	}
	delete(1);
	delete(2);
	delete(56);
	printf("%d\n",search(12));
	printf("%d\n",search(11));
	printf("%d\n",search(56));
	for(int i = 0; i< hsize;++i)
	{
		printf("%d ",HashTable[i]);
	}
}