#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    
    int n, c1 = 0, c2 = 0;
    do {
        cout << " write n " << endl;
        cin >> n;
    } while (n < 100 || n > 1000000);

    int n2 = n;
    int count = 0;

    while (n2 != 0) {
        n2 /= 10;
        count++;
    }

    int* vec = (int*)malloc(count * sizeof(int));


    for (int i = count - 1; i >= 0; i--) {
        vec[i] = n % 10;
        n /= 10;
    }

    for (int i = 0; i < count; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;



    cout << " how many zifrs: " << count << endl;

    for (int i = 0; i < count; i++) {
        if (vec[i] % 2 == 0) {
            c1++;
        }
        else {
            c2++;
        }
    }



    cout << " chet: " << c1 << endl;

    cout << " nechet: " << c2 << endl;

    int* veca = (int*)malloc(c1 * sizeof(int));

    int* vecb = (int*)malloc(c2 * sizeof(int));


    int ina = 0, inb = 0;
    for (int i = 0; i < count; i++) {
        if (vec[i] % 2 == 0) {
            veca[ina++] = vec[i];
        }
        else {
            vecb[inb++] = vec[i];
        }
    }
    cout << "vect a:" << endl;
    for (int i = 0; i < c1; i++) {
        cout << veca[i] << " \n";
    }
    cout << endl;

    cout << "vect b:" << endl;
    for (int i = 0; i < c2; i++) {
        cout << vecb[i] << " \n";
    }
    cout << endl;

    int proizvnechet = 1;
    for (int i = 0; i < c2; i++) {
        proizvnechet *= vecb[i];
    }

    cout << "proizv nechet: " << proizvnechet << endl;

    int kvch = 1;
    for (int i = 0; i < c1; i++) {
        kvch += pow(veca[i], 2);
    }

    cout << "kvadrat chetn: " << kvch - 1 << endl;

    cout << "sum kv ch + proizv nechet: " << kvch - 1 + proizvnechet << endl;

    return 0;
}