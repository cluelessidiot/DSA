#include<stdio.h>
#include<stdlib.h>
#define ll long long int
void main()
{

ll front=0,rear=0,x,n;
scanf("%lld",&n);
ll k=3*n;
x=n;
ll  ar[k];
char opt;
  getchar();
opt=getchar();
while(opt)
{ 
 switch(opt)
  {
     case 'e':
      // printf("emnqueue\n");
    if(x==rear) 
         printf("-2\n");   
    else
         scanf("%lld",&ar[rear++]);


  
       break;
     case 'd':
       //printf("queue\n");
       if(front==rear)
           printf("-1\n");
       else
          { printf("%lld\n",ar[front]);
            front++;
           x++;
           }
       break;
     case 'p':
//       printf(" print queue");
         for(ll i=front;i<rear;i++)
             printf("%lld ",ar[i]);
          printf("\n");
       break;
     case 's':
       exit(0);

  } 
opt=getchar();
}







}
