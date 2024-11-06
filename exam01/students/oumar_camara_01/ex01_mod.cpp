#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
    if(x<=-1){
        return -x+2;
    }else if (x>-1&&x<=3){
        return x*x -1;
    }else if (x>3){
        return -2*x+2;
    }    
}

 double g(double x){
    return 1/(1+ exp(-x));
 }

int main(){
    double x;

    do{
        cout<<"\nErreur: x doit etre dans l'intervalle [-10, 10]"<<endl;
        cin>> x;
    }while(x<-10 || x>10);

    double result1 = f(x);
    double result2 = g(result1);

    cout<<"g(f(x)) = "<<result2 <<endl;
    
    return 0;
}
