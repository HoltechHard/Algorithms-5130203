#include <iostream>
#include <cmath>
using namespace std;
int *memory_allocate(int n);
void scan(int N, int *A, int *B);
void sum(int *A, int*B, int i1, int i2);
int main(){
    int N=0;
    int* A, *B;
    while (N<100||N>1000000){
    cout <<"Enter N: ";
    cin >> N;
    }
    int k=N,n1=0,n2=0;
    while (k>0){
        if (k%10%2==0){
            n1++;
        } else {n2++;}
        k/=10;
    }
    A = memory_allocate(n1);
    B = memory_allocate(n2);
    scan(N, A, B);
    
}
int *memory_allocate(int n){
    if (n==0){
        n = 1;
    }
   int *mem = (int*)malloc(n*sizeof(int));
   return mem;
}
void scan (int N, int *A, int *B){
    int k=N,i1=0,i2=0;
     while (k>0){
        if (k%10%2==0){
            A[i1] = k%10;
            i1++;
        } else { B[i2] = k%10; i2++;}
        k/=10;
        ;
    } 
    cout  << "Vector A: ";
    if (i1 ==0){i1 = 1; A[0]=0;}
    for (int k = 0;k<i1; k++ ){
        cout << A[k] <<" ";
    }
    cout << endl;
      cout  << "Vector B: ";
       if (i2 ==0){i2 = 1; B[0]=0;}
    for (int k = 0;k<i2; k++ ){
        cout << B[k] <<" ";
    }
    cout << endl;
    sum (A, B, i1, i2);
}
void sum (int *A, int*B, int i1, int i2){
    int res1=0, res2=1, result;
    for (int i =0;i<i1;i++){
        res1 += pow (A[i],2);
    }
    for (int i = 0; i<i2; i++){
        res2 *= B[i];
    }
    result = res1+res2;
    cout << "Result = " << result<< endl; 
}