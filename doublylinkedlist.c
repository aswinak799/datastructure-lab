#define size 10
#include<stdio.h>
#include<stdlib.h>
struct node
{int data;
struct node *left,*right;
};struct node *start=NULL;
void main()
{
struct node* search(int);
void delete(int);
void insert(int);
int data,option;
struct node *t;
printf("...................DOUBLY LINKED LIST................\n");
do
{
printf("1.INSERT\n");
printf("2.SEARCH\n");
printf("3.DELETE\n");
printf("4.EXIT\n");
printf("Enter your option:\n");
scanf("%d",&option);
switch(option)
{
case 1:printf("Enter the data\n");
scanf("%d",&data);
insert(data);
break;

case 2:printf("enter the data to search\n");
scanf("%d",&data);
t=search(data);
if(t==(struct node*)0)
{
printf("ITEM NOT FOUND:....\n\n");
}
else
{
printf("ITEM FOUND\n\n");
}
break;
case 3:printf("Enter the item to delete\n");
scanf("%d",&data);
delete(data);
printf("Deleted item is:%d",data);
printf("\n");
break;

case 4:exit(1);
}// this end of switch
}
while(1);
}
//function to insert node at begining of
//doubly linked list
void insert(int data)
{
struct node *t;
t=(struct node*)malloc(sizeof(struct node));
t->data=data;
if(start==(struct node*)0)
{
t->left=t->right=(struct node*)0;
}
else
{t->left=(struct node*)0;
t->right=start;
start->left=t;
}
start=t;
}
struct node* search(int data)
{
struct node *t=start;
while(t!=(struct node*)0 && t->data!=data)
{
t=t->right;
}
return t;
}
void delete(int data)
{
struct node *t;
t=search(data);
if(t==0)
{
printf("NOT FOUND DATA\n\n");
}
else
{
if(t==start) //case of first node
{
if(t->right==(struct node*)0)
start=(struct node*)0;//one and only one node
else
{t->right->left=t->left;//remove 1st node ,more than one node
start=t->right;
}
}
else if(t->right==(struct node*)0)// case of last node
{
t->left->right=t->right;
}
else//case of inter node
{t->left->right=t->right;
t->right->left=t->left;
}
free(t);
}
}
