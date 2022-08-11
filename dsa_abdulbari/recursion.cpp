// Recursion
// Printing the number in ascending order
void print_asc(int n){
if(n>0){
printf(“%d”, n);
print_asc(n-1);
}
}
// Printing the number in descending order
void print_dsc(int n){
if(n>0){
print_dsc(n-1);
printf(“%d”, n);
}
}
// For understanding: asc: first switch the bulb then go to the next room
// 			Dsc: first go to the next room then switch on the bulb.

// Generalising recursion:

Void fun(int n){
      //statements…(gets executing at calling time)- ascending phase.
      fun(n-1)*x;(this executes at returning time)
     // statements…(gets executed during returning time)- descending phase.
}
// How recursion used stack;
// All the functions calls of a given recursive function are called one by one after that each call are retrieved
// Time complexity of recursion: can be find by recursion tree method or by substitution method
Void fun(int n){............T(n)
     if(n>0){.............1unit
     printf(“%d”, n);.........1unit
     fun(n-1);.........T(n-1) unit
     }
}
// T(n) = T(n-1) + 1;
// T(n) = T(n-2) +2;
// T(n)= T(n-3)+3;
// ……..
// T(n)= T(n-k)+k;
// Assume n-k=0 - T(n)= 1+n; So, time complexity is, O(n).
// …..For debugging the code in VS Code , we first click on the leftmost side of the window to make a breakpoint, then navigate to the next step by clicking the F10 button.

// …Static variable and Global variable are stored in code section of memory. When they are used with recursion then the same copy of variable is applied to each calls.
Int fun(int n){
   Static int x=0;
   if(n>0){
       X++;
      return  fun(n-1)+x;
      }
Return 0;
}
Int main(){
   Int n=5;
   cout<<fun(n)<<endl;}
// Above code uses static variable so after incrementing the variable it will just modified the previous value of the variable and do not make the copy of the variable. Static and global var
//acts as same for the above code.
..............*......................
// Tree recursion: Two or more function are called to the same function.
// Example code:
int fun(int n){
    if(n>0){
        printf("%d ",n);
        fun(n-1);
        fun(n-1);
    }
    return 0;
}
int main(){
    int r;
    r= fun(3);
    cout<<r<<endl;
    return 0;
}
output: 3 2 1 1 2 1 1
// for n=3, there are 15 function calls.second funtion call is active while
// returning of the first function call
........................

// Indirect recursion: Here two or more function calls each other in their
// funtions.
// Example code:
void fun2(int n);
void fun1(int n){
    if(n>0){
        printf("%d ",n);
        fun2(n-1);
    }
}
void fun2(int n){
    if(n>1){
        printf("%d ",n);
        fun1(n/2);
    }
}
int main(){
    fun1(20);
    return 0;
}
.....................

// nested recursion: In this, the function which is called is nested 
// inside the same function 
int fun(int n){
    if(n>100){
        return n-10;
    }
    return fun(fun(n+11));
}
int main(){
    int n=95;
    int r;
    r=fun(n);
    printf("%d ",r);
    return 0;
}

......................

// Sum of n natural numbers i.e; 1+2+3+4+........+(n-1)+n
//  so, sum(n)= sum(n-1)+n;
// given expression can be converted into recursion as follows:
int sum(int n){
    if(n==0){
        return 0;
    }
    return sum(n-1)+n;
}
int main(){
    int r;
    r= sum(5);
    printf("%d ",r);
    return 0;
}
//o/p: 15

.....................
// Factorial of n i.e; 1.2.3.4........(n-1).n 
// which can be written as; fact(n)= fact(n-1)*n;
int fact(int n){
    if(n==0){
        return 1;
    }
    return fact(n-1)*n;
}
int main(){
    int r;
    r= fact(4);
    printf("%d ",r);
    return 0;
}
// o/p: 24

.............................

// power using recursion i.e; finding n^m = n......(m-times).n.
// which can be written as; power(n,m)= power(n,m-1).n
// The code of the above expression is:
int power(int n,int m){
    if(m==0){
        return 1;
    }
    return power(n,m-1)*n;
}
int main(){
    int r;
    r= power(2,5);
    printf("%d ",r);
    return 0;
}
// o/p: 32.

.........................

// Taylor series general approach: 1+ x/1+x^2/2! +........+ x^n-1/(n-1)!
//The code for taylor series is:
 int exp(int x,int n){
     if(n==0){
         return 1;
     }
     static int p=1, l=1;
     int r;
     r= exp(x,n-1)
     p= p*x;l= l*n;
     return r+p/l;
 }
 ..............

//  Taylor series efficent implementation, it takes only O(n) multiplication while
//  the previous one takes O(n^2) multiplication
//  Taylors series can be rewritten as, 1+ x/1[i+ x/2[1+x/3[....]]]
int exp(int x, int n){
    static int s=1;
    if(n==0){
        return 0;
    }
    s*=x/n;s= s+1;
    return exp(x,n-1);
}
.....................

// fibonacci series: 0 1 2 3 5 8.....
// which can be rewritten as, fib(n)= fib(n-2)+ fib(n-1)
// if n= 0 or 1 then fib(n)=n;the recursive code is as follows:
int fib(int n){
    if(n==0|| n==1){
        return n;
    }
    return fib(n-2)+ fib(n-1);
}
//memoized version of fibonacci number
int m= {-1,-1,-1,-1,-1,-1,-1};// global array formed first
int fib(int n){
    if(n==0 || n==1){
        m[n]=n;
        return n;
    }
    if(m[n-2]== -1){
        m[n-2]= fib(n-2);
    }
    if(m[n-1]== -1){
        m[n-1]= fib(n-1);
    }
    m[n]= m[n-2]+m[n-1];
    return m[n-2]+m[n-1];
}
// iterative version:
int fib(int n){
    if(n==0 || n== 1){
        return n;
    }
    int s=0, t0=0, t1= 1;
    for(int i=2;i<= n;i++){
        s= t0 +t1;
        t0= t1;
        t1= s;
    }
    return s;
}

.................
// finding ncr general approach(non-recursive)
int fact(int n){
    if(n==0){
        return 1;
    }
    return fact(n-1)*n;
}
int ncr(int n,int r){
    int num= fact(n);
    int den= fact(r)*fact(n-r);
    return num/den;
}
// ncr using pascals triangle: i.e.; ncr= (n-1)C(r-1)+ nC(r-1)
int ncr(int n,int r){
    if(n==0|| n==r){
        return 1;
    }
    return ncr(n-1,r-1)+ ncr(n,r-1);
}

...............
// recursive implementation of Tower Of Hanoi
// first put n-1 blocks on intermediate, then put bottommost block at destination, then put 
// remaining n-1 blocks on the destination
void TOH(int n,int A,int B, int C){
    TOH(n-1,A,C,B);
    printf("from %d to %d\n",A,C);
    TOH(n-1,B,A,C);
}
