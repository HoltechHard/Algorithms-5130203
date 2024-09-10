/*
    PROGRAM 03: CALCULATION OF FUNCTIONS DEFINED BY PART
    Given the definition of functions F(a, b) and G(x)
    Calculate f+G, f*g, f/g

    Definition of variables
        - a, b: arguments of function F
        - F: output variable for F(a, b)
        - x: argument of function G
        - G: output variable for G(x)
 */

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout<< "**** PROGRAM 03 ****"<< endl;
    
    // define variables
    float a, b, x, F,G;
    cout<<"Enter a: \t";
    cin>> a;
    cout<<"Enter b: \t";
    cin>> b;
    cout<<"Enter x: \t";
    cin>> x;

    // calculate function F
    if(a < b){
        F = sqrt(a) * b;
    }else if(b < 0){
        F = pow(a, 2) + b;
    }else{
        F = a - b;
    }

    // calculate function G
    if(x <= 1){
        G = 0;
    }else if(x <= 2){
        G = 2*x - 2;
    }else if(x <= 3){
        G = 2;
    }else if(x <= 4){
        G = -2*x + 8;
    }else{
        G = 0;
    }

    // calculate and print results for F+G, F*G, F/G
    cout<< "Results: "<< endl;
    cout<< "F + G = " << F + G << endl;
    cout<< "F * G = " << F * G << endl;
    cout<< "F / G = " << F / G << endl;

    return 0;
}
