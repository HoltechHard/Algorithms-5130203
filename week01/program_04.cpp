/*
    PROGRAM 04: CONDITIONALS
    Calculate the incremental salary and total salary of employee taking in account:
    * Years of service     |   Salary increase rate
          1-5 years        |        10%
          6 years or +     |        15%
    
    * Another concepts     |    Salary increase rate
        boss               |        10%
        high education     |        5%
        phd                |        12%

    Definition of variables
        - y_service: years of service of employee (input)
        - concepts: description of concept (input)
        - incr_rate1: increase rate based on years of service
        - incr_rate2: increase rate based on another concepts
        - base_salary: basic salary of employee
        - incr_salary: incremental salary taking account incremental rates
        - total_salary: total value of salary
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    cout<< "**** PROGRAM 04 ****" << endl;

    // define variables
    int y_service;
    string concepts;
    float incr_rate1, incr_rate2, base_salary, incr_salary, total_salary;

    cout<< "Base salary (rubles): \t";
    cin>> base_salary;
    cout<< "Enter years of service: \t";
    cin>> y_service;
    cout<< "Enter concepts (boss/high education/phd): \t";
    getline(cin, concepts);     // specific function to read strings input by user in keyboard
    cin.ignore();   // function to clear input buffer

    // calculate increment rate by years of service
    if(1 <= y_service <= 5){
        incr_rate1 = 0.10;
    }else if(y_service >= 6){
        incr_rate1 = 0.15;
    }else{
        incr_rate1 = 0;
    }

    // calculate increment rate by another concepts
    if(concepts == "boss"){
        incr_rate2 = 0.10;
    }else if(concepts == "high education"){
        incr_rate2 = 0.05;
    }else if(concepts == "phd"){
        incr_rate2 = 0.12;
    }else{
        incr_rate2 = 0;
    }

    // calculate incremental and total salary
    incr_salary = base_salary * (incr_rate1 + incr_rate2);
    total_salary = base_salary + incr_salary;

    // print results
    cout<< "*** Results ***" << endl;
    cout<< "Incremental salary: \t" << incr_salary << " rubles" << endl;
    cout<< "Total salary: \t" << total_salary << " rubles" << endl;

    return 0;
}
