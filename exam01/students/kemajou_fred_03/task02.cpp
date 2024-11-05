#include <iostream>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string>
#include <cstdlib>

#define _USE_MATH_DEFINES

using namespace std;


int main(){

int X[5],Y[5];
float a,b,k1,k2=0;
int minx=0;
int maxy=0;
int X_2=0;
int Y_2 =0;
int moy_x=0;
int moy_y=0;

for (int i=0;i<5;i++){
    againX :
    cout<< "entrer un nombre X["<< i+1 <<"] "<<endl;
    cin >> a;
    if (a<10 || a>100){
    cout<< "small number"; 
        goto againX;
    }else{
        X[i]=a;
    }
    moy_x=moy_x+(a/5);

}

minx=X[0];
for (int i=1;i<5;i++){
    if (X[i]<minx){
        minx=X[i];
    }

}

for (int i=0;i<5;i++){
    againY :
    cout<< "entrer un nombre Y["<< i+1 <<"]"<<endl;
    cin >> b;
    if (b<10 || b>100){
    cout<< "small number"; 
        goto againY;
    }else{
        Y[i]=b;
    }
    moy_y=moy_y+(b/5);
}


/*average
for (int i=0;i<5;i++){
   //moy_x=moy_x+X[i];
   moy_y=moy_y+Y[i];


}
moy_x=moy_x/5;
moy_y=moy_y/5;
*/
maxy=Y[0];
for (int i=1;i<5;i++){
    if (Y[i]>maxy){
        maxy=Y[i];
    }

}
k1=(moy_x*minx)/(moy_y*maxy);

for (int i=0;i<5;i++){
   X_2=X_2+pow(X[i],2);
   Y_2=X[i]*Y[i];


}

k2=(X_2 - Y_2)/(pow(moy_x*5,2)+pow(moy_y*5,2));




//cout<< "le min de x est "<< minx<< "le max de y est "<< maxy<< " la moyenne de x est "<< moy_x << "la moyenne de y est "<< moy_y << "k1 est de "<<k1; 

cout<< "the result of k1 is "<< k1<< "the result of k2 is "<< k2<<endl;

//cout << " c'est "<<G;
    return 0;
}