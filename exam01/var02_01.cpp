/*
    EXAM 01 - Algorithms and Programming 5130203/40001    
    VARIANT 02 - EXERCISE 01
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double get_tax(int company_scope, int type_company);

// main function
int main(){
    int company_scope, type_company;
    double profits, percentual_tax, total_tax, real_profit;

    cout<<"\nInput benefits of company: ";
    cin>>profits;
    cout<<"\nScope of company [1->multinational | 2->national]: ";
    cin>>company_scope;    
    cout<<"\nType of company [1->import | 2->export]: ";
    cin>>type_company;

    // calculate tax and real profit
    percentual_tax = get_tax(company_scope, type_company);
    total_tax = percentual_tax * profits;
    real_profit = profits - total_tax;
    cout<<"\nTax: "<<total_tax<<endl;
    cout<<"\nReal profit: "<<real_profit<<endl;

    return 0;    
}

// function to get percentual tax
double get_tax(int company_scope, int type_company){
    double perc_tax;

    switch(company_scope){
        case 1:     // multinational
            switch(type_company){
                case 1:     // import
                    perc_tax = 0.15;
                    break;
                case 2:     // export
                    perc_tax = 0.05;
                    break;
                default:
                    perc_tax = 0.0;
                    break;
            }            
            break;

        case 2:     // national
            switch(type_company){
                case 1:     // import
                    perc_tax = 0.07;
                    break;
                case 2:     // export
                    perc_tax = 0.02;
                    break;
                default:
                    perc_tax = 0.0;
                    break;
            }            
            break;

        default:
            perc_tax = 0.0;
            break;
    }

    return perc_tax;
}
