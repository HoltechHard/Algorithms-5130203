/*
    WEEK 05 - TASK 04: CALCULATION OF MATRIX DETERMINANT

    [1]. Write a program to calculate the determinant of a 2x2 matrix.
    [2]. Write a program to calculate the determinant of a 3x3 matrix.
    [3]. Write a general program to calculate the determinant of the matrix nxn.

    Definition of variables:
        - n: dimensionality of matrix
        - a: matrix A
        - det: result of calculate determinant for matrix A
*/

#include <iostream>
#include <cmath>
using namespace std;

// head of functions defined by user
void input_dimension(int *n);
long double **allocate_matrix(int n);
void input_matrix(int n, long double **x);
void print_matrix(int n, long double **x);
long double calculate_determinant(int n, long double **x);
long double calculate_det_2x2(long double **x);
long double calculate_det_3x3(int n, long double **x);
long double **generate_submatrix(int idx, int n, long double **x);
long double calculate_det_nxn(int n, long double **x);
int get_pivot_position(int col_idx, int n, long double **x);
void mov_rows(int row_idx, int piv_pos, int n, long double **x);
void gauss_jordan_algorithm(int n, long double **x, long double *sign);
void free_memory(int n, long double **x);

// main function
int main(){
    int n;
    long double **a, det;

    // input dimensionality
    input_dimension(&n);

    // input matrix
    a = allocate_matrix(n);
    cout<<"\nInput matrix elements: "<<endl;
    input_matrix(n, a);
    cout<<"\nA = "<<endl;
    print_matrix(n, a);

    // calculate determinant
    det = calculate_determinant(n, a);
    cout<<"\nDeterminant of matrix = "<<det<<endl;
    free_memory(n, a);

    return 0;
}

// procedure to input matrix dimension
void input_dimension(int *n){
    do{
        cout<<"\nDimension of matrix: ";
        cin>>*n;
    }while(*n<=1);
}

// function for dynamic allocation of memory
long double **allocate_matrix(int n){
    long double **x = new long double*[n+1];

    for(int i=1; i<=n; i++){
        x[i] = new long double[n+1];
    }

    return x;
}

// procedure to input elements in matrix
void input_matrix(int n, long double **x){
    for(int i=1; i<=n; i++){
        cout<<"Row "<<i<<": "<<endl;

        for(int j=1; j<=n; j++){
            cout<<"x["<<i<<"]["<<j<<"]: ";
            cin>> x[i][j];
        }
    }
}

// procedure to print elements of matrix
void print_matrix(int n, long double **x){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<x[i][j]<<"  ";
        }
        cout<<endl;
    }    
}

// function to calculate determinant
long double calculate_determinant(int n, long double **x){
    long double det;

    switch(n){
        case 2:
            det = calculate_det_2x2(x);
            break;
        case 3:
            det = calculate_det_3x3(n, x);
            break;
        default:
            det = calculate_det_nxn(n, x);
            break;
    }

    return det;
}

// function to calculate determinant of 2 x 2 matrix
long double calculate_det_2x2(long double **x){    
    return x[1][1]*x[2][2] - x[1][2]*x[2][1];
}

// function to calculate determinant of 3 x 3 matrix
long double calculate_det_3x3(int n, long double **x){
    long double det=0;
    
    for(int i=1; i<=n; i++){
        long double **aux = generate_submatrix(i, n, x);
        det += pow(-1, i+1) * x[1][i] * calculate_det_2x2(aux);
        free_memory(2, aux);
    }

    return det;
}

// function to generate 2 x 2 submatrix
long double **generate_submatrix(int idx, int n, long double **x){
    int ri, ci;
    long double **y;
    y = allocate_matrix(n-1);
    ri=1;

    for(int i=1; i<=n; i++){
        if(i!=1){
            ci=1;
            for(int j=1; j<=n; j++){
                if(j!=idx){
                    y[ri][ci] = x[i][j];                    
                    ci++;
                }
            }
            ri++;
        }
    }

    return y;
}

// function to calculate determinant using Gauss-Jordan method
long double calculate_det_nxn(int n, long double **x){
    long double det=1, sign=1;

    gauss_jordan_algorithm(n, x, &sign);

    for(int i=1; i<=n; i++){
        det *= x[i][i];
    }

    return sign * det;
}

// function to get pivot position
int get_pivot_position(int col_idx, int n, long double **x){
    int piv_pos;
    long double pivot;
    pivot = x[col_idx][col_idx];

    for(int i=col_idx+1; i<=n; i++){
        if(abs(x[i][col_idx]) > abs(pivot)){
            pivot = x[i][col_idx];
            piv_pos = i;
        }
    }

    return piv_pos;
}

// procedure to move rows
void mov_rows(int row_idx, int piv_pos, int n, long double **x){
    long double *aux;

    aux = x[row_idx];
    x[row_idx] = x[piv_pos];
    x[piv_pos]  = aux;
}

// Gauss-Jordan algorithm
void gauss_jordan_algorithm(int n, long double **x, long double *sign){
    int piv_pos;

    for(int i=1; i<=n; i++){    // loop for each row
        piv_pos = get_pivot_position(i, n, x);

        if(piv_pos != i){   // pivots need have position ii
            mov_rows(i, piv_pos, n, x);
            (*sign) *= -1;    // for each interchanging of rows
        }        

        // recalculate the values of row using pivot
        for(int j=i+1; j<=n; j++){
            for(int k=i+1; k<=n; k++){
                if(x[i][i] == 0){
                    cout<<"\nIt is not possible calculate"<<endl;
                    exit(1);
                }else{
                    x[j][k] -= x[j][i]*x[i][k]/x[i][i];
                }                
            }
            x[j][i] = 0;
        }
    }
}

// procedure to clean memory
void free_memory(int n, long double **x){
    for(int i=1; i<=n; i++){
        delete[] x[i];
    }

    delete[] x;
}
