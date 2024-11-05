#include <iostream>
#include <cmath>
using namespace std;
int main(){
double h,o,m,d;
long double F,W;
double G = 6.67 * pow(10,-11);
double M = 5.96 * pow(10,24);
double R = 6.37 * pow(10,6);
cout << " enter m\t";
cin >> m;
cout << " enter h\t"; 
cin >> h;
cout << " enter o\t";
cin >> o;
cout << " enter d\t";
cin >> d;
F=(G*m*M)/pow(R+h,2);
W=F*d*cos(o);
cout << " F= " << F;
cout << " W= " << W;
}