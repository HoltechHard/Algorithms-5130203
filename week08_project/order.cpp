#include <iostream>
#include <cstring>
#include <iomanip>
#include "order.h"
using namespace std;

static int num_ords=0;
static int index=0;

// implementation of methods for struct Order/OrderDetail

// menu of orders
void menu_orders(int *opt, struct Client *lst_clients, struct Product *lst_products, struct Order *lst_orders){
    do{
        cout<<left;
        cout<< setw(20) << "\n --- MANAGMENT OF ORDERS ---"<<endl;
        cout << "\nSelect an option from [1-3] according to the menu:" << endl;
        cout << "[1]. Insert order"<<endl;
        cout << "[2]. Print list of orders"<<endl;
        cout << "[3]. Exit"<<endl;
        cout << "-----------------------------------------------"<<endl;
        cout << "Enter option: ";
        cin>> *opt;

        switch(*opt){
            case 1:     // insert order
                insert_order(&lst_orders[get_num_orders()], lst_clients, lst_products);
                break;
            case 2:     // print orders/details
                print_list_orders(lst_orders);
                break;
            case 3:
                cout << "Exiting to main menu..." << endl;
                break;
            default:
                cout << "\nInvalid option" << endl;
                break;
        }

    }while(*opt != 3);    
}

void insert_order(struct Order *ord, struct Client *lst_clients, struct Product *lst_products){
    char search_cli[50], cont;
    int pos;

    cout<< "\n*** Insert new Order ***"<<endl;
    index++;
    ord->code = index;
    cout<< "\nClient: ";
    pos = search_client(search_cli, lst_clients);
    ord->client = get_client(pos, lst_clients);

    // insert the order details
    do{        
        if(ord->num_details < MAX){
            insert_order_detail(&ord->details[ord->num_details], lst_products);
            ord->total += ord->details[ord->num_details].subtotal;
            ord->num_details++;
        }else{
            cout<<"\nMax number of order details reached!"<<endl;
            break;
        }

        cout<< "Do you want to add another order detail? (y/n): ";
        cin>> cont;
    }while(cont == 'y' || cont == 'Y');

    ord->client.salary -= ord->total;
    num_ords++;
}

int get_num_orders(){
    return num_ords;
}

void insert_order_detail(struct OrderDetail *od, struct Product *lst_products){
    char search_prod[40];
    int pos;

    cout<< "\n*** New Order Detail ***"<<endl;
    cout<< "\nProduct: ";    
    pos = search_product(search_prod, lst_products);
    od->product = get_product(pos, lst_products);

    do{
        cout<< "Quantity: ";
        cin>> od->quantity;
    }while(od->quantity > od->product.stock);
    
    od->subtotal = od->product.unit_price * od->quantity;
    od->product.stock -= od->quantity;
}

void print_list_orders(struct Order *lst_orders){
    cout<<"\n*** List of Orders ***"<<endl;

    for(int i=0; i<get_num_orders(); i++){
        print_order(lst_orders[i]);
    }
}

void print_order(struct Order ord){
    cout<< "Order ID: "<< ord.code<< endl;
    cout<< "Client: "<< ord.client.name<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<left;
    cout<<setw(10)<< "Item"<<setw(15)<<"Product"<<setw(15)<<"Unit Price"<<
          setw(10)<<"Quantity"<<setw(10)<<"Subtotal"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;

    for(int i=0; i<ord.num_details; i++){
        cout<<setw(10)<<(i+1)<<
              setw(15)<<ord.details[i].product.description<<
              setw(15)<<ord.details[i].product.unit_price<<
              setw(10)<<ord.details[i].quantity<<
              setw(10)<<ord.details[i].subtotal<<endl;
    }

    cout<<"\nTotal: "<<ord.total<<endl<<endl;
}
