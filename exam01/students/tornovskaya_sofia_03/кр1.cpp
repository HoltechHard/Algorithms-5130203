#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float G = 6.67 * pow(10, -11), M = 5.69 * pow(10, 24), R = 6.37 * pow(10, 6), F, m, d, h, W, O;
	cout << "Enter m: ";
	cin >> m;
	cout << "\nEnter h: ";
	cin >> h;
	cout << "\nEnter d: ";
	cin >> d;
	cout << "\nEnter O: ";
	cin >> O;

	F = G * m * M / pow((R + h), 2);
	W = F * d * cos(O);

	cout << "F = " << F << endl;
	cout << "W = " << W << endl;

}