#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

#define M_PI acos(-1)

int main() {
    float F, m, h, W, d, angle, G, M, R;

    G = 6.67 * pow(10, -11);
    M = 5.97 * pow(10, 24);
    R = 6.37 * pow(10, 6);

    cout << "Enter the mass of the object (in kilograms): ";
    cin >> m;

    cout << "Enter the height from which the object is dropped (in meters): ";
    cin >> h;

    cout << "Enter the weight of the object (in Newtons): ";
    cin >> W;

    cout << "Enter the distance between two objects (in meters): ";
    cin >> d;

    cout << "Enter the angle between the two objects (in degrees): ";
    cin >> angle;
    
    float r = R + h; 
    F = G * (m * M) / pow(r, 2);

    W = F * d;

    angle = angle * M_PI / 180.0;

    float F_component = F * cos(angle);

    cout << "Force of gravity (F): " << F << " N" << endl;
    cout << "Work done (W): " << W << " J" << endl;


}
