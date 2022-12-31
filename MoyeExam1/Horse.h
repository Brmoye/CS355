#ifndef H_MAMMAL
    #define H_MAMMAL
    #include "Mammal.h"
#endif

#include <iostream>
using namespace std;

class Horse : public Mammal
{
    protected:
        string sound = "nay!";
        string action = "gallop";

    public:
        Horse(string n) : Mammal(n)
        {

        }

        void setName()
        {
            cout << "What is the name of your horse?" << endl;
            cin >> name;
        }

        void doAction()
        {
            cout << "The horse named " << getName() << " goes " << action << endl;
        }
        void Speak()
        {
            cout << "The horse named " <<  getName() << " says " << sound << endl;
        }
};

