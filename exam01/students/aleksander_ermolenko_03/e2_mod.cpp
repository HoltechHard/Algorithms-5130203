#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

int main() {
    vector<int> X(5), Y(5);

    // Input vectors X and Y
    cout << "Enter values for vector X (5 elements between 10 and 100):" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> X[i];
        if (X[i] < 10 || X[i] > 100) {
            cout << "Invalid value. Please enter a value between 10 and 100." << endl;
            i--; 
        }
    }

    cout << "Enter values for vector Y (5 elements between 10 and 100):" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> Y[i];
        if (Y[i] < 10 || Y[i] > 100) {
            cout << "Invalid value. Please enter a value between 10 and 100." << endl;
            i--; 
            
        }
    }

    double sum_X = 0;
    double sum_Y = 0;
    for (int i = 0; i < 5; i++) {
        sum_X += X[i];
        sum_Y += Y[i];
    }
    double average_X = sum_X / X.size();
    double average_Y = sum_Y / Y.size();

    cout << "Mathematical expectation of vector X: " << average_X << endl;
    cout << "Mathematical expectation of vector Y: " << average_Y << endl;


    double smallest_X = *min_element(X.begin(), X.end());
    cout << "smallest_X: " << smallest_X << endl;

    double largest_Y = *max_element(Y.begin(), Y.end());
    cout << "largest_Y: " << largest_Y << endl;

    double k1, k2; 
    k1 = (average_X * smallest_X) / (average_Y * largest_Y);

    double sum_sqrt_X;
    for (int i = 0; i < 5; i++) {
        sum_sqrt_X += pow(X[i], 2);
    }

    double sum_X_Y;
    for (int i = 0; i < 5; i++) {
        sum_X_Y += X[i] * Y[i];
    }

    k2 = (sum_sqrt_X - sum_X_Y) / (pow(sum_X, 2) + pow(sum_Y, 2));

    cout << "k1: " << k1 << endl;
    cout << "k2: " << k2 << endl;

    return 0;
}
