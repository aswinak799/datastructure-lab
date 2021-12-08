#define size 10
#include<stdio.h>
#include<stdlib.h>
int stk[size];
int front=0;
int rear=0;
int start;
void main()
{
void insert(int);
int delete();
int search(int);
int option,item,k;
do
{
printf("...................QUEUE OPERATIONS................\n");
printf("1.INSERTION\n");
printf("2.DELETION\n");
printf("3.SEARCH\n");
printf("4.EXIT\n");
printf("Enter your option:\n");
scanf("%d",&option);
if(option==1)
{
printf("Enter the item\n");
scanf("%d",&item);
insert(item);
}
else if(option==2)
{
item=delete();
if(start==1)
printf("Deleted item is: %d\n",item);
}
else if(option==3)
{
printf("Enter the value to be search\n");
scanf("%d",&item);
k=search(item);
if(k==0)
printf("ITEM NOT FOUND...\n");
}
else
exit(1);
}
while(1);
}
void insert(int n)
{
int t;
t=(rear+1)%size;
if(front==t)
{
printf("THE QUEUE IS FULL!\n");
return;
}
rear=t;
stk[rear]=n;
}
int delete()
{
int r;
if(front==rear)
{
printf("THE QUEUE IS EMPTY\n");
 start=0;
}
else
{
front=(front+1)%size;
start=1;
return stk[front];
}
}
int search(int ser)
{
int f,r;
f=front;
r=rear;
while(f!=r)
{
f=(f+1)%size;
if(stk[f]==ser)
{printf("ITEM FOUND\n");
return(1);
}
}
return 0;
}

