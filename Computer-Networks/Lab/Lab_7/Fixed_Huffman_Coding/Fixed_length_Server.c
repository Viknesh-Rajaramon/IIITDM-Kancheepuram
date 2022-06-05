#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>

#define PORT 9000

int main() 
{
	int s_sockfd, c_sockfd;
	char bitcomp[1024*8];
	char bitmap[1024][8];
	char charmap[1024];
	struct sockaddr_in Server,Client;
	memset(&Server,0,sizeof(Server));
	memset(&Client,0,sizeof(Client));
	socklen_t CLen;
	s_sockfd=socket(AF_INET,SOCK_STREAM,0);
	Server.sin_family=AF_INET;
	Server.sin_port=htons(PORT);
	Server.sin_addr.s_addr=INADDR_ANY;
	bind(s_sockfd,(struct sockaddr*)&Server,sizeof(Server));
	listen(s_sockfd,10);
	CLen=sizeof(Client);
	c_sockfd=accept(s_sockfd,(struct sockaddr*)&Client,&CLen);
	int r,g=0;
	recv(c_sockfd,&r,sizeof(r),0);
	char c;
	while(g!=r)
	{
		recv(c_sockfd,&c,sizeof(c),0);
		bitcomp[g]=c;
		g++;
	}
	int t;
	recv(c_sockfd,&t,sizeof(t),0);
	int w=0;
	while(w<=t)
	{
		int sb;
		recv(c_sockfd,&sb,sizeof(sb),0);
		int s=0;
		while(s<=sb)
		{
			recv(c_sockfd,&c,sizeof(c),0);
			bitmap[w][s]=c;
			s++;
		}
		recv(c_sockfd,&c,sizeof(c),0);
		charmap[w]=c;
		w++;
	}
	int l;
	recv(c_sockfd,&l,sizeof(l),0);
	printf("Fixed Length Huffman Coded sequence : ");
	printf("%s\n",bitcomp);
	printf("\nDECODING SCHEME TABLE : \n");
	for(int i=0;i<t;i++)
	{
		printf("%s - %c\n",bitmap[i],charmap[i]);
	}
	printf("\nDecoded message : ");
	char arr[8];
	int k=0;
	for(int i=0;i<r;i+=l)
	{
		for(int j=i;j<i+l;j++)
		{
			arr[k]=bitcomp[j];
			k++;
		}
		arr[k]='\0';
		for(int x=0;x<t;x++)
		{
			if(strcmp(bitmap[x],arr)==0)
			{
				printf("%c",charmap[x]);
			}
		}
		k=0;
	}
	printf("\n");
	close(s_sockfd);
	return 0;
}



