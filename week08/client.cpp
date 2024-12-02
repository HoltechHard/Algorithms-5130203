#include <iostream>
#include <cstring>
#include <iomanip>
#include "client.h"
using namespace std;

// global variables
static int num_clients=0;
static int index=0;

// implementation of methods for struct Client

// menu of clients
void menu_clients(int *opt){
    cout<<left;
    cout << "-----------------------------------------------"<<endl;
    cout << setw(20) << "*** MANAGMENT SYSTEM OF CLIENTS ***"<<endl;
    cout << "-----------------------------------------------"<<endl;
    cout << "\nSelect an option from [1-7] according to the menu:" << endl;
    cout << "[1]. Insert client"<<endl;
    cout << "[2]. Read list of clients"<<endl;
    cout << "[3]. Search client"<<endl;
    cout << "[4]. Sort in alphabethic order"<<endl;
    cout << "[5]. Update client"<<endl;
    cout << "[6]. Delete client"<<endl;
    cout << "[7]. Find client with highest salary"<<endl;
    cout << "------------------------------------------------"<<endl;
    cout << "Enter option: ";
    cin>> *opt;
}

// insert new client
void insert_client(struct Client *c){
    cout<< "\n*** Insert new Client ***"<<endl;
    index++;
    c->code = index;
    cout<<"Name: ";
    cin>>c->name;

    do{
        cout<<"Age: ";
        cin>> c->age;
    }while(c->age <=0);
    
    do{
        cout<<"Sex [M-male; F-female]: ";
        cin>> c->sex;
    }while(c->sex != 'M' && c->sex != 'm' && c->sex != 'F' && c->sex != 'f');
    
    cout<<"Adress: ";
    cin>>c->address;

    do{
        cout<<"Salary: ";
        cin>>c->salary;
    }while(c->salary < 100000 || c->salary > 500000);
    
    num_clients++;
}

// get total number of clients
int get_num_clients(){
    return num_clients;
}

// print list of clients
void print_lst_clients(struct Client *lst_clients){
    cout<<"\n*** List of clients ***"<<endl;
    cout<<left;
    cout<< setw(10) << "code" << setw(10) << "name" << setw(10) << "age"
        << setw(10) << "sex" << setw(10) <<"salary"<< setw(15)<< "address"<<endl;
    cout << "---------------------------------------------------------------------" << endl;

    for(int i=0; i<get_num_clients(); i++){
        print_client(lst_clients[i]);
    }
}

// print 1 client
void print_client(struct Client c){
    cout<<setw(10)<<c.code<<
            setw(10)<<c.name<<
            setw(10)<<c.age<<
            setw(10)<<(c.sex == 'M' || c.sex == 'm'? "male": "female")<<
            setw(10)<<c.salary<<
            setw(15)<<c.address<<endl;
}

// search some client given the name
int search_client(char *search_name, struct Client *lst_clients){
    int pos;

    cout<< "\n*** Search Client ***"<<endl;
    cout<<"\nWrite the client searched: ";
    cin>>search_name;

    for(int i=0; i<get_num_clients(); i++){
        if (strcmp(lst_clients[i].name, search_name) == 0){
            pos = i;
            break;
        }else{
            pos = -1;
        }
    }

    return pos;
}

// get 1 client
struct Client get_client(int pos, struct Client *lst_clients){
    if(pos != -1)
        return lst_clients[pos];
    else{        
        return default_client();
    }
}

// default client constructor
struct Client default_client(){
    struct Client c;

    c.code = 0;
    c.name[0] = '\0';

    return c;
}

// sort in alphabetical order
void sort_by_names(struct Client *lst_clients){
    struct Client aux;

    for(int i=0; i<get_num_clients()-1; i++){
        for(int j=i+1; j<get_num_clients(); j++){
            if (strcmp(lst_clients[i].name, lst_clients[j].name) > 0){
                aux = lst_clients[i];
                lst_clients[i] = lst_clients[j];
                lst_clients[j] = aux;
            }
        }
    }
}

// update client
void update_client(char *search_name, struct Client *lst_clients){
    int pos;    

    cout<< "\n*** Update Client ***"<<endl;

    // search client
    pos = search_client(search_name, lst_clients);

    if(pos != -1){
        // edit client        
        cout<<"Name: ";
        cin>>lst_clients[pos].name;

        do{
            cout<<"Age: ";
            cin>>lst_clients[pos].age;
        }while(lst_clients[pos].age <=0);

        do{
            cout<<"Sex [M-male; F-female]: ";
            cin>>lst_clients[pos].sex;
        }while(lst_clients[pos].sex != 'M' && lst_clients[pos].sex != 'm' && 
                lst_clients[pos].sex != 'F' && lst_clients[pos].sex != 'f');

        cout<<"Address: ";
        cin>>lst_clients[pos].address;

        do{
            cout<<"Salary: ";
            cin>>lst_clients[pos].salary;
        }while(lst_clients[pos].salary < 100000 || lst_clients[pos].salary > 500000);

        cout<<"\nClient updated!"<<endl;
    }else{
        cout<<"\nClient not found!"<<endl;
    }    
}

// delete client
void delete_client(char *search_name, struct Client *lst_clients){
    int pos;

    cout<<"\n*** Delete Client ***"<<endl;

    // search client
    pos = search_client(search_name, lst_clients);

    if(pos != -1){
        for(int i=pos; i<get_num_clients(); i++){
            lst_clients[i] = lst_clients[i+1];            
        }
        num_clients--;

        cout<<"\nClient deleted!"<<endl;
    }else{
        cout<<"\nClient not found!"<<endl;
    }
}

// find client with highest salary
int get_highest_salary(struct Client *lst_clients){
    int pos_max;
    double max_salary;

    pos_max = 0;
    max_salary = lst_clients[0].salary;

    for(int i=1; i<get_num_clients(); i++){
        if(lst_clients[i].salary > max_salary){
            pos_max = i;
            max_salary = lst_clients[i].salary;
        }
    }

    return pos_max;
}
