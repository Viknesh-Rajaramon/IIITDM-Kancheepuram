#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>

#define MAXSIZE 1024

char history[15][100];
int count=0;

void shell_prompt(char current_directory[])
{
	printf("\033[1;32m");
	printf("viknesh@OS-lab");
	printf("\033[0m");
	printf(":");
	printf("\033[1;34m");
	printf("%s",current_directory);
	printf("\033[0m");
	printf("$ ");
	fflush(stdout);
	return;
}

void display_history(int number)
{
	int x=count;
	int flag=1;
	if(number<x)
	{
		x=number;
		flag=0;
	}
	for(int i=0;i<x;++i)
	{
		printf(" %d.  ",i+1);
		int j=0;
		while((history[i][j]!='\n') && (history[i][j]!='\0'))
		{
			printf("%c",history[i][j]);
			++j;
		}
		printf("\n");
	}
	if(flag)
	{
		printf("No more commands in history\n");
	}
}

int command(char input_command[],char *arg[],int *flag)
{
	int length=read(STDIN_FILENO,input_command,MAXSIZE);
	for(int i=14;i>0;--i)
	{
		strcpy(history[i],history[i-1]);
	}
	strcpy(history[0],input_command);
	++count;
	if(count>15)
	{
		count=15;
	}
	int start=-1;
	if(length==0)
	{
		exit(0);
	}
	else if(length<0)
	{
		printf("\nCommand not read\n");
		exit(0);
	}
	int j=0;
	for(int i=0;i<length;++i)
	{
		switch(input_command[i])
		{
			case ' ':
			case'\t':
				if(start!=-1)
				{
					arg[j]=&input_command[start];
					++j;
				}
				input_command[i]='\0';
				start=-1;
				break;
			case'\n':
				if(start!=-1)
				{
					arg[j]=&input_command[start];
					++j;
				}
				input_command[i]='\0';
				break;
			default:
				if(start==-1)
				{
					start=i;
				}
				if(input_command[i]=='&')
				{
					input_command[i]='\0';
					*flag=1;
				}
				break;
		}
	}
	arg[j]=NULL;
	if(strcmp(arg[0],"close")==0)
	{
		exit(0);
	}
	if(strcmp(arg[0],"cd")==0)
	{
		if(chdir(arg[1])==-1)
		{
			printf("No such file or directory\n");
		}
		return -1;
	}
	if(strcmp(arg[0],"history")==0)
	{
		if(count==0)
		{
			printf("No commands in history\n");
			return -1;
		}
		display_history(count);
		return -1;
	}
	else if(arg[0][0]=='!')
	{
		if((arg[0][1]>='1') && (arg[0][1]<='9'))
		{
			if(arg[0][1]=='1')
			{
				if(arg[0][2]=='\0')
				{
					display_history(1);
				}
				else if((arg[0][2]>='0') && (arg[0][2]<='5') && (arg[0][3]<='\0'))
				{
					int x=arg[0][2]-'0';
					x=x+10;
					display_history(x);
				}
				else
				{
					printf("\nNo such command...Enter <= !15 (buffer size is 15 along with current command)\n");
				}
			}
			else
			{
				if(arg[0][2]=='\0')
				{
					int x=arg[0][1]-'0';
					display_history(x);
				}
				else
				{
					printf("\nNo such command...Enter <= !15 (buffer size is 15 along with current command)\n");
				}
			}
		}
		else
		{
			printf("\nNo such command...\n");
		}
		return -1;
	}
}

int main()
{
	char current_directory[MAXSIZE];
	char input_command[100];
	int flag=0,ret;
	char *arg[MAXSIZE];
	pid_t pid;
	printf("\n");
	while(1)
	{
		flag=0;
		if(getcwd(current_directory,sizeof(current_directory))==NULL)
		{
			perror("getcwd() error\n");
			exit(0);
		}
		shell_prompt(current_directory);
		ret=command(input_command,arg,&flag);
		if(ret!=-1)
		{
			pid=fork();
			if(pid==0)
			{
				if(execvp(arg[0],arg)==-1)
				{
					printf("Error executing command\n");
				}
			}
			else if(pid<0)
			{
				printf("\nForking Failed...\n");
				exit(0);
			}
			else if(flag==0)
			{
				wait(NULL);
			}
		}
	}
	return 0;
}
