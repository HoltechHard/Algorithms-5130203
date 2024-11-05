#include <iostream>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string>
#include <cstdlib>

#define _USE_MATH_DEFINES

using namespace std;

int main(){

float m,h,teta,F,W,d;

float G=6.67*pow(10,-11);
float M=5.96*pow(10,24);
float R=6.37*pow(10,6);

cout << "enter the mass of the body (in KG):"<<endl;
cin >> m;

cout << "enter the height to which the body fall: (in meter)"<<endl;
cin >> h;

cout << "enter the angle of declination (in degree)"<<endl;
cin >> teta;

cout << "enter the traveled distace (in meter) "<<endl;
cin >> d;

F=G*(m*M)/pow((R+h),2);

W=F*d*(cos(teta*acos(-1)/180.0)); //to have result in degree

cout << "the result of F (gravity force) is: " << F <<" (N)"<<endl;

cout << "the result of W (physical work) is: " << W <<" (J)"<<endl;

//cout << " c'est "<<G;
    return 0;
}