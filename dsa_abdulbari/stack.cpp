// stack: follow Last in first out discipline
// stack does pop(),push(),peek(int pos), last_element(),isEmppty(), isfull() ops
// all in O(1) time
.................................
// Stack implementation using array
struct Stack{
    int size;
    int top;
    int *s;
}
// creating a stack and not pushing any value in the stack
void create(struct Stack *st,int n){
    st->size=n;
    st->top=-1;
    st->s= (int *)malloc(st->size*sizeof(int));
}
// printing each element of the stack in top to bottom order
void display(struct Stack st){
    for(int i=st.top; i>=0;i--){
        printf("%d ",st.s[i]);
    }
}
// push the value of element in the stack
void push(struct Stack *st, int key){
    if(st->top>st->size-1){
        printf("Stack Overflow\n");
    }else{
        st->top++;
        st->s[st->top]= key;
    }
}


// removing the element from the stack and returning the removed value
int pop(struct Stack *st){
    int x=-1;
    if(st->top<0){
        printf("Stack Underflow or Stack is empty");
    }else{
        x=st->s[st->top];
        st->top--;
    }
    return x;
}
// finding the index of the element from the peek in a stack
int peek(struct Stack *st,int pos){
    if(st->top-pos+1> st->size){
        return -1;
    }else{
        return (st->top-pos+1);
    }
}
// execution of the program in the given order
int main() {
	struct Stack st;
	create(&st,5);
	push(&st,1);
	push(&st,2);
	push(&st,3);
	push(&st,4);
	push(&st,5);
	display(st);
	printf("pop out element is: %d\n ", pop(&st));
    display(st);
    printf("%d ",peek(&st,2));
	//display();
	return 0;
}

.........................................
// stack implementation using linked list
struct Node{
    int data;
    struct Node *next;
}top=NULL;
.........................
// pushing an element in a stack;
void push(int x){
    struct Node *t;
    t= (struct Node*)malloc(sizeof(struct Node));
    if(t== NULL){
        printf("Stack Overflow");
    }else{
        t->data=x;
        t->next= top;
        top= t;
    }
}
.............................
// removing an element from the stack

int pop(){
    struct Node *p;
    int x=-1;
    if(top== NULL){
        printf("Stack is empty");
    }else{
        p= top;
        top= top->next;
        x= p->data;
        free(p);
    }
}

..................
// finding the position of the element from top of the stack
int peek(int pos){
    struct Node *p=top;
    for(int i=0;p!= NULL && i<pos-1;i++){
        p= p->next;
    }
    if(p== NULL){
        return -1;
    }else{
        return p->data;
    }
}
..............................
int top_element(){
    if(top== NULL){
        return -1;
    }else{
        return top->data;
    }
}
....................
int isempty(){
    return top?0:1;
}
................
int isfull(){
    struct Node *t= (struct Node*)malloc(sizeof(struct Node));
    int r= t?0:1;
    free(t);
    return r;
}
..............................

// checking whether parenthesis are balanced ot not
struct Stack{
    int size;
    int top;
    char* s;
};
int isbalanced(char *exp){
    struct Stack st;
    int n= strlen(exp);
    create(&st,n);
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('){
            push(&st,exp[i]);
        }else if(exp[i]==')'){
            if(st->top== -1){
                return 0;
            }
            pop(&st);
        }
    }
    if(isempty(st)){
        return 1;
    }else{
        return 0;
    }
}

...............................
// full code for balanced parenthesis
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int size;
    int top;
    char* s;
};
create(struct Stack *st,int n){
    st->size=n;
    st->top= -1;
    st->s= (char*)malloc(st->size*sizeof(char));
}
void push(struct Stack *st,int key){
    if(st->top== st->size-1){
        printf("Stack overflow");
    }else{
        st->top++;
        st->s[st->top]= key;
    }
}
char pop(struct Stack *st){
    char x= '\0';
    if(st->top== -1){
        printf("Stack is empty");
    }else{
        x= st->s[st->top];
        st->top--;
    }
    return x;
}
int isempty(struct Stack st){
    return (st->top==-1)?1:0;
}
int isbalanced(char *exp){
    struct Stack st;
    create(&st, strlen(exp));
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('){
            push(&st,exp[i]);
        }else if(exp[i]== ')'){
            if(isempty(st)){
                return 0;
            }else{
                pop(&st);
            }
        }
    }
    if(isempty(st)){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    char *p= "(a+b)*(c+d)";
    printf("%d ",isbalanced(p));
}

..........................................
// checking balancing of brackets contained in an string containing more than one tupe of brackets
// using built in stack and map function in c++ STL

#include <bits/stdc++.h>

using namespace std;


