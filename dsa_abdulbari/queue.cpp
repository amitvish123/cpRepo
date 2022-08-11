// queue are the data structure in which the data are inserted at the end and deleted from the 
// front
// queue implementation using the array
struct Queue{
    int size;
    int front;
    int rear;
    int *q;
};
void create(struct Queue *k,int n){
    size= n;
    front=-1;
    rear= -1;
    q= (int *)malloc(size*sizeof(int));
}
void enqueue(struct Queue *k, int key){
    if(k->rear==k->size-1){
        printf("Queue is full");
    }else{
        k->rear++;
        k->q[k->rear]=key;
    }
}
int dequeue(struct Queue *k){
    int x=-1;
    if(k->front== k->rear){
        printf("Queue is empty");
    }else{
        k->front++;
        x= k->q[k->front];
    }
    return x;
}
int isempty(struct Queue k){
    if(k.front== k.rear){
        return 1;
    }
    return 0;
}
int isFull(struct Queue k){
    if(k.rear== k.size-1){
        return 1;
    }return 0;
}
.......................
// circular queue: It is better than linear queue as the empty spaces can be reused
// circular queue implementation using array
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
        Q->front++;
        x= Q->q[(Q->front+1)%Q->size];
    }
    return x;
}
...........................
// queue using linked list
struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;
void enqueue(int key){

    struct Node *t;
    t= (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queue is full");
    }else{
        t->data=key;
        t->next=NULL;
        if(rear== NULL){
            front=rear= t;
        }else{
            rear->next= t;
            rear= t;
        }
    }
}
int dequeue(){
    int x=-1;
    struct Node *p;
    if(front==NULL){
        printf("Queue is empty");
    }else{
        p= front;
        front= front->next;
        x=p->data;
        free(p);
    }
    return x;
}
int isempty(){
    if(front==NULL){
        return 1;
    }return 0;
}
int isfull(){
    struct Node *t;
    t= (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        return 1;
    }return 0;
}

..............................
// Implementing doubly ended queue using linked list
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}*front= NULL,*rear=NULL;
void rear_enqueue(int key){
    struct Node *p;
    p->data= key;
    p->next=NULL;
    p->prev= NULL;
    if(p== NULL){
        printf("Queue is full");
    }
    else if(front==rear==NULL){
        front=rear=p;
    }else{
        p->prev= rear;
        if(rear!=NULL)
        rear->next=p;
        rear=p;
    }
}
void front_enqueue(int key){
    struct Node *p;
    p->data= key;
    p->next=NULL;
    p->prev= NULL;
    if(p== NULL){
        printf("Queue is full");
    }
    else if(front ==NULL){
        front = rear=p;
    }else{
        p->next= front;
        front->prev= p;
        front=p;
    }
}
int front_dequeue(){
    struct Node *p;
    if(front== rear){
        printf("Queue is empty");
    }else{
        p= front;
        front=front->next;
        x= p->data;
        free(p);
    }
}
int rear_dequeue(){
    struct Node *p;
    if(front== rear){
        printf("Queue is empty");
    }
    else{
        p= rear;
        rear= rear->prev;
        x= p->data;
        free(p);
    }
}
......................
// priority scheduling implementaton using queues
// no of priority =3;
// we have to form three queues
int main(){
    struct Queue Q1,Q2,Q3;
    vector<pair<int,int>> v;
    vector<int> vv;
    v= {{1,2},{3,1},{4,3},{5,1}};
    for(int i=0;i<v.size();i++){
        if(v[i].second== 1){
            enqueue(&Q1, v[i].first);
        }else if(v[i].second==2){
            enqueue(&Q2, v[i].first);
        }else{
            enqueue(&Q3, v[i].first);
        }
        if(isempty(Q1)){
            if(isempty(Q2)){
                if(isempty(Q3)){
                    printf("No element in array");
                }
                else{
                    vv.push_back(dequeue(&Q3));
                }
            }else{
                vv.push_back(dequeue(&Q2));
            }
        }else{
            vv.push_back(dequeue(&Q1));
        }
    }
    for(int x:vv){
        vout<<x<<" ";
    }
}
......................
// implementing queue using two stacks
void enqueue(int x){
    push(&s1, x);
}
int dequeue(){
    int x=-1;
    if(isempty(s2)){
        if(isempty(s1)){
            printf("Queue is empty");
            return x;
        }else{
            while(isempty(s1)){
                push(&s2,pop(&s1));
            }
        }
    }else{
       return pop(s2);
    }
}
