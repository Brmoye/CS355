#include <iostream>
#include <string>

using namespace std;

#include "Dog.h"
#include "Cat.h"
#include "Horse.h"
#include "GuineaPig.h"

int main()
{
    Mammal* theArray[5];
    Mammal* ptr;
    int choice, i;
    string name;
    for (i = 0; i<5; i++)
    {
        cout << "(1)dog (2)cat (3)horse (4)guinea pig: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                ptr = new Dog("NoNameDog");
                ptr -> setName();
            break;
            case 2:
                ptr = new Cat("NoNameCat");
                ptr -> setName();
            break;
            case 3:
                ptr = new Horse("NoNameHorse");
                ptr -> setName();
            break;
            case 4:
                ptr = new GuineaPig("NoNameGuineaPig");
                ptr -> setName();
            break;
            default:
                cout<<"Error: Invalid Selection.  You've been assigned a dog."<<endl;
                ptr = new Dog("NoNameDog");
                ptr -> setName();
            break;
        }
        theArray[i] = ptr;
    }
    cout<<"********"<<endl;
    for (i=0;i<5;i++){
        theArray[i]->Speak();
    }
    cout<<"********"<<endl<<endl<<endl;
    for (i=0;i<5;i++){
        theArray[i]->doAction();
    }
    cout<<"********"<<endl;
    return 0;
}
