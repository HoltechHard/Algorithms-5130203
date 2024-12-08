#include <iostream>
#include <cstring>
#include <cmath>
#include "client.h"
#include "product.h"
#include "order.h"
using namespace std;

#define MAX_CLIENTS 100
#define MAX_PRODUCTS 100
#define MAX_ORDERS 100

void menu_master(int *opt);

int main(){
    int opt;
    char cont;
    struct Client *lst_clients;
    struct Product *lst_products;
    struct Order *lst_orders;
    
    lst_clients = new struct Client[MAX_CLIENTS];
    lst_products = new struct Product[MAX_PRODUCTS];
    lst_orders = new struct Order[MAX_ORDERS];

    do{
        menu_master(&opt);

        switch(opt){
            case 1:     // clients
                menu_clients(&opt, lst_clients);
                break;
            case 2:     // products
                menu_products(&opt, lst_products);
                break;
            case 3:     // orders
                menu_orders(&opt, lst_clients, lst_products, lst_orders);
            default:
                cout<<"\nInvalid option"<<endl;
                break;
        }

        // Request to user continue or not
        cout << "\nDo you want continue [Y|N]? "<< endl;
        cin>> cont;
    }while(cont == 'y' || cont == 'Y');

    cout << "The program is over!"<< endl;

    // clean the memory
    delete[] lst_clients;
    delete[] lst_products;
    delete[] lst_orders;

    return 0;
}

void menu_master(int *opt){
    cout << "-----------------------------------------------"<<endl;
    cout<<"*** SYSTEM OF PRODUCT SALES ***"<<endl;
    cout << "-----------------------------------------------"<<endl;
    cout << "\nSelect an option from [1-3] according to the menu:" << endl;
    cout << "[1]. Managment of Clients"<<endl;
    cout << "[2]. Managment of Products"<<endl;
    cout << "[3]. Managment of Orders"<<endl;
    cout << "-----------------------------------------------"<<endl;
    cout << "Enter option: ";
    cin>> *opt;
    cout <<endl;
}
