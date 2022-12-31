#include <iostream>
#include "Increasing.h"
#include "Decreasing.h"
using namespace std;

int main()
{
    Increasing i1;
    Decreasing d1;

    cout << "Increasing: " << endl;
    i1.randomFill();
    i1.print();
    i1.sort();
    i1.print();

    cout << endl;
    cout << "Decreasing: " << endl;
    d1.randomFill();
    d1.print();
    d1.sort();
    d1.print();

    return 0;
}
