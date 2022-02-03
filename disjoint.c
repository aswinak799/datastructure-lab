#include<stdio.h>
#include<stdlib.h>
struct node{
int value;
struct rep * repptr;
struct node * next;
};
struct rep{
struct node * head;
struct node * tail;
};
struct nodaddr{
int key;
struct node * obj_node_ptr;
struct nodaddr * next;
};
struct nodaddr * ndr=0;
//function to create a set for an object
void makeset(int a)
{//create a set reference
struct nodaddr * t=(struct nodaddr *)malloc(sizeof(struct nodaddr));
//create a new set
struct rep * newset=(struct rep *)malloc(sizeof(struct rep));
struct node * n=(struct node *)malloc(sizeof(struct node));
//fill values
n->value=a;
n->repptr=newset;
n->next=0;
//initialize head and tail
newset->head=newset->tail=n;
//to store object node pointer and key
t->obj_node_ptr=n;
t->key=a;
t->next=ndr;
ndr=t;
}
//function to return pointer of the representative
//containing x
struct rep * find(int x)
{
struct nodaddr *t=ndr;
while(t->key!=x && t!=0)
t=t->next;
return t->obj_node_ptr->repptr;
}
void unionset(int key1,int key2)
{
struct rep * set1,* set2;
struct node *t1;
set1=find(key1);
set2=find(key2);
t1=set2->head;
while(t1!=0)
{
t1->repptr=set1;
t1=t1->next;
}
//set the tail of set1 to tail of set2
set1->tail->next=set2->head;
set1->tail=set2->tail;
free(set2);
}
//function to display a set
void display_set(int a)
{
struct rep * r;
r=find(a);
printf("Set members containing %d : ",a);
while(r->head!=0)
{
printf("%d,",r->head->value);
r->head=r->head->next;
}
}
void main()
{
makeset(10);
makeset(20);
makeset(30);
makeset(40);
makeset(50);
printf("find(10)=%p",find(10));
printf("\nfind(20)=%p",find(20));
printf("\nfind(30)=%p",find(30));
printf("\nfind(40)=%p",find(40));
unionset(10,20);
printf("\nAfter union of 10 and 20 find(20)=%p",find(20));
unionset(30,40);
printf("\nAfter union of 30 and 40 find(40)=%p",find(40));
unionset(20,40);
printf("\nAfter union of set containing 20 and 40 find(40)=%p",find(40));
}

/*
--output---

find(10)=0x562f3cf7a280
find(20)=0x562f3cf7a2e0
find(30)=0x562f3cf7a340
find(40)=0x562f3cf7a3a0
After union of 10 and 20 find(20)=0x562f3cf7a280
After union of 30 and 40 find(40)=0x562f3cf7a340
After union of set containing 20 and 40 find(40)=0x562f3cf7a280

*/
