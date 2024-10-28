/*
    LIST 04 - TASK 02: OPERATIONS WITH VECTORS AND POINTERS
    Enter a vector with dynamic memory allocation (uses the malloc function).
    The user must dynamically determine the number of elements he wants to have
    in the vector of integers. The vector elements must be in the range 1000 to 10000.
    The number of vector elements must be even.

    [1]. Check if the vector is STARKX. A vector is called STARKX if every number in the even field (0,2,4,...) 
         is greater than any number in the odd field (1,3,5,...).
    [2]. Extract the largest digit of each element of vector A. Generate a number whose magnitude order is 
         the same as the index of the vector element.
    [3]. Make a report of the number of digits that appear in each element of vector A. 
         Store the number of digits in vector D and print the report of the number of digits.
    [4]. Create a vector X that is a copy of vector A. Then create a function that checks the 
         second smallest digit of each number in vector X. Modify each element of vector X by 
         removing the second smallest digit (if there is a tie, remove the digit with the 
         smallest ordinal number) and recounting each digit. 
         Perform the digit count again on the new vector, and compare the digit count report in A 
         with the report in X.

    Definition of variables:
        - n: number of elements of vector
        - a: vector of numbers
        - b: vector with max digits

*/

#include <iostream>
#include <cmath>
using namespace std;

// header of functions defined by user
void input_num_elements(int *n);
int *allocate_memory(int n);
void input_vector(int n, int *x);
void print_vector(int n, int *x);
bool is_starkx(int n, int *x);
void generate_vec_max_digits(int n, int *x, int *y);
int search_highest_digit(int num);
long long generate_number(int n, int *x);
void vec_count_digits(int n, int *x, int *d);
void count_digits(int num, int *d);
void report_digits(int *d);

// main function
int main(){
    // define variables
    int n, *a, *b, *d;
    long long num;

    // input number of elements for vector
    input_num_elements(&n);

    // dynamic allocation of memory
    a = allocate_memory(n);

    // input the elements of vector A
    cout<<"\nInput the elements in vector: "<<endl;
    input_vector(n, a);
    cout<<"\nVector A: "<<endl;
    print_vector(n, a);

    // check if vector is STARKX
    if(is_starkx(n, a) == true){
        cout<<"\nThe vector is STARKX"<<endl;
    }else{
        cout<<"\nThe vector is not STARKX"<<endl;
    }

    // generate vector with maximum digits
    b = allocate_memory(n);
    generate_vec_max_digits(n, a, b);
    cout<<"\nVector of max digits: "<<endl;
    print_vector(n, b);
    num = generate_number(n, b);
    cout<<"\nGenerated number = "<<num<<endl;

    // vector to count the digits
    d = allocate_memory(10);
    vec_count_digits(n, a, d);
    cout<<"Report of digits:"<<endl;
    report_digits(d);

    return 0;
}

// procedure to input the number of elements for vectors
void input_num_elements(int *n){
    do{
        cout<<"\nNumber of elements: ";
        cin>>*n;
    }while(*n<=0 || *n%2 != 0);
}   

// function for dynamic allocation of memory for vectors using malloc
int *allocate_memory(int n){
    return (int *) malloc(n * sizeof(int));
}

// procedure to input the elements in 1 vector
void input_vector(int n, int *x){
    for(int i=0; i<n; i++){
        do{
            cout<<"X["<<i<<"]: ";
            cin>>x[i];
        }while(x[i]<1000 || x[i]>10000);        
    }
}

// procedure to print the elements of vector
void print_vector(int n, int *x){
    for(int i=0; i<n; i++){
        cout<<x[i]<<"  ";
    }
    cout<<endl;
}

// function to check if vector is STARKX
bool is_starkx(int n, int *x){
    int *even, *odd, counter=0;
    bool flag=true;
    even = x;
    odd = x;

    while(counter < n/2 && flag == true){
        if(*(even+2*counter) < *(odd+2*counter+1)){ // move 2 positions to right
            flag = false;
        }

        counter++;
    }

    return flag;
}

// procedure to generate vector with max digits
void generate_vec_max_digits(int n, int *x, int *y){
    for(int i=0; i<n; i++){
        y[i] = search_highest_digit(x[i]);
    }
}

// function to return the max digit for 1 number
int search_highest_digit(int num){
    int aux, dig, max_dig=-1;
    aux = num;

    // decompose the number
    while(aux>0){
        dig = aux%10;

        if(dig>max_dig){    // check if have higher digit than currently max_digit
            max_dig = dig;
        }

        aux = aux/10;
    }

    return max_dig;
}

long long generate_number(int n, int *x){
    long long num = 0, order=1;

    for(int i=0; i<n; i++){
        num = num + x[i]*order;
        order = order * 10;
    }

    return num;
}

void vec_count_digits(int n, int *x, int *d){
    for(int i=0; i<10; i++)
        d[i] = 0;
    
    for(int i=0; i<n; i++){
        count_digits(x[i], d);
    }
}

void count_digits(int num, int *d){
    int aux, dig;
    aux = num;

    while(aux>0){
        dig = aux%10;
        d[dig]++;
        aux = aux/10;
    }
}

void report_digits(int *d){
    for(int i=0; i<10; i++){
        cout<<"Digit "<<i<<" count "<<d[i]<<" elements"<<endl;
    }
}