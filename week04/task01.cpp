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
    
    Definition of variables:
        - n: number of elements of vector
        - a, b: vectors
        - c: vector result of unify a, b
        - e_dist: output result of calculate euclidean distance
        - s_prod: output result of calculate scalar product
        - angle: output result of calculate angle between 2 vectors using functions with call by value
        - angle2: output result of calculate angle between 2 vectors using procedure
*/

#include <iostream>
#include <cmath>
using namespace std;

// header of functions defined by user
void input_num_elements(int *n);
int *allocate_memory(int n);
void input_vector(int n, int *x);
void print_vector(int n, int *x);
double euclidean_dist(int n, int *x, int *y);
double scalar_product(int n, int *x, int *y);
double calculate_module(int n, int *x);
double calculate_angle(int n, int *x, int *y);
void calculate_angle2(int n, int *x, int *y, double *angle);
void unify_vector(int n, int *x1, int *x2, int *y);
void insertion_sort(int n, int *x);

// main function
int main(){
    // define variables
    int n, *a, *b, *c;
    double e_dist, s_prod, angle, angle2;

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

    // calculate euclidean distance
    e_dist = euclidean_dist(n, a, b);
    cout<<"\nEuclidean distance = "<<e_dist<<endl;

    // calculate scalar product
    s_prod = scalar_product(n, a, b);
    cout<<"\nScalar product = "<<s_prod<<endl;

    // calculate angle using function by call
    angle = calculate_angle(n, a, b);
    cout<<"\nCalculate angle using function = "<<angle<<endl;

    // calculate angle using procedure
    calculate_angle2(n, a, b, &angle2);
    cout<<"\nCalculate angle using process = "<<angle2<<endl;

    // unify vectors a, b in vector c
    c = allocate_memory(2*n);
    unify_vector(n, a, b, c);
    cout<<"\nUnified vector: "<<endl;
    print_vector(2*n, c);

    // apply sort in ascendent order
    insertion_sort(2*n, c);
    cout<<"\nSorted vector: "<<endl;
    print_vector(2*n, c);

    return 0;
}

// procedure to input the number of elements for vectors
void input_num_elements(int *n){
    do{
        cout<<"\nNumber of elements: ";
        cin>>*n;
    }while(*n<=0);
}   

// function for dynamic allocation of memory for vectors using malloc
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

// function to calculate euclidean distance
double euclidean_dist(int n, int *x, int *y){
    double dist=0;

    for(int i=0; i<n; i++){
        dist+= pow(x[i] - y[i], 2);
    }

    return sqrt(dist);
}

// function to calculate scalar product
double scalar_product(int n, int *x, int *y){
    double sp=0;

    for(int i=0; i<n; i++){
        sp += x[i]*y[i];
    }

    return sp;
}

// function to calculate module of vector
double calculate_module(int n, int *x){
    double mod = 0;

    for(int i=0; i<n; i++){
        mod += pow(x[i], 2);
    }

    return sqrt(mod);
}

// function to calculate angle between 2 vectors
double calculate_angle(int n, int *x, int *y){
    double sp=0, mod_x=0, mod_y=0;

    sp = scalar_product(n, x, y);
    mod_x = calculate_module(n, x);
    mod_y = calculate_module(n, y);

    return acos(sp/(mod_x * mod_y));
}

// procedure to calculate angle between 2 vectors
void calculate_angle2(int n, int *x, int *y, double *angle){
    double sp=0, mod_x=0, mod_y=0;

    sp = scalar_product(n, x, y);
    mod_x = calculate_module(n, x);
    mod_y = calculate_module(n, y);

    *angle = acos(sp/(mod_x * mod_y));
}

// procedure to unify 2 vectors
void unify_vector(int n, int *x1, int *x2, int *y){
    for(int i=0; i<n; i++){
        y[i] = x1[i];
        y[i+n] = x2[i];
    }
}

// algorithm insertion-sort in ascendent order
void insertion_sort(int n, int *x){
    int key, j;

    for(int i=1; i<n; i++){
        key = x[i];

        for(j=i-1; j>=0 && x[j]>key; j--){
            x[j+1] = x[j];
        }

        x[j+1] = key;
    }
}

