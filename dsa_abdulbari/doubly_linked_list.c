#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first;
void create(int A[], int n){
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data= A[0];
    first->prev= NULL;
    first->next= NULL;
    last= first;
    for(int i=1;i<n;i++){
        t= (struct Node*)malloc(sizeof(struct Node));
        t->data= A[i];
        t->prev= last;
        t->next= last->next;
        last->next= t;
        last= t;
    }
}
// displaying a doubly linked list 
void display(struct Node *p){
    do{
        printf("%d ",p->data);
        p= p->next;
    }while(p);
}
// length of linked list
int length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p= p->next;
    }
    return len;
}

// inserting a node at any position in a doubly linked list
void insert(struct Node *p,int pos, int key){
    struct Node *t;
    t= (struct Node*)malloc(sizeof(struct Node));
    t->data= key;
    t->prev= NULL;
    t->next= NULL;
    if(pos==0){
        t->next= first;
        first->prev= t;
        first= t;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p= p->next;
        }
        t->next= p->next;
        t->prev= p;
        if(p->next){
            p->next->prev=t;
        }
        p->next=t;
    }
}

// deleting an element from a doubly linked list
void delete(struct Node *p, int pos){
    if(pos==0){
        p= first;
        first= first->next;
        if(first)
        first->prev= NULL;
        free(p);
    }else{
        for(int i=0;i<pos;i++){
            p= p->next;
        }
        p->prev->next= p->next;
        if(p->next){
        p->next->prev= p->prev;}
        free(p);
    }
}
int main(){
    int A[]= {1,2,3,4,5};
    create(A,5);
    insert(first,0,7);
    display(first);
    delete(first,0);
    display(first);
}