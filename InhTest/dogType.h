
#include <iostream>
using namespace std;

class dogType : public petType
{
    private:
        string breed;

    public:
        dogType(string n, string b) : petType(n)
        {
            breed = b;
        }

        void print()
        {
            petType::print();
            cout << "Breed: " << breed << endl;
        }
};
