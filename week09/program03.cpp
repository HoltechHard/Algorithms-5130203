#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

struct Person{
    char name[30];
    int age;
    double salary;
};

#define MAX 100

static int num_persons=0;

void write_file(char file_name[30], struct Person p);
void read_file(char file_name[30], struct Person *lst_persons);
void print_persons(struct Person *lst_persons);

int main(){
    struct Person p, *lst_persons;
    char file_name[30];

    lst_persons = new Person[MAX];

    cout<<"File name: ";
    cin>>file_name;

    // input the data
    cout<<"Name: ";
    cin>> p.name;
    cout<<"Age: ";
    cin>>p.age;
    cout<<"Salary: ";
    cin>>p.salary;

    // send the struct to write file
    write_file(file_name, p);

    // read file
    read_file(file_name, lst_persons);

    // print struct person
    printf("\n***List of Persons***\n");
    print_persons(lst_persons);

    return 0;
}

void write_file(char file_name[30], struct Person p){
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "a");

    if(file){
        fprintf(file, "%s %d %.2f\n", p.name, p.age, p.salary);
        fclose(file);
    }else{
        printf("Error to open file\n");
    }
}

void read_file(char file_name[30], struct Person *lst_persons){
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "r");

    if(file){
        printf("File %s opened!\n", file_path);
        while (fscanf(file, "%29s %d %lf", lst_persons[num_persons].name, 
                        &lst_persons[num_persons].age, &lst_persons[num_persons].salary) == 3) {            
            num_persons++;
        }

        fclose(file);
    }else{
        printf("Error to open file\n");
    }
}

void print_persons(struct Person *lst_persons){    
    cout<<left;
    cout<<setw(15)<<"Name"<<setw(10)<<"Age"<<setw(10)<<"Salary"<<endl;
    cout<<"---------------------------------------------"<<endl;

    if(num_persons != 0){
        for(int i = 0; i < num_persons; i++){
            cout<<setw(15)<<lst_persons[i].name<<
                    setw(10)<<lst_persons[i].age<<
                    setw(10)<<lst_persons[i].salary<<endl;            
        }
    }else{        
        printf("No persons\n");
    }
}
