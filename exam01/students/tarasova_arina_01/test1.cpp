#include <iostream>
#include <ctime>
#include <cmath>
#include <random>

using namespace std;

int main(){
    int x,f;
    float g;
    
    do{
        cout<<"Enter x: ";
        cin>>x;
    }
    while(x<-10||x>10);
    if(x<=-1){
        f=-x+2;
    }else if(x>-1 && x<=3){
        f=pow(x,2)-1;
    }else if(x>3){
        f = -2*x+2;
    }
    g = 1/(1+(exp(-f)));
    cout<<"Result :"<<g<<endl;
}