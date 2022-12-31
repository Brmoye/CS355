#include <iostream>
using namespace std;

class Mammal
{
    protected:
        string name;
        string sound;
        string action;

    public:
        Mammal(string n)
        {
            name = n;
            cout << name << " was created." << endl;
        }

        string getName()
        {
            return name;
        }

        virtual void setName() = 0;
        virtual void doAction() = 0;
        virtual void Speak() = 0;
};
