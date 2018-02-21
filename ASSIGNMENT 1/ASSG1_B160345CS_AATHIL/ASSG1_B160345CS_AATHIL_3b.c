#include<stdio.h>
#include<stdlib.h>
void swap(int *p,int *q);
void spiral(int *a[],int);
//void reverse1(char* ,int ,int );
void main()

{ int j,i;
int n;
//printf("input numbers");
scanf("%d",&n);
 int *a[n];
    for (i=0; i<n; i++)
         a[i] = (int *)malloc(n * sizeof(int));
if(a==NULL)
   exit(0);


void transpose(int *a[],int,int);
for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
        {
         scanf("%d",&a[i][j]);
//           printf("%d  ",a[i][j]);
        }
  }
transpose(a,0,n);
spiral(a,n);

}
void transpose(int *a[],int i,int n)
{  if(i<n)
  {  int q=0;
    for(q=i+1;q<n;q++)
    {
     if(q!=i)
     swap (&a[i][q],&a[q][i]);
      

   }

 transpose(a,i+1,n);
 }


}

void swap(int *p,int*q)
{
int temp=*p;
*p=*q;
*q=temp;


}
void spiral(int *arr[],int n)
{
    int x,y,z;
    for(x=n-1, y=0; x>y; x--, y++)
    {

        for(z=y; z<x; z++)
              printf("%d ", arr[y][z]);
        for(z=y; z<x; z++)
              printf("%d ", arr[z][x]);
        for(z=x; z>y; z--)
              printf("%d ", arr[x][z]);
        for(z=x; z>y; z--)
              printf("%d ", arr[z][y]);

    }
     int mid = (n-1)/2;
     if (n% 2 == 1) printf("%d", arr[mid][mid]);
}
