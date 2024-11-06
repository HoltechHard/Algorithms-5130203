#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    string sphera, deat;
    int sum, nalog = 0;

    cout << "write sum: ";
    cin >> sum;

    cin.ignore();

    cout << "(national or extranational): ";
    getline(cin, sphera);

    if (sphera == "extranational") {
        cout << "import or export: ";
        cin >> deat;
        if (deat == "import") {
            nalog = sum * 0.15;
        }
        else if (deat == "export") {
            nalog = sum * 0.05;
        }
        else {
            cout << "not correct " << endl;
            return 1;
        }
    }
    else if (sphera == "national") {
        cout << "import or export ";
        cin >> deat;
        if (deat == "import") {
            nalog = sum * 0.07;
        }
        else if (deat == "export") {
            nalog = sum * 0.02;
        }
        else {
            cout << " not correct " << endl;
            return 1;
        }
    }
    else {
        cout << "not correct " << endl;
        return 1;
    }

    cout << "nalog: " << nalog << " rubles " << endl;

    cout << "pribil: " << sum - nalog << " rubles " << endl;

    return 0;
}