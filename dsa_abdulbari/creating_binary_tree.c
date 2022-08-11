// tree is a non linear data structure which can be implemented using physical data
// structure linke array and linked list
// here we creeate a binary tree using linked data strcture
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
struct Node *root=NULL;

void Treecreate(){
    struct Node *t,*p;//creating a temporary pointer
    struct Queue q;
    int x;
    create(&q,100);
    printf("Enter value of root node");
    scanf("%d", &x);
    root= (struct Node*)malloc(sizeof(struct Node));
    root->data= x;
    root->lChild= root->rChild=NULL;
    
    enqueue(&q,root);
    while(!isEmpty(q)){
        p= dequeue(&q);
        
        printf("Enter value of lchild:");
        scanf("%d", &x);
        if(x!= -1){
        t= (struct Node*)malloc(sizeof(struct Node));
        t->data= x;
        t->lChild= t->rChild=NULL;
        p->lChild=t;
        enqueue(&q,t);}

        printf("Enter value of rchild:");
        scanf("%d", &x);
        if(x!= -1){
        t= (struct Node*)malloc(sizeof(struct Node));
        t->data= x;
        t->lChild= t->rChild=NULL;
        p->rChild=t;
        enqueue(&q,t);}
    }
} 
void preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lChild);
        preorder(p->rChild);
    }
}
int main(){
    Treecreate();
    preorder(root);
    return 0;
}