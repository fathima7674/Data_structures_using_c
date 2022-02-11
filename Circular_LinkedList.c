#include <stdio.h>
struct ccl
{
  int data;
  struct ccl *next;
 
}
typedef struct ccl node;
node *create(node *first)
{
  node *new,*prev=first;
  int x;
  printf("enter data or -1");
  scanf("%d",&x);
  while(x!=-1)
  {
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if(first==NULL)
    {
      first=new;
      prev=new;
      
    }
    else
{
  prev->next=new;
  prev=new;
}
printf("enter data or -1");
scanf("%d",&x);
  }
  prev->next=first;
  return first;
}
void display()
{
  node *temp;
  if(first==NULL)
  {
    printf("no list to print");
  }
  else
{
  temp=first;
  do
{
  printf("|%d|->",temp->data);
  temp=temp->next;
}while(temp!=first);

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
  do
{
  c++;
  temp=temp->next;
  
}while(temp!=first);
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
  do
{
  if(temp->data==x)
  {
    flag=1;
    break;
    }
    else
{
  temp=temp->next;
 
}

  }while(temp!=first);
}
if(flag==1)
printf("element found");
else
printf("not found");
}
}

node *insert_at_begin(node *first,int x)
{
  node *temp,*new;
  new=(node*)malloc(sizeof(node));
  new->data=x;
  new->next=NULL;
  if(first==NULL)
  {
    first=new;
    new->next=first;
  }
  else
{
  temp=first;
  do
{
  temp=temp->next;
    
  }while(temp->next!=first);
  new->next=first;
  temp->next=new;
  first=new;
}
return first;
}

node *insert_at_end(node *first,int x)
{
  node *temp,*new;
  new=(node*)malloc(sizeof(node));
  new->data=x;
  new->next=NULL;
  if(first==NULL)
  {
    first=new;
    new->next=first;
  }
  else
{
  temp=first;
  do
{
  temp=temp->next;
} while(temp->next!=NULL);
temp->next=new;
new->next=first;
}
return first;
}

node *insert_at_pos(node *first,int pos,int x)
{
  node *temp,*new;
  int n=count(first);
  if(pos>1&&pos<n)
  {
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    for(int i=1;i<pos-1;i++)
    {
      temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
  }
  return first;
}

node *delete(node *first,int x)
{
  node *temp1,*temp;
  if(first==NULL)
  {
    printf("no elements to delete");
    
  }
  else if(first->data==x)
  {
    temp1=first;
    temp=first;
    while(temp->next!=first)
    {
      temp=temp->next;
    }
    first=first->next;
    temp->next=first;
    free(temp1);
  }
  else
{
  temp1=first;
  temp=temp1->next;
  while(temp!=first)
  {
    if(temp->data==x)
    {
      flag=1;
      break;
      
    }
    else
{
  temp=temp->next;
}
}
  }
  if (flag==1)
  {
    temp1->next=temp->next;
    free(temp);
  }
  else
{ printf("element %d not found",x);
}
return first;
}


//Compiler version gcc 6.3.0

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
