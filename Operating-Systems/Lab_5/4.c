#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

#define MAXSIZE 1024

void convert(char str1[],char str2[])
{
	int length=strlen(str1);
	int j=0;
	for(int i=0;i<length;++i)
	{
		if((str1[i]>=65) && (str1[i]<=90))
		{
			str2[j]=str1[i]+32;
			++j;
		}
		else if((str1[i]>=97) && (str1[i]<=122))
		{
			str2[j]=str1[i];
			++j;
		}
	}
	str2[j]='\0';
}

void palindrome_check(char str1[],char str2[])
{
	char string[MAXSIZE],rev_string[MAXSIZE];
	convert(str1,string);
	convert(str2,rev_string);
	if(strcmp(string,rev_string)==0)
	{
		printf("\nIT IS A PALINDROME...\n");
	}
	else
	{
		printf("\nNOT A PALINDROME...\n");
	}
}

int main()
{
	char string[MAXSIZE],rev_string[MAXSIZE];
	memset(string,0,MAXSIZE);
	memset(rev_string,0,MAXSIZE);
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
		printf("\nEnter a string : ");
		fgets(string,MAXSIZE,stdin);
		write(fd_parent[1],string,strlen(string)+1);
		read(fd_child[0],rev_string,MAXSIZE);
		printf("\nReversed string : %s\n",rev_string);
		palindrome_check(string,rev_string);		
	}
	else if(pid==0)
	{
		close(fd_parent[1]);
		close(fd_child[0]);
		read(fd_parent[0],string,MAXSIZE);
		int len=strlen(string);
		for(int i=0;i<len;++i)
		{
			rev_string[len-i-1]=string[i];
		}
		rev_string[len]='\0';
		write(fd_child[1],rev_string,strlen(rev_string)+1);
		exit(0);
	}
	else
	{
		perror("Fork failed...\n");
		exit(0);
	}
	return 0;
}
