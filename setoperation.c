#include<stdio.h>
struct bit 
 {
	unsigned char x:1;
 };
int u[]={1,2,3,4,5,6,7,8,9},size=9; //declaring universal set

void main()
 {
	void insert(struct bit[],int);
	void display(struct bit[]);
	void setunion(struct bit[],struct bit[],struct bit[]);
	void setintersection(struct bit[],struct bit[],struct bit[]);
	void setdiff(struct bit[],struct bit[],struct bit[]);
	struct bit a[9]={0}; //assigning zeros to all places of a
	struct bit b[9]={0}; //assigning zeros to all places of b
	struct bit c[9]={0}; //assigning zeros to all places of c
	int x,y,i;
	printf("Enter the size of set A:\n");
	 scanf("%d",&x);
	printf("Enter the elements of set A:\n");
	 insert(a,x);
	printf("Enter the size of  set B:\n");
	 scanf("%d",&y);
	printf("Enter the elements of set B:\n");
	 insert(b,y);
	printf("A U B: ");
	 setunion(a,b,c);
	printf("\n");
	printf("\nA I B: ");
	 setintersection(a,b,c);
	printf("\n");
	printf("\nA-B: ");
	 setdiff(a,b,c);
	printf("\n"); 
}

void insert(struct bit a[],int n)
 {
	int i,d,j;
	printf("Enter %d elements: \n",n);
	for(i=0;i<n;i++)
	  {
		scanf("%d",&d);
		for(j=0;j<size;j++)
		  {
			if(d==u[j])
			 {
				a[j].x=1;
				break;
			 }
		  }
	  }
 }

void display(struct bit a[])
 {
	int i;
	printf("{");
	for(i=0;i<size;i++)
	  {
		if(a[i].x==(unsigned char)1)
		 {
			if(i!=0){
				printf(",");
			}
			printf("%d",u[i]);
		 }
	  }
	  printf("}");
	return;
 }

void setunion(struct bit a[],struct bit b[],struct bit c[])
 {
	int i;
	for(i=0;i<size;i++)
	  {
		c[i].x=a[i].x | b[i].x;
	  }
	display(c);
	return;
 }

void setintersection(struct bit a[],struct bit b[],struct bit c[])
 {
	int i;
	for(i=0;i<size;i++)
	  {
		c[i].x=a[i].x & b[i].x;
	  }
	display(c);
	return;
 }

void setdiff(struct bit a[],struct bit b[],struct bit c[])
 {
	int i;
	for(i=0;i<size;i++)
	  {
		c[i].x=a[i].x & !(b[i].x);
	  }
	display(c);
	return;
 }

