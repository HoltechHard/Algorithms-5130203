/*
    EXAM 01 - Algorithms and Programming 5130203/40001
    VARIANT 03 - EXERCISE 02
*/

#include <iostream>
#include <cmath>
using namespace std;

int const N=5;

void input_vector(int x[N]);
void print_vector(int x[N]);
int calculate_sum(int x[N]);
int get_min(int x[N]);
int get_max(int x[N]);
int calculate_sum_squares(int x[N]);
int calculate_internal_prod(int x[N], int y[N]);
double calculate_k1(int x[N], int y[N]);
double calculate_k2(int x[N], int y[N]);

// main function
int main(){
    int x[N], y[N];
    double k1_res, k2_res;

    // input elements of vector
    cout<<"\nInput vector X: "<<endl;
    input_vector(x);
    cout<<"\nInput vector Y: "<<endl;
    input_vector(y);

    // show vectors
    cout<<"X: "<<endl;
    print_vector(x);
    cout<<"Y: "<<endl;
    print_vector(y);

    // calculate result
    k1_res = calculate_k1(x, y);
    cout<<"\nk1 = "<<k1_res<<endl;

    k2_res = calculate_k2(x, y);
    cout<<"\nk2 = "<<k2_res<<endl;

    return 0;
}

// procedure to input elements of vector
void input_vector(int x[N]){
    for(int i=0; i<N; i++){
        do{
            cout<<"x["<<i<<"]: ";
            cin>>x[i];
        }while(x[i]<10 || x[i]>100);
    }
}

// procedure to print vector
void print_vector(int x[N]){
    for(int i=0; i<N; i++){
        cout<<x[i]<<"  ";
    }
    cout<<endl;
}

// function to get sum of vector elements
int calculate_sum(int x[N]){
    int sum=0;

    for(int i=0; i<N; i++)
        sum += x[i];

    return sum;
}

// function to get min
int get_min(int x[N]){
    int min = x[0];

    for(int i=1; i<N; i++){
        if(x[i]<min)
            min = x[i];
    }

    return min;
}

// function to get max
int get_max(int x[N]){
    int max = x[0];

    for(int i=1; i<N; i++){
        if(x[i]>max)
            max = x[i];
    }

    return max;
}

// function to calculate sum squares of vector
int calculate_sum_squares(int x[N]){
    int sum=0;

    for(int i=0; i<N; i++)
        sum += pow(x[i], 2);

    return sum;
}

// function to calculate internal product
int calculate_internal_prod(int x[N], int y[N]){
    int ip=0;

    for(int i=0; i<N; i++)
        ip += x[i]*y[i];

    return ip;
}

// function to calculate k1
double calculate_k1(int x[N], int y[N]){    
    double x_mean, x_min, y_mean, y_max, k1;

    x_mean = calculate_sum(x)/N;
    x_min = get_min(x);
    y_mean = calculate_sum(y)/N;
    y_max = get_max(y);
    k1 = (x_mean * x_min)/(y_mean * y_max);

    return k1;
}

// function to calculate k2
double calculate_k2(int x[N], int y[N]){
    double sum_x2, sum_xy, sum_x, sum_y, k2;

    sum_x2 = calculate_sum_squares(x);
    sum_xy = calculate_internal_prod(x, y);
    sum_x = calculate_sum(x);
    sum_y = calculate_sum(y);
    k2 = (sum_x2 - sum_xy)/(pow(sum_x, 2) + pow(sum_y, 2));

    return k2;
}
