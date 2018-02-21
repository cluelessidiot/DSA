#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse1(char ar[] ,int l ,int k);
void main()
{
  int num=1;
  char *s;
  s=(char*)malloc(num*sizeof(char));
  if(s==NULL)
    exit(0);
char ch;
int i=0;
while((ch=getchar())!='\n')
     {
        if(i>=num)
         {
             num=num+1;
             s=(char*)realloc(s,num);
             if(s==NULL)
                exit(0);
           // printf("allocated\n");
         }


//printf("%u\t",&c[i]);


        s[i]=ch;
        i++;
       

    }
  s[i]='\0';
  //printf("%d\n",n);
  reverse1(s,(i-1-(i%2))/2,i-1);
  puts(s);

}

 void reverse1(char *ar,int l,int k)
 { if(k==0)
       return;
 

   if(l>=0)
   {
    ar[l]=ar[l]+ar[k-l];
    ar[k-l]=ar[l]-ar[k-l];
    ar[l]=ar[l]-ar[k-l];
    reverse1(ar,l-1,k);

   }
  } 
