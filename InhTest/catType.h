
#include <iostream>
using namespace std;

class catType : public petType
{
    private:
        string color;

    public:
        catType(string n, string c) : petType(n)
        {
            color = c;
        }

        void print()
        {
            petType::print();
            cout << "Color: " << color << endl;
        }
};
