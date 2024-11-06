#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;


int main()
{
   srand(static_cast<usigned int>(time(0)));
   std::vector<int> A(5);
   std::vector<double> B(5);
   std::vector<double> C(5);

   for(int i=0; i<5; ++i){
    A[i]=rand()%  3 + 1;
    B[i]=100000 + rand()%250001;

   }
   for (int i=0; i<5; ++i){
    if (A[i]==1){
    C[i]=B[i]*1.10;

    }else if (A[i]==2){
    C[i]=B[i]*0.95;
    else if (A[i]=B[i]*0.98
    }
    }
    double max_salary =
    std::max_element(C.bigin(), C.end());

    std::cout<<\vector C (salary ofter )<<

    for (double salary : C) {

   std::cout << salary << \;

   max_salary << std::endl

   std::cout<<\ same salary:<<
   max_salary<<std::endl;

return 0; }
   }

    return 0;
}
