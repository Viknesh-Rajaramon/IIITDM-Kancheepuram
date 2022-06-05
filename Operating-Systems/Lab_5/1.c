#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

#define MAXSIZE 1024

int main()
{
	char string[MAXSIZE];
	memset(string,0,MAXSIZE);
	int fd_parent[2];//Parent writes and Child Reads
	int fd_child[2];//Child writes and Parent Reads
	if(pipe(fd_parent)==-1)
	{
		perror("Pipe failed...\n");
		exit(0);
	}
	if(pipe(fd_child)==-1)
	{
		perror("Pipe failed...\n");
		exit(0);
	}
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		close(fd_parent[0]);
		close(fd_child[1]);
		printf("\nEnter string : ");
		scanf("%s",string);
		write(fd_parent[1],string,strlen(string)+1);
		read(fd_child[0],string,MAXSIZE);
		printf("\nReversed string : %s\n",string);
	}
	else if(pid==0)
	{
		close(fd_parent[1]);
		close(fd_child[0]);
		read(fd_parent[0],string,MAXSIZE);
		int len=strlen(string);
		for(int i=0;i<len/2;++i)
		{
			char temp=string[i];
			string[i]=string[len-i-1];
			string[len-i-1]=temp;
		}
		write(fd_child[1],string,strlen(string)+1);
		exit(0);
	}
	else
	{
		perror("Fork failed...\n");
		exit(0);
	}
	return 0;
}
