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
return 0;}}

void main()
{  char a[20],b[20];
   struct node* hptr1=NULL;
   struct node* hptr2=NULL;
   printf("enter the number 1 along with sign:");
   gets(a);
   printf("enter the number 2 along with sign:");
   gets(b);
   for(int i=1;i<strlen(a);i++)
     insert(a[i]-48,&hptr1);
   for(int i=1;i<strlen(b);i++)
     insert(b[i]-48,&hptr2);
  printf("\n");
    reverse(&hptr1);reverse(&hptr2);
   printf("negation of number 1:");
   if(a[0]=='+')printf("-");
   else printf("+");
   print(hptr1);
printf("\n");
   if(a[0]=='+' && b[0]=='-')
      printf("no 1 is the greater number");
  else if(a[0]=='-' && b[0]=='+')
        printf("no 2 is the greater number");
   else if(a[0]=='+' && b[0]=='+')
        printf("%d 1-no 1 is greater -1 no 2 is greater 0=both are same",comparator(hptr1,hptr2));
  else 
         printf("%d 1=no 2 is greater -1=no 1 is greater 0=both are same",comparator(hptr1,hptr2));



}

