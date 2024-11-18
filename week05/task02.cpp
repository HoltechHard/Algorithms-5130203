/*
    WEEK 05 - TASK 02: SORT A LIST OF WORDS ALPHABETICALLY
    
    Read a set of words, storing each word in a character array string of no more than 30 letters. 
    Sort the words alphabetically and output the result of the original word list and the sorted word list.
*/

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX 30

// head of functions defined by user
void input_dimension(int *n);
char **allocate_matrix(int n);
void input_matrix(int n, char **x);
void print_matrix(int n, char **x);
void order_words(int n, char **x);
void free_memory(int n, char **x);

// main function
int main(){
    int n;
    char **x;

    // input #words
    input_dimension(&n);
    
    // allocate dynamically memory for matrix
    x = allocate_matrix(n);

    // input matrix of words
    cout<<"\nInput the list of words: "<<endl;
    input_matrix(n, x);
    cout<<"\nList of original words: "<<endl;
    print_matrix(n, x);

    // list the words ordered
    cout<<"\nList of ordered words: "<<endl;
    order_words(n, x);
    print_matrix(n, x);
    free_memory(n, x);

    return 0;
}

// procedure to input dimensionality of matrix
void input_dimension(int *n){
    do{
        cout<<"\nInput the number of words: ";
        cin>>*n;
    }while(n<=0);
}

// procedure to allocate memory for matrix dynamically
char **allocate_matrix(int n){
    char **m = (char **) malloc(n * sizeof(char *));

    for(int i=0; i<n; i++){
        m[i] = (char *) malloc(MAX * sizeof(char));
    }

    return m;
}

// procedure to input list of words
void input_matrix(int n, char **x){
    for(int i=0; i<n; i++){
        cout<<"\nWord "<<i<<": "<<endl;
        cin>>x[i];
    }
}

// procedure to print list of words
void print_matrix(int n, char **x){
    for(int i=0; i<n; i++){
        cout<<x[i]<<endl;
    }
}

// procedure to order ascendently the list of words
void order_words(int n, char **x){
    char aux[MAX];

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(x[j-1], x[j])>0){
                strcpy(aux, x[j-1]);
                strcpy(x[j-1], x[j]);
                strcpy(x[j], aux);
            }
        }
    }
}

// procedure to free up memory
void free_memory(int n, char **x){
    for (int i = 0; i < n; i++) {
        free(x[i]);
    }
    free(x);
}
