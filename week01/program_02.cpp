/*
    PROGRAM 02: KINETIC ENERGY OF ELECTRON
    Definition of variables
        - me: electron mass (input)
        - c: speed of light (input)
        - v: speed of electron (input)
        - Ek: kinetic energy of electron (output)
        - E: non-relative energy of electron (output)
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout<< "**** PROGRAM 02 **** \n";

    // definition of variables
    double me, c, v; 
    long double Ek, E;
    me = 9.1 * pow(10, -31);
    c = 2.998 * pow(10, 8);
    cout<< "Enter the speed of electron: \t";
    cin>> v;

    // calculation of kinetic energy of electron
    if(1 - pow(v/c, 2) > 0){
        Ek = me * pow(c, 2) * ( 1/sqrt(1 - pow(v/c, 2)) - 1);
    }else{
        cout<< "It's not possible calculate value of kinetic energy of electron \n";
    }

    // calculation of non-relative energy of electron
    E = me * pow(v, 2)/2;

    // print results
    cout<< "Kinetic energy of electron: \t"<< Ek << endl;
    cout<< "Non-relative energy of electron: \t"<< E << endl;

}
