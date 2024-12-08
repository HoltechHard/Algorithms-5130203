/*
    WEEK 09 - TASK 02: READ DATA IN FILES
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    char name[50];
    int age;
    FILE *file;

    // open file
    file = fopen("data/text01.txt", "r");

    // read data from file
    if(file){
        fscanf(file, "Name: %49s\nAge: %d", name, &age);
        fclose(file);
    }else{
        printf("Error opening file");
    }

    // print results in terminal
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;

    return 0;
}

