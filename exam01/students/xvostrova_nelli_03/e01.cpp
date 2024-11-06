#include <iostream>
#include <cmath>


int main(){
    std::cout << cos(0.5) << std::endl;
    float F, G = 6.67 * pow(10, -11), M = 5.96 * pow(10, 24), R = 6.37 * pow(10, 6), h, W, d, angle, m;
    std::cout << "Let's find F" << std::endl;
    std::cout << "enter m" << std::endl;
    std::cin >> m;
    std::cout << "enter h" << std::endl;
    std::cin >> h;
    F = G * (m * M)/(pow(R + h, 2));
    std::cout << "F = " << F << std::endl;

    std::cout << "Now find W" << std::endl;
    std::cout << "enter d" << std::endl;
    std::cin >> d;
    std::cout << "enter angle" << std::endl;
    std::cin >> angle;
    W = F * d * cos(angle);
    std::cout << "W = " << W << std::endl;
}