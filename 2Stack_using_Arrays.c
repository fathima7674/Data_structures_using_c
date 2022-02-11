#include<stdio.h>
#define MAX 20
int a[MAX];
int top1=-1;
int top2=MAX;
void push1(int x)
{
        if(top1==top2-1)
        {
                printf("stack1 is overflow\n");
        }
        else
        {
                //++top1;
                //a[top]=x;
                a[++top1]=x;
        }
}
void push2(int x)
{
        if(top2==top1+1)
        {
                printf("stack 2 is overflow \n");
        }
        else
        {
                a[--top2]=x;
        }
}
int pop1()
{
        if(top1==-1)
        {
                return -1;
        }
        else
        {
                return a[top1--];
        }
}
int pop2()
{
        if(top2==MAX)
        {
                return -1;
        }
        else
        {
                return a[top2++];
        }
}
void display1()
{
        int i;
        if(top1==-1)
        {
                printf("stack 1 is empty \n");
        }
        else
        {
        for(i=top1;i>=0;i--)
        {
                printf("%d\t",a[i]);
        }
        }
}
void display2()
{
        int i;
        if(top2==MAX)
        {
                printf("stack 2 is underflow\n");
        }
        else
        {
                for(i=top2;i<MAX;i++)
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

        printf("\n1.insert1\n 2.insert2 \n 3.delete1 \n 4.delete2 \n 5.display1 \n 6.display2 \n 7.exit \n");
        printf("enter your choice \n");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1:printf("enter element to insert in stack1 \n");
                       scanf("%d",&x);
                       push1(x);
                       break;
                case 2:printf("enter element to insert in stack 2 \n");
                       scanf("%d",&x);
                       push2(x);
                       break;
                case 3:x=pop1();
                       if(x==-1)
                               printf("stack underflow\n");
                       else
                               printf("deleted element is:%d",x);
                       break;
                case 4:x=pop2();
                       if(x==-1)
                               printf("stack2 underflow \n");
                       else
                               printf("deleted element is:%d",x);
                       break;
                case 5:printf("stack1 elements are\n");
                       display1();
                       break;
                case 6:printf("stack2 elements are\n");
                       display2();
                       break;
                case 7:exit(0);
                       break;
                default:printf("check choice\n");
        }
        }
}