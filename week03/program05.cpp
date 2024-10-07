/*
    WEEK 03 - PROGRAM 05: POINTERS IN MATRICES
    Create a program that uses pointers to determine the number of rows and columns of a matrix. 
    Each element of the matrix is ​​calculated using the formula:
                e = i^2 - i - 2*j + m*n + rand()% (m + n)
    Print the largest and smallest value of an array. 

    Definition of variables: 
        - matrix: static matrix
        - n: #rows of static matrix
        - m: #columns of static matrix
        - matrix1: dynamic matrix
        - n1: #rows of dynamic matrix
        - m1: #columns of dynamic matrix
        - i, j: internal indexes for loops (for rows and columns respectively)
*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

const int n=2, m=3;

int main(){

    int matrix[n][m];
    srand(static_cast<unsigned int>(time(0)));

    //  --- Definition of matrix with static allocation of memory ---

    // calculate values for static matrix
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            matrix[i][j] = pow(i, 2)-i-2*j+m*n+rand()%(m+n); 
        }
    }

    // print static matrix
    cout<< "\n --- Static matrix ---"<<endl;
    for(int i=0; i<n;i++){
        cout<<endl;
        for(int j=0; j<m; j++){
            cout<<matrix[i][j]<<"  ";
        }
    }
    cout<<endl;

    // --- Definition of matrix with dynamic allocation of memory ---

    // dinamic matrix
    int n1, m1;

    // user define #rows, #columns
    cout<<"\n --- Dinamic matrix ---"<<endl;
    do{
        cout<<"\n#Rows = ";
        cin>>n1;
        cout<<"\n#Columns = ";
        cin>>m1;
    }while(n1<=0 | m1<=0);

    // allocate dynamically memory in matrix
    int **matrix1 = (int **) malloc(n1 * sizeof(int *));

    for(int i=0; i<n1; i++){
        matrix1[i] = (int *) malloc(m1 * sizeof(int));
    }

    // calculate values for dynamic matrix
    for(int i=0; i<n1; i++){
        for(int j=0; j<m1; j++){
            matrix1[i][j] = pow(i, 2)-i-2*j+m1*n1+rand()%(m1+n1); 
        }
    }

    // print dynamic matrix
    for(int i=0; i<n1; i++){
        cout<<endl;
        for(int j=0; j<m1; j++){
            cout<<matrix1[i][j]<< "  ";
        }
    }
    cout<<endl;

    // find highest and lowest element of matrix
    int max, min;
    max = min = matrix1[0][0];

    for(int i=0; i<n1; i++){
        for(int j=0; j<m1; j++){
            // check the highest
            if(matrix1[i][j] > max)
                max = matrix1[i][j];
            // check the lowest
            if(matrix1[i][j] < min){
                min = matrix1[i][j];
            }
        }
    }

    cout<< "\nMax value = "<<max<<endl;
    cout<< "Min value = "<<min<<endl;

    return 0;
}