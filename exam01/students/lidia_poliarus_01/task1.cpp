#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

float *allocate_memory(float empn){
    return (float *) malloc(empn * sizeof(float));
}

void nalog(int empn, float *k, float *sal, float *finish){
    for(int i = 0; i < empn; i++){
        if(k[i] == 1){
            finish[i] = sal[i] * 1.1;
        } else if(k[i] == 2){
            finish[i] = sal[i] * 0.95;
        } else {
            finish[i] = sal[i] * 0.98;
        }
    }
}

void randomk(int empn, float *k){
    for(int i = 0; i < empn; i++){
        k[i] = rand() % 3 + 1;
    }
}

void randomzp(int empn, float *sal){
    for(int i = 0; i < empn; i++){
        sal[i] = rand() % (250000) + 100000;
    }
}

void printvector(int empn, float *finish){
    float maxsal = 0;
    for(int i = 0; i < empn; i++){
        cout << "Salary" << i+1 << " of this employer is " << finish[i] << endl;
        if (finish[i] > maxsal){
            maxsal = finish[i];
        }
    }cout << "Maximum salary is " << maxsal << endl;
}

int main(){
    srand(static_cast<unsigned int>(time(0)));
    float *kl, *zrpl, *finish;
    int empn = 5;
    kl = allocate_memory(empn);
    zrpl = allocate_memory(empn);
    finish = allocate_memory(empn);
    randomk(empn, kl);
    randomzp(empn, zrpl);
    nalog(empn, kl, zrpl, finish);
    printvector(empn, finish);
}