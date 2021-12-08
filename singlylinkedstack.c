#define size 10
#include<stdio.h>
#include<stdlib.h>
struct node
{int data;
struct node *next;
};
int flag;
struct node *sp=(struct node*)0;
void main()//main function
{
void push(int);
int pop();
int search(int);
int option,data,k;
printf("...................SINGLY LINKED STACK................\n");
do
{
printf("1.PUSH\n");
printf("2.POP\n");
printf("3.SEARCH\n");
printf("4.EXIT\n");
printf("Enter your option:\n");
scanf("%d",&option);
switch(option)
{
	case 1:printf("Enter the data\n");
	      scanf("%d",&data);
	      push(data);
		break;

	case 2:data=pop();
	       if(flag==1)
	       printf("poped item is: %d\n",data); //poping elements from stack
		break;
	case 3:printf("Enter the data to search\n");
		scanf("%d",&data);
		k=search(data);
		if(k==1)
		{
		  printf("Item not found\n");
		}
		break;

	case 4:exit(0);
}// this end o switch
}
while(1);
}
void push(int x)//function for push elememt
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=sp;
    sp=newnode;
}
int pop()//function for delete elements from singly linked stack
{
   int a;
   struct node *temp;
   if(sp==(struct node *)0)
   {
	flag=0;     
	printf("empty stack\n");
   }
   else
   {
    a=sp->data;
    temp=sp;
    sp=sp->next;
    free(temp);
    flag=1;
    return a;
   }
}
int search(int x)
{
    struct node *ptr;
    ptr=sp;
    while(ptr!=0)
    {
     if(ptr->data==x)
      {
       printf("item found...\n");
       return 0;
      }
     ptr=ptr->next;
    }
return 1;
}
