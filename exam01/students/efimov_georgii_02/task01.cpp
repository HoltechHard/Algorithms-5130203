#include <iostream>

using namespace std;

int main() {
    double profit, nalog, result;
    string field, type;
    
    cout << "Enter profit of company: ";
    cin >> profit;

    
    cout << "Enter type of activity of a company: ";
    cin >> type;



    cout << "Enter field of activity of a company: ";
    cin >> field;


    if (field == "multinational") {
        if (type == "import") {
            nalog = profit * 0.15;
        } else if (type == "export") {
            nalog = profit * 0.05;
        }
    } else if (field == "national") {
        if (type == "import") {
            nalog = profit * 0.07;
        } else if (type == "export") {
            nalog = profit * 0.02;
        }
    } 

    result = profit - nalog;

    cout << "\nTaxes would be " << nalog << endl;
    cout << "net profit is:  " << profit << " - " << nalog << " = " << result;
}