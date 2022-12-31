#ifndef H_rect
#define H_rect
#include "rectangle.h"
#endif
#include "square.h"

#include <iostream>
using namespace std;

int main()
{
    Rectangle r1(3,4);

    cout << r1.getArea() << endl;
    r1.print();

    Square s1(5,5);
    cout << s1.getArea() << endl;
    s1.print();

    return 0;
}
