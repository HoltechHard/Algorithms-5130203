#include <iostream>
#include <cmath>
using namespace std;

void input_num_elements(int *n);
int *allocate_memory(int n);
void input_vector(int n, int *x);
void print_vector(int n, int *x);
bool is_starkx(int n, int *x);
void generate_vec_max_digits(int n, int *x, int *y);
int search_highest_digit(int num);

int main(){
    int n, *a, *b;
    input_num_elements(&n);
    a = allocate_memory(n);
    cout<<"\nInput the elements in vector: "<<endl;
    input_vector(n, a);
    cout<<"\nVector A: "<<endl;
    print_vector(n, a);

    if(is_starkx(n, a) == true){
        cout<<"\nThe vector is STARKX"<<endl;
    }else{
        cout<<"\nThe vector is not STARKX"<<endl;
    }

    b = allocate_memory(n);
    generate_vec_max_digits(n, a, b);
    cout<<"\nVector of max digits: "<<endl;
    print_vector(n, b);

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

bool is_starkx(int n, int *x){
    int *even, *odd, counter=0;
    bool flag=true;
    even = x;
    odd = x;

    while(counter < n/2 && flag == true){
        if(*(even+2*counter) < *(odd+2*counter+1)){
            flag = false;
        }

        counter++;
    }

    return flag;
}

void generate_vec_max_digits(int n, int *x, int *y){
    for(int i=0; i<n; i++){
        y[i] = search_highest_digit(x[i]);
    }
}


int search_highest_digit(int num){
    int aux, dig, max_dig=-1;
    aux = num;

    while(aux>0){
        dig = aux%10;

        if(dig>max_dig){
            max_dig = dig;
        }

        aux = aux/10;
    }

    return max_dig;
}

