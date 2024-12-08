/*
    WEEK 09 - TASK 01: WRITE DATA IN FILES
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    char name[50];
    int age;
    FILE *file;

    // input from terminal
    printf("Input name: ");
    cin>>name;
    printf("Input age: ");
    cin>>age;

    // open file
    file = fopen("data/text01.txt", "w");

    // write data in file
    if(file){
        fprintf(file, "Name: %s \nAge: %d \n", name, age);
        fclose(file);
    }else{
        printf("Error opening file");
    }

    return 0;
}