bool isbalanced(string s){
    map<char,char> m;
    m[')']= '(';
    m['}']='{';
    m[']']='[';
    stack<char> stk;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            stk.push(s[i]);
        }
        else if(s[i]==')'||s[i]=='}'|| s[i]==']'){
            if(stk.empty()){
                return false;
            }
            else{
                char x= stk.top();
                auto it= m.find(s[i]);
                if(x== it->second){
                    stk.pop();
                }else{
                    return false;
                }
            }
        }
    }
    if(stk.empty()){
        return true;
    }else{
        return false;
    }
}
int main() {
    string s="({c*b}*[a+b])";
    if(isbalanced(s)){
        cout<<"balanced";
    }else{
        cout<<"Not Balanced";
    }
	return 0;
}
.........................
// infix to postfix conversion
struct Stack{
    int size;
    int top;
    char* postfix;
};
void create(struct Stack *stk,int n){
    st->top= -1;
    st->size= n;
    st->postfix= (char*)malloc(st->size*sizeof(char));
}
int isoperand(char x){
    if(x=='+'||x=='-'||x=='/'||x=='*'){
        return 0;
    }else{
        return 1;
    }
}
int prec(char x){
    if(x=='+'||x=='-'){
        return 1;
    }else if(x=='*'|| x=='/'){
        return 2;
    }
    return 0;
}
char* convert(char* infix){
    struct Stack st;
    int n= strlen(infix)+1;
    create(&st,n);
    int i=0,j=0;
    char* post= (char*)malloc(n*sizeof(char));
    while(infix[i]!= '\0'){
        if(isoperand(infix[i])){
            post[j++]= infix[i++];
        }
        else{
            if(prec(infix[i])>prec(st.postfix[st.top])){
                push(&st,infix[i]);i++;
            }else{
                char temp=pop(&st);
                post[j++]=temp;
            }
        }
    }
    while(isempty(st)){
        post[j++]= st.postfix[st->top];
        st->top--;
    }
    post[j]='\0';
    return post;

}

............................
// infix to postfix conversion of the expression containing brackets and both type of associativity
int isoperand(char x){
    if(x=='+'||x=='-'||x=='/'||x=='*'||x=='('||x==')'||x=='^'){
        return 0;
    }else{
        return 1;
    }
}
int stackoutprec(char x){
    if(x=='+'||x== '-'){
        return 1;
    }else if(x=='*'|| x== '/'){
        return 3;
    }else if(x=='^'){
        return 6;
    }else if(x== '('){
        return 7;
    }else if(x==')'){
        return 0;
    }
}
int stackinprec(char x){
    if(x=='+'||x=='-'){
        return 2;
    }else if(x=='*'|| x=='/'){
        return 4;
    }else if(x=='^'){
        return 5;
    }else if(x== '('){
        return 0;
    }else if(x==')'){
        return -1;
    }
}
char* convert(char* infix){
    struct Stack st;
    int n= strlen(infix)+1;
    create(&st, n);
    char* post= (char*)malloc(n*sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            post[j++]= infix[i++];
        }else{
            if(isempty(st)|| stackoutprec(infix[i])> stackinprec(st.postfix[st.top])){
                push(&st,infix[i]);i++;
            }else if(stackoutprec(infix[i])== stackinprec(st.postfix[st.top])){
                pop(&st);
            }else{
                char x= pop(&st);
                post[j++]=x;
            }
        }
    }
    while(isempty(st)){
        post[j++]= st.postfix[st.top];
        pop(&st);
    }
    post[j]='\0';
    return post;
}
// infix to postfix expression using stl
string convert(string s){
    stack<char> st;
    string post;
    for(int i=0;i<s.length();i++){
        if(isoperand(s[i])){
            post.push_back(s[i++]);
        }else{
            if(stackoutprec(s[i])> stackinprec(st.top())){
                st.push(s[i]);i++;
            }else if(stackoutprec(s[i])== stackinprec(st.top())){
                st.pop();
            }else{
                post.push_back(st.top());
                st.pop();
            }
        }
    }
    while(!st.empty() and st.top()!= ')'){
        post.push_back(st.top());
        st.pop();
    }
    return post;
}
.............................
// postfix evaluation
int eval(char* post){
    struct Stack st;
    int n= strlen(post);
    create(&st,n);
    for(int i=0;post[i]!= '\0';i++){
        if(isoperand(post[i])){
            push(&st, post[i]-'0');
        }else{
            int x= pop(&st),y= pop(&st);
            switch(post[i]){
                case '+': r= y+x;push(&st,r);break;
                case '-': r= y-x;push(&st,r);break;
                case '*': r= y*x;push(&st,r);break;
                case '/':r= y/x;push(&st,r);break;
            }
        }
    }
    return pop(&st);
}

.................................

