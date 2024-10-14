/*
    WEEK 04 - PROGRAM 01: INTRO TO FUNCTIONS AND PROCESSES
    Develop a program that make the next 3 operations:
    1. Define a function that increment the variable n in 2 units using functions
       with call by value. The argument n cannot be altered.
    2. Define a function that increment the variable n in 2 units using functions
       with call by reference. The argument n needs to undergo modifications.
    3. Define a procedure that gets the increment of variable n in 2 units without
       altering the value of n. 

    Definition of variables:
        - n: original integer number entered by user
        - x1: variable that will store the result of incrementing n using a function 
              with call by value
        - x2: variable that will store the result of incrementing n using a function
              with call by reference
        - res: output variable of increment_by_process() that will store the result
               of increasing variable n
*/

#include <iostream>
using namespace std;

// header of functions defined by user
int increment_by_value(int n);
int increment_by_reference(int *n);
void increment_by_process(int n, int *res);

// main function
int main(){
    // define variables
    int n, x1, x2, res;

    // input the int number
    do{
        cout<<"N = ";
        cin>>n;
    }while(n<=0);

    // function with call by value
    cout<<"\nCall by value: "<<endl;
    x1 = increment_by_value(n);    // in call by value, sent the variable
    cout<<"n = "<<n<<"  --> "<<x1<<endl;

    // function with call by reference
    cout<<"\nCall by reference: "<<endl;
    x2 = increment_by_reference(&n);    // in the call by reference, sent the memory adress of the variable
    cout<<"n = "<<n<<"  --> "<<x2<<endl;

    // procedure with execution like process
    cout<<"\nExecute process: "<<endl;
    increment_by_process(n, &res);  // in the process, sent the inputs as variables and memory adresses of outputs
    cout<<"n = "<<n<<"  --> "<<res<<endl;

    return 0;
}

// function to increment variable n with call by value
int increment_by_value(int n){
    n = n + 2;
    return n;
}

// function to increment variable n with call by reference
int increment_by_reference(int *n){
    *n = *n + 2;
    return *n;
}

// procedure to obtain the increment of variable n
void increment_by_process(int n, int *res){
    *res = n + 2;
}
