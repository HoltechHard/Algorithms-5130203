#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float F, m, h, W, d, angle, G, M, R;

    G = 6.67 * pow(10, -11);
    M = 5.97 * pow(10, 24);
    R = 6.37 * pow(10, 6);

    cout << "Enter m: ";
    cin >> m;

    cout << "Enter h: ";
    cin >> h;

    cout << "Enter d: ";
    cin >> d;

    cout << "Enter angle: ";
    cin >> angle;
    
    float r = R + h; 
    F = G * (m * M) / pow(r, 2);

    W = F * d;

    angle = angle * M_PI / 180.0;

    float F_component = F * cos(angle);

    cout << "F = " << F << endl;
    cout << "W = " << W << endl;


}
