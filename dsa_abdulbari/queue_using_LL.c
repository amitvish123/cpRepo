#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front= NULL,*rear=NULL;

void enqueue(int x){//inserting ar rear end
    struct Node *p= (struct Node*)malloc(sizeof(struct Node));
    if(p== NULL){
        printf("Queue is full");
    }else{
       
        p->data= x;
        p->next= NULL;
        if(front== NULL){
            front= rear= p;
        }else{
            rear->next= p;
            rear=p;
        }
    }
}
int dequeue(){//deleting from front end
    int x= -1;
    if(front== NULL){//if front if null or rear is null , then queue is
    //empty
        printf("Queue is empty");
    }
    else{
        struct Node *p;
        p= front;//storing the element to be deleted first before deletion
        front= front->next;
        x= p->data;
        free(p);
    }
    return x;
}
int isempty(){
    if(front== NULL){//we can replace it with rear == null
        printf("Queue is empty");
    }
}
int main(){
    int A[5]= {1,2,3,4,5};
    for(int i=0;i<5;i++){
        enqueue(A[i]);
    }
    int x=dequeue();
    printf("%d\n",x);
    enqueue(7);
    struct Node *p;
    p= front;
    while(p!= NULL){
        printf("%d\n",p->data);
        p= p->next;
    }
}