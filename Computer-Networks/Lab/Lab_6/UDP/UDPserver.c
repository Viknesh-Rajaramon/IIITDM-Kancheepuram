#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>

#define PORT 8000
#define MAXLINE 1024

int main()
{
	int sockfd;
	char filename[MAXLINE],binary_filename[MAXLINE],BITMAP_filename[MAXLINE],c;
	memset(filename,0,MAXLINE);
	struct sockaddr_in Server;
	int SLen=sizeof(Server);
	
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
	
	int received=recvfrom(sockfd,filename,MAXLINE,0,(struct sockaddr *) &Server,&SLen);
	if(received==-1)
	{
		perror("recvfrom() failed...\n");
		exit(1);
	}
	
	int i=0,j=0;
	while(filename[i]!='\0')
	{
		if(filename[i]=='.')
		{
			char a[12]="_binary_UDP";
			for(int k=0;k<11;++k,++j)
			{
				binary_filename[j]=a[k];
			}
		}
		binary_filename[j]=filename[i];
		++i;
		++j;
	}
	
	printf("\nReceiving File in Binary encoded format...\n\nFile transfer has been initiated...\n");
	
	int r=recvfrom(sockfd,&i,sizeof(i),0,(struct sockaddr *) &Server,&SLen);

	FILE *fptr;
	fptr=fopen(binary_filename,"wb");
	
	do
	{
		received=recvfrom(sockfd,&c,sizeof(c),0,(struct sockaddr *) &Server,&SLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		fputc(c,fptr);
		
		received=recvfrom(sockfd,&i,sizeof(i),0,(struct sockaddr *) &Server,&SLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
	}while(i!=1);
	
	printf("\nFile has been Received...\n\nFile saved as : %s\n",binary_filename);
	fclose(fptr);
	
	i=0,j=0;
	while(filename[i]!='\0')
	{
		if(filename[i]=='.')
		{
			char a[12]="_BITMAP_UDP";
			for(int k=0;k<11;++k,++j)
			{
				BITMAP_filename[j]=a[k];
			}
		}
		BITMAP_filename[j]=filename[i];
		++i;
		++j;
	}
	
	int sent=sendto(sockfd,&i,sizeof(i),0,(struct sockaddr *) &Server,SLen);
	if(sent==-1)
	{
		perror("sendto() failed...\n");
		exit(1);
	}
	printf("\nReceiving File in BITMAP format...\n\nFile transfer has been initiated...\n");
	
	r=recvfrom(sockfd,&i,sizeof(i),0,(struct sockaddr *) &Server,&SLen);
	
	fptr=fopen(BITMAP_filename,"w");
	
	do
	{
		received=recvfrom(sockfd,&c,sizeof(c),0,(struct sockaddr *) &Server,&SLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
		fputc(c,fptr);
		
		received=recvfrom(sockfd,&i,sizeof(i),0,(struct sockaddr *) &Server,&SLen);
		if(received==-1)
		{
			perror("recvfrom() failed...\n");
			exit(1);
		}
		
	}while(i!=1);
	
	printf("\nFile has been Received...\n\nFile saved as : %s\n",BITMAP_filename);
	fclose(fptr);
	
	sent=sendto(sockfd,&i,sizeof(i),0,(struct sockaddr *) &Server,SLen);
	if(sent==-1)
	{
		perror("sendto() failed...\n");
		exit(1);
	}
	
	close(sockfd);
	return 0;
}
