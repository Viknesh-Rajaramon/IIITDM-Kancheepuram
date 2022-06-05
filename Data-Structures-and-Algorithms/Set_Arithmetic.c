#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
  int data;
  struct node* next;
};
struct node* hptr3=NULL;
struct node* hptr4=NULL;

void print(struct node *ptr)
{
  struct node* thptr=ptr;
 while(thptr!=NULL)
 {     printf(" %d ",thptr->data);
    thptr=thptr->next;}
}
int check(int x,struct node* ptr)
{  int flag=0;
  struct node* thptr=ptr;
 while(thptr!=NULL)
 {     if(thptr->data==x) {flag=1;break;}
    thptr=thptr->next;}
  return flag;}
void insert(int x,struct node **ptr)
{  int c=check(x,*ptr); 
  if(!c)
 { struct node* temp=(struct node*)malloc(sizeof(struct node));
  temp->data=x;
  temp->next=*ptr;
  *ptr=temp;}
}
void un(struct node* ptr1,struct node *ptr2)
{ struct node* thptr=ptr1;
 while(thptr!=NULL)
 {  insert(thptr->data,&hptr3);
    thptr=thptr->next;}
  struct node* thptr2=ptr2;
  while(thptr2!=NULL)
{  insert(thptr2->data,&hptr3);
   thptr2=thptr2->next; 
}}

void inter(struct node *ptr1,struct node *ptr2)
{  struct node* thptr=ptr1;
   struct node* thptr2=ptr2;
  while(thptr!=NULL)
{  int c=check(thptr->data,thptr2);
   if(c) insert(thptr->data,&hptr4); 
  thptr=thptr->next;
}
}
void complement(struct node *uod,struct node *ptr)
{
  struct node* thptr=uod;
  struct node* thptr2=ptr;
 while(thptr!=NULL)
{  int c=check(thptr->data,thptr2);
   if(!c) printf(" %d",thptr->data);
  thptr=thptr->next;
}
}
   
   
void main()
{ int c;
  struct node* hptr1=NULL;
 struct node* hptr2=NULL;
 struct node* uod=NULL;
 for(int i=0;i<=12;i++)
{ insert(i,&uod);}
printf("uod is from 0 to 12");
 insert(39,&hptr1);insert(49,&hptr1);insert(80,&hptr1);
 insert(11,&hptr2);insert(8,&hptr2);
printf(" elements of set 1:");
 print(hptr1);
 printf("\n");
printf("elements of set 2:");
 print(hptr2);
printf("\n");
printf("union of two sets ");
 un(hptr1,hptr2);
 print(hptr3);
printf("\n");
printf("intersect of two sets");
inter(hptr1,hptr2);
print(hptr4);
printf("\nenter the number to check in set 1 or 2:");
scanf("%d",&c);
printf("%d in set 1(1-yes 0-no)\n",check(c,hptr1));
printf("%d in set 2(1-yes 0-no)",check(c,hptr2));
printf("complement of set 1");
complement(uod,hptr1);
}

