#include <iostream>
#include <cstring>
#include <iomanip>
#include "product.h"
using namespace std;

static int num_prods=0;
static int index=0;

// implementation of methods for struct Product

// menu of products
void menu_products(int *opt, struct Product *lst_products){
    int pos;
    char search_prod[40];
    struct Product p;

    do{
        cout<<left;
        cout << setw(20) << "\n --- MANAGMENT OF PRODUCTS ---"<<endl;    
        cout << "\nSelect an option from [1-8] according to the menu:" << endl;
        cout << "[1]. Insert product"<<endl;
        cout << "[2]. Read list of products"<<endl;
        cout << "[3]. Search product"<<endl;
        cout << "[4]. Sort by unit price"<<endl;
        cout << "[5]. Update product"<<endl;
        cout << "[6]. Delete product"<<endl;
        cout << "[7]. Find product with lowest price"<<endl;
        cout << "[8]. Exit"<<endl;
        cout << "------------------------------------------------"<<endl;
        cout << "Enter option: ";
        cin>> *opt;

        switch(*opt){
            case 1:     // insert
                insert_product(&lst_products[get_num_products()]);
                break;
            case 2:     // read 
                print_lst_products(lst_products);
                break;
            case 3:     // search                
                // get the position
                pos = search_product(search_prod, lst_products);
                
                // get the client
                p = get_product(pos, lst_products);

                if(p.code != 0){
                    // print the client
                    cout<<"\nSearched product: "<<endl;
                    print_product(p);
                }else{
                    cout<<"\nProduct not found"<<endl;
                }
                
                // clean the memory of client
                memset(&p, 0, sizeof(p));
                break;
            case 4:     // sort data by price
                cout<<"\nList of products ordered by price"<<endl;
                sort_by_prices(lst_products);
                print_lst_products(lst_products);
                break;
            case 5:     // update client                
                update_product(search_prod, lst_products);
                break;
            case 6:     // delete client                
                delete_product(search_prod, lst_products);
                break;
            case 7:     // get client with cheapest cost
                pos = get_cheapest_product(lst_products);
                p = get_product(pos, lst_products);
                cout<<"\nProduct with cheapest price: "<<endl;
                print_product(p);
                break;
            case 8:
                cout << "Exiting to main menu..." << endl;
                break;
            default:
                cout << "\nInvalid option" << endl;
                break;
        }

    }while(*opt != 8);
}

// insert new product
void insert_product(struct Product *p){
    cout<< "\n*** Insert new Product ***"<<endl;
    index++;
    p->code = index;
    cout<<"Product description: ";
    cin>>p->description;

    do{
        cout<<"Stock: ";
        cin>>p->stock;
    }while(p->stock <=0);
    
    do{
        cout<<"Unit price: ";
        cin>>p->unit_price;
    }while(p->unit_price <=0);

    num_prods++;
}

// get total number of products
int get_num_products(){
    return num_prods;
}

// print list of products
void print_lst_products(struct Product *lst_products){
    cout<<"\n*** List of products ***"<<endl;
    cout<<left;
    cout<< setw(10) << "code" << setw(15) << "description"
        << setw(10) << "stock" << setw(10) << "unit_price"<<endl;
    cout<<"-----------------------------------------------"<<endl;

    for(int i=0; i<get_num_products(); i++){
        print_product(lst_products[i]);
    }
}

// print 1 product
void print_product(struct Product p){
    cout<<setw(10)<<p.code<<
            setw(15)<<p.description<<
            setw(10)<<p.stock<<
            setw(10)<<p.unit_price<<endl;
}

// search some product given the description
int search_product(char *search_description, struct Product *lst_products){
    int pos;

    cout<<"\n*** Search Product ***"<<endl;
    cout<<"\nWrite the product searched: ";
    cin>>search_description;

    for(int i=0; i<get_num_products(); i++){
        if(strcmp(lst_products[i].description, search_description) == 0){
            pos = i;
            break;
        }else{
            pos = -1;
        }
    }

    return pos;
}

// get 1 product
struct Product get_product(int pos, struct Product *print_lst_products){
    if(pos != -1){
        return print_lst_products[pos];
    }else{
        return default_product();
    }
}

// default product constructor
struct Product default_product(){
    struct Product p;
    p.code = 0;
    p.description[0] = '\0';

    return p;
}

// sort by price
void sort_by_prices(struct Product *lst_products){
    struct Product aux;

    for(int i=0; i<get_num_products()-1; i++){
        for(int j=i+1; j<get_num_products(); j++){
            if(lst_products[i].unit_price > lst_products[j].unit_price){
                aux = lst_products[i];
                lst_products[i] = lst_products[j];
                lst_products[j] = aux;
            }
        }
    }
}

// update product
void update_product(char *search_description, struct Product *lst_products){
    int pos;

    cout<<"\n*** Update Product ***"<<endl;

    // search product
    pos = search_product(search_description, lst_products);

    if(pos != -1){
        // edit product
        cout<<"Description: ";
        cin>>lst_products[pos].description;

        do{
            cout<<"Stock: ";
            cin>>lst_products[pos].stock;
        }while(lst_products[pos].stock <=0);
        
        do{
            cout<<"Unit price: ";
            cin>>lst_products[pos].unit_price;
        }while(lst_products[pos].unit_price <=0);
        
        cout<<"\nProduct updated!"<<endl;        
    }else{
        cout<<"\nProduct not found!"<<endl;
    }
}

// delete product
void delete_product(char *search_description, struct Product *lst_products){
    int pos;

    cout<<"\n*** Delete Product ***"<<endl;

    // search product
    pos = search_product(search_description, lst_products);

    if(pos != -1){
        for(int i=pos; i<get_num_products(); i++){
            lst_products[i] = lst_products[i+1];
        }
        num_prods--;

        cout<<"\nProduct deleted!"<<endl;        
    }else{
        cout<<"\nProduct not found!"<<endl;
    }
}

// find the cheapest product
int get_cheapest_product(struct Product *lst_products){
    int pos_min;
    double min_price;

    pos_min=0;
    min_price = lst_products[0].unit_price;

    for(int i=1; i<get_num_products(); i++){
        if(lst_products[i].unit_price < min_price){
            pos_min = i;
            min_price = lst_products[i].unit_price;
        }
    }

    return pos_min;
}
