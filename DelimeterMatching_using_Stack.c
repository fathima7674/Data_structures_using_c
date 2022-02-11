#include<stdio.h>
#define MAX 20
int top=-1;
char a[MAX];
void push(char);
char pop();
void main()
{
        char exp[MAX],ch,x;
        int i=0;
        int flag=1;
        printf("enter the expression for delimeter matching\n");
        scanf("%s",exp);

        while(exp[i]!='\0')
        {
                ch=exp[i];
                if(ch=='(' || ch=='{' || ch=='[')
                {
                        push(ch);
                }
                else if(ch==')' || ch=='}' || ch==']')
                {
                        if(top==-1)
                        {
                                flag=0;
                                break;
                        }
                        else
                        {
                                x=pop();
                                if(x=='(' && ch==')' || x=='{' && ch=='}' || x=='[' && ch==']')
                                {
                                        flag=1;

                                }
                                else
                                {
                                        flag=0;
                                        break;

                                }
                        }
                }
                i++;
        }
        if(top!=-1)
        {
                flag=0;

        }

        if(flag==1)
                printf("matched\n");
        else
                printf("not matched\n");
}

void push(char x)
{
        a[++top]=x;
}
char pop()
{
        return a[top--];
}
