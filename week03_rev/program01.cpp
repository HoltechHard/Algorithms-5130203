/*
    REVIEW - WEEK 03: CALCULATE MCM AND MCD
    Введите два целых числа от 100 до 1000. Вычислите
    наименьшее общее кратное (НОК) и наибольший общий делитель (НОД).
    Не используйте указатели или функции, только переменные,
    последовательные инструкции и циклы.
*/

#include <iostream>
using namespace std;

int main(){
    int a, b, a1, b1;    

    // define variables
    do{
        cout<<"\n A = ";
        cin>>a;
        cout<<"\n B = ";
        cin>>b;
    }while(a<100 || a>1000 || b<100 || b>1000);

    a1 = a;
    b1 = b;

    // calculate MCM
    int i, mcm;
    i=2;
    mcm = 1;

    while(a!=1 || b!=1){
        if(a%i == 0 || b%i == 0){
            mcm = mcm * i;

            if(a%i == 0)
                a = a/i;

            if(b%i == 0)
                b = b/i;
        }else{
            i++;
        }
    }

    // calculate MCD
    int j, mcd;
    j = 2;
    mcd = 1;    

    while(a1 > j || b1 > j){
        if(a1%j == 0 && b1%j == 0){            
            mcd = mcd * j;
            a1 = a1/j;
            b1 = b1/j;
        }else{
            j++;
        }        
    }

    cout<<"\n MCM = "<<mcm<<endl;
    cout<<"\n MCD = "<<mcd<<endl;

    return 0;
}
