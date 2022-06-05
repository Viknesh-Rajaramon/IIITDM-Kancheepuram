#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>

#define PORT 9000

int t=0;
char charmap[1024];
char bitmap[1024][8];

struct node
{
 	char data;
	int frequency;
	struct node *left, *right;
};

struct MinHeap
{
	int size;
	int capacity;
	struct node **array;
};

struct node *newNode(char data,int frequency)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->left=temp->right=NULL;
	temp->data=data;
	temp->frequency=frequency;
	return temp;
}

struct MinHeap *createMinHeap(int capacity)
{
	struct MinHeap *minHeap=(struct MinHeap *)malloc(sizeof(struct MinHeap));
	minHeap->size=0;
	minHeap->capacity=capacity;
	minHeap->array=(struct node **)malloc(minHeap->capacity*sizeof(struct node *));
	return minHeap;
}

void swapnode(struct node **a,struct node **b)
{
	struct node *t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct MinHeap *minHeap,int index)
{
	int smallest=index;
	int left=2*index+1;
	int right=2*index+2;
	if((left<minHeap->size) && ((minHeap->array[left]->frequency)<(minHeap->array[smallest]->frequency)))
	{
		smallest=left;
    }
	if((right<minHeap->size) && ((minHeap->array[right]->frequency)<(minHeap->array[smallest]->frequency)))
	{
		smallest=right;
	}
	if(smallest!=index)
	{
		swapnode(&minHeap->array[smallest],&minHeap->array[index]);
		minHeapify(minHeap, smallest);
	}
}

int isSizeOne(struct MinHeap *minHeap)
{
  return (minHeap->size==1);
}

struct node *extractMin(struct MinHeap *minHeap)
{
	struct node *temp=minHeap->array[0];
	minHeap->array[0]=minHeap->array[minHeap->size-1];
	minHeap->size=minHeap->size-1;
	minHeapify(minHeap,0);
	return temp;
}

void insertMinHeap(struct MinHeap *minHeap, struct node *node)
{
	minHeap->size=minHeap->size+1;
	int i=minHeap->size-1;
	while(i && (node->frequency<(minHeap->array[(i-1)/2]->frequency)))
	{
		minHeap->array[i]=minHeap->array[(i-1)/2];
		i=(i-1)/2;
	}
	minHeap->array[i]=node;
}

void buildMinHeap(struct MinHeap *minHeap)
{
	int n=minHeap->size-1;
	for(int i=(n-1)/2;i>=0;--i)
	{
		minHeapify(minHeap,i);
	}
}

void printArr(int arr[], int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		bitmap[t][i]=(arr[i]==0)?'0':'1';
		printf("%d",arr[i]);
	}
	bitmap[t][i]='\0';
	printf("\n");
}

int isLeaf(struct node *root)
{
	return (!(root->left) && !(root->right));
}

struct MinHeap *createAndBuildMinHeap(char data[], int frequency[], int size)
{
	struct MinHeap *minHeap=createMinHeap(size);
	for(int i=0;i<size;++i)
	{
		minHeap->array[i]=newNode(data[i],frequency[i]);
	}
	minHeap->size=size;
	buildMinHeap(minHeap);
	return minHeap;
}

struct node *buildHuffmanTree(char data[],int frequency[],int size)
{
	struct node *left,*right,*top;
	struct MinHeap *minHeap=createAndBuildMinHeap(data,frequency,size);
	while (!isSizeOne(minHeap))
	{
		left=extractMin(minHeap);
		right=extractMin(minHeap);
		top=newNode('#', left->frequency + right->frequency);
		top->left=left;
		top->right=right;
		insertMinHeap(minHeap, top);
	}
	return extractMin(minHeap);
}
void printCodes(struct node *root,int arr[],int top)
{
	if(root->left)
	{
		arr[top]=0;
		printCodes(root->left,arr,top+1);
	}
	if(root->right)
	{
		arr[top]=1;
		printCodes(root->right,arr,top+1);
	}
	if(isLeaf(root))
	{
		printf("%c - ",root->data);
		charmap[t]=root->data;
		printArr(arr, top);
		t++;
	}
}

void HuffmanCodes(char data[],int frequency[],int size)
{
	struct node *root=buildHuffmanTree(data,frequency,size);
	int arr[1024],top=0;
	printCodes(root,arr,top);
}

int main()
{
	char A[1024];
	char bitcomp[1024*8];
	printf("\nEnter the text to be sent : ");
	scanf("%s",A);
	int B[26]={0},C[26]={0};
	for(int i=0;A[i];i++)
	{
		if((A[i]>='A') && (A[i]<='Z'))
		{
			B[(int)A[i]-65]++;
		}
		else
		{
			C[(int)A[i]-97]++;
		}
	}
	char arr[100];
	int freq[100];
	int k=0;
	for(int i=0;i<26;i++)
	{
		if(B[i]!=0)
		{
			arr[k]=(char)(i+65);
			freq[k]=B[i];
			k++;
		} 
	}
	for(int i=0;i<26;i++)
	{
		if(C[i]!=0)
		{
			arr[k]=(char)(i+97);
			freq[k]=C[i];
			k++;
		} 
	}
	int size=k;
	printf("\nENCODING SCHEME TABLE : \n");
	HuffmanCodes(arr,freq,size);
	int r=0;
	for(int i=0;A[i];i++)
	{
		for(int j=0;j<t;j++)
		{
			if(charmap[j]==A[i])
			{
				for(int k=0;k<strlen(bitmap[j]);k++)
				{
					bitcomp[r]=bitmap[j][k];
					r++;
				}
			}
		}
	}
	bitcomp[r]='\0';
	printf("\nVariable Length Huffman Coded sequence : %s\n",bitcomp);
	int sockfd;
	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in Client;
	memset(&Client,0,sizeof(Client));
	Client.sin_family=AF_INET;
	Client.sin_port=htons(PORT);
	Client.sin_addr.s_addr=INADDR_ANY;
	connect(sockfd,(struct sockaddr*)&Client,sizeof(Client));
	int g=0;
	char c;
	send(sockfd,&r,sizeof(r),0);
	while(g!=r)
	{
		c=bitcomp[g];
		send(sockfd,&c,sizeof(c),0);
		g++;
	}
	printf("\nEncoded message sent...\n");
	send(sockfd,&t,sizeof(t),0);
	int w=0;
	while(w<=t)
	{
		int sb=strlen(bitmap[w]);
		send(sockfd,&sb,sizeof(sb),0);
		int s=0;
		while(s<=sb)
		{
			c=bitmap[w][s];
			send(sockfd,&c,sizeof(c),0);
			s++;
		}
		c=charmap[w];
		send(sockfd,&c,sizeof(c),0);
		w++;
	}
	printf("\nEncoding scheme sent...\n");
	close(sockfd);
	return 0; 
}


