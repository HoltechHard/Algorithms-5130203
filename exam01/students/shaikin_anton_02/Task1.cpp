#include <iostream>
#include <cmath>
using namespace std;
void nalog();
int main(){
nalog();
return 0;
    } 
    void nalog(){
        int money, imp, nat, nalog; 
        float pribil;
        cout << "Enter the dohod: ";
        cin >> money;
        cout << "Choose type of your company: \n 1. National \n 2. International \n";
        cin >> nat;
        cout << "Import or export: \n 1. Import \n 2. Export \n";
        cin>>imp;
        if (nat - 1&&imp -1){
            pribil = money * 0.95;
            nalog = money*0.05;
        } else if (!(nat -1)&&imp-1){
            pribil = money * 0.98;
            nalog = money*0.02;
        } else if (nat - 1 && !(imp-1)){
            pribil = money * 0.85;
            nalog = money*0.15;
        } else if (!(nat - 1)&&!(imp-1)){
            nalog = money*0.07;
            pribil = money * 0.93;
        } cout << "Pribil = " << round(pribil*100)/100 << " Rub" << endl; 
        cout << "Nalog = " <<  nalog << endl;      
    }     