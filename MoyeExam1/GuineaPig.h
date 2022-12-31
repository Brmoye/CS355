#ifndef H_MAMMAL
    #define H_MAMMAL
    #include "Mammal.h"
#endif

#include <iostream>
using namespace std;

class GuineaPig : public Mammal
{
    protected:
        string sound = "weep weep!";
        string action = "skitter";

    public:
        GuineaPig(string n) : Mammal(n)
        {

        }

        void setName()
        {
            cout << "What is the name of your GuineaPig?" << endl;
            cin >> name;
        }

        void doAction()
        {
            cout << "The guinea pig named " << getName() << " goes " << action << endl;
        }
        void Speak()
        {
            cout << "The guinea pig named " <<  getName() << " says " << sound << endl;
        }
};

