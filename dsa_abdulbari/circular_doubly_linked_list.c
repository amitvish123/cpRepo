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
    first->prev= first;
    first->next= first;
    last= first;
    for(int i=1;i<n;i++){
        t= (struct Node*)malloc(sizeof(struct Node));
        t->data= A[i];
        t->prev= last;
        t->next= last->next;
        last->next= t;
        last= t;
    }
    first->prev= last;
}
// displaying a circular doubly linked list 
void display(struct Node *p){
    do{
        printf("%d ",p->data);
        p= p->next;
    }while(p!= first);
}
// length of circular doubly linked list
int length(struct Node *p){
    int len=0;
    do{
        len++;
        p= p->next;
    }while(p!= first);
    return len;
}

// inserting a node at any position in a cirsular doubly linked list
void insert(struct Node *p,int pos, int key){
    struct Node *t;
    t= (struct Node*)malloc(sizeof(struct Node));
    t->data= key;
    t->prev= NULL;
    t->next= NULL;
    if(pos==0){
        t->next= first;
        t->prev= first->prev;
        first->prev->next= t;
        first->prev= t;
        first= t;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p= p->next;
        }
        t->next= p->next;
        t->prev= p;
        if(p->next!= first){
            p->next->prev=t;
        }
        p->next=t;
    }
}

// deleting an element from a doubly linked list
// void delete(struct Node *p, int pos){
//     if(pos==0){
//         p= first;
//         first= first->next;
//         if(first)
//         first->prev= NULL;
//         free(p);
//     }else{
//         for(int i=0;i<pos;i++){
//             p= p->next;
//         }
//         p->prev->next= p->next;
//         if(p->next){
//         p->next->prev= p->prev;}
//         free(p);
//     }
// }
int main(){
    int A[]= {1,2,3,4,5};
    create(A,5);
    insert(first,0,7);
    display(first);
    insert(first,1,7);
    display(first);
   return 0;
}