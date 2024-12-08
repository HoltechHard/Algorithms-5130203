#include "other.h"

///////////////////////////////////////////////////



void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) )
{
	int i;
	for(i=1; i<nNumber; i++)
		for(int j=nNumber-1; j>=i; j--)
		{
			char* pCurrent = pcFirst+j*size;
			char* pPrevious = pcFirst+(j-1)*size;
			if((*Compare)( pPrevious, pCurrent ) > 0)//требуется
												//переставить
				(*Swap)( pPrevious, pCurrent );
		}
}

void SwapInt(void* p1, void* p2)
{
	int temp = *static_cast<int*>(p1);
	*static_cast<int*>(p1) = *static_cast<int*>(p2);
	*static_cast<int*>(p2) = temp;
}

void SwapDouble(void* p1, void* p2)
{
	double temp = *static_cast<double*>(p1);
	*static_cast<double*>(p1) = *static_cast<double*>(p2);
	*static_cast<double*>(p2) = temp;
}

void SwapStr(void* p1, void* p2)
{
	char *temp = *static_cast<char**>(p1);
	*static_cast<char**>(p1) = *static_cast<char**>(p2);
	*static_cast<char**>(p2) = temp;
}

int CmpInt(void* p1, void* p2)
{
	int nResult;

	int *iP1 = static_cast<int*>(p1);
	int *iP2 = static_cast<int*>(p2);

	nResult = (*iP1 < *iP2) ? -1 : (*iP1 > *iP2) ? 1 : 0;

	return nResult;
}

int CmpDouble(void* p1, void* p2)
{
	int nResult;

	double *iP1 = static_cast<double*>(p1);
	double *iP2 = static_cast<double*>(p2);

	nResult = (*iP1 < *iP2) ? -1 : (*iP1 > *iP2) ? 1 : 0;

	return nResult;
}
#include <string>
int CmpStr(void* p1, void* p2)
{
	int nResult;

	nResult = strcmp(*static_cast<char**>(p1), *static_cast<char**>(p2));

	return nResult;
}


double Sum(double a, double b)
{
	return a+b;
}

double Sub(double a, double b)
{
	return a-b;
}

double Mul(double a, double b)
{
	return a*b;
}

double Div(double a, double b)
{
	if(!b) 
		return 0;

	return a/b;
}

const char* GetString1()
{
	static const char *str = "String1";
	return str;
}

const char* GetString2()
{
	static const char *str = "String2";
	return str;
}

const char* GetString3()
{
	static const char *str = "String3";
	return str;
}

void printBook(const BOOK &book)
{
	printf("Book: %10s %10s %d %4.2lf %d\n", book.author, book.title, book.year,
		book.price, book.category);
}

void readBook(BOOK &book)
{

		printf("Enter struct in format: Author Title Year Price Category\n\
			   Select Category from 0-3: \n\
			   0-FANTASY, 1-FANTASTIC, 2-ROMAN, 3-HISTORY:\n");
		do
		{
			scanf("%19s %19s %d %lf %d", book.author, book.title, &book.year,
			&book.price, &book.category);
			if(book.year > 2013 || book.year < 1000)
				printf("Wrong year, try again\n");
			else if(book.price < 0)
				printf("Wrong price, try again\n");
			else if(book.category < 0 || book.category > 3)
				printf("Wrong category. Will be in 0-3, try again\n");
			else
				break;
		}
		while(1);
}