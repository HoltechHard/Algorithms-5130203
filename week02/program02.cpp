/*
    WEEK 02 - PROGRAM 02: PRIME NUMBERS
    Develop a program that allows you to print prime numbers in the range [2, 100] on the terminal.

    Definition of variables:
        - n: analized number in the range [2, 100]
        - div: potential divisor of n
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    // definition of variables
    int n, div;

    // cycle to check each number in range [2, 100]
    cout<< "Prime numbers: "<< endl;    
    for(n=2; n<=100; n++){
        div = 2;
        // cycle to verify potential divisors [2, n-1]
        while(div < n){
            if(n % div == 0) break;   // stop program if find divisor
            div++;
        }

        // print prime number when unique divisor found was the same number
        if(div == n) 
            cout << n << "  ";
    }

    return 0;
}
