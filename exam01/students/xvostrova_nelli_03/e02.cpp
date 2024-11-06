#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


int main(){
    int x, y, xsum, ysum;
    double xsr, ysr, k1, k2;
    std::vector<int> datax;
    std::vector<int> datay;
    std::cout << "enter x" << std::endl;
    for (int i = 1; i <= 5; i++){
        std::cin >> x;
        datax.push_back(x);
    }
    std::cout << "enter y" << std::endl;
    for (int j = 1; j <= 5; j++){
        std::cin >> y;
        datay.push_back(y);
    }

    std::sort(datax.begin(), datax.end());
    std::sort(datay.begin(), datay.end());

    for (int i1 = 0; i1 <= 4; i1++){
        xsum += datax[i1];
    }

    for (int j1 = 0; j1 <= 4; j1++){
        ysum += datay[j1];
    }

    xsr = xsum / 5;
    ysr = ysum / 5;

    k1 = xsr * datax[0] / (ysr * datay[0]);
    k2 = ((pow(datax[0], 2) + pow(datax[1], 2) + pow(datax[2], 2) + pow(datax[3], 2) + pow(datax[4], 2)) - ((datax[0] * datay[0]) + (datax[1] * datay[1]) + (datax[2] * datay[2]) + (datax[3] * datay[3]) + (datax[4] * datay[4]))) / ((pow(datax[0] + datax[1] + datax[2] + datax[3] + datax[4], 2)) + (pow(datay[0] + datay[1] + datay[2] + datay[3] + datay[4], 2)));
    std::cout << k1 << std::endl;
    std::cout << k2 << std::endl;
}