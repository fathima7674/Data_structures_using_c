#include<stdio.h>
#include<stdlib.h>
struct queue
{
        int data;
        struct queue *next;
};
typedef struct queue node;
node *front=NULL,*rear=NULL;
node *enqueue(int x)
{
        node *new=(node*)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;

        if(front==NULL)
        {
                front=rear=new;
        }
        else
        {
                rear->next=new;
                rear=new;
        }
}
int dequeue()
{
        int x;
        if(front==NULL)
        {
                return -1;
        }
        else
        {
                x=front->data;
                if(front==rear)
                {
                        front=rear=NULL;
                }
                else
                {
                        front=front->next;
                }
                return x;
        }

}
void display()
{
        node *temp;
        if(front==NULL)
        {
                printf("queue is empty\n");
        }
        else
        {
        temp=front;

        while(temp!=NULL)
        {
                printf("%d\t",temp->data);
                temp=temp->next;
        }
}
}
void main()
{
        int x,ch;
        while(1)
        {
                printf("\n1.insert \n 2.delete \n 3.display \n 4.exit\n");
                printf("enter your choice \n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:printf("enter element to insert \n");
                               scanf("%d",&x);
                               enqueue(x);
                               break;
                        case 2:x=dequeue();
                               if(x==-1)
                               {
                                       printf("queue is underflow \n");
                               }
                               else
                               {
                                       printf("deleted element is:%d",x);
                               }
                               break;
                        case 3:printf("queue elements are :");
                               display();
                               break;
                        case 4:exit(0);
                               break;
                        default: printf("check choice\n");
                }
        }
}
