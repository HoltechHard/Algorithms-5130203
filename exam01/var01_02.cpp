/*
    EXAM 01 - Algorithms and Programming 5130203/40001
    VARIANT 01 - EXERCISE 02
*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

const int n=5;

void input_profession(int a[n]);
void input_salary(int b[n]);
void calculate_tax(int a[n], int b[n], double tax[n]);
void calculate_payment(int b[n], double tax[n], double c[n]);
void print_vector1(int x[n]);
void print_vector2(double x[n]);

// main function
int main(){
    int a[n], b[n];
    double tax[n], c[n];

    // random seed
    srand(static_cast<unsigned int>(time(0)));

    // input vector A
    cout<<"\nProfessions of employeers [1-project manager | 2-full stack | 3-ML engineer]: ";
    input_profession(a);
    print_vector1(a);

    // input vector B
    cout<<"\nSalaries of employeers [100000, 350000]: ";
    input_salary(b);
    print_vector1(b);

    // calculate vector tax
    cout<<"\nTax rates of employeers: ";
    calculate_tax(a, b, tax);
    print_vector2(tax);

    // calculate benefits
    cout<<"\nFinal payments of employeers: ";
    calculate_payment(b, tax, c);
    print_vector2(c);

    return 0;
}

// procedure to input vector of professions
void input_profession(int a[n]){
    for (int i = 0; i < n; i++) {
        a[i] = 1 + rand()%3;
    }
}

// procedure to input vector of salaries
void input_salary(int b[n]){
    for (int i = 0; i < n; i++) {
        b[i] = 100000 + rand()%(350000-100000);
    }
}

// procedure to calculate taxes
void calculate_tax(int a[n], int b[n], double tax[n]){
    for (int i = 0; i < n; i++) {
        switch(a[i]){
            case 1:
                tax[i] = 0.10;
                break;
            case 2:
                tax[i] = 0.05;
                break;
            case 3:
                tax[i] = 0.02;
                break;       
        }

        tax[i] *= b[i];
    }
}

// procedure to calculate payments to employeers
void calculate_payment(int b[n], double tax[n], double c[n]){
    for (int i = 0; i < n; i++) {
        c[i] = (double) b[i] - tax[i];
    }
}

// print vector
void print_vector1(int x[n]){
    for (int i = 0; i < n; i++) {
        cout<<x[i]<<"  ";
    }
    cout<<endl;
}

// print vector
void print_vector2(double x[n]){
    for (int i = 0; i < n; i++) {
        cout<<x[i]<<"  ";
    }
    cout<<endl;
}
