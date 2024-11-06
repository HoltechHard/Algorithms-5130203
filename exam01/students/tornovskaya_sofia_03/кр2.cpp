#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	vector<int> X(5);
	vector<int> Y(5);
	cout << "¬ведите 5 значений вектора X (от 10 до 100) : " << endl;
	for (int i = 0; i < 5; i++) {
		cin >> x[i] >> endl;
	}
	cout << "¬ведите 5 значений вектора Y (от 10 до 100) : " << endl;
	for (int i = 0; i < 5; i++) {
		cin >> y[j] >> endl;
	}
	int sumx = 0, sumy = 0;
	for (int i = 0; i < 5; i++) {
		sumx = sumx + X[i];
	}
	for (int i = 0; i < 5; i++) {
		sumy = sumy + Y[i];
	}
	float x, y;
	x = sumx / 5;
	y = sumy / 5;
	float k1, k2;
	k1 = x * min(X) / y / max(Y);
	int sum1=0, sum2=0, sum3=0, sum4=0;
	for (int i = 0; i < 5; i++) {
		sum1 = sum1 + pow(x[i], 2);
		sum2 = sum2 + x[i] * y[i];
		sum3 = sum3 + x[i];
		sum4 = sum4 + y[i];

	}
	k2 = (sum1 - sum2) / (pow(sum3, 2) + pow(sum4, 2));
	cout << "k1 = " << k1 << endl;
	cout << "k2 = " << k2 << endl;
}