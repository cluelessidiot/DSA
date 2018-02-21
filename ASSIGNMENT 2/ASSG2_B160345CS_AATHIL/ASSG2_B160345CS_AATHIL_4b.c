#include<stdio.h>
#include<stdlib.h>
void mod_binary_search(int *,int,int,int);
void main()
{
int m,n,i,j;
scanf("%d",&n);
int *a;
 a=(int*)malloc(n*sizeof(int)); 
if(a==NULL)
   exit(0);
for(i=0;i<n;i++)
{
   scanf("%d",&a[i]);
}
/*for(i=0;i<n;i++)
{
   printf("%d  ",a[i]);
}
*/
int k,f,l;

scanf("%d",&k);
m=0;
mod_binary_search(a,0,n-1,k);
printf("-1");
}



void mod_binary_search(int *a, int f, int l, int k)
{
	int mid = (f+l)/2;
	if(f<=l)
	{
		if(a[mid]==k)
		{
			printf("%d",mid);
			exit(0);
		}
		else if (a[mid]>a[f] && a[mid]<a[l])
		{
			if(k<a[mid])
				mod_binary_search(a, f, mid-1, k);
			else
				mod_binary_search(a, mid+1, l, k);
		}
		else if (a[mid]>a[f])
		{
			if(k>=a[f])
				mod_binary_search(a, f, mid-1, k);
			else
				mod_binary_search(a, mid+1, l, k);
		}
		else if (a[mid]<a[l])
		{
			if(k<=a[l])
				mod_binary_search(a, mid+1, l, k);
			else
		 	 	 mod_binary_search(a, f, mid-1, k);
		}
	}
}

