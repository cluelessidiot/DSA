#include<stdio.h>
void main()
{
FILE *f,*g;
int flag;
g=fopen("out.txt","w");
if(g==NULL)
   {
    printf("\nfile allocation failed\n");
	return;
   }
f=fopen("in.txt","r");
if(f==NULL)
   {
    printf("\nfile allocation failed\n");
	return;
   }
char ch;
while((ch=getc(f))!=EOF)
{  if((ch==' '&& flag==1)||(ch=='\t'&& flag==1))
      flag=1;
   else
     { if(ch==' ')
       {
          flag=1;
           //if(ch=='\t')
               
           putc(ch,g);
          
       }
     else if(ch=='\t')
        {
         flag=1;
         putc(' ',g);


       }

      else
        {
          putc(ch,g);
           flag=0;

        }
      }

}
fclose(f);
fclose(g);
}
