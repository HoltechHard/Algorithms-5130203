#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int sfer, det, prib;
	std::wcout << L"Введите сферу деятельности компании(многонациональный-1, национальный-2):" << std::endl;
	cin >> sfer;
	std::wcout << L"Введите вид деятелььности(импортная-1, экспортная-2):" << std::endl;
	cin >> det;
	std::wcout << L"Введите прибыль компании:" << std::endl;
	cin >> prib;

	if (sfer == 1 && det == 1) {
		prib *= 0.85;
	}
	else if (sfer == 1 && det == 2) {
		prib *= 0.95;
	}
	else if (sfer == 2 && det == 1) {
		prib *= 0.93;
	}
	else if (sfer == 2 && det == 2) {
		prib *= 0.98;
	}

	std::wcout << L"Чистая прибыль компании:" << prib << std::endl;

	int a;
	cin >> a;
	return 0;
}