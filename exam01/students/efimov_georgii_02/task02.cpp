#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;


int* allocate_memory(int n);
void print_vector(int n, int* x);

int main() {
    int number, n_even = 0, n_odd = 0;
    int* even, * odd;
    string field, type;
    do {
        cout << "Enter number: ";
        cin >> number;
    } while (number < 100 || number > 1000000);

    int num = number;
    int dig;
    while (num > 0) {
        dig = num % 10;
        if (dig % 2 == 0) {
            n_even += 1;
        } else {
            n_odd += 1;
        }
        num /= 10;
    }
    if (n_even > 0) {
        even = allocate_memory(n_even);
    } else {even = allocate_memory(1);}
    
    if (n_odd > 0) {
        odd = allocate_memory(n_odd);
    } else {odd = allocate_memory(1);}
    
    

    int even_index = 0, odd_index = 0;
    int temp = number;

    while (temp > 0) {
        int digit = temp % 10;
        if (digit % 2 == 0) {
            even[even_index] = digit;
            even_index++;
        } else {
            odd[odd_index] = digit;
            odd_index++;
        }
        temp /= 10;
        if (n_even == 0) {
            even[0] = 0;
        }
        if (n_odd == 0) {
            odd[0] = 0;
        }
    }
    int product_odd = 1, sum_even = 0;
    if (n_odd > 0) {
        for (int i = 0; i < n_odd; i++) {
            product_odd *= odd[i];
        }
    } else {
        product_odd = 0;
    }

    if (n_even > 0) {
        for (int i = 0; i < n_even; i++) {
            sum_even += even[i] * even[i];
        }
    } else {
        sum_even = 0;
    }

    cout << "\nEven: ";
    print_vector(n_even, even);

    cout << "\nOdd: ";
    print_vector(n_odd, odd);
    cout << "\n(product of odds) "<< product_odd << " + (sum of square of evens) " << sum_even << " = " << product_odd + sum_even ;
}

int* allocate_memory(int n) {
	return (int*)malloc(n * sizeof(int));
}

void print_vector(int n, int* x) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}


