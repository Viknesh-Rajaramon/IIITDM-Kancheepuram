#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<math.h>

#define PORT 9000

char bitmap[1024][8];
int t=0;

void HuffmanCodes(char bin[],int k,int i,int p)
{
	static int w=0;
	if(w!=p)
	{
		if(i==k)
		{
			bin[i]='\0';
			strcpy(bitmap[t],bin);
			t++;
			w++;
		}
		else
		{
			bin[i]='0';
			HuffmanCodes(bin,k,i+1,p);
			bin[i]='1';
			HuffmanCodes(bin,k,i+1,p);
		}
	} 
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
		if(A[i]>='A' && A[i]<='Z')
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
	int size = k;
	int l=0;
	int s=size;
	while(s!=0)
	{
		s/=2;
		l++;
	}
	if(size%2==0)
	{
		l--;
	}
	char bin[8];
	strcpy(bin,"");
	printf("\nENCODING SCHEME TABLE : \n");
	HuffmanCodes(bin,l,0,size);
	for(int i=0;i<t;i++)
	{
		printf("%c - %s\n",arr[i],bitmap[i]);
	}
	int r=0;
	for(int i=0;A[i];i++)
	{
		for(int j=0;j<t;j++)
		{
			if(arr[j]==A[i])
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
	printf("\nFixed Length Huffman Coded sequence : %s\n",bitcomp);
	int sockfd;
	char receive[255];
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in Client;
	memset(&Client,0,sizeof(Client));
	Client.sin_family = AF_INET;
	Client.sin_port = htons(PORT);
	Client.sin_addr.s_addr = INADDR_ANY;
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
		c=arr[w];
		send(sockfd,&c,sizeof(c),0);
		w++;
	}
	send(sockfd,&l,sizeof(l),0);
	printf("\nEncoding scheme sent...\n");
	close(sockfd);
	return 0;
}
