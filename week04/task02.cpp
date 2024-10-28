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
        - d: vector to count the digits in elements of vector a
        - x: vector which drop 2nd lowest digits for each number
        - d2: vector to count the digits in elements of vector x

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
void copy_vector(int n, int *x, int *y);
void vec_drop_2lowest_digit(int n, int *x);
void search_2lowest_digit(int num, int *seclow_dig);
void search_position_digit(int num, int search_digit, int *pos);
int drop_2lowest_digit(int num, int pos);

// main function
int main(){
    // define variables
    int n, *a, *b, *d, *x, *d2;
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
    cout<<"\nReport of digits:"<<endl;
    report_digits(d);

    // drop the second lowest digit
    x = allocate_memory(n);
    copy_vector(n, a, x);
    vec_drop_2lowest_digit(n, x);
    cout<<"\nVector of numbers after dropping 2nd lowest digits: "<<endl;
    print_vector(n, x);

    // report of digit counts after drop 2nd lowest digit    
    d2 = allocate_memory(10);
    vec_count_digits(10, x, d2);
    cout<<"\nReport of digit counts after drop 2nd lowest digits: "<<endl;
    print_vector(10, d2);

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

// procedure to copy vector
void copy_vector(int n, int *x, int *y){
    for(int i=0; i<n; i++)
        y[i]=x[i];    
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

// vectorize procedure to generate vector with max digits
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

        // check if current digit is higher than the highest_digit
        if(dig>max_dig){    
            max_dig = dig;
        }

        aux = aux/10;
    }

    return max_dig;
}

// function to generate number using the vector of highest digits
long long generate_number(int n, int *x){
    long long num = 0, order=1;

    for(int i=0; i<n; i++){
        num = num + x[i]*order;
        order = order * 10;
    }

    return num;
}

// vectorize procedure to count the number of digits for each number
void vec_count_digits(int n, int *x, int *d){
    // initialize vector counter of #digits
    for(int i=0; i<10; i++)
        d[i] = 0;
    
    for(int i=0; i<n; i++){
        count_digits(x[i], d);
    }
}

// procedure to count the number of digits for 1 number
void count_digits(int num, int *d){
    int aux, dig;
    aux = num;

    while(aux>0){
        dig = aux%10;
        d[dig]++;   // counter #digits
        aux = aux/10;
    }
}

// procedure to report the #digits counted
void report_digits(int *d){
    for(int i=0; i<10; i++){
        cout<<"Digit "<<i<<" count "<<d[i]<<" elements"<<endl;
    }
}

// vectorize procedure to drop the 2nd lowest digit
void vec_drop_2lowest_digit(int n, int *x){
    int sec_lowest, pos;

    for(int i=0; i<n; i++){
        sec_lowest=10;
        pos=0;
        search_2lowest_digit(x[i], &sec_lowest);
        search_position_digit(x[i], sec_lowest, &pos);
        x[i] = drop_2lowest_digit(x[i], pos);
    }
}

// procedure to find the 2nd lowest digit for 1 number
void search_2lowest_digit(int num, int *seclow_dig){
    int aux, dig, low_dig;
    aux = num;

    // initialization
    low_dig = 10;
    *seclow_dig = 10;

    // number decomposition
    while(aux>0){
        dig = aux%10;

        if(dig<low_dig){
            *seclow_dig = low_dig;
            low_dig = dig;
        }else if(low_dig==dig){
            *seclow_dig = dig;
        }else if(dig>low_dig && dig < *seclow_dig){
            *seclow_dig = dig;
        }

        aux = aux/10;
    }
}

// procedure to find the positional order of 2nd lowest digit
void search_position_digit(int num, int search_digit, int *pos){
    int aux, dig, curr_pos=0;
    bool is_found=false;    // variable which control if searched digit was found
    aux = num;

    while(aux>0 && is_found == false){
        dig = aux%10;

        // searched digit was found
        if(search_digit == dig){
            *pos = curr_pos;
            is_found = true;
        }

        aux = aux/10;
        curr_pos++;
    }
}

// procedure to recalcule the number dropping the 2nd lowest digit
int drop_2lowest_digit(int num, int pos){
    int aux, dig, curr_pos=0;
    int number=0, order = 1;
    aux = num;

    while(aux>0){
        dig = aux%10;

        // compute number in all positional orders except in position of 2nd lowest digit
        if(curr_pos!= pos){
            number = number + dig * order;
            order = order*10;
        }

        aux = aux/10;
        curr_pos++;
    }

    return number;
}
