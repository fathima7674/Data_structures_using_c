#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int a[MAX],front=-1,rear=-1;
void enqueue(int x)
{
if((front==0  && rear==MAX-1)||(front==rear+1))
{
printf("queue overflow");
}
else
{
if(front==-1)
{
front=rear=0;
}
/*else if(rear==MAX-1)
{
rear=0;
}
else
{
++rear;
} */
else
{

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
{
x=a[front];
if(front==rear)
{
front=rear=-1;
}
else if(front==MAX-1)
{
front=0;
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
else if(front<=rear)
{
for(i=front;i<=rear;i++)
{
printf("%d\t",a[i]);
}
}
else
{
for(i=front;i<MAX-1;i++)
{
printf("%d\t",a[i]);
}
for(i=0;i<=rear;i++)
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

    return 0;
}