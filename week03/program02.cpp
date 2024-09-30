/*
    WEEK 03 - PROGRAM 02: SINGLE AND DOUBLE POINTERS
    1) Show the values ​​of the variables, the memory address where they were stored, 
        and the amount of memory allocated for each variable.
    2) Assign the pointer p to the memory address of the variable a. 
        Assign the pointer q to the memory address of the variable p. 
        Access the contents of the variables and make changes to the values ​​of p, q. 
        Check what happened to the values ​​of the variables a, x, p, q.
    3) Change the memory addresses of the variables p, q to different addresses. 
        The pointer p should point to the variable x and get its value. 
        The pointer q should point to the variable a and get its value.

    Definition of variables:
        - a, x, b, c, d, e: native variables
        - *p: single pointer variable
        - **q: double pointer variable
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a = 2000, x;
    int *p, **q;
    char b = 'H';
    float c = acos(-1);     // definition of value PI
    double d = acos(-1);
    long double e = acos(-1);
    x = a;

    //      values of variables -       adress -               #bytes of memory
    cout<< "Variable a = "<< a<<" stay in adress "<< &a<<" and have "<< sizeof(a)<<" bytes" <<endl;
    cout<< "Variable x = "<< x<<" stay in adress "<< &x<<" and have "<< sizeof(x)<<" bytes" <<endl;
    cout<< "Variable b = "<< b<<" stay in adress "<<hex<< (int)&b<<" and have "<< sizeof(b)<<" bytes"<<endl;
    cout<< "Variable c = "<< c<<" stay in adress "<< &c<<" and have "<< sizeof(c)<<" bytes"<<endl;
    cout<< "Variable d = "<< d<<" stay in adress "<< &d<<" and have "<< sizeof(d)<<" bytes"<<endl;
    cout<< "Variable e = "<< e<<" stay in adress "<< &e<<" and have "<<dec<< sizeof(e)<<" bytes"<<endl;

    // check the pointer variables and its data
    p = &a;
    q = &p;
    cout<< "-- Operations with pointers --"<<endl;
    cout<< "In adress "<< p<< " have value = "<<dec<< *p<<endl;
    cout<< "In adress "<< q<<" make reference in adress "<<*q<< " and have value = "<<dec<<**q<<endl;
        
    // modify values of pointers p, q
    (*p) -= 50;
    (**q) += 10;

    // modify adresses of pointers p, q
    p += 50;
    q -= 50;

    // new pointers assignation
    p = &x;     // assign adress of x to p

    int *r;
    r = &a;
    q = &r;     // assign adress of a to q ==> you can use *q = &a

    cout<< "In adress p: "<< p<< " have value = "<<dec << *p<<endl;
    cout<< "In adress q: "<< q<< " make reference "<<*q<< " and have value = "<<dec << **q<<endl;

    return 0;
}