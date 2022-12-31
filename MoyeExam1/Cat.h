#ifndef H_MAMMAL
    #define H_MAMMAL
    #include "Mammal.h"
#endif

#include <iostream>
using namespace std;

class Cat : public Mammal
{
    protected:
        string sound = "meow!";
        string action = "preen";

    public:
        Cat(string n) : Mammal(n)
        {

        }

        void setName()
        {
            cout << "What is the name of your cat?" << endl;
            cin >> name;
        }

        void doAction()
        {
            cout << "The cat named " << getName() << " goes " << action << endl;
        }
        void Speak()
        {
            cout << "The cat named " <<  getName() << " says " << sound << endl;
        }
};

