#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

#define MAXSIZE 1024

int main()
{
	char string1[MAXSIZE],string2[MAXSIZE];
	memset(string1,0,MAXSIZE);
	memset(string2,0,MAXSIZE);
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
	printf("\nEnter string 1 : ");
	scanf("%s",string1);
	printf("\n");
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		close(fd_parent[0]);
		close(fd_child[1]);
		read(fd_child[0],string2,MAXSIZE);
		close(fd_child[0]);
		strcat(string1," ");
		strcat(string1,string2);
		write(fd_parent[1],string1,strlen(string1)+1);
		wait(NULL);
	}
	else if(pid==0)
	{
		close(fd_parent[1]);
		close(fd_child[0]);
		printf("Enter string 2 : ");
		scanf("%s",string2);
		printf("\n");
		write(fd_child[1],string2,strlen(string2)+1);
		close(fd_child[1]);
		read(fd_parent[0],string1,MAXSIZE);
		printf("Concatenated string : %s\n",string1);
		printf("\nThe two strings are separated by a space...\n");
		exit(0);
	}
	else
	{
		perror("Fork failed...\n");
		exit(0);
	}
	return 0;
}
