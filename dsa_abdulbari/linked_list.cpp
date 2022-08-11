// linked list- dynamic version of array...whose elements are not at contiguous memory locations
// creating a node:
struct Node{
    int data;
    struct Node *next;
}*first= NULL;
// creating a linked list using array elements:
void create(int a[],int n){
    struct Node *t,*last;
    first->data= a[0];
    first->next= NULL;
    first= last;
    for(int i=1;i<n;i++){
        t= (struct Node)malloc(sizeof(struct Node));
        t->data= a[i];
        t->next= NULL;
        last->next= t;
        last=t;
    }
}
// iterative fucntion to display linked list
void display(struct Node *p){
    while(p!= NULL){
        print("%d ",p->data);
        p= p->next;
    }
}
// recursive function to display linked list
void display(struct Node *p){
    if(p!= NULL){
        print("%d ",p->data);
        display(p->next);
        // diplaying in reverse order
        // display(p->next); print("%d ", p->data);
    }
}

................
// counting number of nodes in alinked list
int count(struct Node *p){
    int c=0;
    while(p!= NULL){
        c++;
        p= p->next;
    }
    return c;
}
// recursive version:
int count(struct Node *p){
    if(p== NULL){
        return 0;
    }
    return 1+ count(p->next);
}
....................
// sum of each data of the Nodes
int sum(struct Node *p){
    int s=0;
    while(p!= NULL){
        s+= p->data;
        p= p->next;
    }
    return s;
}
// recursive version
int sum(struct Node *p){
    if(p== 0){
        return 0;
    }
    return sum(p->next)+ p->data;
}
................................
// maximum element in a linked list
int max(struct Node *p){
    int maxx= INT_MIN;
    while(p!= NULL){
        if(p->data> maxx){
            maxx= p->data;
        }
        p= p->next;
    }
    return maxx;
}
// recursive version:
int max(struct Node *p){
    int maxx= INT_MIN;
    if(p== NULL){
        return maxx;
    }
    int x= max(p->next);
    if(x>p->data){
        return x;
    }else{
        return p->data;
    }
}
.....................
// searching an element in linked list
struct Node search(struct Node *p, int key){
    while(p!= NULL){
        if(p->data== key){
            return p;
        }
        p= p->next;
    }
    return NULL;
}
// recursive version
struct Node search(struct Node *p, int key){
    if(p== 0){
        return NULL;
    }
    if(key= p->data)    return p;
    int x= search(p->next, key);
    return x;
}
// improved search:by putting the searched element on the first position
struct Node search(struct Node *p, int key){
    struct Node *q= NULL;
    while(p!= NULL){
        if(p->data== key){
            q->next= p->next;
            p->next= first;
            first= p;
            return p;
        }
        q=p;
        p= p->next;
    }
    return NULL;
}
..............................
// inserting an element in a  linked list
void insert(struct Node *p, int pos, int x){
     struct Node *t;
     t= (struct Node)malloc(sizeof(struct Node));
    t->data= x;
    if(pos== 0){ 
        t->next= first;
        first=t;
    }else{
        //struct Node *q= NULL;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t->next= p->next;
        p->next= t;
    }
    
}
................
// inserting in a sorted linked list
void insert_sorted(struct Node *p, int key){
    struct Node *q= NULL;
    struct Node *t;
    t= (struct Node)malloc(sizeof(struct Node));
    t->data=key;
    t->next= NULL;
    if(first== NULL){
        first= t;
    }else{
        while(p!= NULL){
            if(key>p->data){
                q=p;
                p= p->next;
            }
        }
        if(p == first){
            t->next= first;
            first=t;
        }else{
            t->next= q->next;
            q->next=t;
        }
    }
}
.............................
// deleting an element from a linked list
void delete(struct Node *p, int ind){
    struct Node *q= NULL;
    
    if(p==NULL) return;
    if(ind<1 ||ind>count(p))    return -1;
    if(ind==1){
        q= first;
        first= first->next;
        delete q;

    }else{
        for(int i=0;i<ind-1;i++){
            q=p;
            p= p->next;
        }
        q->next= p->next;
        delete p;
    }
}
........................
// Checking if the linked list is sorted or not
bool isSorted(struct Node *p){
    int curr= INT_MIN;
    while(p!= NULL){
        if(curr>p->data){
            return false;
        }
        curr= p->data;
        p=p->next;

    }
    return true;
}
.......................
// removing duplicate elements from a linked list
void rm_dup(struct Node *p){
    struct Node *q;
    q= p->next;
    while(q!= NULL){
        if(p->data!=q->data){
            p=q;
            q= q->next;
        }else{
           
            p->next= q->next;
            free(q);
            q=p->next;
        }
    }
}
.......................
// reversing a linked list by changing the position of elements
vector<int> v;
void Link_reverse(struct Node *p){
    while(p!= NULL){
        v.push_back(p->data);
         p= p->next;
    }
    p= first;
    int n= v.size();
    while(p!= NULL){
        p->data= v[n-1];
        n--;
        p= p->next; 
    }
}   
// reversing a linked list by reversing the links in a linked list
void Rreverse(struct Node *p){
    struct Node *r, *q;
    r=NULL;q=NULL;
    while(p!= NULL){
        r=q;
        q=p;
        p= p->next;
        q->next=r;
    }
    first=q;
}
// recursive reversing of linked list
void reverse(struct Node *q,struct Node *p){
    if(p!= NULL){
        reverse(p,p->next);
        p->next=q;
    }else{
        p=first;
    }
}
........................
// Concatenating two linked list
void concatenate(struct Node *p, struct Node *q){
    while(p!= NULL){
        p=p->next;
    }
    p= q;
}
......................
// merging two linked list
void merge(struct Node *first, struct Node *second){
    struct Node *third, *last;
    if(first->data< second->data){
        third= last= first;
        third->next= NULL;
        first= first->next;
    }else{
        third= last= second;
        third->next= NULL;
        second= second->next;
    }
    while(first and second){
        if(first->data<second->data){
            last->next= first;
            last= first;
            first= first->next;
            last->next= NULL;

        }else{
            last->next=second;
            last= second;
            second= second->next;
            last->next= NULL;
        }
    }
    if(first){
        last->next= first;
    }else{
        last->next= second;
    }
}
.....................
// finding the loop in a linked list
bool finding_loop(struct Node *p){
    struct Node *q;
    q= first;p= first;
    while(q and p){
        p= p->next;
        q= q->next;
        q= q?q->next:q
        if(p==q){
            return true;
        }
    }
    return false;
}
................................
// circular linked list iterative
void display(struct Node *p){
    do{
        printf("%d ", p->data);
        p= p->next;
    }while(p!= first)
}
// recursive version:
void display(struct Node *p){
    static int flag=0;
    if(p!= first or flag==0){
        flag=1;
        printf("%d ",p->data);
        display(p->next);
    }
    flag=0;
}
..............................
// inserting in  circular linked list
void insert(struct Node *p,int pos, int key){
    struct Node *t;
    t= (struct Node)malloc(sizeof(struct Node));
    t->data= key;
    t->next= NULL;
    if(pos== 0){
        if(first= NULL){
            first=t;
            first->next= first;
        }
        else{
            do{
                p= p->next;
            }while(p->next!= first);
            t->next= p->next;
            p->next= t;
        }
    }else{
        for(int i=0;i<pos-1;i++){
            p= p->next;
        }
        t->next= p->next;
        p->next= t;
    }
}
.................
// deleting the element from a circular linked list
void delete(struct Node *p, int pos){
    struct Node *q;
    if(pos==0){
        while(p->next!= first){
            p= p->next;
        }
        if(first== p){
            free(first);
            first= NULL;
        }else{
            p->next=first->next;
            free(first);
            first= p->next;
        }
    }else{
        for(int i=0;i<pos-2;i++){
            p= p->next;
        }
        q= p->next;
        p->next= q->next;
        free(q);
    }
}
................................
// creating a doubly linked list
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first;
void create(int A[], int n){
    struct Node *t, *last;
    first = (struct Node)malloc(sizeof(struct Node));
    first->data= A[0];
    first->prev= NULL;
    first->next= NULL;
    last= first;
    for(int i=1;i<n;i++){
        t= (struct Node)malloc(sizeof(struct Node));
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
....................
// inserting a node at any position in a doubly linked list
void insert(struct Node *p,int pos, int key){
    struct Node *t;
    t= (struct Node)malloc(sizeof(struct Node));
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
..................................
// deleting an element from a doubly linked list
void delete(struct Node *p, int pos){
    if(pos==0){
        p= first;
        first= first->next;
        first->prev= NULL;
        free(p);
    }else{
        for(int i=0;i<pos-1;i++){
            p= p->next;
        }
        p->prev->next= p->next;
        if(p->next){
        p->next->prev= p->prev;}
        free(p);
    }
}
.........................
// reversing a doubly linked list
void reverse(struct Node *p){
    struct Node *temp;
    while(p!= NULL){
        temp= p->next;
        p->next= p->prev;
        p->prev=temp;
        if(p->next==NULL){
            first= p;
        }
    }
}
.....................
// displaying a doubly circular linked list
void display(struct Node *p){
    do{
        printf("%d ",p->data);
        p= p->next;
    }while(p!= first);
}
// creating a circular doubly linked list
void create(int A[], int n){
    struct Node *t,*last;
    first= (struct Node*)malloc(sizeof(struct Node));
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
}
..................
// inserting an element in a circular doubly linked list
void insert(struct Node *p,int pos, int key){
    struct Node *t;
    t= (struct Node*)malloc(sizeof(struct Node));
    t->data= key;
    if(pos ==0){//error
        t->next= first;
        if(first->prev!= NULL){
        first->prev->next= t;}
        t->prev= first->prev;
        first->prev=t;
        
    }else{
        for(int i=0;i<pos-1;i++){
            p= p->next;
        }
        t->next= p->next;
        t->prev= p;
        if(p->next){
            p->next->prev=t;
        }
        p->next= t;
    }
}
............................
// finding the intersection point of two linked list

..........................
// sparse matrix using linked list
struct Node{
    int col;
    int data;
    struct Node *next;
}first;
struct Node *B[n];
void create(int A[][], int n,int m){  
    struct Node *last;
    for(int i=0;i<n;i++){
        B[i]= (struct Node*)malloc(sizeof(struct Node));
        B[i]= NULL;last= NULL;
        for(int j=0;j<m;j++){
            if(A[i][j]!= 0){
                
                if(B[i]==NULL){
                    B[i]->col= j;
                    B[i]->data= A[i][j];
                    B[i]->next= NULL;
                    last= B[i];
                }else{
                    B[i]->col= j;
                    B[i]->data= A[i][j];
                    B[i]->next= NULL;
                    last->next=B[i];
                    last = B[i];
                }
            }
        }
    }
}
void display(struct Node *p,int n,int m){
    for(int i=0;i<n;i++){
        p= B[i];
        for(int j= 0;j<m;j++){
            if(j== p->col){
                printf("%d ",p->data);
                p= p->next;
            }else{
                printf(0);
            }
        }
        printf("\n");
    }
}
...........................
// creating ,displaying and evaluating a pollynomial function using linked list
struct Node{
    int coeff;
    int exp;
    struct Node next;
}*p=NULL;
void create(){
    struct Node *t, *last;
    int num;
    printf("\nEnter the number of terms:\n");
    scanf("%d", &num);
    printf("\nEnter each number with their coefficient and exponents\n");
    for(int i=0;i<num;i++){
        t= (struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d",&t->coeff,&t->exp);
    }
    t->next= NULL;
    if(p== NULL){
        p= last= t;
    }else{
        last->next= t;
        last=t;
    }
}
void display(struct Node *p){
    while(p){
        printf("%d %d",p->coeff,p->exp);
        p= p->next;
    }
    printf("\n");
}
long eval(struct Node *p, int x){
    long sum=0;
    while(p){
        sum+= p->coeff*pow(x, p->exp);
        p= p->next;
    }
    return sum;
}
int main(){
    create();
    display(p);
    printf("%d ",eval(p,2));
    return 0;
}
