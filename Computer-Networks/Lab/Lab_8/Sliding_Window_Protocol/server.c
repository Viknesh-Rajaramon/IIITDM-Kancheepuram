#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<time.h>

#define PORT 9000
#define MAXSIZE 1024

int main()
{
	srand(time(0));
	int c_sockfd,s_sockfd;
	char data[MAXSIZE];
	memset(data,0,MAXSIZE);
	struct sockaddr_in Server,Other;
	
	memset(&Other,0,sizeof(Other));
	socklen_t size=sizeof(Other);
	
	s_sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(s_sockfd<0)
	{
		printf("Socket Creation failed...");
		exit(0);
	}
	
	memset(&Server,0,sizeof(Server));
	Server.sin_family=AF_INET;
	Server.sin_port=htons(PORT);
	Server.sin_addr.s_addr=INADDR_ANY;
	
	if(bind(s_sockfd,(struct sockaddr *) &Server,sizeof(Server))==-1)
	{
		printf("Socket Bind failed...");
		exit(0);
	}
	
	listen(s_sockfd,5);
	
	c_sockfd=accept(s_sockfd,(struct sockaddr *)&Other,&size);
	if(c_sockfd==-1)
	{
		printf("Socket Accept failed...\n");
		exit(0);
	}
	
	int exit_status=0;
	int i=0;
	char buf;
	int receive=0;
	
	int window_size;
	
	recv(c_sockfd,&window_size,sizeof(window_size),0);
	
	int ack;
	
	printf("Receiving Data...\n");
	
	while(1)
	{
		recv(c_sockfd,&exit_status,sizeof(exit_status),0);
		if(exit_status==1)
		{
			break;
		}
		int count=window_size;
		for(int j=0;j<window_size;++j)
		{
			recv(c_sockfd,&buf,sizeof(buf),0);
			if(buf=='\0')
			{
				count=j;
				break;
			}
			printf("Received : %c\n",buf);
			data[i]=buf;
			++i;
		}
		for(int j=0;j<count;++j)
		{
			ack=rand()%2;
			printf("ACK : %d\n",ack);
			send(c_sockfd,&ack,sizeof(ack),0);
			if(ack==0)
			{
				i=i-window_size+j;
				break;
			}
		}
		if((buf=='\0') && (ack==1))
		{
			break;
		}
	}
	
	printf("Data Received...\n");
	
	printf("\nReceived Data : %s\n",data);
	
	close(s_sockfd);
	close(c_sockfd);
	return 0;
}
