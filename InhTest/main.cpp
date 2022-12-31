#include <iostream>
#include "petType.h"
#include "dogType.h"
#include "catType.h"
using namespace std;

int main()
{
    petType* pTArray[5];

    pTArray[0] = new dogType("Asta", "German Short-haired Pointer");
    pTArray[1] = new dogType("Noodle", "Standard Poodle");
    pTArray[2] = new dogType("Tallulah", "Boston Terrier");
    pTArray[3] = new catType("Daisy", "Calico");
    pTArray[4] = new catType("Loki", "Grey and Black");

    for(int i = 0; i < 5; ++i)
    {
        pTArray[i]-> print();
        cout << endl;
    }

    return 0;
}
