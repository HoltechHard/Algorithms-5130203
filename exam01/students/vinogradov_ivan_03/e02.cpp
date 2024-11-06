#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int const n = 5;
    int x[n];
    int y[n];
    int minx, miny;
    long double k1, k2, ax, ay, sumxi, sumxi2, sumyi, sumxyi;
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    for (int i = 0; i < n; i++){
        cin >> y[i];
    }

    for (int i = 0; i < n; i++){
        ax += x[i];
        ay += y[i];
    }
    ax = ax/2;
    ay = ay/2;

    for (int i = 0; i < n; i++){
        if (x[i] >= minx){
            minx = x[i];
        }
        if (y[i] >= miny){
            miny = y[i];
        }
    }
    k1 = (ax*minx)/(ay*miny);
    for (int i = 0; i < n; i++){
        sumxi += x[i];
        sumxi2 += pow(x[i], 2);
        sumyi += y[i];
        sumxyi += x[i]*y[i];
    }
    k2 = (sumxi2 - (sumxi*sumxyi))/(pow(sumxi, 2))+pow(sumyi, 2);
    cout << "k1 = " << k1 << endl;
    cout << "k2 = " << k2 << endl;
    
    return 0;
}