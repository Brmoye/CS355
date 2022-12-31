//Program that uses the class largeIntegers

#include <iostream>

using namespace std;

#include "largeIntegers.h"

int main()
{
    largeIntegers num1;  
    largeIntegers num2; 
    cin >> num1;
    cin >> num2;

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;

    cout << "num1 + num2 = " << num1 + num2 << endl;

    cout << "num1 - num2 = " << num1 - num2 << endl;

    return 0;	
}
