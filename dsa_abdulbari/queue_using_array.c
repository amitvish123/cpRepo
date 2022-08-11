
#include <bits/stdc++.h>
using namespace std;




struct Queue{
    int size;
    int front;
    int rear;
    int *q;
};
void create(struct Queue *Q,int n){
    Q->size=n;
    Q->front=0;
    Q->rear=0;
    Q->q= (int *)malloc(size*sizeof(int));
}
void enqueue(struct Queue *Q,int key){
    if((Q->rear+1)%Q->size == Q->front){
        printf("Queue is full");
    }else{
        Q->q[(Q->rear+1)%Q->size]= key;//inserting the element at the position 
        //just after the rear element.. if rear is the last elemtent of the queue
        //then the element is inserted at the first position in the queue.
    }
}
int dequeue(struct Queue *Q){
    int x=-1;
    if(Q->front== Q->rear){
        printf("Queue is empty");
    }else{
        
        x= Q->q[(Q->front+1)%Q->size];
    }
    return x;
}
void display(){
    
}
int main(){
    struct Queue q;
    create(&q, 5);
    int arr[]= {1,2,3,4,5};
    for(int i=0;i<5;i++){
        enqueue(&q, arr[i]);
    }
    dequeue(&q);
}