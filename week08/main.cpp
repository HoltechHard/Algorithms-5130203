#include <iostream>
#include <cstring>
#include <cmath>
#include "client.h"
using namespace std;

#define MAX_CLIENTS 100

int main(){
    int opt, pos;
    char cont, search_name[50];
    struct Client *lst_clients, c;
    lst_clients = new struct Client[MAX_CLIENTS];

    do{        
        menu_clients(&opt);

        switch(opt){
            case 1:     // insert
                insert_client(&lst_clients[get_num_clients()]);
                break;
            case 2:     // read 
                print_lst_clients(lst_clients);
                break;
            case 3:     // search                
                // get the position
                pos = search_client(search_name, lst_clients);
                
                // get the client
                c = get_client(pos, lst_clients);

                if(c.code != 0){
                    // print the client
                    cout<<"\nSearched client: "<<endl;
                    print_client(c);    
                }else{
                    cout<<"\nClient not found"<<endl;
                }
                
                // clean the memory of client
                memset(&c, 0, sizeof(c));
                break;
            case 4:     // sort data in alphabetic order
                cout<<"\nList of clients ordered alphabetically"<<endl;
                sort_by_names(lst_clients);
                print_lst_clients(lst_clients);
                break;
            case 5:     // update client                
                update_client(search_name, lst_clients);                
                break;
            case 6:     // delete client                
                delete_client(search_name, lst_clients);            
                break;
            case 7:     // get client with highest salary
                pos = get_highest_salary(lst_clients);
                c = get_client(pos, lst_clients);
                cout<<"\nClient with highest salary: "<<endl;
                print_client(c);
                break;
            default:
                cout<<"\nInvalid option"<<endl;
                break;
        }

        // Request to user continue or not
        cout << "\nDo you want continue [Y|N]? "<< endl;
        cin>> cont;

    }while(cont == 'y' || cont == 'Y');    
    
    cout << "The program is over!"<< endl;

    return 0;
}
