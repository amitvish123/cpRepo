
struct Node{
    struct Node *lChild;
    int data;
    struct Node *rChild;
};
struct Queue{
    int size;
    int front;
    int rear;
    struct Node **q;
};
void create(struct Queue *Q,int n){
    Q->size=n;
    Q->front=0;
    Q->rear=0;
    Q->q= (struct Node **)malloc(Q->size*sizeof(struct Node *));
}
void enqueue(struct Queue *Q,struct Node *x){
    if((Q->rear+1)%Q->size == Q->front){
        printf("Queue is full");
    }else{
        Q->rear=(Q->rear+1)%Q->size;
        Q->q[Q->rear]= x;
    }
}
struct Node * dequeue(struct Queue *Q){
    struct Node  *x=NULL;
    if(Q->front== Q->rear){
        printf("Queue is empty");
    }else{
        Q->front=(Q->front+1)%Q->size;
        x= Q->q[Q->front];
    }
    return x;
}
int isEmpty(struct Queue Q){
    return Q.front== Q.rear;
}