#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int sfer, det, prib;
	std::wcout << L"������� ����� ������������ ��������(�����������������-1, ������������-2):" << std::endl;
	cin >> sfer;
	std::wcout << L"������� ��� �������������(���������-1, ����������-2):" << std::endl;
	cin >> det;
	std::wcout << L"������� ������� ��������:" << std::endl;
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

	std::wcout << L"������ ������� ��������:" << prib << std::endl;

	int a;
	cin >> a;
	return 0;
}