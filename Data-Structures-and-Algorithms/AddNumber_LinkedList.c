#include<stdio.h>
#include<stdlib.h>

struct node
{
 int num;
 struct node *nptr;
};

struct node *hptr=NULL;

void insert(int x,int pos)
{
 struct node *temp=(struct node *) malloc(sizeof(struct node));
 struct node *thptr=hptr;
 temp->num=x;
 if(pos==0)
 {
  temp->nptr=hptr;
  hptr=temp;
 }
 else
 {
  for(int i=0;i<pos-1;++i)
  {
   thptr=thptr->nptr;
  }
  temp->nptr=thptr->nptr;
  thptr->nptr=temp;
 }
}

void print(struct node *p)
{
 struct node *thptr=p;
 while(thptr!=NULL)
 {
  printf("%d",thptr->num);
  thptr=thptr->nptr;
 }
 printf("\n");
}

int main()
{
 int dig1,dig2,num;
 printf("\nEnter the number of digits for number 1 : ");
 scanf("%d",&dig1);
 for(int i=0;i<dig1;++i)
 {
  lab1:
  printf("\nEnter digit %d : ",i+1);
  scanf("%d",&num);
  if((num>=0) && (num<=9))
  {
   insert(num,i,hptr1);
  }
  else
  {
   printf("\nEnter again...");
   goto lab1;   
  }
 }
 printf("\nEnter the number of digits for number 2: ");
 scanf("%d",&dig2);
 for(int i=0;i<dig2;++i)
 {
  lab2:
  printf("\nEnter digit %d : ",i+1);
  scanf("%d",&num);
  if((num>=0) && (num<=9))
  {
   insert(num,i,hptr2);
  }
  else
  {
   printf("\nEnter again...");
   goto lab2;   
  }
 }
 return 0;
}
