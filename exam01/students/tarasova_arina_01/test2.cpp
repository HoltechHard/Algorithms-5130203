#include <iostream>
#include <cmath>
#include<cstdlib>
#include<time.h>
using namespace std;

float *allocate_memory(float n){
    return (float *) malloc(n * sizeof(float));
}

void tax(int n, float *k,float *res,float*pay){
    for(int i = 0; i < n; i++){
        if(k[i] == 1){
            res[i] = pay[i] * 1.1;
        } else if(k[i] == 2){
            res[i] = pay[i] * 0.95;
        } else {
            res[i] = pay[i] * 0.98;
        }
    }
}

void randomk(int n, float *k){
    for(int i = 0; i < n; i++){
        k[i] = rand() % 3 + 1;
    }
}

void randompay(int n, float *pay){
    for(int i = 0; i < n; i++){
        pay[i] = rand() % (250000) + 100000;
    }
}

void output(int n, float *res){
    float maxx = 0;
    for(int i = 0; i < n; i++){
        cout << "заработная плата " << i+1 << "сотрудника" << res[i] << endl;
        if (res[i] > maxx){
            maxx = res[i];
        }
    }cout <<  "самая высокая зарплата" << maxx << endl;
}