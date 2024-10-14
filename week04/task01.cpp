/*
    LIST 04 - TASK 01: BASIC OPERATIONS WITH VECTORS
    Using functions and prodecures, enter vectors A and B with dynamic memory
    and let the user define the number of elements. Make the next operations:

    [1]. Create a procedure that allows the user to enter vector elements from the keyboard.
    [2]. Create a procedure that allows the user to print vector elements.
    [3]. Calculate the Euclidean distance between two vectors.
    [4]. Calculate the dot product of two vectors A and B using the linear combination formula.
    [5]. Calculate the angle formed between vectors A and B.
    [6]. Create a vector C that concatenates vectors A and B with elements sorted in ascending order. 
         Use the insertion-sort algorithm.
    [7]. Using the ordered vector C, calculate the statistical measures: 
         - math expectation
         - standard deviation
         - median    
*/

#include <iostream>
#include <cmath>
using namespace std;

// header of functions defined by user
void input_num_elements(int *n);
int *allocate_memory(int n);
void input_vector(int n, int *x);
void print_vector(int n, int *x);

// main function
int main(){
    // define variables
    int n, *a, *b;

    // input the number of elements for vectors
    input_num_elements(&n);

    // dynamic allocation of memory
    a = allocate_memory(n);
    b = allocate_memory(n);

    // input vectors A and B
    cout<<"\nInput the elements for vectors: "<<endl;
    cout<<"\nA: "<<endl;
    input_vector(n, a);
    cout<<"\nB: "<<endl;
    input_vector(n, b);

    // print elements of vectors A and B
    cout<<"\nVector A: "<<endl;
    print_vector(n, a);
    cout<<"\nVector B: "<<endl;
    print_vector(n, b);    

    return 0;
}

// procedure to input the number of elements for vectors
void input_num_elements(int *n){
    do{
        cout<<"\nNumber of elements: ";
        cin>>*n;
    }while(*n<=0);
}   

// function to dynamic allocation of memory for vectors using malloc
int *allocate_memory(int n){
    return (int *) malloc(n * sizeof(int));
}

// procedure to input the elements in 1 vector
void input_vector(int n, int *x){
    for(int i=0; i<n; i++){
        cout<<"X["<<i<<"]: ";
        cin>>x[i];
    }
}

// procedure to print the elements of vector
void print_vector(int n, int *x){
    for(int i=0; i<n; i++){
        cout<<x[i]<<"  ";
    }
    cout<<endl;
}
