#include<stdio.h>
#include<stdlib.h>
void merge(long int *a,int f,int m1,int m2,int l);
void mergesort(long int* a,int f,int l);
void main()
{
int m,j;
int long n;
//scanf("%ld",&n);

FILE *read_ptr=fopen("in","rb"),*write_ptr=fopen("out","wb");
	long int i=0,k;
	long int *a=malloc(sizeof(long int));
fread(&k,sizeof(int),1,read_ptr);
	while(!feof(read_ptr))
   	{
	   a=realloc(a,(i+1)*sizeof(long int));
	   a[i]=k;
	   i++;    
     fread(&k,sizeof(int),1,read_ptr);
	}
     n=i;



    


/*for(i=0;i<n;i++)
{
   scanf("%d",&a[i]);
}
*/
mergesort(a,0,n-1);
for(i=0;i<n;i++)
{
   printf("%ld ",a[i]);
}
	for(i=0;i<n;i++)
       {  int x;
          x=a[i];
          fwrite(&x,sizeof(int),1,write_ptr);
	}
       fclose(read_ptr);
	fclose(write_ptr);
 

}

void mergesort(long int* a,int f,int l)
 {       
 if(f<l)
	{ 
	 int m1=f+((l-f)/3);
         int m2=(2*m1)-f; 
	    //printf(" %d %d %d  %d \n",f,l,m1,m2);
          mergesort(a,f,m1);
	  mergesort(a,m1+1,m2);
	  mergesort(a,m2+1,l);
           merge(a,f,m1,m2,l);	
      //printf("mrege   %d  %d \n",f,l);
	}
}	


 void merge(long int *a,int f,int m1,int m2,int l)
{ 

if(f<l)
{
    
	int n1=m1-f+1;
	int n2=m2-m1;
	int n3=l-m2;
        int i,j,k;
        int l1[n1];
	int r1[n2];
	int t1[n3];

  for(i=0;i<n1;i++)
   {
      l1[i]=a[f+i];
   }
  for(j=0;j<n2;j++)
   {
      r1[j]=a[f+n1+j];
   }
  for(k=0;k<n3;k++)
   {
      t1[k]=a[f+n1+n2+k];
   }
i=0;j=0;k=0;
int g;
g=f; 
while(i<n1 &&j<n2 && k<n3)
 {
    if((l1[i]<=r1[j] && l1[i]<=t1[k]) || (l1[i]<=r1[j] && t1[k]>=r1[j]))
        {
	  a[g]=l1[i];         
	 g++;
          i++;
         
   	}
     
     if((r1[j]<=l1[i] && r1[j]<=t1[k])|| (r1[j]<=t1[k] && t1[k]<=l1[i]))
        {
	  a[g]=r1[j];
          g++;
          j++;
   	}
    if ((t1[k]<=r1[j] && t1[k]<=l1[i])||(t1[k]<=l1[i] && l1[i]<=r1[j] ))
        {
	  a[g]=t1[k];
          g++;
          k++;
   	}     
/*   if(i<n1 && j==n2 && k==n3)
       {
          a[g]=l1[i];
printf("\n  l[i]    a[%d]  %d   ",g,a[g]);
           g++;
           i++;
       }
   if(j<n2 && i==n1  && k==n3)
       {
          a[g]=r1[j];
printf("\nr[i]    a[%d]  %d   ",g,a[g]);
           g++;
           j++;
       }  
   if(k<n3 && j==n2 && i==n1)
       {
          a[g]=t1[k];
printf("\nt[i]   sa[%d]  %d   ",g,a[g]);
           g++;
           k++;
       }*/
}
while(i<n1 && j<n2)
{
  if(l1[i]<=r1[j])
      {
        a[g]=l1[i];
          i++;
           g++;

      }
 else
   {
       a[g]=r1[j];
         j++;
	 g++;
   }
}
while(i<n1 && k<n3)
{
  if(l1[i]<=t1[k])
      {
        a[g]=l1[i];
          i++;
           g++;

      }
 else
   {
       a[g]=t1[k];
         k++;
	 g++;
   }
}
while(k<n3 && j<n2)
{
  if(t1[k]<=r1[j])
      {
        a[g]=t1[k];
          k++;
           g++;

      }
 else
   {
       a[g]=r1[j];
         j++;
	 g++;		
   }
}
while(i<n1)
{
a[g]=l1[i];
  g++;
i++;
}
while(j<n2)
{
a[g]=r1[j];
  g++;
j++;
}while(k<n3)
{
a[g]=t1[k];
  g++;
k++;
}
}
}

