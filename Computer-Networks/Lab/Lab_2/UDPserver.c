#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

#define PORT 8000
#define MAXLINE 1024

int main()
{
	int sockfd;
	char message[MAXLINE];
	memset(message,'\0',MAXLINE);
	struct sockaddr_in Server,Client;
	int CLen=sizeof(Client);
	int i=1;
	
	int num1,num2,ans,choice=0;
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
	{
		perror("Socket Creation failed...\n");
		exit(0);
	}

	memset((char *) &Server,0,sizeof(Server));
	Server.sin_family=AF_INET;
	Server.sin_port=htons(PORT);
	Server.sin_addr.s_addr=htonl(INADDR_ANY);
	
	int b=bind(sockfd,(struct sockaddr *) &Server,sizeof(Server));
	if(b==-1)
	{
		perror("Socket not Binded to Port...\n");
		exit(1);
	}
	
	int sent=0;
	int received=0;
	
	memset(message,'\0',MAXLINE);
	received=recvfrom(sockfd,message,MAXLINE,0,(struct sockaddr *) &Client,&CLen);
	if(received==-1)
	{
		perror("recvfrom() failed...\n");
		exit(1);
	}
	
	while(i)
	{
		memset(message,'\0',MAXLINE);
		strcpy(message,"\n\tMENU FOR ARITHMETIC OPERATIONS\n\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n\nEnter your choice : ");
		sent=sendto(sockfd,message,strlen(message),0,(struct sockaddr *) &Client,CLen);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		received=recvfrom(sockfd,&choice,sizeof(int),0,(struct sockaddr *) &Client,&CLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("\t\tCALCULATION %d\n\n",i);
		
		memset(message,'\0',MAXLINE);
		strcpy(message,"Enter number 1 : ");
		sent=sendto(sockfd,message,strlen(message),0,(struct sockaddr *) &Client,CLen);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		received=recvfrom(sockfd,&num1,sizeof(num1),0,(struct sockaddr *) &Client,&CLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("Number 1 : %d\n",num1);
		
		memset(message,'\0',MAXLINE);
		strcpy(message,"Enter number 2 : ");
		sent=sendto(sockfd,message,strlen(message),0,(struct sockaddr *) &Client,CLen);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		received=recvfrom(sockfd,&num2,sizeof(num2),0,(struct sockaddr *) &Client,&CLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("Number 2 : %d\n\n",num2);
		
		switch(choice)
		{
			case 1:
					ans=num1+num2;
					break;
			case 2:
					ans=num1-num2;
					break;
			case 3:
					ans=num1*num2;
					break;
			case 4:
					ans=num1/num2;
					break;
		}
		
		sent=sendto(sockfd,&ans,sizeof(ans),0,(struct sockaddr *) &Client,CLen);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		memset(message,'\0',MAXLINE);
		received=recvfrom(sockfd,message,MAXLINE,0,(struct sockaddr *) &Client,&CLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		++i;
	}

	close(sockfd);
	return 0;
}
