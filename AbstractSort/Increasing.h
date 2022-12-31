#ifndef ABSTRACTSORT_H
#define ABSTRACTSORT_H
#include "AbstractSort.h"
#endif
#include <iostream>
using namespace std;

class Increasing : public AbstractSort
{
    bool compare(int first, int second)
    {
        return first > second;
    }
};
