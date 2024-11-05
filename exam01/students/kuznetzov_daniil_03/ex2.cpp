#include <iostream>
#include <cmath>
using namespace std;


// Функция для динамического выделения памяти для вектора
int *allocate_memory(int n){
    return (int *) malloc(n * sizeof(int));
}
void input_vector(int n, int *x, int *y){
    for(int i=0; i<n; i++){
            do {
            cout << "Point " << i + 1 << " (X Y): ";
            cin>>x[i]>>y[i];
            } while (x[i] < 10 || x[i] > 100 || y[i] < 10 || y[i] > 100 );
    }
}

// Процедура  для вывода элементов вектора
void print_vector(int n, int *x, int *y){
    for(int i=0; i<n; i++){
        cout<<x[i]<<"  " <<y[i] << endl;
    }
    cout<<endl;
}

double calculate_average(int n, int *x) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i]; 
    }
    return static_cast<double>(sum) / n;  
}

double minX(int n, int *x) {
    int min = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] < min)
        min = x[i];
    }
    return min; 
}

double maxY(int n, int *x) {
    int max = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] > max)
        max = x[i];
    }
    return max;  
}

double powX(int n, int *x) {
    int sum=0;
    for (int i = 1; i < n; i++) {
        sum+=pow(x[i],2);
    }
    return sum;  
}

double multiply(int n, int *x,int *y) {
   int sum=0;
    for (int i = 1; i < n; i++) {
        sum+=x[i]*y[i];
    }
    return sum;  
}

double sumX(int n, int *x) {
    int sum=0;
    for (int i = 1; i < n; i++) {
        sum+=x[i];
    }
    return sum;  
}

double sumY(int n, int *x) {
    int sum=0;
    for (int i = 1; i < n; i++) {
        sum+=x[i];
    }
    return sum;  
}


int main(){
    int *x, *y;
    long double k1,k2;
    int n=5;
    x = allocate_memory(n);  
    y = allocate_memory(n);
    cout<<"\nInput the elements in vector: "<<endl;
    input_vector(n,x,y);         
    cout<<"\nVector A: "<<endl;
    print_vector(n,x,y);         
    k1=(calculate_average(n,x)*minX(n, x))/(calculate_average(n,y)*maxY(n, y));
    k2=(powX(n,x)-multiply(n,x,y))/(pow(sumX(n,x),2)-pow(sumY(n,y),2));
    cout << "k1= " <<k1 <<endl;
    cout << "k2= " <<k2;
}
