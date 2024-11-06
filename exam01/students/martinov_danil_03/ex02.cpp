#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    const int SIZE = 5;
    vector<double> X(SIZE), Y(SIZE);

    cout << "Введите 5 элементов для вектора X от 10 до 100: ";
    for (int i = 0; i < SIZE; ++i) {
        cin >> X[i];
        if (X[i] < 10 || X[i] > 100) {
            cout << "Значение от 10 до 100." << endl;
            return 1;
        }
    }

    cout << "Введите 5 элементов для вектора Y от 10 до 100: ";
    for (int i = 0; i < SIZE; ++i) {
        cin >> Y[i];
        if (Y[i] < 10 || Y[i] > 100) {
            cout << "Значение от 10 до 100." << endl;
            return 1;
        }
    }

    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum_x += X[i];
        sum_y += Y[i];
    }
    double x_avg = sum_x / SIZE;
    double y_avg = sum_y / SIZE;

    double x_min = X[0];
    double y_max = Y[0];
    for (int i = 1; i < SIZE; ++i) {
        if (X[i] < x_min) x_min = X[i];
        if (Y[i] > y_max) y_max = Y[i];

    }

    double k1 = (x_avg / x_min) * (y_avg / y_max);
    double sum_x_squared = 0.0, sum_xy = 0.0;
    for (int i = 0; i < SIZE; ++i) {
        sum_x_squared += X[i] * X[i];
        sum_xy += X[i] * Y[i];

    }
    double k2 = (sum_x_squared - sum_xy) / ((sum_x * sum_x) + (sum_y * sum_y));
    cout << "k1 = " << k1 << endl;
    cout << "k2 = " << k2 << endl;



    return 0;


}
