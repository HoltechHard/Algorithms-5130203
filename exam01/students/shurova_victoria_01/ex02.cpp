#include <iostream>
#include <cmath>
#include<cstdlib>
#include<time.h>
using namespace std;

float *allocate_memory(float n);
void pay(int n, float *k, float *zp, float *itog);
void randomclass(int n, float *k);
void randompay(int n, float *zp);
void printvector(int n, float *itog);

int main(){
    srand(static_cast<unsigned int>(time(0)));
    float *k, *zp, *itog;
    int n = 5;
    k = allocate_memory(n);
    zp = allocate_memory(n);
    itog = allocate_memory(n);
    randomclass(n, k);
    randompay(n, zp);
    pay(n, k, zp, itog);
    printvector(n, itog);
}

void pay(int n, float *k, float *zp, float *itog){
    for(int i = 0; i < n; i++){
        if(k[i] == 1){
            itog[i] = zp[i] * 1.1;
        } else if(k[i] == 2){
            itog[i] = zp[i] * 0.95;
        } else {
            itog[i] = zp[i] * 0.98;
        }
    }
}
void randomclass(int n, float *k){
    for(int i = 0; i < n; i++){
        k[i] = rand() % 3 + 1;
    }
}
float *allocate_memory(float n){
    return (float *) malloc(n * sizeof(float));
}
void randompay(int n, float *zp){
    for(int i = 0; i < n; i++){
        zp[i] = rand() % (250000) + 100000;
    }
}
void printvector(int n, float *itog){
    float maxx = 0;
    for(int i = 0; i < n; i++){
        cout << "Pay: " << i+1 << "of people " << itog[i] << endl;
        if (itog[i] > maxx){
            maxx = itog[i];
        }
    }cout << "Max pay: " << maxx << endl;
}