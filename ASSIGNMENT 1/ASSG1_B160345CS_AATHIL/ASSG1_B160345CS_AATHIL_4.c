#include<stdio.h>
#include<stdlib.h>

struct ratio
{
int x;
int y;

}n1,n2,n3;
int gcd (int,int);
void red(struct ratio );
void disp(struct ratio);
void main()
{
int r;
//printf("1. Print a/b form \n2. Sum of Rational numbers \n3. Product of Rational numbers \n4. Sort in ascending order \n5. Print in Simplest form \n");
scanf("%d",&r);
switch(r)
{
case 1:
//printf("Enter a and b: \n");
scanf("%d%d",&n1.x,&n1.y);
red(n1);


break;
case 2:
//printf("Enter a and b: \n");
scanf("%d%d",&n1.x,&n1.y);
//printf("Enter c and d: \n");
scanf("%d%d",&n2.x,&n2.y);
n3.x=((n1.x*n2.y)+(n2.x*n1.y));
n3.y=n1.y*n2.y;
red(n3);
break;
case 3:
//printf("Enter a and b: \n");
scanf("%d%d",&n1.x,&n1.y);
//printf("Enter c and d: \n");
scanf("%d%d",&n2.x,&n2.y);
n3.x=n1.x*n2.x;
n3.y=n1.y*n2.y;
red(n3);
break;
case 4:
{
//printf("\nNumber of rational numbers to be sorted:\n ");
int z;
scanf("%d",&z);
//struct ratio *n;
struct ratio *n=malloc(z*sizeof(struct ratio));
if(n==NULL)
  exit(0);

int i,temp;
for(i=0;i<z;i++)
   {
     //printf("Enter in the form a b:\n");
     scanf("%d%d",&n[i].x,&n[i].y);
     if(n[i].y<0)
       { n[i].y=-n[i].y;
        n[i].x=-n[i].x;}

   }
   for(i=1;i<z;i++)
   { // struct ratio temp=n[i];
    // printf("Enter in the form a b:\n");
    for(int j=i-1;j>=0;j--)
      {
          if((n[j+1].x*n[j].y)<(n[j].x*n[j+1].y))
            {
                  temp=n[j+1].x;
                   n[j+1].x=n[j].x;
                    n[j].x=temp;
                     temp=n[j+1].y;
                   n[j+1].y=n[j].y;
                    n[j].y=temp;
            }
      }
    }
for(i=0;i<z;i++)
  {
    disp(n[i]);
  }
break;
}
case 5:
//printf("Enter a and b: \n");
scanf("%d%d",&n1.x,&n1.y);
red(n1);
break;
}
}
void red(struct ratio n1)
{int k=gcd(n1.x,n1.y);
n1.x=n1.x/k;
n1.y=n1.y/k;
if(n1.y<0)
{     n1.y=-n1.y;
     n1.x=-n1.x;}
disp(n1);
}

int gcd (int a,int b)
{
  if(a==0)
   return b;
  else
    gcd(b%a,a);

}

void disp(struct ratio n1)
  {
    printf("%d/%d ",n1.x,n1.y);

  }
