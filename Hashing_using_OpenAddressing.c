

































































































































































































































































































































































#include<stdio.h>
void main()
{
        int a[10],x,flag=0,ch,i;
        for(i=0;i<10;i++)
        {
                a[i]=-1;
        }
        while(1)
        {
                printf("\n 1.insert \n 2.search \n 3.delete \n 4.display \n 5. exit \n");
                printf("enter your choice ");
                scanf("%d",&ch);
                switch(ch)
                {
case 1:printf("enter element to insert");
      scanf("%d",&x);
      insert(a,x);
      break;
case 2:printf("enter element search");
      scanf("%d",&x);
     search(a,x);
    break;
case 3:printf("enter element to delete");
      scanf("%d",&x);
      delete(a,x);
      break;
case 4:printf("the array elements are");
      display(a);
      break;
case 5:printf("exit");
      exit(0);
default: printf("check choice");
        }
   }
}
int hash(int x)
{
        return x%10;
}
        void insert(int a[10],int x)
        {
                int i=hash(x),flag=0,j;
                if(a[i]==-1)
                {
                        a[i]=x;
                        flag=1;
                }
                else
                {
                        for(j=i+1;j<10;j++)
                        {
                                if(a[j]==-1)
                                {
                                        a[j]=x;
                                        flag=1;
                                        break;
                                }
                        }
                for(j=0;j<i&&flag==0;j++)
                {
                        if(a[j]==-1)
                        {
                                a[j]=x;
                                flag=1;
                                break;
                        }
                }
                }
                if(flag==0)
                        printf("no slot to place element=%d",x);
        }
        void search(int a[10],int x)
        {
        int i=hash(x);
         int flag=0,j;
 if(a[i]==x)
 {
flag=1;
 }
 else
{
         for(j=i+1;j<10;j++)
         {
                 if(a[j]==x)
                 {
                         flag=1;
                         break;
                 }
         }
         for(j=0;j<i&&flag==0;j++)
         {
                 if(a[j]==x)
                 {
                         flag=1;
                         break;
                 }
         }
}

         if(flag==1)
                 printf("the element is found");
         else
                 printf("the element not found");
}
void delete(int a[10],int x)
{
        int i=hash(x);
        int flag=0,j;
        if(a[i]==x)
        {
                a[i]=-1;
                flag=1;
        }
        else
        {
                for(j=i+1;j<10;j++)
                {
                        if(a[j]==x)
                        {
                                a[j]=-1;
                                flag=1;
                                break;
                        }
                }
                for(j=0;j<i&&flag==0;j++)
                {
                        if(a[j]==x)
                        {
                                a[j]=-1;
                                flag=1;
                                break;
                        }
                }
}
if(flag==1)
        printf("element %d found and deleted",x);
else
        printf("element %d not found",x);
}
void display(int a[10])
{
        int i;
        for(i=0;i<10;i++)
        {
                printf("%d\t",a[i]);

        }
}
