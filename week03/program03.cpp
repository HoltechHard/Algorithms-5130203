/*
    WEEK 03 - PROGRAM 03: POINTERS FOR VECTORS + BUBBLE SORT
    1) Create a program that generates random numbers between 1 and 100 and 
        stores them in a one-dimensional vector containing 10 elements. 
        Display the memory address and contents of each element of the vector in the terminal.
    2) After entering random values, sort the elements of the vector in ascending order 
        using the bubble sort method. Show the value at the middle position of the vector. 
        Use pointers.

    Definition of variables:
        - n: number of elements for vector x
        - x: vector of integer values
        - i, j: indexes variables
        - aux: auxiliary/temporary variable
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int n = 10;  // static variable

int main(){    
    // definition of variables and static definition of vector
    int x[n], i, j, aux;

    // seed for random number generation
    srand(static_cast<unsigned int>(time(0)));

    // random generation of elements of vector
    cout<<"\n Vector of numbers: "<<endl;
    for(i=0; i<n; i++){
        *(x+i) = 1 + rand()%100;
        cout<<"\nIn adress "<<(x+i)<<" have values "<<*(x+i)<<"  ";
    }
    cout<<endl;

    // algorithm bubble sort
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(*(x+i) > *(x+j)){
                aux = *(x+j);
                *(x+j) = *(x+i);
                *(x+i) = aux;
            }
        }
    }

    // print sorted results
    for(i=0; i<n; i++){
        cout<< *(x+i)<< "  ";
    }

    cout<<endl;

    return 0;
}