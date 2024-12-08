// Data struct of Order and OrderDetail

#ifndef ORDER_H
#define ORDER_H

#include "client.h"
#include "product.h"
#define MAX 10

// order details attributes
struct OrderDetail{
    Product product;
    int quantity;
    double subtotal;
};

// order attributes
struct Order{
    int code;
    Client client;
    OrderDetail details[MAX];
    int num_details;
    double total;

    Order():
        num_details(0), total(0.0){}
};

// methods
void menu_orders(int *opt, struct Client *lst_clients, struct Product *lst_products, struct Order *lst_orders);
void insert_order(struct Order *ord, struct Client *lst_clients, struct Product *lst_products);
void insert_order_detail(struct OrderDetail *od, struct Product *lst_products);
int get_num_orders();
void print_list_orders(struct Order *lst_orders);
void print_order(struct Order ord);

#endif
