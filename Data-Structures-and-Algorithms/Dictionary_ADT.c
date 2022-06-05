#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char w[100];
	char m[1000];
	int height;
	struct node *lptr;
	struct node *rptr;
};

struct node *tptr=NULL;

int Height(struct node *ptr)
{
	int l,r;
	if(ptr==NULL)
	{
		return -1;
	}
	else
	{
		if(ptr->lptr==NULL)
		{
			l=-1;
		}
		else
		{
			l=(ptr->lptr)->height;
		}
		if(ptr->rptr==NULL)
		{
			r=-1;
		}
		else
		{
			r=(ptr->rptr)->height;
		}
	}
	if(l<r)
	{
		return r+1;
	}
	else
	{
		return l+1;
	}
}

struct node *right(struct node *ptr) // Case 1
{
	struct node *xptr=ptr;
	struct node *yptr=ptr->lptr;
	xptr->lptr=yptr->rptr;
	yptr->rptr=xptr;
	xptr->height=Height(xptr);
	yptr->height=Height(yptr);
	return yptr;
}

struct node *left(struct node *ptr) // Case 4
{
	struct node *xptr=ptr;
	struct node *yptr=ptr->rptr;
	xptr->rptr=yptr->lptr;
	yptr->lptr=xptr;
	xptr->height=Height(xptr);
	yptr->height=Height(yptr);
	return yptr;
}

struct node *leftright(struct node *ptr) // Case 2
{
	ptr->lptr=left(ptr->lptr);
	return right(ptr);
}

struct node *rightleft(struct node *ptr) // Case 3
{
	ptr->rptr=right(ptr->rptr);
	return left(ptr);
}

struct node *insert(char a[],char b[],struct node *ptr)
{
	if(ptr==NULL)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		strcpy(temp->w,a);
		strcpy(temp->m,b);
		temp->lptr=temp->rptr=NULL;
		temp->height=0;
		ptr=temp;
	}
	else
	{
		if((strcmp(a,ptr->w))<0)
		{
			ptr->lptr=insert(a,b,ptr->lptr);
		}
		else
		{
			ptr->rptr=insert(a,b,ptr->rptr);
		}
		ptr->height=Height(ptr);
		if((((Height(ptr->lptr))-(Height(ptr->rptr))) == 2) || (((Height(ptr->lptr))-(Height(ptr->rptr))) == -2))
		{
			if((strcmp(a,ptr->w)<0))
			{
				if((strcmp(a,(ptr->lptr)->w)<0))
				{
					ptr=right(ptr);
				}
				else
				{
					ptr=leftright(ptr);
				}
			}
			else
			{
				if((strcmp(a,(ptr->rptr)->w)<0))
				{
					ptr=rightleft(ptr);
				}
				else
				{
					ptr=left(ptr);
				}
			}
		}
	}
	return ptr;
}

void search(char a[],struct node *ptr)
{
	if(ptr==NULL)
	{}
	else
	{
		if((strcmp(a,ptr->w))==0)
		{
			printf("\nMeaning : ");
			puts(ptr->m);
		}
		else if((strcmp(a,ptr->w))<0)
		{
			search(a,ptr->lptr);
		}
		else
		{
			search(a,ptr->rptr);
		}
	}
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lptr);
		printf("\n");
		puts(ptr->w);
		inorder(ptr->rptr);
	}
}

void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lptr);
		postorder(ptr->rptr);
		printf("\n");
		puts(ptr->w);
	}
}

void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("\n");
		puts(ptr->w);
		preorder(ptr->lptr);
		preorder(ptr->rptr);
	}
}

int main()
{
	int n;
	char w[100],m[1000],s[100];
	printf("\nEnter the number of word to be inserted : ");
	scanf("%d",&n);
	printf("\nEnter the words to be inserted : ");
	for(int i=0;i<n;++i)
	{
		printf("\nWord %d : ",i+1);
		scanf("%s",w);
		getchar();
		printf("\nMeaning : ");
		gets(m);
		tptr=insert(w,m,tptr);
	}
	printf("\nEnter the word to search for : ");
	scanf("%s",s);;
	search(s,tptr);
	printf("\nInorder : ");
	inorder(tptr);
	printf("\nPreorder : ");
	preorder(tptr);
	printf("\nPostorder : ");
	postorder(tptr);
	return 0;
}