#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

#define PORT 9000
#define MAXSIZE 1024

int main()
{
	int sock_fd;
	char data[MAXSIZE];
	memset(data,0,MAXSIZE);
	struct sockaddr_in Client;
	
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
	if(sock_fd<0)
	{
		printf("Socket Creation failed...");
		exit(0);
	}
	
	memset(&Client,0,sizeof(Client));
	Client.sin_family=AF_INET;
	Client.sin_port=htons(PORT);
	Client.sin_addr.s_addr=INADDR_ANY;
	
	if(connect(sock_fd,(struct sockaddr *) &Client,sizeof(Client))==-1)
	{
		printf("Connection failed...");
		exit(0);
	}
	
	printf("Enter data to send : ");
	fgets(data,MAXSIZE,stdin);
	
	int length=strlen(data)-1;
	int ack=1;
	int exit_status=0;
	int i=0;
	printf("Sending Data...\n");
	
	while(i<length)
	{
		send(sock_fd,&exit_status,sizeof(exit_status),0);
		char buf=data[i];
		ack=0;
		while(ack==0)
		{
			send(sock_fd,&buf,sizeof(buf),0);
			printf("Sending : %c\n",buf);
			recv(sock_fd,&ack,sizeof(ack),0);
			printf("ACK : %d\n",ack);
		}
		++i;
	}
	
	exit_status=1;
	send(sock_fd,&exit_status,sizeof(exit_status),0);
	
	printf("Data Sent...\n");
	
	close(sock_fd);
	return 0;
}
