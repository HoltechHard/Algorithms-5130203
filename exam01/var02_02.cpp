/*
    EXAM 01 - Algorithms and Programming 5130203/40001
    VARIANT 02 - EXERCISE 02
*/

#include <iostream>
#include <cmath>
using namespace std;

void input_value(int *n);
void count_digits(int n, int *n1, int *n2);
int *allocate_vector(int n);
void input_vectors(int n, int *n1, int *a, int *n2, int *b);
int calculate_result(int n1, int *a, int n2, int *b);
void print_vector(int n, int *x);

// main function
int main(){
    int n, n1=0, n2=0, *a, *b, res;

    // input N
    input_value(&n);    
    cout<<"N = "<<n<<endl;

    // count #even and #odd digits
    count_digits(n, &n1, &n2);    
    cout<<"n1 = "<<n1<<endl;
    cout<<"n2 = "<<n2<<endl;

    // input digits to vectors
    a = allocate_vector(n1);
    b = allocate_vector(n2);
    input_vectors(n, &n1, a, &n2, b);
    
    cout<<"\nVector A: "<<endl;
    print_vector(n1, a);
    cout<<"\nVector B: "<<endl;
    print_vector(n2, b);

    // calculate the result
    res = calculate_result(n1, a, n2, b);
    cout<<"\nFinal result = "<<res<<endl;

    return 0;
}

// procedure to input N
void input_value(int *n){
    do{
        cout<<"\nInput the number: ";
        cin>>*n;
    }while(*n<100 || *n>1000000);
}

// function for dynamic allocation of memory in vector
int *allocate_vector(int n){
    if(n > 0)
        return (int *) malloc(n * sizeof(int)); // allocate n elements
    else
        return (int *) malloc(sizeof(int));     // allocate 1 element
}

// procedure to count number of even and odd digits
void count_digits(int n, int *n1, int *n2){
    int aux, dig;
    aux = n;

    while(aux>0){
        dig = aux%10;
        if(dig%2 == 0){
            *n1 += 1;
        }else{
            *n2 += 1;
        }

        aux = aux/10;
    }    
}

// procedure to extract even digits and store to A and odd digits and store to B
void input_vectors(int n, int *n1, int *a, int *n2, int *b){
    int aux, dig, count_a=0, count_b=0;
    aux = n;

    // if not even digits
    if(*n1==0){
        a[0]=0;
        *n1=1;
    }

    // if not odd digits
    if(*n2==0){
        b[0]=0;
        *n2=1;
    }

    // decompose the number and store the digits in A, B
    while(aux>0){
        dig = aux%10;

        if(dig%2==0){
            a[count_a++] = dig;
        }else{
            b[count_b++] = dig;
        }

        aux = aux/10;
    }
}

// function to calculate final result
int calculate_result(int n1, int *a, int n2, int *b){
    int res=0, prod=1;

    for(int i=0; i<n1; i++){
        res += pow(a[i], 2);
    }

    for(int j=0; j<n2; j++){
        prod *= b[j];
    }

    res = res + prod;

    return res;
}

// procedure to print elements of vector
void print_vector(int n, int *x){
    for(int i=0; i<n; i++){
        cout<<x[i]<<"  ";
    }
    cout<<endl;
}
