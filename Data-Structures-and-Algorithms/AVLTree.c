#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *lcptr;
	int data;
	int height;
	struct node *rcptr;
};

struct node *rptr = NULL;

void inorder(struct node *ptr)
{
	if(ptr)
	{
		inorder(ptr->lcptr);
		printf("%d-%d\n",ptr->data,ptr->height);
		inorder(ptr->rcptr);
	}
}

int Height(struct node *ptr)
{
	int lh,rh;
	if(ptr == NULL)
	{
		return -1;
	}
	else 
	{
		if(ptr->lcptr == NULL)
		{
			lh = -1;
		}
		else
		{
			lh = (ptr->lcptr)->height;
		}		
		if(ptr->rcptr == NULL)
		{
			rh = -1;
		}
		else
		{
			rh = (ptr->rcptr)->height;
		}
	}
	if(lh < rh)
	{
		return rh + 1;
	}
	else
	{
		return lh + 1;
	}
}

struct node *RotateRight(struct node *ptr)// case 1
{
	struct node *xptr = ptr;
	struct node *yptr = ptr->lcptr;
	xptr->lcptr = yptr->rcptr;
	yptr->rcptr = xptr;
	xptr->height=Height(xptr);
	yptr->height=Height(yptr);
   	return yptr;
}

struct node *RotateLeft(struct node *ptr)// case 4 
{
	struct node *xptr = ptr;
	struct node *yptr = ptr->rcptr;
	xptr->rcptr = yptr->lcptr;
	yptr->lcptr = xptr;
	xptr->height=Height(xptr);
	yptr->height=Height(yptr);
	return yptr;
}

struct node *RotateLeftRight(struct node *ptr)//case 2
{
	ptr->lcptr = RotateLeft(ptr->lcptr);
	return RotateRight(ptr);
}

struct node *RotateRightLeft(struct node *ptr)//case 3
{
	ptr->rcptr = RotateRight(ptr->rcptr);
	return RotateLeft(ptr);
}

struct node *insert(int x,struct node * ptr)
{
	if(ptr == NULL)
	{
		ptr = (struct node*)malloc(sizeof(struct node));
		ptr->data = x;
		ptr->height = 0;
		ptr->lcptr = ptr->rcptr = NULL;
	}
	else
	{
		if(x < ptr->data)
		{
			ptr->lcptr = insert(x,ptr->lcptr);
		}
		else
		{
			ptr->rcptr = insert(x,ptr->rcptr);
		}
		ptr->height = Height(ptr);
		if((Height(ptr->lcptr) - Height(ptr->rcptr) == -2) || (Height(ptr->lcptr) - Height(ptr->rcptr) == 2))
		{
			if(x < ptr->data)
			{
				if(x < (ptr->lcptr)->data)     //case 1
				{
					ptr = RotateRight(ptr);
				}
				else  //case 2
				{
					ptr=RotateLeftRight(ptr); 
				}
			}
			else
			{
				if(x < (ptr->rcptr)->data) //case 3
				{
					ptr = RotateRightLeft(ptr);
				}
				else  //case 4
				{
					ptr=RotateLeft(ptr);
				}
				
			}
		}
	}
	return ptr;
}

void main()
{
	rptr = insert(50,rptr);
	printf("1:\n");
	inorder(rptr);
	rptr = insert(40,rptr);
	printf("2:\n");
	inorder(rptr);
	rptr = insert(30,rptr);
	printf("3:\n");
	inorder(rptr);
	rptr = insert(20,rptr);
	printf("4:\n");
	inorder(rptr);
	rptr = insert(10,rptr);
	printf("5:\n");
	inorder(rptr);
}