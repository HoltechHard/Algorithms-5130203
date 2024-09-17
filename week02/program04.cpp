/*
    WEEK 02 - PROGRAM 04: TAYLOR SERIES
    Write a program to calculate the cosine function using Taylor's formula. 
    The argument x is entered by the user from the keyboard, and the series boundary n 
    is defined as a constant with a value equal to 20.
    Calculate the approximate value of cos(x).

    Definition of variables: 
        - x: argument of cosin function
        - last_term: value of the current term of taylor serie
        - result: final sum of all terms of taylor serie
*/

#include <iostream>
using namespace std;

const int n = 20;

int main(){
    // definition of variables
    double x, last_term;
    long double result=0.0;
    
    cout << "Enter a value for x: ";
    cin>> x;

    // term and taylor result when i = 0
    last_term = 1;
    result = last_term;

    // cycle to find each term of taylor serie
    cout<< "Serie terms:"<< endl;
    for(int i=1; i<=n; i++){
        last_term *= -1 * (x*x) / ((2*i-1)*(2*i));
        cout<< last_term << "  ";
        result += last_term;
    }

    cout<< "\nFinal result: "<< endl;
    cout<< "cos("<<x<<") = "<< result<< endl;

    return 0;
}
