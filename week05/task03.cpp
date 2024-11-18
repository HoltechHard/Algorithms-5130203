/*
    WEEK 05 - TASK 03: VECTORIZE CALCULATION OF DIVISORS

    Enter a vector of numbers and perform the following operations (without changing the 
    original values ​​of the vector):
    
    [1]. Factor each number into prime factors. Keep the prime factors that factor each number. 
         Print the factorization of each element of the vector.
    [2]. Calculate the minimum common multiple (vector version of MCM)
    [3]. Calculate the maximum common divisor (vector version of MCD)
    [4]. Create a vector Y that combines all the prime factorization vectors of a numeric vector X.
         Store in the vector the number of prime factors that appear in each element of vector X 
         (consider only the first 20 primes that exist for a given count).

    Definition of variables:
        - n: number of values for vector X
        - x: vector of input numbers
        - primes: vector of 20 first prime numbers
          order: 20 elements
        - factors: matrix of prime factor decomposition for each number of vector X
          order: [#elements of X vector] x [MAX elements]
        - num_fact: vector to calculate how many prime factors have the decomposition 
          for each value of vector X
          order: n elements
        - c_primes: matrix to count #prime factors in factor decomposition for each number 
          of vector X
          order: [#elements of X vector] x [20 prime numbers]
        - mcm_res: minimum common multiple for list of values in vector X
        - mcd_res: maximum common divisor for list of values in vector X
*/

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

const int MAX=100;

// header of functions defined by user
void input_num_elements(int *n);
int *allocate_vector(int n);
void input_vector(int n, int *x);
void print_vector(int n, int *x);
void list_primes(int *pf);
int get_num_divisors(int num);
int **allocate_matrix(int rows, int cols);
void vec_primes_decomposition(int n, int *x, int *primes, int **pf, int *num_f);
void primes_decomposition(int num, int *primes, int *pf, int *nf);
void print_primes_decomposition(int n, int *x, int **pf, int *num_f);
void counter_primes(int n, int **pf, int *primes, int *num_f, int **counter_primes);
int search_prime(int search, int *primes);
void print_matrix(int n, int m, int **matrix);
int mcm(int n, int **counter_primes, int *primes);
int mcd(int n, int **counter_primes, int *primes);
int max(int n, int *vec);
int min(int n, int *vec);

// main function
int main(){
    int n, *x, *primes, **factors, *num_fact, **c_primes, mcm_res, mcd_res;
    // input number of elements for vector
    input_num_elements(&n);

    // dynamic allocation of memory
    x = allocate_vector(n);

    // input the elements of vector A
    cout<<"\nInput the elements in vector: "<<endl;
    input_vector(n, x);
    cout<<"\nVector X: "<<endl;
    print_vector(n, x);

    // list of 20 first primes
    primes = allocate_vector(20);
    list_primes(primes);
    cout<<"\nVector of first 20 primes: "<<endl;
    print_vector(20, primes);

    // prime decomposition for vector of numbers
    factors = allocate_matrix(n, MAX);
    num_fact = allocate_vector(n);
    vec_primes_decomposition(n, x, primes, factors, num_fact);
    cout<<"\n***Primes decomposition***"<<endl;
    cout<<"\nNumber of factors: "<<endl;
    print_vector(n, num_fact);
    cout<<"\n--Primes factors-- "<<endl;
    print_primes_decomposition(n, x, factors, num_fact);

    // count number of occurences of each prime factor
    cout<<"\nCount the primes occurences in factors: "<<endl;
    c_primes = allocate_matrix(n, 20);
    print_vector(20, primes);
    counter_primes(n, factors, primes, num_fact, c_primes);
    print_matrix(n, 20, c_primes);

    // mcm
    mcm_res = mcm(n, c_primes, primes);
    cout<<"\nMinimum common multiple (MCM) = "<<mcm_res<<endl;
    
    // mcd
    mcd_res = mcd(n, c_primes, primes);
    cout<<"\nMaximum common divisor (MCD) = "<<mcd_res<<endl;

    return 0;
}

// procedure to input the number of elements for vectors
void input_num_elements(int *n){
    do{
        cout<<"\nNumber of elements: ";
        cin>>*n;
    }while(*n<=0);
}   

// function for dynamic allocation of memory for vectors using malloc
int *allocate_vector(int n){
    return (int *) malloc(n * sizeof(int));
}

// procedure to input the elements in 1 vector
void input_vector(int n, int *x){
    for(int i=0; i<n; i++){
        cout<<"X["<<i<<"]: ";
        cin>>x[i];
    }
}

// procedure to print the elements of vector
void print_vector(int n, int *x){
    for(int i=0; i<n; i++){
        cout<<x[i]<<"  ";
    }
    cout<<endl;
}

