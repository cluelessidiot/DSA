#include<stdio.h>
#include<stdlib.h>
int arsrch(int *a[],int,int,int);
void main()
{
int m,n,i,j,k;
scanf("%d%d",&n,&m);
int *a[n];
    for (i=0; i<n; i++)
         a[i] = (int *)malloc(m * sizeof(int));

for(i=0;i<n;i++)
{
 for(j=0;j<m;j++)
	{
	  scanf("%d",&a[i][j]);
	}
}

/*for(i=0;i<n;i++)
{
 for(j=0;j<m;j++)
	{
	  printf("%d  ",a[i][j]);
 	}


printf("\n");
}
*/
scanf("%d",&k);
int q=arsrch(a,n,m,k);
printf("%d",q);

}

int arsrch(int *a[],int n,int m,int k)
{  int j=m-1;
   int i=0;
     int g=0;
while(i<=n-1 && j>-1)
  {
    if(a[i][j]==k)
	{
         return 1;
        }

    if(a[i][j]<k)
        i++;
    if(a[i][j]>k)
          j--;       
    
   g++;
 }
return -1;
}

