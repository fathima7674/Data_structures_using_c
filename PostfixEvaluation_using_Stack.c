#include<stdio.h>
#include<math.h>
#define MAX 20
int a[MAX];
int top=-1;
int operation(int,int,char);
void push(int);
int pop();

void main()
{
        char postfix[MAX],c;
        int op1,op2,res;
        int i=0;
        printf("enter the postfix expression\n");
        scanf("%s",postfix);
        while(postfix[i]!='\0')
        {
                c=postfix[i];
                if(isdigit(c))
                {
                        push(c-'0');
                }
                else
                {
                        op1=pop();
                        op2=pop();
                        res=operation(op1,op2,c);
                        push(res);
                }
                i++;
        }
        printf("postfix evaluation result is for the given infix expression is %s:%d\n",postfix,a[top]);
}
int operation(int op1,int op2,char ch)
{
        switch(ch)
        {
                case '^':return(pow(op1,op2));
                         break;
                case '*': return(op1*op2);
                          break;
                case '/':return(op1/op2);
                         break;
                case '%':return(op1%op2);
                         break;
                case '+':return(op1+op2);
                         break;
                case '-':return(op1-op2);
                         break;
                default:printf("check choice\n");
        }
}
void push(int x)
{
        a[++top]=x;
}
int pop()
{
        return a[top--];
}
