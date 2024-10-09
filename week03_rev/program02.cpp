/*
    REVIEW - WEEK 03: CONVERSION OF SYSTEM OF NUMBERS
    Преобразование системы счисления. Организованное в меню опций
    ввод чисел и расчет требуемых преобразований системы нумерации. Не
    используйте указатели или функции, только переменные,
    последовательные инструкции и циклы.
    [1]. Введите число в десятичном формате. Преобразуйте число по
    основанию 10 в основание n.
    [2]. Введите число по baza n. Преобразуйте число в десятичную
    систему счисления.
*/

#include <iostream>
using namespace std;

int main(){
    int x, n;

    cout<<"\nConversion from base 10 to base n";    
    cout<<"\n Define x = ";
    cin>>x;
    cout<<"\n Define n = ";
    cin>>n;

    int aux, dig, order, y;
    aux = x;
    order = 1;
    y = 0;

    while(aux > 0){
        dig = aux%n;
        aux = aux/n;
        y = y + dig * order;
        order = order * 10;
    }

    cout<< "\n Value in base "<<n<<" = "<< y<< endl;

    int n1, x1, aux1, y1;

    cout<<"\nConvert from base n to base 10";    
    cout<<"\nInput the number: ";
    cin>>x1;
    cout<<"\nInput the base: ";
    cin>>n1;

    aux1 = x1;
    y1 = 0;

    int dig1, order1;
    order1 = 1;

    while(aux1 > 0){
        dig1 = aux1%10;
        y1 = y1 + dig1 * order1;
        aux1 = aux1/10;
        order1 = order1 * n1;
    }
    
    cout<< "\n Value in base 10 "<<" = "<< y1<< endl;
    return 0;

}