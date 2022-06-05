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
	int window_size;
	
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
	
	printf("Enter the window size : ");
	scanf("%d",&window_size);
	getchar();
	
	printf("Enter data to send : ");
	fgets(data,MAXSIZE,stdin);
	
	int length=strlen(data)-1;
	int ack=0;
	int exit_status=0;
	int i=0;
	
	send(sock_fd,&window_size,sizeof(window_size),0);
	
	printf("Sending Data...\n");
	
	while(i<length)
	{
		send(sock_fd,&exit_status,sizeof(exit_status),0);
		char buf;
		int j=0;
		for(j=0;j<window_size;++j)
		{
			if(j==(length-i))
			{
				break;
			}
			printf("Sending : %c\n",data[i+j]);
			buf=data[i+j];
			send(sock_fd,&buf,sizeof(buf),0);
		}
		if((i+j)==length)
		{
			buf='\0';
			send(sock_fd,&buf,sizeof(buf),0);
		}
		int ack_count=-1;
		for(j=0;j<window_size;++j)
		{
			if(j==(length-i))
			{
				break;
			}
			recv(sock_fd,&ack,sizeof(ack),0);
			printf("ACK : %d\n",ack);
			if(ack==0)
			{
				ack_count=j;
				break;
			}
		}
		if(ack_count==-1)
		{
			i=i+window_size;
		}
		else
		{
			i=i+ack_count;
		}
	}
	
	exit_status=1;
	send(sock_fd,&exit_status,sizeof(exit_status),0);
	
	printf("Data Sent...\n");
	
	close(sock_fd);
	return 0;
}
