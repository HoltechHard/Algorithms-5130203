#include <iostream>
using namespace std;
#include <cmath>

int main(){
    int s,v;
    int c;
    double k;
    cout << "Введите сферу деятельности multinational/national (1/2)";
    cin >> s;
    cout<< "Введите вид деятельности import/export (1/2)";
    cin>>v;

    cout<<"Введите company profit";
    cin >> c;

    if (s==1){
        if (v==1){
            k=c*0.85;
            cout<<"Налог "<< c-c*0.85<<endl;
            cout<<"Ваш profit "<<k;
        }
    }
    if (s==1){
        if (v==2){
            k=c*0.95;
            cout<<"Налог "<< c-c*0.95<<endl;
            cout<<"Ваш profit "<<k;
        }
    }
    if (s==2){
        if (v==1){
            k=c*0.93;
            cout<<"Налог "<< c-c*0.93<<endl;
            cout<<"Ваш profit "<<k;
        }
    }
    if (s==2){
        if (v==2){
            k=c*0.98;
            cout<<"Налог "<< c-c*0.98<<endl;
            cout<<"Ваш profit "<<k;
        }
    }
}