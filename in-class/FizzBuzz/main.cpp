#include <iostream>
#include "FizzBuzz.h"

using namespace std;

int main()
{
	FizzBuzz fb1;
	int choice;

	choice = fb1.menu();

	while(choice != 3)
	{
		switch(choice)
		{
			case 1:
				cout << endl;
				fb1.run();
				cout << endl;
				break;

			case 2:
				fb1.setLimit();

			default:
				cout << "Invalid choice. Try again.\n" << endl;
				break;
		}
		choice = fb1.menu();
	}

	return 0;
}
