#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
  int data;
  struct node* next;
};
struct node* hptr3=NULL;
void insert(int x,struct node **ptr)
{
  struct node* temp=(struct node*)malloc(sizeof(struct node));
  temp->data=x;
  temp->next=*ptr;
  *ptr=temp;
}

void print(struct node *ptr)
{
  struct node* thptr=ptr;
 while(thptr!=NULL)
 {     printf(" %d ",thptr->data);
    thptr=thptr->next;}
}
void sub(struct node *ptr1,struct node* ptr2)
{  struct node *tptr1=ptr1;
  struct node* tptr2=ptr2;
  while(tptr1!=NULL && tptr2!=NULL)
{
    if(tptr1->data >= tptr2->data)
   {
       insert(tptr1->data-tptr2->data,&hptr3);
       tptr1=tptr1->next; tptr2=tptr2->next;}
   else
     {  int c=borrow(tptr1);                              //getting borrow from adjacent node
          tptr1->data=c;}  
       }
while(tptr1!=NULL)
{  insert(tptr1->data,&hptr3);
   tptr1=tptr1->next;}
} 

int borrow(struct node *ptr)
{  struct node* tbptr=ptr;
   if((tbptr->next)->data!=0)                              // getting borrow from adj node if adjkey is not 0
   {  tbptr->data=tbptr->data+10;
             (tbptr->next)->data=(tbptr->next)->data-1;
return tbptr->data;}
   else
    {  int c=borrow(tbptr->next);                  // recursively calling borrow if adjkey is 0;returned value of borrow is updated val of argument node after borrowing 
       (tbptr->next)->data=c;
        tbptr->data=tbptr->data+10;
          (tbptr->next)->data=(tbptr->next)->data-1;return tbptr->data;
}
}
struct node* removezeroes(struct node* ptr)
{ struct node *thptr=ptr;
 int count=0;
    while(thptr!=NULL&&thptr->data==0)
    {  count++;
         thptr=thptr->next;}
thptr=ptr;
 while(count!=0)
{     thptr=thptr->next;
      count--;   }
return thptr;
} 
int comparator(struct node* ptr1,struct node *ptr2)
{  int count1=0,count2=0;
   struct node* thptr1=ptr1;
    struct node* thptr2=ptr2;
   while(thptr1!=NULL)
    {  count1++; 
        thptr1=thptr1->next; }
   while( thptr2!=NULL)
     { count2++;  thptr2=thptr2->next;}
                 
thptr1=ptr1;
thptr2=ptr2;
 if(count1<count2)
       return -1;
 else if(count1>count2)
    return 1;
 else
     { while(count1!=0)
         { if(thptr1->data>thptr2->data)
                  return 1;
           else if(thptr1->data<thptr2->data)
                   return -1;
           else { thptr1=thptr1->next;
                  thptr2=thptr2->next;count1--; }}
return 0;
}

}
void reverse(struct node** ptr) 
{ 
    struct node* prev = NULL; 
    struct node* current = *ptr; 
    struct node* next = NULL; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
          prev = current; 
        current = next; 
    } 
    *ptr= prev; 
} 
struct node *copy(struct node *start1)
{
    struct node *start2=NULL,*previous=NULL;
       while(start1!=NULL)
    {
    struct node * temp = (struct node *) malloc (sizeof(struct node));
    temp->data=start1->data;
    temp->next=NULL;

    if(start2==NULL)
    {
        start2=temp;
        previous=temp;
    }
    else
    {
        previous->next=temp;
        previous=temp;          
    }
    start1=start1->next;
}return start2;
}
void main()
{  char a[20],b[20];
long count=0;
   struct node* hptr1=NULL;
   struct node* hptr2=NULL;
   printf("enter the number 1 with sign:");
   gets(a);
   printf("enter the number 2 with sign:");
   gets(b);
   for(int i=1;i<strlen(a);i++)
     insert(a[i]-48,&hptr1);
   for(int i=1;i<strlen(b);i++)
     insert(b[i]-48,&hptr2);
  printf("\n");
  reverse(&hptr1);reverse(&hptr2);
  while(comparator(hptr1,hptr2)>=0)
{ reverse(&hptr1);reverse(&hptr2); 
 sub(hptr1,hptr2);                                      
    hptr3=removezeroes(hptr3);
if(hptr3==NULL) insert(0,&hptr3);                                         //if result becomes zero then removezero fn makes it null so inserting 0 if its null
    hptr1=copy(hptr3);                       
    hptr3=NULL;
   count++;                                                                  
  reverse(&hptr2);                                                           // reversing hptr2 so as to use in comparator function 
      }
  if(a[0]!=b[0])printf("-");
  printf("%ld",count);
}          

