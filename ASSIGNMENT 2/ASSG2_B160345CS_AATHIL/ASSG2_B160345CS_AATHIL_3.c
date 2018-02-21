#include<stdio.h>
#include<stdlib.h>
void swap(int*,int*);
void heapify(int *ar,int,int);
void heap_sort(int *ar,int,int);

void main(){

int k,n,i,j;
scanf("%d",&n);
int *a;
 a=(int*)malloc(n*sizeof(int)); 
if(a==NULL)
   exit(0);
for(i=0;i<n;i++)
{
   scanf("%d",&a[i]);
}
scanf("%d",&k);
heap_sort(a,n,k);	
/*for(i=0;i<n;i++)
{
   printf("%d  ",a[i]);
}*/

printf("%d",a[n-k]);
}

void heap_sort(int *ar,int n,int k)
{
int i;
for(i=(n/2)-1;i>=0;i--)
{
  heapify(ar,n,i);

}
for(i=0;i<k;i++)
{
  swap(&ar[0],&ar[n-1-i]);
  heapify(ar,n-1-i,0);
}
}

void heapify(int *ar,int n,int i)
{
 int left=2*i+1;
 int right=2*i+2;
 int parent=i;
if(left<n && ar[left]>ar[parent])
  {
   parent=left;
  }

if(right<n && ar[right]>ar[parent])
  {
   parent=right;
  }
if(parent!=i)
  {
   swap(&ar[i],&ar[parent]);
   heapify(ar,n,parent);
}
}
void swap(int *p,int *q)
{

int temp=*p;
   *p=*q;
   *q=temp;
}


