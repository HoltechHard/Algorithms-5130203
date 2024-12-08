// Data struct of Product

#ifndef PRODUCT_H
#define PRODUCT_H

// attributes
struct Product {
    int code;
    char description[40];
    int stock;
    double unit_price;
};

// methods
void menu_products(int *opt, struct Product *lst_products);
void insert_product(struct Product *p);
int get_num_products();
void print_product(struct Product p);
void print_lst_products(struct Product *lst_products);
int search_product(char *search_description, struct Product *lst_products);
struct Product get_product(int pos, struct Product *lst_products);
struct Product default_product();
void sort_by_prices(struct Product *lst_products);
void update_product(char *search_description, struct Product *lst_products);
void delete_product(char *search_description, struct Product *lst_products);
int get_cheapest_product(struct Product *lst_products);

#endif