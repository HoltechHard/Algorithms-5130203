struct BOOK
{
	enum Category { FANTASY, FANTASTIC, ROMAN, HISTORY };

	char author[40];
	char title[40];
	double price;
	int year;
	int category;
};


//Прототипы используемых в данном задании функций:

void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) );
void SwapInt(void* p1, void* p2);
void SwapDouble(void* p1, void* p2);
void SwapStr(void* p1, void* p2);
int CmpInt(void* p1, void* p2);
int CmpDouble(void* p1, void* p2);
int CmpStr(void* p1, void* p2);
double Sum(double, double);
double Sub(double, double);
double Mul(double, double);
double Div(double, double);
const char* GetString1();
const char* GetString2();
const char* GetString3();
void printBook(const BOOK &book);
void readBook(BOOK &book);