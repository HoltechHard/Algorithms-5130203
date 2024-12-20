/*
    WEEK 05 - TASK 01: BASIC OPERATIONS WITH MATRICES

    [1]. Enter the elements of matrices A and B from the keyboard, taking into account the elements 
         in the range [10, 100]. Create a procedure to print the elements of arrays A, B in a tabular format.
    [2]. Create a procedure to calculate the sum of the elements in each row and store the results in a vector.
         Apply the procedure to matrices A and B and print the vector of results.
    [3]. Create a procedure to calculate the sum of the elements in each column and store the results in a vector. 
         Apply the procedure to matrices A and B and print the results.
    [4]. Develop a procedure that calculates the sum of transposed matrices, storing the result in the matrix 
         S = A^T + B^T
    [5]. Create a procedure to add a row to the matrix A at a given position. The row to be added should be stored
         in a vector of dimension n, generated by random numbers from 10 to 100.
    [6]. Create a procedure to add a column to matrix B at a given position. The column to be added should be
         stored in a vector of dimension n, generated by random numbers from 10 to 100.
    [7]. Given updated matrices A of size (n+1) x n and matrix B of size n x (n+1), calculate the matrix product
         and store the result in matrix P of size (n+1) x (n+ 1).

    Definition of variables:
        - n: dimensionality of matrix (n x n)
        - a: matrix A
        - b: matrix B
        - sum_rows_a, sum_rows_b: vector which contains the sum of elements for each row for matrices A and B
        - sum_cols_a, sum_cols_b: vector which contains the sum of elements for each colum for matrices A and B
        - at, bt: transpose matrices of A, B matrices
        - s: matrix sum
        - p: matrix product
        - new_ra: vector with random numbers to add new row to matrix A
        - new_cb: vector with random numbers to add new column to matrix B
        - posa: position to add new row in matrix A
        - posb: position to add new column in matrix B
*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

// head of functions defined by user
void input_dimension(int *n);
int **allocate_matrix(int n);
void input_matrix(int n, int **x);
void print_matrix(int n, int m, int **x);
int *allocate_vector(int n);
void calculate_sum_by_rows(int n, int **x, int *vec_rows);
void calculate_sum_by_cols(int n, int **x, int *vec_cols);
void print_vector(int n, int *x);
void transpose_matrix(int n, int **x, int **trx);
void sum_matrices(int n, int **x, int **y, int **s);
void rand_vec_generate(int n, int *x);
int **insert_row(int n, int **x, int *row, int pos);
int **insert_col(int n, int **x, int *col, int pos);
void free_matrix(int n, int **x);
void product_matrices(int n, int **x, int **y, int **p);

// main function
int main(){
    int n, **a, **b, *sum_rows_a, *sum_rows_b, *sum_cols_a, *sum_cols_b, **at, **bt, **s, **p, *new_ra, *new_cb, posa, posb;

    // define random seed
    srand(static_cast<unsigned int>(time(0)));

    // input matrix dimensionality
    input_dimension(&n);

    // define matrices A, B
    a = allocate_matrix(n);
    b = allocate_matrix(n);
    cout<<"\nInput matrix A: "<<endl;
    input_matrix(n, a);
    cout<<"\nInput matrix B: "<<endl;
    input_matrix(n, b);
    cout<<"A: "<<endl;
    print_matrix(n, n, a);
    cout<<"B: "<<endl;
    print_matrix(n, n, b);

    // calculate sum of rows
    sum_rows_a = allocate_vector(n);
    sum_rows_b = allocate_vector(n);
    calculate_sum_by_rows(n, a, sum_rows_a);
    calculate_sum_by_rows(n, b, sum_rows_b);
    cout<<"\nSum of rows of A: ";
    print_vector(n, sum_rows_a);
    cout<<"\nSum of rows of B: ";
    print_vector(n, sum_rows_b);
    
    // calculate sum of cols
    sum_cols_a = allocate_vector(n);
    sum_cols_b = allocate_vector(n);
    calculate_sum_by_cols(n, a, sum_cols_a);
    calculate_sum_by_cols(n, b, sum_cols_b);
    cout<<"\nSum of cols of A: ";
    print_vector(n, sum_cols_a);
    cout<<"\nSum of cols of B: ";
    print_vector(n, sum_cols_b);

    // calculate S = AT + BT
    at = allocate_matrix(n);
    transpose_matrix(n, a, at);
    bt = allocate_matrix(n);
    transpose_matrix(n, b, bt);
    s = allocate_matrix(n);
    sum_matrices(n, at, bt, s);
    
    cout<<"A^T = "<<endl;
    print_matrix(n, n, at);
    cout<<"B^T = "<<endl;
    print_matrix(n, n, bt);
    cout<<"\nS = AT + BT: "<<endl;
    print_matrix(n, n, s);

    // new row for A
    new_ra = allocate_vector(n);
    rand_vec_generate(n, new_ra);
    cout<<"\nNew row for A: ";
    print_vector(n, new_ra);
    cout<<"\nInsert the position: ";
    cin>>posa;
    a = insert_row(n, a, new_ra, posa);
    cout<<"\nA after inserting new row: "<<endl;
    print_matrix(n+1, n, a);

    // new col for B
    new_cb = allocate_vector(n);
    rand_vec_generate(n, new_cb);
    cout<<"\nNew col for B: ";
    print_vector(n, new_cb);
    cout<<"\nInsert the position: ";
    cin>>posb;
    b = insert_col(n, b, new_cb, posb);
    cout<<"\nB after inserting new col: "<<endl;
    print_matrix(n, n+1, b);

    // product of matrices
    p = allocate_matrix(n+1);
    product_matrices(n, a, b, p);
    cout<<"\nProduct of A and B: "<<endl;
    print_matrix(n+1, n+1, p);
    
    return 0; 
}

// procedure to input the dimensionality of matrix
void input_dimension(int *n){
    do{
        cout<<"\nInput the dimension of matrix: ";
        cin>>*n;
    }while(n<=0);
}

// function to allocate dynamically memory for matrix
int **allocate_matrix(int n){
    int **m = (int **) malloc(n * sizeof(int *));

    for(int i=1; i<=n; i++){
        m[i] = (int *) malloc(n * sizeof(int));
    }

    return m;
}

// procedure to input elements in matrix
void input_matrix(int n, int **x){
    for(int i=1; i<=n; i++){
        cout<<"Row "<<i<<": "<<endl;

        for(int j=1; j<=n; j++){
            do{
                cout<<"x["<<j<<"]: ";
                cin>>x[i][j];
            }while(x[i][j]<10 || x[i][j]>100);            
        }
        cout<<endl;
    }
}

// procedure to print elements of matrix
void print_matrix(int n, int m, int **x){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

// function to allocate dynamically memory to vector
int *allocate_vector(int n){
    return (int *) malloc(n * sizeof(int));
}

// procedure to calculate the sum of row elements
void calculate_sum_by_rows(int n, int **x, int *sum_rows){
    for(int i=1; i<=n; i++){
        sum_rows[i] = 0;

        for(int k=1; k<=n; k++){
            sum_rows[i] += x[i][k];
        }
    }    
}

// procedure to calculate the sum of column elements
void calculate_sum_by_cols(int n, int **x, int *sum_cols){
    for(int i=1; i<=n; i++){
        sum_cols[i] = 0;

        for(int k=1; k<=n; k++){
            sum_cols[i] += x[k][i];
        }
    }
}

// procedure to print elements of vector
void print_vector(int n, int *x){
    for(int i=1; i<=n; i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

// procedure to transpose matrix
void transpose_matrix(int n, int **x, int **trx){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            trx[j][i] = x[i][j];
        }
    }
}

// procedure to calculate sum between 2 matrices
void sum_matrices(int n, int **x, int **y, int **s){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            s[i][j] = x[i][j] + y[i][j];
        }
    }
}

// procedure to generate elements in vector randomly
void rand_vec_generate(int n, int *x){
    for(int i=1; i<=n; i++){
        x[i] = rand() % (100-10) + 10;
    }
}

// function to insert new row to matrix
int **insert_row(int n, int **x, int *row, int pos){
    int **new_x = allocate_matrix(n+1);

    for(int i=n+1; i>=1; i--){
        for(int j=1; j<=n; j++){
            if(i<pos){
                new_x[i][j] = x[i][j];
            }else if(i==pos){
                new_x[pos][j] = row[j];
            }else if(i>pos){
                new_x[i][j] = x[i-1][j];
            }
        }
    }

    free_matrix(n, x);

    return new_x;
}

// function to insert new column to matrix
int **insert_col(int n, int **x, int *col, int pos){
    int **new_x = allocate_matrix(n+1);

    for(int i=n+1; i>=1; i--){
        for(int j=1; j<=n; j++){
            if(i<pos){
                new_x[j][i] = x[j][i];
            }else if(i==pos){
                new_x[j][pos] = col[j];
            }else if(i>pos){
                new_x[j][i] = x[j][i-1];
            }
        }
    }

    free_matrix(n, x);

    return new_x;
}

// procedure to clean occupied memory
void free_matrix(int n, int **x){
    for(int i=1; i<=n; i++){
        free(x[i]);
    }

    free(x);
}

// procedure to calculate product between 2 matrices
void product_matrices(int n, int **x, int **y, int **p){
    for(int i=1; i<=n+1; i++){
        for(int j=1; j<=n+1; j++){
            p[i][j] = 0;

            for(int k=1; k<=n; k++){
                p[i][j] += x[i][k]*y[k][j];
            }
        }
    }
}
