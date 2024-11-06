#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    if (x <= -1) {
        return -x + 2;
    } else if (x <= 3) {
        return x * x - 1;
    } else {
        return -2 * x + 2;
    }
}

double g(double x) {
    return 1 / (1 + exp(-x));
}

int main() {
    double x;

    do{
        cout << "Введите значение x в диапазоне [-10, 10]: ";
        cin >> x;
    }while(x<-10 || x>10);
    
    double fx = f(x);
    double gfx = g(fx);

    cout << "f(x) = " << fx << endl;
    cout << "g(f(x)) = " << gfx << endl;

    return 0;
}