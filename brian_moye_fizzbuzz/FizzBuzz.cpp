#include "FizzBuzz.h"

FizzBuzz::FizzBuzz():limit(100)
{

}

FizzBuzz::FizzBuzz(int l = 100)
{
    limit = l;
}

void FizzBuzz::setLimit(int l)
{
    limit = l;
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
