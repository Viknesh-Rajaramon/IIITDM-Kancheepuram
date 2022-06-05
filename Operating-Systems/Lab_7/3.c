#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<pthread.h>

#define CONSUMER 0
#define PRODUCER 1

bool flag[2];
int turn;

int chance=0;

struct dict
{
	char word[100];
	char primary_meaning[1000];
	char secondary_meaning[1000];
	struct dict *left;
	struct dict *right;
};

struct dict *root=NULL;

int strcmpi(char s1[],char s2[])
{
	int i;
	if(strlen(s1)!=strlen(s2))
	{
		return -1;
	}
	for(i=0;i<strlen(s1);i++)
	{
		if(toupper(s1[i])!=toupper(s2[i]))
		{
			return s1[i]-s2[i];
		}
	}
	return 0;
}

struct dict *insert(struct dict *ptr,struct dict *temp)
{
	if(ptr==NULL)
	{
		return temp;
	}
	else if(strcmpi(ptr->word,temp->word)>0)
	{
		ptr->left=insert(ptr->left,temp);
	}
	else
	{
		ptr->right=insert(ptr->right,temp);
	}
	return ptr;
}

void add_new_word()
{
	struct dict *temp=(struct dict *)malloc(sizeof(struct dict));
	temp->left=temp->right=NULL;
	getchar();
	printf("\nEnter word : ");
	scanf("%s",temp->word);
	getchar();
	printf("\nEnter Primary Meaning : ");
	fgets(temp->primary_meaning,sizeof(temp->primary_meaning),stdin);
	printf("\nEnter Secondary Meaning : ");
	fgets(temp->secondary_meaning,sizeof(temp->secondary_meaning),stdin);
	
	int len=strlen(temp->primary_meaning);
	temp->primary_meaning[len-1]=temp->primary_meaning[len];
	
	len=strlen(temp->secondary_meaning);
	temp->secondary_meaning[len-1]=temp->secondary_meaning[len];
	
	root=insert(root,temp);
	
	printf("\n%s added to Dictionary....\n",temp->word);
}

struct dict *search_word(char w[])
{
	struct dict *ptr=root;
	while(ptr!=NULL)
	{
		int diff=strcmpi(ptr->word,w);
		if(diff==0)
		{
			break;
		}
		else if(diff>0)
		{
			ptr=ptr->left;
		}
		else
		{
			ptr=ptr->right;
		}
	}
	return ptr;
}

void print(struct dict *ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	print(ptr->left);
	printf("%s, ",ptr->word);
	print(ptr->right);
}

void *producer()
{
	int y=0;
	while(1)
	{
		flag[PRODUCER]=true;
		turn=CONSUMER;
		while((flag[CONSUMER]==true) && (turn==CONSUMER))
		{
			;
		}
		printf("\nEnter number of words you want to add to the Dictionary : ");
		scanf("%d",&y);
		printf("\nEnter the word along with primary and secondary meaning...\n");
		for(int i=0;i<y;++i)
		{
			add_new_word();
			chance=1;
		}
		printf("\n----------------------------------------------------------------------------------------\n");
		flag[PRODUCER]=false;
	}
}

void *consumer()
{
	int y=0;
	char w[100];
	struct dict *ptr=NULL;
	while(1)
	{
		flag[CONSUMER]=true;
		turn=PRODUCER;
		while((flag[PRODUCER]==true) && (turn==PRODUCER))
		{
			;
		}
		if(chance==0)
		{
			goto end;
		}
		printf("\nWords in Dictionary : ");
		print(root);
		printf("\b\b\n");
		printf("\nEnter number of words you want to search in the Dictionary : ");
		scanf("%d",&y);
		for(int i=0;i<y;++i)
		{
			if(root==NULL)
			{
				printf("\nDictionary is empty...\n");
				break;
			}
			else
			{
				getchar();
				printf("\nEnter the word to be searched for  : ");
				scanf("%s",w);
				ptr=search_word(w);
				if(ptr!=NULL)
				{
					printf("\nPrimary Meaning : %s",ptr->primary_meaning);
					printf("\nSecondary Meaning : %s\n",ptr->secondary_meaning);
				}
				else
				{
					printf("\nWord not found\n");
				}
			}
		}
		printf("\n----------------------------------------------------------------------------------------\n");
		end:
		flag[CONSUMER]=false;
	}
}

int main()
{
	pthread_t tid_producer,tid_consumer;
	pthread_create(&tid_producer,NULL,producer,NULL);
	pthread_create(&tid_consumer,NULL,consumer,NULL);
	pthread_join(tid_producer,NULL);
	pthread_join(tid_consumer,NULL);
	return 0;
}
