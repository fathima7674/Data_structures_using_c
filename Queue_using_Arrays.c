#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int a[MAX];
int front=-1,rear=-1;
void enqueue(int x)
{
        if(rear==MAX-1)
        {
                printf("queue is overflow\n");
        }
        else
        {
                if(front==-1)
                {
                        front=rear=0;
                }
                else
                {
                        ++rear;
                }
                a[rear]=x;
        }
}
int dequeue()
{
        int x;
        if(front==-1)
        {
                return -1;
        }
        else
        {       x=a[front];
                if(front==rear)
                {
                        front=rear=-1;
                }
                else
                {
                        ++front;
                }
                return x;
        }
}
void display()
{
        int i;
        if(front==-1)
        {
                printf("queue is empty");
        }
        else
        {
                for(i=front;i<=rear;i++)
                {
                        printf("%d\t",a[i]);
                }
        }
}
int main()
{
        int x,ch;
        while(1)
        {
        printf("1.insert\n 2.delete \n 3.display \n 4.exit\n");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1:printf("enter element to insert\n");
                       scanf("%d",&x);
                       enqueue(x);
                       break;
                case 2:x=dequeue();
                       if(x==-1)
                       {
                               printf("queue underflow\n");
                       }
                       else
                       {
                               printf("deleted element is:%d",x);
                       }
                       break;
                case 3:printf("queue elements are:\n");
                       display();
                       break;
                case 4:exit(0);
                default: printf("check choice\n");
        }
        }
}