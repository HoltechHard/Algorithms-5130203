/*
    First program in C++
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float x, y, z;
    cout<< "Print value of x: "<<endl;
    cin>>x;
    cout << "Hello, World!" << endl;
    y = sqrt(x);
    z = pow(x, 2);
    cout<< "Square = "<< y << endl;
    cout<< "Power in 2 = "<< z << endl;

    return 0;

}
