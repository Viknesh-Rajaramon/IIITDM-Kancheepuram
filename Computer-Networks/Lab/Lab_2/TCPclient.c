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
	memset(message,0,MAXLINE);
	struct sockaddr_in Server;
	int SLen=sizeof(Server);
	int num1,num2,ans,choice=0;
	int i=1;
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		perror("Socket Creation failed...\n");
		return 0;
	}
	
	Server.sin_family=AF_INET;
	Server.sin_port=htons(PORT);
	Server.sin_addr.s_addr=htonl(INADDR_ANY);
	memset(Server.sin_zero,0,sizeof(Server));
	
	connect(sockfd,(struct sockaddr *) &Server,sizeof(Server));

	int sent=0;
	int received=0;
	
	memset(message,'\0',MAXLINE);
	received=recv(sockfd,message,MAXLINE,0);
	if(received==-1)
	{
		perror("recvfrom() failed...\n");
		exit(1);
	}
	
	printf("%s",message);
	scanf("%d",&choice);
	
	while(i)
	{
		if((choice<0) || (choice>5))
		{
			printf("Wrong choice...\nEnter your choice : ");
			scanf("%d",&choice);
			continue;
		}
		
		sent=send(sockfd,&choice,sizeof(choice),0);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		if(choice==5)
		{
			break;
		}
		
		memset(message,'\0',MAXLINE);
		received=recv(sockfd,message,MAXLINE,0);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("\n%s",message);
		scanf("%d",&num1);
		
		sent=send(sockfd,&num1,sizeof(num1),0);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		memset(message,'\0',MAXLINE);
		received=recv(sockfd,message,MAXLINE,0);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("\n%s",message);
		scanf("%d",&num2);
		
		sent=send(sockfd,&num2,sizeof(num2),0);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		memset(message,'\0',MAXLINE);
		received=recv(sockfd,&ans,sizeof(ans),0);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("\n\t\tAnswer = %d\n",ans);
		
		memset(message,'\0',MAXLINE);
		received=recv(sockfd,message,MAXLINE,0);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("%s",message);
		scanf("%d",&choice);
	}
	
	printf("\nClient connection closed...\n");
	
	close(sockfd);
	return 0;
}
