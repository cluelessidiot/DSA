
#include <stdio.h>
#include <stdlib.h>
//nodem* search(nodem* h,int val);
struct node{
	int data;
	struct node* next;
};
#define ll long long int
#define nodem struct node

nodem* search(nodem* h,int val);
nodem* intnode(int a){
	nodem* new;
	new=(nodem*)malloc(sizeof(nodem));
	new->data=a;
	new->next=NULL;
	return new;
}
ll swap(nodem* head1,nodem* head2);
nodem* insert(nodem* head,nodem* nd){
	nodem *temp;
	temp=head;
	if(head==NULL){
		head=nd;
		return head;
	}
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=nd;
	return head;
}

nodem* search(nodem* h,int val){
	//nodem *t=h;
	while(h!=NULL && h->data!=val)
		h=h->next;
	return h;
}

int sumlist(nodem *head1,nodem *head2){
	int a;	
	if(head1->next==NULL && head2->next==NULL){
	     a=head1->data+10-head2->data;
	     head1->data=a%10;
		  return a/10;
	}
	int c=sumlist(head1->next,head2->next);
	a=c+head1->data+9-head2->data;
	head1->data=a%10;
	return a/10;
}

void print_list(nodem *head){
	nodem* temp;
	temp=head;
         ll flag=0;
	while(temp!=NULL){
             if(temp->data>=1)
               flag=1;
	  if(flag==1)	
             printf("%d",temp->data);
		temp=temp->next;
	}
      if(flag==0)
             printf("0");
	printf("\n");
}

int main(){
	int i,b;
	char a;
	ll n;
	char ch;
	nodem* temp,*head1,*head2;
	head1=NULL;
	head2=NULL;
	
	a=getchar();
	while(a!='\n'){
		
		temp=intnode(atoi(&a));
		if(temp==NULL){
	 	  printf("node cannot be created\n");
		  return 0;
		}
		head1=insert(head1,temp);
                a=getchar();
	}

	    a=getchar();
	  while(a!='\n'){
		   
		temp=intnode(atoi(&a));
		if(temp==NULL){
	 	  printf("node cannot be created\n");
		  return 0;
		}
          		head2=insert(head2,temp);
                        a=getchar();
  	}
        ll q;
         q=swap(head1,head2);
 //        printf("as%lld",q);
      if(q==1) 
	{i=sumlist(head1,head2);
          print_list(head1);
}
if(q==-1) 
       {	i=sumlist(head2,head1);
         print_list(head2);}
	//if(i==1){
	//	temp=intnode(1);
	//	temp->next=head1;
	//	head1=temp;
	//}
	//print_list(head1);
}
ll swap(nodem* head1,nodem* head2)
{    nodem *head11,*head22;
     head11=head1;
     head22=head2;
    while(head11->data==head22->data)
       {
              head11=head11->next;
	      head22=head22->next; 
       }

    if(head11->data<head22->data)
       {

          return -1;




      }
   return 1;

}
