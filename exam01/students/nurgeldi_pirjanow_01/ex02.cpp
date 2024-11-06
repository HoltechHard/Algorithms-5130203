#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm> 

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int numEmployees = 5;
    vector<int> A(numEmployees);
    vector<int> B(numEmployees);
    vector<double> C(numEmployees);

        for (int i = 0; i < numEmployees; ++i) {
        A[i] = rand() % 3 + 1;
        B[i] = rand() % (350000 - 100000 + 1) + 100000;
    }

        for (int i = 0; i < numEmployees; ++i) {
        if (A[i] == 1) {
            C[i] = B[i] * 1.1;
        } else if (A[i] == 2) {
            C[i] = B[i] * 0.95;
        } else if (A[i] == 3) {
            C[i] = B[i] * 0.98;
        }
    }

    double maxSalary = *max_element(C.begin(), C.end());

        cout << "Зарплаты после учета бонусов и налогов (вектор C):\n";
    for (double salary : C) {
        cout << salary << " ";
    }
    cout << "\nСамая высокая зарплата: " << maxSalary << endl;

    return 0;
}