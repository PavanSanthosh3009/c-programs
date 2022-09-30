#include<stdio.h>
#include<stdlib.h>
typedef struct que_dyn
{
  int key;
}element;

element *queue, *nqueue;
int front = 0, rear=0, capacity = 2;

int isFull(){

   if( ((rear+1)%capacity) == front )
       return 1;
   else
       return 0;
}

int isEmpty(){

    if( rear == front )
       return 1;
    else
       return 0;
}

void copy(element *st, element *end, element *qu)
{
  int it;
  int sz = end - st;
  element *itr;
  itr = st;

  for(it=0 ; it<sz ; it++){
      *(qu+it) = *(itr);
       itr++;
  }
}


void queueFull(){

  int start;
  nqueue = (element*)malloc(2*capacity*sizeof(element));
  start = (front+1)%capacity;

  if( start < 2)
     copy(queue+start, queue+capacity, nqueue);
  else
  {
     copy(queue+start, queue+capacity, nqueue);
     copy(queue, queue+rear+1,  nqueue+capacity-start);
  }

  front = 2*capacity-1;
  rear = capacity - 2;
  capacity = capacity*2;
  free(queue);
  queue = nqueue;
}

void insert(element e){

  if( isFull() ){
      printf("\nDoubling the queue size from %d to %d", capacity, 2*capacity);
      queueFull();
   }
  rear = (rear + 1)%capacity;
  *(queue+rear) = e;
   printf("\n the item inserted is %d", e.key);
}

int delete_(){

   int k;
   if( isEmpty() )
       printf("\n Queue is Empty....");
   else
      {
        front = (front+1)%capacity;
        k = (queue + front)->key;
        printf("\nThe item deleted is %d", k);
        return k;
   }
}

int main(){

   int i, k;
   queue = (element*)malloc(capacity*sizeof(element));

   for( i=0 ; i<10 ; i++ ){
        element e;
        e.key = i;
        insert(e);
   }

   for( i=0 ; i<12 ; i++)
       k = delete_();

}





     

   


