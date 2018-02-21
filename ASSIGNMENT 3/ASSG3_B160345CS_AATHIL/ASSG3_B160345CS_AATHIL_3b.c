#include<stdio.h>
#include<stdlib.h>
#define ll long long int
#define que struct queue 
ll n;
que
{
  ll data;
  que* next;
}*temp,*first,*rear;
ll data;
que* createque()
{
 temp=(que*)malloc(sizeof(que));
  scanf("%lld",&n);
  temp->data=n;
   temp->next=NULL;
 return temp;

}
void enqueue()
 {
   temp=createque();
   if(first==NULL && rear==NULL)
     {   first=temp;
         rear=temp; 
     //printf("str");
     }
   else
     { //  printf("else");
        rear->next=temp;
        rear=temp;

     }
 }
void display()
{
   if(first==NULL && rear==NULL)
        printf("nothing to display\n");
   temp=first;

   while(temp!=NULL)
     {
       printf("%lld ",temp->data);
       temp=temp->next;
    }
 printf("\n");


}
void dequeue()
{
   if(first==NULL)
      printf("-1\n");
   else
{  if(first->next==NULL)
       rear=NULL;
  temp=first->next;
   printf("%lld\n",first->data);
  first=NULL;
  first=temp;

}




}
void main()
{


char opt;
opt=getchar();
while(opt)
{ 
 switch(opt)
  {
     case 'e':
       //printf("enqueue\n");
         enqueue();
  
       break;
     case 'd':
       //printf("queue\n");
        dequeue();
       break;
     case 'p':
    //   printf(" print queue");
       display(); 
       break; 
   case 's':
       exit(0);

  } 
opt=getchar();
}







}
