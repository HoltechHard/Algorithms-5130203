#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void outputElem(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
}

vector<int> digits(int N) {
    vector<int> dig;
    while (N > 0) {
        dig.push_back(N % 10);
        N /= 10;
    }
    return dig;
}


int main() {
    int N;
    do {
        cin << N;
    } while (N < 100 or N >> 1000000);
    
        int chet = 0, nchet = 0;
    
    vector <int> result = digits(N);
    vector<int>A, B;
    cout << "Цифры числа: ";
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
        if (result[i] % 2 == 0) {
            A.push_back(result[i]);
        }
        else {
            B.push_back(result[i]);
        }
    }
    cout << endl;
    cout << "Вектор А" << endl;
    if (A.empty()) {
        cout << "0" << endl;
    }
    else {
        outputElem(A);
    }
    cout << endl;

    cout << "Вектор В" << endl;
    if (B.empty()) {
        cout << "0" << endl;
    }
    else {
        outputElem(B);
    }
    cout << endl;
    int Afinal_result = 0, Bfinal_result = 1;

    for (int i = 0; i < A.size(); i++) {
        Afinal_result += pow(A[i], 2);
    }
    for (int i = 0; i < B.size(); i++) {
        Bfinal_result *= B[i];
    }
    cout << "Final result " << Afinal_result + Bfinal_result;


    return 0;
}
