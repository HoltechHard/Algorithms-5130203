/*
    WEEK 07 - STRUCT: DOT OPERATOR VS ARROW OPERATOR

    [1]. Create a struct for Points in euclidean space with integer values for axis X, Y
    [2]. Initialize 2 points like struct variables and assign their respective coordinates
    [3]. Create a pointer of struct and assign the memory address in this point. Change the
         original value of this value using pointer. Print the results and check the changes. 

    Definition of Variables: 
        - p1, p2: instances of struct Point with coordinates (x, y)
        - p: pointer to struct Point
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    int x;
    int y;
};

// main function
int main(){
    // define struct variables
    struct Point p1, p2;

    // point 01
    p1.x = 10;
    p1.y = 20;

    // point 02
    p2.x = 30;
    p2.y = 40;

    // print the coordinates for each point
    cout<<"\nPoint p1 = ";
    cout<<"("<<p1.x<<", "<<p1.y<<")"<<endl;
    cout<<"Point p2 = ";
    cout<<"("<<p2.x<<", "<<p2.y<<")"<<endl;

    // define pointer to struct and make modifications
    struct Point *p;
    p = &p2;
    p->x += 100;
    p->y += 200; 

    cout<<"\nPoint P = ";
    cout<<"("<<p->x<<", "<<p->y<<")"<<endl;
    cout<<"Point p1 = ";
    cout<<"("<<p1.x<<", "<<p1.y<<")"<<endl;
    cout<<"Point p2 = ";
    cout<<"("<<p2.x<<", "<<p2.y<<")"<<endl;

    return 0;
}

