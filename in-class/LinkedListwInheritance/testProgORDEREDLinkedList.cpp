//Program to test the various operations on an
//ordered linked list

#include <iostream>                             //Line 1
#include "orderedLinkedList.h"                  //Line 2

using namespace std;                            //Line 3

int main()                                      //Line 4
{                                               //Line 5
    orderedLinkedList<int> list1, list2;        //Line 6
    int num;                                    //Line 7

    cout << "Line 8: Enter numbers ending "
         << "with -999." << endl;               //Line 8
    cin >> num;                                 //Line 9

    while (num != -999)                         //Line 10
    {                                           //Line 11
        list1.insert(num);                      //Line 12
        cin >> num;                             //Line 13
    }                                           //Line 14

    cout << endl;                               //Line 15

    cout << "Line 16: list1: ";                 //Line 16
    list1.print();                              //Line 17
    cout << endl;                               //Line 18

    list2 = list1; //test the assignment operator Line 19

    cout << "Line 20: list2: ";                 //Line 20
    list2.print();                              //Line 21
    cout << endl;                               //Line 22

    cout << "Line 23: Enter the number to be "
         << "deleted: ";                        //Line 23
    cin >> num;                                 //Line 24
    cout << endl;                               //Line 25

    list2.deleteNode(num);                      //Line 26

    cout << "Line 27: After deleting "
         << num << ", list2: " << endl;         //Line 27
    list2.print();                              //Line 28
    cout << endl;                               //Line 29

    return 0;                                   //Line 30
}                                               //Line 31



