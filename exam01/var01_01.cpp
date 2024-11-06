/*
    EXAM 01 - Algorithms and Programming 5130203/40001
    VARIANT 01 - EXERCISE 01
*/

#include <iostream>
#include <cmath>
using namespace std;

// main function
int main(){
    double x, f, g;

    // input x
    do{
        cout<<"\nInput x: ";
        cin>>x;
    }while(x<-10 || x>10);    

    // calculate f(x)
    if(x<=-1){
        f = -x+2;
    }else if(x<=3){
        f = pow(x,2)-1;
    }else{
        f = -2*x+2;
    }

    // calculate g(f(x))
    g = 1/(1 + exp(-f));

    cout<<"\ng(f(x)) = "<<g<<endl;

    return 0;
}
