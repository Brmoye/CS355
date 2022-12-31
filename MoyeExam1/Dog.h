#ifndef H_MAMMAL
    #define H_MAMMAL
    #include "Mammal.h"
#endif

#include <iostream>
using namespace std;

class Dog : public Mammal
{
    protected:
        string sound = "bark!";
        string action = "lick lick";

    public:
        Dog(string n) : Mammal(n)
        {

        }

        void setName()
        {
            cout << "What is the name of your dog?" << endl;
            cin >> name;
        }

        void doAction()
        {
            cout << "The dog named " << getName() << " goes " << action << endl;
        }
        void Speak()
        {
            cout << "The dog named " <<  getName() << " says " << sound << sound << endl;
        }
};
