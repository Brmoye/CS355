#include <iostream>
using namespace std;

#include "FizzBuzz.h"
#include "FizzBuzzExt1.h"

int main()
{
   	FizzBuzzExt fizz;
   	int choice;

   	choice = fizz.menu();

	while(choice != 5){
		switch(choice){
			case 1:
				cout << endl;
				fizz.run();
				cout << endl;
				break;

			case 2:
				fizz.setLimit();
				break;

			case 3:
				fizz.addRule();
				break;

			case 4:
				fizz.clear();
				break;

			default:
				cout<< "Invalid Choice. Try Again.\n" << endl;
				break;
		}
		choice = fizz.menu();
	}
	return 0;
}

