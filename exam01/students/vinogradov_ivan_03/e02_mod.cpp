#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int const n = 5;
    double x[n];
    double y[n];
    int minx, miny;
    double k1, k2, ax, ay, sumxi, sumxi2, sumyi, sumxyi;
    
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    for (int i = 0; i < n; i++){
        cin >> y[i];
    }

    ax = 0.0;
    ay = 0.0;

    for (int i = 0; i < n; i++){
        ax += x[i];
        ay += y[i];
    }
    
    ax = ax/n;
    ay = ay/n;

    minx = x[0];
    miny = y[0];
    
    for (int i = 0; i < n; i++){
        if (x[i] < minx){
            minx = x[i];
        }
        if (y[i] > miny){
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
    k2 = (sumxi2 - sumxyi)/(pow(sumxi, 2)+pow(sumyi, 2));

    cout << "k1 = " << k1 << endl;
    cout << "k2 = " << k2 << endl;
    
    return 0;
}