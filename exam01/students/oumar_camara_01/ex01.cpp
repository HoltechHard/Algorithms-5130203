#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
if(x<=-1)
    return -x+2;
}else if (x>-1&&x<=3){
 return x*x -1;
 }else if (x>3){
 return -2*x+2;
 }
 double g(double x){
 return 1/(1+ exp(-x));
 }
 int main(){
 double x;
 std::cout<<"\Erreur: x doit etre dans l'intervalle [-10, 10]"<<std::endl;
 return 1;
 }
 double result= g(f(x));
 std:::cout<<"\g(f(<<x<<\)) = "<<result << std::endl;
    return 0;
}
