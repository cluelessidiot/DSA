#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ll long long int

ll maxsize=10000;
struct p_d{
	ll e;
	ll pt;
        ll val1;
};

#define node struct p_d
struct priority_que{
	node * que;
	ll size;
        ll val;
};

#define pque struct priority_que
node* extract_min(pque*);
ll search(pque *pq,ll ele,ll newpr);
void swap(node *ar1,node *ar2);
void heapify(pque *pq,ll i);
void insert(pque *pq,ll ele,ll pr);
ll search_priority(pque *pq,ll pr);
//inserting element
/*
void min_Heapify(PQ *pq,long long int i)
{
    long long int large=i;
    if ((pq[i].priority>pq[leftchild(i)].priority)&&(leftchild(i)<heap_size))
        large=leftchild(i);
    if ((pq[large].priority>pq[rightchild(i)].priority)&&(rightchild(i)<heap_size))
        large=rightchild(i);
    if(large!=i)
    {
        PQ temp;
        temp=pq[large];
        pq[large]=pq[i];
        pq[i]=temp;
        min_Heapify(pq,large);
    }
}
*/
void insert(pque *pq,ll ele,ll pr){
	if(pq->size>=maxsize){
	  maxsize+=100;
	  pq->que=(node *)realloc(pq->que,maxsize*sizeof(node));
	}
	if(pq->size==0){
	   pq->que[1].e=ele;
	   pq->que[1].pt=pr;
	   pq->size++;
	   return;
	}
	pq->size++;
	ll i=pq->size;
	pq->que[pq->size].e=ele;
	pq->que[pq->size].pt=pr;
	while(i>1 && pq->que[i/2].pt>pq->que[i].pt){
		swap(&pq->que[i/2],&pq->que[i]);
		i=i/2;
	}
	return;
}
void printque(pque *pq){
	ll i=1;
	if(pq->size==0){
	  printf("EMPTY\n");
	  return;
	}
	while(i<=pq->size){
		printf("%lld ",pq->que[i].e);
		i++;
	}
	printf("\n");
	return;
}




void heapify(pque *pq,ll i){
	ll min=i;
	if(2*i<=pq->size){
	  if(pq->que[2*i].pt<pq->que[i].pt)
	    min=2*i;
	 

 
         if(2*i+1<=pq->size){
		if(pq->que[2*i+1].pt<pq->que[min].pt)
		  min=2*i+1;
	   }
	
      if(min!=i){
		swap(&pq->que[i],&pq->que[min]);
		heapify(pq,min);
	   }
	}
}

ll search(pque *pq,ll ele,ll newpr){
	if(pq->size==0)
	  return -1;
	ll i=0;
	for(i=1;i<=pq->size;i++)
            if(pq->que[i].e==ele && pq->que[i].pt>=newpr)
	  return i;
	return -1;
}
//searching a given priority in priority que,if found return 1or else -1
ll search_priority(pque *pq,ll pr){
	if(pq->size==0)
	  return -1;
	ll i=0;
	for(i=1;i<=pq->size;i++)
	if(pq->que[i].pt==pr)
	  return 1;
	return -1;
}
//initialize a priority que and initialize node from pque

void swap(node *ar1,node *ar2){
	node temp;
	temp=*ar1;
	*ar1=*ar2;
	*ar2=temp;
}
pque* intpque(){
         //for(ll q=0;q<10;q++)
          //  {   /* printf("int");*/}
	pque * temp;
	temp=(pque *)malloc(sizeof(pque));
	temp->que=(node *)malloc(maxsize*sizeof(node));
	temp->size=0;
	return temp;
}

node* get_min(pque* pq){
	if(pq->size==0)
	  return NULL;
	return &pq->que[1];
}

//decrease priority of a given element
void decrease_priority(pque *pq, ll elem, ll newpr){
	ll pos;
	pos=search(pq,elem,newpr);
	if(pos==-1){
	   printf("INVALID INPUT\n");
	   return;
	}
	if(pq->que[pos].pt<=newpr){
	   printf("INVALID INPUT\n");
	   return;
	}
	pq->que[pos].pt=newpr;

  
    for(;pos>1 && pq->que[pos/2].pt>pq->que[pos].pt;){                                                     
	   swap(&pq->que[pos/2],&pq->que[pos]);
	   pos/=2;
	}
	return;
}

ll main(){
	ll c,d;
	ll a,b;
	pque* pq;
	pq=intpque();
	char ch;
	
	scanf("%c",&ch);
	
	for(;ch!='s';){
	 
	    if(ch=='a') {
	       scanf("%lld%lld",&c,&d);
	         a=c;
                 b=d;
		if(search_priority(pq,b)==-1)
	       insert(pq,a,b);
		else{
		    printf("INVALID INPUT\n");
		    return 0;
		}
	    }
	    else if(ch=='e'){
	    	node *temp;
		temp=extract_min(pq);
		if(temp==NULL)
		printf("EMPTY\n");
		else
		printf("%lld (%lld)\n",temp->e,temp->pt);
	    }
	    else if(ch=='g'){
	    	node *temp;
		temp=get_min(pq);
		if(temp==NULL)
		printf("EMPTY\n");
		else
		printf("%lld (%lld)\n",temp->e,temp->pt);
	    }
	    else if(ch=='d'){
	         scanf("%lld%lld",&c,&d);            
		a=c;
                b=d;
		if(search_priority(pq,b)==-1)
	       decrease_priority(pq,a,b);
		else{
		    printf("INVALID INPUT\n");
		    return 0;
		}
	    }
	    else if(ch!='s'){
	      printf("INVALID INPUT\n");
	      return 0;
	    }
	      scanf("%c",&ch);
	      scanf("%c",&ch);
	}
return 0;
}

node* extract_min(pque * pq){
	if(pq->size==0)
	  return NULL;
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->e=pq->que[1].e;
	temp->pt=pq->que[1].pt;
	pq->que[1]=pq->que[pq->size];
         ll k=pq->size;
         // printf("size %lld",k);
	pq->size--;
	heapify(pq,1);
	return temp;
}




