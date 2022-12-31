#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <iostream>

using namespace std;

class FizzBuzz
{
    public:
        FizzBuzz();
        FizzBuzz(int l);
        void setLimit(int l);
        void run();

    private:
        int limit;
};

#endif // FIZZBUZZ_H
