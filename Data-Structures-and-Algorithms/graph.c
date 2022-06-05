#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct list
{
	int ip;
	struct node * hptr;
};

struct list a[20];

void initialize() //initialize all hptrs to null
{
	for(int i=0;i<20;i++)
	{
		a[i].hptr=NULL;
	}
}

void create(int u,int v)
{  
  struct node *temp=(struct node* ) malloc(sizeof(struct node));
  temp->next=NULL;
  temp->data=v;
  if(a[u].hptr==NULL)
  { a[u].hptr=temp;
  }
  else 
   { temp->next=a[u].hptr;
     a[u].hptr=temp;    
   }
   struct node *temp1=(struct node*)malloc(sizeof(struct node));
   temp1->next=NULL;
   temp1->data=u;
   if(a[v].hptr==NULL)
   { a[v].hptr=temp1;
   }  
   else
    { temp1->next=a[v].hptr;
      a[v].hptr=temp1;
    }
  
}
int visit[20];
int count[20];
void visitin(int n)
{ for(int i=1;i<=n;i++)
     { visit[i]=0; count[i]=0;
      }
}
void dfs(int u)
{ printf(" comp %d with ip %d ",u,a[u].ip);
  visit[u]=1;
 count[u]=0;
  struct node *thptr=a[u].hptr;
   while(thptr!=NULL)
  {  if(visit[thptr->data]==1)
          count[u]++;
      if(visit[thptr->data]==0)
      { dfs(thptr->data);}
      thptr=thptr->next;
            }        
           }
void printlist(int n)
{ for(int i=1;i<=n;i++)
{ printf("%d  ",i);
  struct node *thptr=a[i].hptr;
  while(thptr!=NULL)
  { printf("%d ->",thptr->data);
    thptr=thptr->next;
  }
  printf("NULL");
  printf("\n");
}
}
void main()
{ 
   int i,n,k,flag=1;
   initialize();
   printf("enter no of nodes");
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   { printf("enter the ip ad of computer %d ",i);
     scanf("%d",&k);
     a[i].ip=k;
   }
   create(1,2);
    create(1,3);
  // create(2,3);
   create(4,5);
  create(4,6);
  create(5,6);
 //printlist(n);  
 visitin(n);
   dfs(1);
   for(i=1;i<=n;i++)
       { if(visit[i]==0)
           {flag=0;break;}
       }
    if(!flag)
       printf("\nnot connected ");
    else printf("\nconnected");
    flag=0;
              for(i=1;i<=n;i++)
       { if(count[i]>1)
           {flag=1;break;}
       }
        if(flag)
       printf("\n cycle ");
   
         for(i=1;i<=n;i++) 
         { if(visit[i]==0)
             dfs(i);
         }
                for(i=1;i<=n;i++)
       { if(count[i]>1)
           {flag=1;break;}
       } 
         if(flag)
       printf("\n cycle ");
    else 
         printf("\n no cycle");
    
    
    
}