// procedure to create a list of first 20 prime numbers
void list_primes(int *pf){
    int num=2, counter=0, num_div;
    
    while(counter<20){
        num_div = get_num_divisors(num);

        // check if without counting itself, the number of divisors is 1, it is prime
        if(num_div==1){
            pf[counter] = num;
            counter++;
        }
        
        num++;
    }
}

// function to calculate number of divisors
int get_num_divisors(int num){
    int num_fact=0;

    for(int i=1;i<=num/2; i++){
        if(num%i==0){
            num_fact++;
        }
    }

    return num_fact;
}

// function for dynamic allocation of matrix
int **allocate_matrix(int rows, int cols){
    int **matrix = (int **) malloc(rows * sizeof(int *));

    for(int i=0; i<rows; i++){
        matrix[i] = (int *) malloc(cols * sizeof(int));
    }

    return matrix;
}

// procedure to vectorize descomposition of numbers in prime factors
void vec_primes_decomposition(int n, int *x, int *primes, int **pf, int *num_f){
    for(int i=0; i<n; i++){
        primes_decomposition(x[i], primes, pf[i], &num_f[i]);
    }
}

// procedure to decompose 1 single number in prime factors
void primes_decomposition(int num, int *primes, int *pf, int *nf){
    int aux, counter=0, idx=0;
    aux = num;

    // while number is completely decomposer in prime factors, find the prime factors
    while(aux>1 && counter<20){
        // check if the prime number is divisible
        if(aux%primes[counter]==0){
            pf[idx] = primes[counter];  // store the prime number as factor
            aux = aux/primes[counter];  // decompose, dividing by prime factor
            idx++;  // accounting prime factors when find one
        }else{
            counter++;  // counter variable to pass to the next prime factor when is not divisible
        }
    }
    *nf = idx;  // store how many prime factors have the prime decomposition
}

// procedure to print the matrix of prime number decomposition for each number of vector X
void print_primes_decomposition(int n, int *x, int **pf, int *num_f){
    for(int i=0; i<n; i++){
        cout<<"\nPrimes for number "<<x[i]<<": "<<endl;

        for(int j=0; j<num_f[i]; j++){
            if(j!=num_f[i]-1)
                cout<<pf[i][j]<<" x ";
            else
                cout<<pf[i][j];
        }
    }
}

// procedure to print matrix
void print_matrix(int n, int m, int **matrix){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}

// procedure to count primes and store the counts in matrix counter_primes
void counter_primes(int n, int **pf, int *primes, int *num_f, int **counter_primes){
    int pos;

    // initialize the couting of prime factors in zero in all positions
    for(int i=0; i<n; i++){
        for(int j=0; j<20; j++){
            counter_primes[i][j]=0;
        }
    }

    // couting the primes found in a specific position
    for(int i=0; i<n; i++){
        for(int j=0; j<num_f[i]; j++){            
            pos = search_prime(pf[i][j], primes);
            counter_primes[i][pos]++;
        }
    }
}

// function to search position of prime in vector of 20 first primes
int search_prime(int search, int *primes){
    for(int i=0; i<20; i++){
        if(search == primes[i])
            return i;
    }
}

// function to calculate min common multiple
int mcm(int n, int **counter_primes, int *primes){
    int max_exp, mcm=1;

    for(int i=0; i<20; i++){
        max_exp = 0;

        for(int j=0; j<n; j++){
            if(counter_primes[j][i]>max_exp){
                max_exp = counter_primes[j][i];
            }
        }

        if(max_exp!=0){
            for(int k=0; k<max_exp; k++)
                mcm *= primes[i];
        }
    }

    return mcm;
}

// function to calculate max common divisor
int mcd(int n, int **counter_primes, int *primes){
    int min_exp, mcd=1;
    bool common;

    for(int i=0; i<20; i++){
        min_exp = INT_MAX;
        common = true;

        for(int j=0; j<n && common==true; j++){
            if(counter_primes[j][i] == 0){
                common = false;
                min_exp = 0;
            }

            if(counter_primes[j][i]<min_exp){
                min_exp = counter_primes[j][i];
            }
        }

        if(min_exp!=0){
            for(int k=0; k<min_exp; k++)
                mcd *= primes[i];
        }
    }

    return mcd;
}

// function to find max value of vector
int max(int n, int *vec){
    int max=-1;

    for(int i=0; i<n; i++){
        if(vec[i]>max)
            max = vec[i];
    }

    return max;
}

// function to find min value of vector
int min(int n, int *vec){
    int min=INT_MAX;

    for(int i=0; i<n; i++){
        if(vec[i]<min)
            min = vec[i];
    }

    return min;
}
