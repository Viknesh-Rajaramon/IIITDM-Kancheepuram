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
	int s_sockfd,c_sockfd;
	char message[MAXLINE];
	memset(message,'\0',MAXLINE);
	struct sockaddr_in Server,Client;
	int CLen=sizeof(Client);
	int i=1;
	
	int num1,num2,ans,choice=0;
	
	s_sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(s_sockfd<0)
	{
		perror("Socket Creation failed...\n");
		exit(0);
	}

	memset((char *) &Server,0,sizeof(Server));
	Server.sin_family=AF_INET;
	Server.sin_port=htons(PORT);
	Server.sin_addr.s_addr=htonl(INADDR_ANY);
	
	int b=bind(s_sockfd,(struct sockaddr *) &Server,sizeof(Server));
	if(b==-1)
	{
		perror("Socket not Binded to Port...\n");
		exit(1);
	}
	
	listen(s_sockfd,10);
	
	c_sockfd=accept(s_sockfd,(struct sockaddr *) &Client,&CLen);
	if(c_sockfd<0)
	{
		perror("Server Accept failed...\n");
		exit(0);
	}
	
	int sent=0;
	int received=0;
	
	while(i)
	{
		memset(message,'\0',MAXLINE);
		strcpy(message,"\n\tMENU FOR ARITHMETIC OPERATIONS\n\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n\nEnter your choice : ");
		sent=send(c_sockfd,message,strlen(message),0);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		received=recv(c_sockfd,&choice,sizeof(int),0);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		if(choice==5)
		{
			break;
		}
		
		printf("\n");
		printf("\n\t\tCALCULATION %d\n",i);
		
		memset(message,'\0',MAXLINE);
		strcpy(message,"Enter number 1 : ");
		sent=send(c_sockfd,message,strlen(message),0);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		received=recv(c_sockfd,&num1,sizeof(num1),0);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("\nNumber 1 : %d\n",num1);
		
		memset(message,'\0',MAXLINE);
		strcpy(message,"Enter number 2 : ");
		sent=send(c_sockfd,message,strlen(message),0);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		received=recv(c_sockfd,&num2,sizeof(num2),0);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("\nNumber 2 : %d\n",num2);
		
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
		
		sent=send(c_sockfd,&ans,sizeof(ans),0);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		++i;
		
	}
	
	printf("\nClosing Server...\n");
	
	close(s_sockfd);
	return 0;
}
