/*
    WEEK 02 - PROGRAM 01: DIVISORS OF NUMBER
    Develop a program that, when a number in the range [2, 1000] is entered, 
    displays all the divisors of the number, the number of divisors, 
    and the sum of the specified divisors.

    Definition of variables:
        - n: input number [2, 1000]
        - i: analized number as potential divisor [1, n]
        - num_divisors: number of divisors
        - sum_divisors: sum of all divisors
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, i, num_divisors=0, sum_divisors=0;

    do{
        cout<< "Enter the n: ";
        cin>> n;
        
    }while(n<2 || n>1000);

    cout<< "Divisors: "<< endl;
    for(i=1; i<=n; i++){
        if(n % i == 0){
            cout<< i << " ";
            num_divisors++;
            sum_divisors += i;
        }
    }
    
    cout<< "\nNumber of divisors: "<< num_divisors<< endl;
    cout<< "Sum of divisors: "<< sum_divisors<< endl;

    return 0;
}
