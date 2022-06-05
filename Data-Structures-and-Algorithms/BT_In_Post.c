#include<stdio.h>
#include<stdlib.h>

struct node
{ 
  int data;
  struct node* left;
  struct node* right;
};
struct node* tptr=NULL;
struct node* newnode(int x)
{ struct node* temp=(struct node*)malloc(sizeof(struct node));
  temp->left=temp->right=NULL;
  temp->data=x;
   return temp;
  }

int check(int st,int end,int x,int in[])
{ int i;
for(i=st;i<=end;i++)
{ if(in[i]==x)
  break;
  } return i;
}
struct node* fn(int st,int end,int in[],int post[],int* ir)
{
  if(st>end)
   return NULL;
struct node* root=newnode(post[(*ir)--]);
if (st==end)
   { return root;}
else{ 
 int index=check(st,end,root->data,in); 
  root->right=fn(index+1,end,in,post,ir);
   root->left=fn(st,index-1,in,post,ir); 
return root;}
 }
void inorder(struct node* ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr->left);
		printf("%d ",ptr->data);               
		inorder(ptr->right);
	}
}
void preorder(struct node* ptr)
{
	if(ptr != NULL)
	{       printf("%d ",ptr->data);
		preorder(ptr->left);             
		preorder(ptr->right);
	}
}
void main()
{ struct node* root=NULL;
int in[20],post[20],i,n;
printf("enter no of nodes (inorder first)");
scanf("%d",&n);
for(i=0;i<n;i++)
  scanf("%d",&in[i]);  
printf("enter post order");
for(i=0;i<n;i++)
  scanf("%d",&post[i]);
int a=n-1;
  root=fn(0,n-1,in,post,&a);
 inorder(root);
printf("\n");
 preorder(root);
}
