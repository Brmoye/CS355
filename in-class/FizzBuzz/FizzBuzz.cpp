#include <iostream>
#include "FizzBuzz.h"

using namespace std;

// Class method definitions / implementations

FizzBuzz::FizzBuzz(int lim)
{
	limit = lim;
}

void FizzBuzz::run()
{
	for(int i = 1; i <= limit; ++i)
	{
		if(i % 3 == 0 && i % 5 == 0)
		{
			cout << "FizzBuzz" << endl;
		}
		else if(i % 3 == 0)
		{
			cout << "Fizz" << endl;
		}
		else if(i % 5 == 0)
		{
			cout << "Buzz" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}
}

void FizzBuzz::setLimit()
{
	cin >> limit;
}

int FizzBuzz::menu()
{
	int choice;
	//1, 2, or 3
	
	cin >> choice;
	return choice;
}