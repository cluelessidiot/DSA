#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ll long long int
#define snode struct stack_node
ll final;
snode* create_node();
ll power_calc(ll,ll);
void evaluator(char*);
void inf_prt(char*);
snode
{
 ll data;
 snode *next;

}*front,*rear,*temp,*han;
ll power_cal(ll n1,ll n2)
{ ll i,res=1;

  for(i=0;i<n2;i++)
    { res=res*n1;
     
    }
 return res;
}
snode* create_node()
{
    temp=(snode*)malloc(sizeof(snode));
     if(temp==NULL)
         printf("Memmory not allocated");
           
    else
        return temp;  

}



void main()
{
  ll i,j,x,flag;
  char str[100000];
scanf("%[^\n]string",str);
 // for(i=0;str[i]!='\0';i++)
   // printf("%c",str[i]);

    evaluator(str);
       inf_prt(str);

   printf("\n%lld",final);
}
void inf_prt(char* string)
{
ll i;
ll j;
ll flag=0;
char key_char;
 while(string[i]!='\0')                                                                          /*   for(ll i=0;string[i]!='\0';)*/
   {      
      if(string[i]>='0' && string[i]<='9'|| string[i]==' ')
          {i++;
           continue;
          }
     else 
           {
               key_char=string[i];
                      for(j=i-1;j>=0;j--)
                          {
                            if(string[j]>='0' && string[j]<='9')
                                 flag=1;
                            else if (string[j]==' '&&flag==1)
                               {  string[j]=key_char;
                                 break;
                               }
                         }
                      for(j=i;string[j]!='\0';j++)
                        {
                             string[j]=string[j+1];
                        }
                     for(j=i;string[j]!='\0';j++)
                        {
                             string[j]=string[j+1];
                        }

          flag=0;
          }
       
   }
printf("%s",string);
}


void evaluator(char* str)
{  ll i,num_ct,y,x,num_sum=0;
   ll num1,num2;
    ll flag=0;
for(i=0;str[i]!='\0';i++)
        {   
              if(str[i]>='0' && str[i]<='9')
                 {       flag=1;
                          num_ct++;
                           ll k=str[i];
                          num_sum=num_sum*10+(k-48);
                           //printf("\n%lld",k);                         
                 }
             else if(str[i]==' ')
                {
                    if(flag==1)
                         {   flag=0;
                                       //adding to the stacks
                                
                                   if(front==NULL)
                                    {        front=create_node();
                                             front->data=num_sum;
                                             front->next=NULL;

                                    } 
                                   else
                                    {
                                       han=front;
                                       front=create_node();
                                       front->data=num_sum;
                                       front->next=han;	
                                    }

                                 num_sum=0;
                         }
 
               } 
        else
           {    
                num2=front->data;
                front=front->next;
                num1=front->data;
                 front=front->next;

                if(str[i]=='+')
                 {  num1=num1+num2;    
                        }
              else if(str[i]=='-')
                 {  num1=num1-num2;      }
              else if(str[i]=='*')
                 {  num1=num1*num2;      }
              else if(str[i]=='/')
                  {  num1=num1/num2;      }
                else if(str[i]=='^')
                  {  num1=power_cal(num1,num2);      }
          
                                 if(front==NULL)
                                    {        front=create_node();
                                             front->data=num1;
                                             front->next=NULL;

                                    } 
                                   else
                                    {
                                       han=front;
                                       front=create_node();
                                       front->data=num1;
                                       front->next=han;
                                    }


           }
       
        }

  final=front->data;
  //printf("%lld",num1);
  front=front->next;





}
