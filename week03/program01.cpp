/*
    WEEK 03 - PROGRAM 01: POINTERS OF VARIABLES
    Develop a program which the variable's pointer to data contains the address of another variable.

    Definition of variables:
        - v, x: native variables
        - *p: pointer variable
*/

#include <iostream>
using namespace std;

int main(){

    int v, *p, x;
    v = 600;    
    p = &v;
    x = *p;

    *p += 200;
    
    cout<< "\nVariable --> adress: "<<&v<<" have value = "<<v;
    cout<< "\nPointer --> address: "<<p<<" have value = "<<*p;
    cout<< "\nVariable --> address: "<<&x<<" have value = "<<x;
    return 0;
}
