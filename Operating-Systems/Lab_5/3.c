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
	int start_index,end_index;
	memset(string,0,MAXSIZE);
	int fd[2];//Parent writes and Child Reads
	if(pipe(fd)==-1)
	{
		perror("Pipe failed...\n");
		exit(0);
	}
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		close(fd[0]);
		printf("\nEnter string : ");
		fgets(string,MAXSIZE,stdin);
		printf("\nEnter start index : ");
		scanf("%d",&start_index);
		printf("\nEnter end index : ");
		scanf("%d",&end_index);
		printf("\n");
		write(fd[1],string,MAXSIZE);
		write(fd[1],&start_index,sizeof(start_index));
		write(fd[1],&end_index,sizeof(end_index));
		wait(NULL);
	}
	else if(pid==0)
	{
		close(fd[1]);
		read(fd[0],string,MAXSIZE);
		read(fd[0],&start_index,sizeof(start_index));
		read(fd[0],&end_index,sizeof(end_index));
		int length=strlen(string);
		printf("Substring : ");
		int i=start_index;
		while((i<=end_index) && (string[i]!='\0'))
		{
			printf("%c",string[i]);
			++i;
		}
		printf("\n");
		exit(0);
	}
	else
	{
		perror("Fork failed...\n");
		exit(0);
	}
	return 0;
}
