#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class AbstractSort
{
    private:
        int* arrayPointer;

    protected:
        const int ARRAY_SIZE = 10;

    public:
        AbstractSort()
        {
            arrayPointer = new int[ARRAY_SIZE];
            srand(time(NULL));
        }

        void randomFill()
        {
            for(int i = 0; i < ARRAY_SIZE; ++i)
            {
                arrayPointer[i] = rand() % 100 + 1;
            }
        }

        void print()
        {
            for(int i = 0; i < ARRAY_SIZE; ++i)
            {
                cout << arrayPointer[i] << " ";
            }
            cout << endl;
        }

        virtual bool compare(int first, int second) = 0;

        void sort()
        {
            int temp = 0;
            for(int i = 0; i < ARRAY_SIZE - 1; ++i)
            {
                for(int j = 0; j < ARRAY_SIZE - 1 - i; ++j)
                {
                    if(compare(arrayPointer[j], arrayPointer[j + 1]))
                    {
                        temp = arrayPointer[j];
                        arrayPointer[j] = arrayPointer[j + 1];
                        arrayPointer[j + 1] = temp;
                    }
                }
            }
        }
};
