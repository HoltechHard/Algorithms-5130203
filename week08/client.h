// Data struct of Client

// attributes
struct Client{
    int code;
    char name[50];
    int age;
    char sex;
    char address[100];
    double salary;
};

// methods
void menu_clients(int *opt);
void insert_client(struct Client *c);
int get_num_clients();
void print_client(struct Client c);
void print_lst_clients(struct Client *lst_clients);
int search_client(char *search_name, struct Client *lst_clients);
struct Client get_client(int pos, struct Client *lst_clients);
struct Client default_client();
void sort_by_names(struct Client *lst_clients);
void update_client(char *search_name, struct Client *lst_clients);
void delete_client(char *search_name, struct Client *lst_clients);
int get_highest_salary(struct Client *lst_clients);
