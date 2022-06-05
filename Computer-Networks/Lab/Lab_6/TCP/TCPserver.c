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
	int s_sockfd,c_sockfd;
	char filename[MAXLINE],binary_filename[MAXLINE],BITMAP_filename[MAXLINE],c;
	memset(filename,0,MAXLINE);
	memset(binary_filename,0,MAXLINE);
	memset(BITMAP_filename,0,MAXLINE);
	struct sockaddr_in Server,Client;
	int CLen=sizeof(Client);
	
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
	
	listen(s_sockfd,5);
	
	c_sockfd=accept(s_sockfd,(struct sockaddr *) &Client,&CLen);
	if(c_sockfd<0)
	{
		perror("Server Accept failed...\n");
		exit(0);
	}
	
	int received=recv(c_sockfd,filename,MAXLINE,0);
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
			char a[12]="_binary_TCP";
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
	
	int r=read(c_sockfd,&i,sizeof(i));

	FILE *fptr;
	fptr=fopen(binary_filename,"wb");
	
	do
	{
		r=read(c_sockfd,&c,sizeof(c));
		fputc(c,fptr);
		r=read(c_sockfd,&i,sizeof(i));
	}while(i!=1);
	
	printf("\nFile has been Received...\n\nFile saved as : %s\n",binary_filename);
	fclose(fptr);
	
	i=0,j=0;
	while(filename[i]!='\0')
	{
		if(filename[i]=='.')
		{
			char a[12]="_BITMAP_TCP";
			for(int k=0;k<11;++k,++j)
			{
				BITMAP_filename[j]=a[k];
			}
		}
		BITMAP_filename[j]=filename[i];
		++i;
		++j;
	}
	
	printf("\nReceiving File in BITMAP format...\n\nFile transfer has been initiated...\n");
	
	r=read(c_sockfd,&i,sizeof(i));

	fptr=fopen(BITMAP_filename,"w");
	
	do
	{
		r=read(c_sockfd,&c,sizeof(c));
		fputc(c,fptr);
		r=read(c_sockfd,&i,sizeof(i));
	}while(i!=1);
	
	printf("\nFile has been Received...\n\nFile saved as : %s\n",BITMAP_filename);
	
	fclose(fptr);
	close(s_sockfd);
	return 0;
}
