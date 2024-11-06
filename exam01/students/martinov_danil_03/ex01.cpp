#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
const double G = 6.67e-11;  
const double M = 5.96e24;  
const double R = 6.37e6;

int main() {


    double m, h, d, o;
    cout << "введите массу тела: ";
    cin >> m;
    cout << "введите высоту над поверхностью земли: ";
    cin >> h;
    cout << " ведите пройденное расстоояние: ";
    cin >> d;
    cout << "ведите угол наклона: ";
    cin >> o;

    double o_true = o * 3.14/180.0; // ??work or not??
    double F = (G * m * M)/pow(R + h, 2);
    double W = F * d * cos(o_true);


    cout << "сила гравитации F: " << F << endl;
    cout << " работа W: " << W << endl;



    return 0;


}
