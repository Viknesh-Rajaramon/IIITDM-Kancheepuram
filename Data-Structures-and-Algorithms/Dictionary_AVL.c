#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
  char word[20];
  char mean[20];
  struct node* lptr;
  struct node* rptr;
  int ht;
  };
  struct node* root=NULL;
  
  int height(struct node *ptr)
  {
    int lh,rh;
    if(ptr==NULL)
    {
       return -1;}
    else
      {  if(ptr->lptr==NULL)
           lh=-1;
          else 
           lh=(ptr->lptr)->ht; 
         if(ptr->rptr==NULL)
           rh=-1;
           else 
             rh=(ptr->rptr)->ht;
       }
     if(lh<rh)
       return rh+1;
      else 
         return lh+1;
    }
  struct node* rotateright(struct node *ptr)
  {
     struct node* xptr=ptr;
     struct node* yptr=ptr->lptr;
     xptr->lptr=yptr->rptr;
     yptr->rptr=xptr;
  xptr->ht=height(xptr);
  yptr->ht=height(yptr);
    return yptr;
  }      
    struct node* rotateleft(struct node *ptr)
    {
           struct node* xptr=ptr;
           struct node* yptr=ptr->rptr;
           xptr->rptr=yptr->lptr;
           yptr->lptr=xptr;
  xptr->ht=height(xptr);
  yptr->ht=height(yptr);
    return yptr;
  }
  struct node* rotateleftright(struct node *ptr)
  {
      ptr->lptr=rotateleft(ptr->lptr);
      return rotateright(ptr);
   }
  struct node* rotaterightleft(struct node*ptr)
  {
     ptr->rptr=rotateright(ptr->rptr);
     return rotateleft(ptr);
   }
  void preorder(struct node* ptr)
       {  if(ptr!=NULL)
           { printf(" %s ",ptr->word);
              preorder(ptr->lptr);              
              preorder(ptr->rptr);}
       }
  void postorder(struct node* ptr)
       {  if(ptr!=NULL)
           {  postorder(ptr->lptr);              
              postorder(ptr->rptr);
              printf(" %s ",ptr->word);}
       }
    
   struct node* insert(char a[],char b[],struct node* ptr)
   {
      if(ptr==NULL)
      {
         ptr=(struct node*) malloc(sizeof(struct node));
         strcpy(ptr->word,a);
         strcpy(ptr->mean,b);
         ptr->lptr=ptr->rptr=NULL;
      }
      else 
        { if(strcmp(a,ptr->word)<0)
           { ptr->lptr=insert(a,b,ptr->lptr);}
          else
            ptr->rptr=insert(a,b,ptr->rptr);
         }
        ptr->ht=height(ptr);
      if(height(ptr->lptr)-height(ptr->rptr)==2||height(ptr->lptr)-height(ptr->rptr)==-2)
       {
         if (strcmp(a,ptr->word)<0)
             { if(strcmp(a,(ptr->lptr)->word)<0)
                    ptr=rotateright(ptr);
               else 
                  ptr=rotateleftright(ptr);
              }
         else {     
            if(strcmp(a,(ptr->rptr)->word)>0)
                   ptr=rotateleft(ptr);
            else
                 ptr=rotaterightleft(ptr);
             }
        }
                return ptr;
     }
      
  void search(char s[],struct node* ptr)
  {  struct node* tptr=ptr;
     if(tptr==NULL) 
       printf("dict is empty");
     else
       while(tptr!=NULL && strcmp(tptr->word,s)!=0)
       {
          if(strcmp(s,tptr->word)<0)
            {  tptr=tptr->lptr;}
          else 
             tptr=tptr->rptr;
        }
          if(tptr==NULL)
            printf("word not found");
          else
           printf("%s means %s",tptr->word,tptr->mean);     
  }                          
  void main()
  { 
      int i,j,n;
      char a[20],b[20],c[20],z;  
      printf("enter the number of inputs");
       scanf("%d",&n);
       z=getchar();
       printf("inserting");
     for(i=0;i<n;i++) 
      
         {   
              printf(" enter word ");
          gets(a);
          printf("enter meaning ");
          gets(b);
          root=insert(a,b,root);   
       }   
       printf("the built dict is (in preorder) ");
       preorder(root);
        printf("the built dict is (in postorder) ");
       postorder(root);
       printf("\n enter word to search ");
       gets(c);
       search(c,root);
     
  /*   root=insert("data","who",root);
     preorder(root);
     printf("\n");
     root=insert("rithic","awesome",root);
     preorder(root);
     printf("\n");
     root=insert("prog","random",root);
     preorder(root);
     printf("\n");
     root=insert("algo","random1",root);
     preorder(root);
     printf("\n");
     root=insert("done","me",root);
     preorder(root);
     printf("\n");
    search("rithic",root);*/
    
   }
         
   
      
   
              
        
        
             
                                   
                      
           
    
                   
