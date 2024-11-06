#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	double sfer, det, prib;
	std::cout <<"Введите сферу деятельности компании(многонациональный-1, национальный-2):" << std::endl;
	cin >> sfer;
	std::cout <<"Введите вид деятелььности(импортная-1, экспортная-2):" << std::endl;
	cin >> det;
	std::cout <<"Введите прибыль компании:" << std::endl;
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

	std::cout <<"Чистая прибыль компании:" << prib << std::endl;

	return 0;
}