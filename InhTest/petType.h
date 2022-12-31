#include <iostream>
using namespace std;

class petType
{
    private:
        string name;

    public:
        petType(string n="")
        {
            name = n;
        }

        virtual void print()
        {
            cout << "Name: " << name << endl;
        }
};
