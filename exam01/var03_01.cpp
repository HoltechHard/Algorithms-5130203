/*
    EXAM 01 - Algorithms and Programming 5130203/40001
    VARIANT 03 - EXERCISE 01
*/

#include <iostream>
#include <cmath>
using namespace std;

long double calculate_force(long double G, double m, long double M, long double R, double h);
long double calculate_work(long double F, double d, double theta);

// main function
int main(){
    long double G, M, R, F, W;
    double m, h, d, theta;

    // define constants
    G = 6.67*pow(10, -11);
    M = 5.96*pow(10, 24);
    R = 6.37*pow(10, 6);

    // calculate the gravity force
    cout<<"\nMass of body = ";
    cin>>m;
    cout<<"\nHeight = ";
    cin>>h;
    F = calculate_force(G, m, M, R, h);
    cout<<"F = "<<F<<endl;

    // calculate the work of gravity force
    cout<<"\nDistance = ";
    cin>>d;
    cout<<"\nTheta (rad) = ";
    cin>>theta;
    W = calculate_work(F, d, theta);
    cout<<"W = "<<W<<endl;

    return 0;
}

long double calculate_force(long double G, double m, long double M, long double R, double h){
    return (G*m*M)/pow(R+h, 2);
}

long double calculate_work(long double F, double d, double theta){
    return F*d*cos(theta);
}
