#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left,*right;
};

struct node *root=NULL;

void main()
{

void insert(int);
struct node* search(struct node*,int);
int dele(int);
void inorder(struct node*);
int option,data,k;
printf("#########\tBINARY SEARCH TREE\t#########\n");
do
{
printf("\tCHOICES FOR YOU\n");
printf("1.INSERT\n");
printf("2.SEARCH\n");
printf("3.DELETE\n");
printf("4.DISPLAY\n");
printf("5.EXIT\n");
printf("enter your option:\n");
scanf("%d",&option);
switch(option)
{
case 1:printf("Enter data to insert:\n");
       scanf("%d",&data);
       insert(data);
       break;
case 2:printf("Enter data to search:\n");
       scanf("%d",&data);
       search(root,data);
       break;
case 3:printf("Enter data to delete:\n");
       scanf("%d",&data);
       k=dele(data);
	   if(k==0)
       printf("deleted item is:%d \n",data);
       break;
case 4:if(root==NULL)
	   printf("NULL TREE......\n");
	   else {
	   printf("Inorder traversal result: ");
        inorder(root);
        printf("\n");
	}
       break;       
case 5:printf("Exiting..\n");
       exit(0);                     
}
}while(1);
}

//function to insert a node
void insert(int x)
{
struct node *t,*t1,*t2;
t=(struct node*)malloc(sizeof(struct node));
t->data=x;
t->left=t->right=NULL;
if(root==NULL)//case of empty tree
root=t;
else
{
t1=root;
while(t1!=NULL && t1->data!=x)//condition to avoid inserting same again
{
t2=t1;//remembering parent node
if(x>t1->data)
  t1=t1->right;
else
  t1=t1->left;  
}
if(t1!=0)
   printf("duplication not allowed..\n");
else//actual insertion code block   
{
if(x>t2->data)//case of new data greather than parent
   t2->right=t;
else//case of new data lower than parent
   t2->left=t;   
}
}
}

//function to search an item
struct node* search(struct node* root,int a)
{
  if(root==NULL)//case of empty tree
     printf("NOT FOUND...\n");
   else if(root->data==a)
   {
     printf("ITEM FOUND...\n");
   } 
   else 
   {
   if(a>root->data)//case of right subtree
        return search(root->right,a);
   else //case of left subtree
        return search(root->left,a);     
   } 
}

//function to delete a node
int dele(int item)
{
struct node *t1,*t2,*t3,*sucpar,*suc;
t1=root;
//loop to find the node to be deleted
    while(t1!=NULL && t1->data!=item)
    {
      t2=t1;
      if(item>t1->data)
         t1=t1->right;
      else
         t1=t1->left;   
    
    }
  //after the loop t1 points to node to be deletd
  //t2 points to parent of the node to be deleted
  //t1==NULL implies not found
if(t1==NULL)
  printf("NOT FOUND...\n");
else //element found case
{
  if(t1->right==NULL && t1->left==NULL)//case of leaf node
  {
 if(t1!=root){
  
  if(t2->data>item)
      t2->left=NULL;
  else
      t2->right=NULL;
  }
  else
    root=NULL;        
  }
  else if(t1->left==NULL || t1->right==NULL)//case of single child
  {
  if(t1!=root)
  {
  if(item>t2->data)//case of deleting node on the right side of parent
     t2->right=t1->left==NULL?t1->right:t1->left;//case of deleting node have child on left or right
  else
     t2->left=t1->left=NULL?t1->right:t1->left; 
   }
  else{
     if(root->right!=NULL)
        root=root->right;
      else
        root=root->left;
        } 
  }
  else//case of 2 child
  //inorder successor will be left extreme of right subtree
  {
  sucpar=t1;
  suc=t1->right;
  while(suc->left!=NULL)
  {
   sucpar=suc;
   suc=suc->left;
  }
  //copy the inorder succesor to the node to be deleted
  t1->data=suc->data;
  //next step is to add link to inorder succesor parent
  //for that we need to find left or right of sucpar
  if(suc->data<sucpar->data)
    sucpar->left=suc->right;
  else
    sucpar->right=suc->right;
  t1=suc;     
  }
  free(t1);//comon removal for all cases
  return 0;
}      
}
  

void inorder(struct node *t)
{
if(t!=NULL)
{
inorder(t->left);
printf("%d,",t->data);
inorder(t->right);
}
}

