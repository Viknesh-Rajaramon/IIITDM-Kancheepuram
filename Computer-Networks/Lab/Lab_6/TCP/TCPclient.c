#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

#define PORT 8000
#define MAXLINE 1024

int main()
{
	int sockfd;
	char c_filename[MAXLINE],s_filename[MAXLINE],c;
	memset(c_filename,0,MAXLINE);
	memset(s_filename,0,MAXLINE);
	struct sockaddr_in Client;
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		perror("Socket Creation failed...\n");
		return 0;
	}
	
	Client.sin_family=AF_INET;
	Client.sin_port=htons(PORT);
	Client.sin_addr.s_addr=htonl(INADDR_ANY);
	memset(Client.sin_zero,0,sizeof(Client));
	
	int con=connect(sockfd,(struct sockaddr *) &Client,sizeof(Client));
	if(con==-1)
	{
		perror("Connection Error...\n");
		exit(0);
	}
	
	printf("\nEnter the file name to be transfered with the extension : ");
	scanf("%s",c_filename);

	printf("\nEnter the file name you want the file to be saved with the extension : ");
	scanf("%s",s_filename);

	int sent=send(sockfd,s_filename,strlen(s_filename),0);
	if(sent==-1)
	{
		perror("sendto() failed...\n");
		exit(1);
	}
	
	FILE *fptr;
	fptr=fopen(c_filename,"rb");
	if(fptr==NULL)
	{
		perror("File not present...\n");
		exit(0);
	}
	
	printf("\nSending File in Binary encoded format...\n\nFile transfer has been initiated...\n");
	
	clock_t time;
	time=clock();
	
	int i=0;
	c=fgetc(fptr);
	
	while(!feof(fptr))
	{
		write(sockfd,&i,sizeof(i));
		write(sockfd,&c,sizeof(c));
		c=fgetc(fptr);
	}
	
	i=1;
	write(sockfd,&i,sizeof(i));
	
	time=clock()-time;
	double time_taken_binary=((double)time)*1000/CLOCKS_PER_SEC;
	
	printf("\nFile sent successfully...\n");
	fclose(fptr);
	
	fptr=fopen(c_filename,"r");
	if(fptr==NULL)
	{
		perror("File not present...\n");
		exit(0);
	}
	
	printf("\nSending File in BITMAP format...\n\nFile transfer has been initiated...\n");
	
	time=clock();
	
	i=0;
	c=fgetc(fptr);
	
	while(!feof(fptr))
	{
		write(sockfd,&i,sizeof(i));
		write(sockfd,&c,sizeof(c));
		c=fgetc(fptr);
	}
	
	i=1;
	write(sockfd,&i,sizeof(i));
	
	time=clock()-time;
	double time_taken_BITMAP=((double)time)*1000/CLOCKS_PER_SEC;
	
	printf("\nFile sent successfully...\n");
	fclose(fptr);
	
	printf("\nAverage Latency in Binary encoded format : %f ms\n",time_taken_binary);
	printf("\nAverage Latency BITMAP format: %f ms\n",time_taken_BITMAP);
	
	close(sockfd);
	return 0;
}
