#include<stdio.h>
void main()
{
void readarr(int[],int);
void disarr(int[],int);
void merge(int[],int[],int[],int,int);
int s1[50],s2[50],s3[100],n,m;
printf("enter the limit of array: \");
scanf("%d",&n);
printf("enter the element s of 1st array:");
readarr(s1,n);
printf("enter the limit of 2nd array: ");
scanf("%d",&m);
printf("enter the elements for 2nd array:");
readarr(s2,m);
merge(s1,s2,s3,n,m);
printf("the merged Array list is:\n");
disarr(s3,m+n);
}
void readarr(int s[],int n)
{
int i;
printf("enter the no.s in non decreasing order: ");
for(i=0;i<n;++i)
scanf("%d",&s[i]);
return;
}
void disarr(int s[],int n)
{
int i;
for(i=0;i<n;++i)
printf("%d\n",s[i]);
return;
}
void merge(int s1[],int s2[],int s3[],int m,int n)
{
int i,j,k;
i=j=k=0;
while(i<m && j<n)
{
if (s1[i]<s2[j])
{
s3[k]=s1[i];
i=i+1;
k=k+1;
}
else
{
s3[k]=s2[j];
j=j+1;
k=k+1;
}
}
while(i<m)
{
s3[k++]=s1[i++];

}
while(j<n)
{
s3[k++]=s2[j++];
}
return;
}
