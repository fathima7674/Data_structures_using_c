#include<stdio.h>
#include<stdlib.h>
struct stack
{
        int data;
        struct stack *next;
};
typedef struct stack node;
node *top=NULL;
void main()
{
        int ch,x;
        while(1)
        {
                printf("1.push \n 2.pop \n 3.peak \n 4.display \n 5.exit \n");
                printf("enter your choice\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:printf("enter element to push\n");
                               scanf("%d",&x);
                               push(x);
                               break;
                        case 2:x=pop();
                               if(x==-1)
                               {
                                       printf("stack underflow\n");
                               }
                               else
                               {
                                       printf("popped element is %d",x);
                               }
                               break;
                        case 3:x=peak();
                               printf("top element of the stack is %d",x);
                              break;
                        case 4:printf("stack elements are\n");
                        case 5:exit(0);
                              //break;
                        default:printf("check choice\n");
                }
}
}
void push(int x)
{
        node *new;
        new=(node*)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(top==NULL)
        {
                top=new;
        }
        else
        {
                new->next=top;
                top=new;
        }
}
int pop()
{
        node *temp;
        int x;
        if(top==NULL)
        {
                return -1;
        }
        else
        {
                temp=top;
-- INSERT --    x=top->data;                                                                  44,2          57%
                top=top->next;
                free(temp);
                return x;
        }
}
int peak()
{
        return(top->data);
}
void display()
{
        node *temp;
        temp=top;
        while(temp!=NULL)
        {
                printf("|%d|->",temp->data);
                temp=temp->next;
        }
        printf("NULL\n");
}
