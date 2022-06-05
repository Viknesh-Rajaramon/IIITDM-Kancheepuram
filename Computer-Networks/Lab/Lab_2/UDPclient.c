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
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
	{
		perror("Socket Creation failed...\n");
		return 0;
	}
	
	Server.sin_family=AF_INET;
	Server.sin_port=htons(PORT);
	Server.sin_addr.s_addr=htonl(INADDR_ANY);
	memset(Server.sin_zero,0,sizeof(Server));

	int sent=0;
	int received=0;
	
	memset(message,'\0',MAXLINE);
	strcpy(message,"s");
	sent=sendto(sockfd,message,strlen(message),0,(struct sockaddr *) &Server,SLen);
	if(sent==-1)
	{
		perror("sendto() failed...\n");
		exit(1);
	}
	
	memset(message,'\0',MAXLINE);
	received=recvfrom(sockfd,message,MAXLINE,0,(struct sockaddr *) &Server,&SLen);
	if(received==-1)
	{
		perror("recvfrom() failed...\n");
		exit(1);
	}
	
	printf("%s",message);
	scanf("%d",&choice);
	
	while(choice!=5)
	{
		sent=sendto(sockfd,&choice,sizeof(choice),0,(struct sockaddr *) &Server,SLen);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		if(choice==5)
		{
			break;
		}
		
		if((choice<0) || (choice>5))
		{
			printf("Wrong choice...");
			continue;
		}
		
		memset(message,'\0',MAXLINE);
		received=recvfrom(sockfd,message,MAXLINE,0,(struct sockaddr *) &Server,&SLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("\n%s",message);
		scanf("%d",&num1);
		
		sent=sendto(sockfd,&num1,sizeof(num1),0,(struct sockaddr *) &Server,SLen);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		memset(message,'\0',MAXLINE);
		received=recvfrom(sockfd,message,MAXLINE,0,(struct sockaddr *) &Server,&SLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("\n%s",message);
		scanf("%d",&num2);
		
		sent=sendto(sockfd,&num2,sizeof(num2),0,(struct sockaddr *) &Server,SLen);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		memset(message,'\0',MAXLINE);
		received=recvfrom(sockfd,&ans,sizeof(ans),0,(struct sockaddr *) &Server,&SLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("\n\t\tAnswer = %d\n",ans);
		
		memset(message,'\0',MAXLINE);
		strcpy(message,"s");
		sent=sendto(sockfd,message,strlen(message),0,(struct sockaddr *) &Server,SLen);
		if(sent==-1)
		{
			perror("sendto() failed...\n");
			exit(1);
		}
		
		memset(message,'\0',MAXLINE);
		received=recvfrom(sockfd,message,MAXLINE,0,(struct sockaddr *) &Server,&SLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		printf("%s",message);
		scanf("%d",&choice);
		
		while((choice<0) || (choice>5))
		{
			printf("Wrong choice...\nEnter your choice : ");
			scanf("%d",&choice);
		}
	}
	
	printf("\nClient connection closed...\n");
	
	close(sockfd);
	return 0;
}
