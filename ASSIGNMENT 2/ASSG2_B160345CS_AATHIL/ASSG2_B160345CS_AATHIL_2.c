#include<stdio.h>
#include<stdlib.h>
int median_of_medians(int *a,int p,int q,int k);
void swap(int *a,int *b);
int breaking(int *a,int p,int q);
void quicksort(int *a,int p,int q);

int median_of_medians(int *a,int p,int q,int k)
{
int m,i;
m=breaking(a,p,q);
 if(m==k)
   return(m);
 else if(m>k)
 {
   m=median_of_medians(a,p,m-1,k);
   return(m);
 }
 else 
 {
   m=median_of_medians(a,m+1,q,k);
   return(m);
 }

}

int breaking(int *a,int p,int q)
{

int i,j,z,piv;
i=p-1;
piv=a[q];
for(j=p;j<q;j++)
{

   if(a[j]<=piv)
   {
      i++;
      swap(&a[i],&a[j]);
   }   
}
swap(&a[i+1],&a[q]);

return(i+1);
}


void swap(int *a,int *b)
{
 int temp;
 temp=*a;
 *a=*b;
 *b=temp;

}
void quicksort(int *a,int p,int q)
{
int m;
if(p<q)
{
 m=median_of_medians(a,p,q,(p+q)/2);
 quicksort(a,p,m-1);
 quicksort(a,m+1,q);

}
}

void main()
{

int n,p,q,i,a[1000],r,s,t;

scanf("%d",&n);

for(i=0;i<n;i++)
  scanf("%d",&a[i]);
r=(n-1)/2;
s=(n-r-2)/2;
s=r+((n-r)/2);
printf("%d\n",a[median_of_medians(a,0,n-1,r)]);
printf("%d\n",a[median_of_medians(a,0,r-1,(r-1)/2)]);
printf("%d\n",a[median_of_medians(a,r+1,n-1,s)]);
quicksort(a,0,n-1);

for(i=0;i<n;i++)
  printf("%d ",a[i]);

}



