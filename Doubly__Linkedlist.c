#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
struct ccl
{
  int data;
  struct ccl *left,*right;

};
typedef struct ccl node;
node *create(node *first)
{
  node *new,*prev;
  int x;
  printf("enter data or -1");
  scanf("%d",&x);
  while(x!=-1)
  {
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->left=new->right=NULL;
    if(first==NULL)
    {
      first=new;
      prev=new;
     
    }
    else
{
  prev->right=new;
  new->left=prev;
 
  prev=new;
}
printf("enter data or -1");
scanf("%d",&x);
  }
 
  return first;
}
void display(node *first)
{
  node *temp=first;
  if(first==NULL)
  {
    printf("no list to print");
  }
  else
{
 
  while(temp!=NULL)
{
  printf("|%d|->",temp->data);
  temp=temp->right;
}
printf("NULL");
}
}
int count(node *first)
{
  node *temp=first;
  int c=0;
  if(first==NULL)
  {
    return c;
  }
  else
{
  while(temp!=NULL)
{
  c++;
  temp=temp->right;
 
}
}
return c;

}
void search(node *first,int x)
{
  node *temp=first;
  int flag=0;
  if(first==NULL)
  {
    printf("no list to search");
   
  }
  else
{
  while(temp!=NULL)
{
  if(temp->data==x)
  {
    flag=1;
    break;
    }
    else
{
  temp=temp->right;

}

  }
}
if(flag==1)
printf("element found");
else
printf("not found");
}

node *insert_at_begin(node *first,int x)
{
  node *temp,*new;
  new=(node*)malloc(sizeof(node));
  new->data=x;
  new->left=new->right=NULL;
  if(first==NULL)
  {
    first=new;
   
  }
  else
{
 
 
  new->right=first;
  first->left=new;
  first=new;
}
return first;
}

node *insert_at_end(node *first,int x)
{
  node *temp=first,*new;
  new=(node*)malloc(sizeof(node));
  new->data=x;
  new->left=new->right=NULL;
  if(first==NULL)
  {
    first=new;
   
  }
  else
{
 
  while(temp->right!=NULL)
{
  temp=temp->right;
}

temp->right=new;
new->left=temp;
}
return first;
}

node *insert_at_pos(node *first,int pos,int x)
{
  node *temp=first,*new;
  int n=count(first);
  if(pos>1&&pos<n)
  {
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->left=new->right=NULL;
    for(int i=1;i<pos-1;i++)
    {
      temp=temp->right;
    }
    new->right=temp->right;
    temp->right=new;
    new->left=temp;
    new->right->left=new;
  }
  return first;
}

node *delete(node *first,int x)
{
  node *temp=first;
  int flag=0;
  if(first==NULL)
  {
    printf("no elements to delete");
   
  }
  else if(first->data==x)
  {
   
  
   
    first=first->right;
    if(first!=NULL)
    {
      first->left=NULL;
    }
   
    free(temp);
  }
  else
{
  temp=first;
 
  while(temp!=NULL)
  {
    if(temp->data==x)
    {
      flag=1;
      break;
     
    }
    else
{
 
  temp=temp->right;
}
}
 
  if (flag==1)
  {
    if(temp->right==NULL)
    {
    temp->left->right=NULL;
    free(temp);
    printf("element is deleted");
    }
    else
{
  temp->right->left=temp->left;
  temp->left->right=temp->right;
  free(temp);
}
}
 
  else
{ printf("element %d not found",x);
}
}
return first;
}

//Compiler version gcc  6.3.0

int main()
{
  int ch,x,pos,n;
  node * head=NULL;
  //printf("Hello, World!");
  while(1)
  {
    printf("\n 1 create \n 2.display\n 3.count\n4.search\n 5.insert at beg\n 6.insert at end\n 7.insert at pos\n 8.delete \n 9.exit\n ");
    printf("enter u r choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: head=create(head);
      break;
      case 2:printf("\n the list of elements are");
      display (head);
      break;
      case 3: n=count(head);
      printf("no of elements in list are %d:",n);
      break;
      case 4:printf("enter element to serach");
      scanf("%d",&x);
      search(head,x);
      break;
      case 5:printf("\n enter element to insert ");
      scanf("%d",&x);
      head=insert_at_begin(head,x);
      break;
      case 6:printf("\n enter element to insert ");
      scanf("%d",&x);
      head=insert_at_end(head,x);
      break;
      case 7:printf("\n enter element to insert ");
      scanf("%d",&x);
      printf("\n enter position to insert");
      scanf("%d",&pos);
      head=insert_at_pos(head,pos,x);
      break;
      case 8:
       printf("\n enter element to delete");
      scanf("%d",&x);
      head=delete(head,x);
      break;
      case 9:exit(0);
      default:printf("check choice ");
     
    }
  }
}