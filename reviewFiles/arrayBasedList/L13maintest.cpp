#include <iostream>                              //Line 1
#include "L13arrayListType.h"                    //Line 2

using namespace std;                             //Line 3
  
int main()                                       //Line 4
{                                                //Line 5
    arrayListType intList(25);          //Line 6

    int number;                                  //Line 7

    cout << "List 8: Enter 8 integers: ";        //Line 8

    for (int count = 0; count < 8; count++)      //Line 9
    {                                            //Line 10
        cin >> number;                           //Line 11
        intList.insertEnd(number);               //Line 12
    }                                            //Line 13

    cout << endl;                                //Line 14
    cout << "Line 16: intList: ";                //Line 15
    intList.print();                             //Line 16
    cout << endl;                                //Line 17

    cout << "Line 18: Enter the number to be " 
         << "deleted: ";                         //Line 18
    cin >> number;                               //Line 19
    cout << endl;                                //Line 20

    intList.remove(number);                      //Line 21

    cout << "Line 22: After removing " << number
         << " intList: ";                        //Line 22
    intList.print();                             //Line 23
    cout << endl;                                //Line 24
 
    cout << "Line 25: Enter the search item: ";  //Line 25

    cin >> number;                               //Line 26
    cout << endl;                                //Line 27

    if (intList.seqSearch(number) != -1)         //Line 28
        cout << "Line 29: " << number 
             << " found in intList." << endl;    //Line 29
    else                                         //Line 30
        cout << "Line 31: " << number 
             << " is not in intList." << endl;   //Line 31

    return 0;                                    //Line 32
}                                                //Line 33
