#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 void decrypt(char str[],int n,int k);
void encrypt(char str[],int n,int k);
void main()
{
int n,k,l,i;
int choice;
//printf("1.ENCRYPTION.\n2.DECRYPTION.");
//printf("\nENTER YOUR CHOICES:");
scanf("%d",&choice);




if(choice==1)
{
  //printf("\nEnter String length:");
  scanf("%d",&n);

// printf("\nEnter String: ");
 // char str[n];
//scanf("%[^\t\n]s",&str);
char *str;
 str=(char*)malloc(n*sizeof(char)); 
if(str==NULL)
   exit(0);
 scanf(" %[^\t\n]s",str);
  
//printf("\nEnter K:");
   scanf("%d",&k);
    k=k%26;
encrypt(str,n,k);

}
else
{
  if(choice==2)
 {  
   
// printf("\nEnter String length:");
 scanf("%d",&n);
// printf("\nEnter String: ");
// char str[n];
char *str;
 str=(char*)malloc(n*sizeof(char)); 
if(str==NULL)
   exit(0);
 scanf(" %[^\t\n]s",str);
//printf("\nEnter K:");
 scanf("%d",&k);
 k=k%26;
 decrypt(str,n,k);
 }

else
  return;
}}  
void encrypt(char *str,int n,int k)
{
for(int i=0;i<=n;i++)
   { int x=str[i];
     if(x>='a' && x<='z')
         { x=x+k;
           if(x>'z')
             x=x-'z'+'a'-1;
           str[i]=x;
          printf("%c",str[i]);



         }

     else
         {  if(x>='A' && x<='Z')
                { x=x+k;
                  if(x>'Z')
                    x=x-'Z'+'A'-1;
                  str[i]=x;
                 printf("%c",str[i]);
                }
            else
               printf("%c",str[i]);
         }

    }
}
void decrypt(char *str,int n,int k)
{
  for(int i=0;i<=n;i++)
  { int x=str[i];
  if(x>='a' && x<='z')
  { x=x-k;

  if(x<'a')

  x='z'-'a'+x+1;
  str[i]=x;

  printf("%c",str[i]);
  }
  else
  {  if(x>='A' && x<='Z')
  { x=x-k;
  if(x<'A')
  x='Z'-'A'+x+2;
  str[i]=x;
  printf("%c",str[i]);

  }
  else
  printf("%c",str[i]);
  }
}}
 



