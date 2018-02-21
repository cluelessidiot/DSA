#include <stdio.h>
#include<stdlib.h>
#define ll long long int
#define snode struct node
snode* createnode(ll);
void insert_front();
void insert_last();
void printnode();
void delete(ll dval);
snode
{
ll data;
snode* next;
};
snode *str,*ptrt;
snode *newnode,*ptr,*prev,*temp;
snode *first=NULL,*last=NULL ;
void reverse();
ll k;
void main()
{
  
  //printf("%lld",newnode->data);


ll q,n;
char c;
 c=' ';
while (c==' ')
 {
  
   insert_last();
    c=getchar(); 
 }

reverse();



printnode();

}

snode* createnode(ll val)
{

  newnode=(snode*)malloc(sizeof(snode));
  if(newnode==NULL)
         printf("MEmemory wasnt allocated");
  else
   {
     newnode->data=val;
     newnode->next=NULL;
      return newnode;
   }
 
}
void insert_front()
{ 
   ll p;
   scanf("%lld",&p);
  newnode=createnode(p);
  if(first==NULL)
  {
      first=newnode;
      first->next=NULL;
  
  }
  else
 {
     temp=first;
     first=newnode;
     first->next=temp;
  } 


}
void insert_last()
{ 
   ll p;
   scanf("%lld",&p);
   
  newnode=createnode(p);
  if(first==NULL)
  {
      first=newnode;
       first->next=NULL;
         return;
  }
  temp=first;
 while(temp->next!=NULL)
       temp=temp->next;
 

    temp->next=newnode;
    newnode->next=NULL;
 }
void printnode()
{   
    temp=first;
     while(temp!=NULL) 
  {    
        printf("%lld ",temp->data);
         temp=temp->next;
     
 }                                  
}

void insert_middle()
{ 
   ll p;
   scanf("%lld",&p);
  newnode=createnode(p);
  if(first==NULL)
  {
      first=newnode;
       first->next=NULL;
         return;
  }
  temp=first;
 while(temp->next!=NULL)
       temp=temp->next;
  

    temp->next=newnode;
    newnode->next=NULL;
 }
void delete(ll dval)
{
  temp=first;
  if(first->data==dval)
   {
      first=first->next;
      return;
   }
  while(temp!=NULL)
   {
      if(((temp->next)->data)==dval)
        {
             temp->next=(temp->next)->next; 
                return;             
       }  
         temp=temp->next;  
   }   
} 
 void reverse()
{    
  if(first==NULL||first->next==NULL)
      return;
  else
     {   //printf("\nfirst %lld\n",first->data); 
        ptr=first->next;
        first->next=NULL;
      while(ptr->next!=NULL)
          {  //printf("%lld\n",ptr->data);
              ptrt=ptr->next;
              ptr->next=first;  
               first=ptr;
                ptr=ptrt;
            
 
 	  }
       ptr->next=first;
         first=ptr;
      
    }

}
