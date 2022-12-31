#ifndef H_rect
#define H_rect
#include "rectangle.h"
#endif

#include <iostream>
using namespace std;

class Square : public Rectangle
{
    private:

    public:
        Square(int x, int y) : Rectangle(x, y)
        {
            if(width != height)
            {
                cout << "Error: this is not a square. Values set to 1x1." << endl;
                width = 1;
                height = 1;
            }
        }
        void setDimensions(int x, int y)
        {
            if(width != height)
            {
                cout << "Error: this is not a square. Values set to 1x1." << endl;
                width = 1;
                height = 1;
            }
            else
            {
                width = x;
                height = y;
            }
        }
        // static function name binding - function overwriting
        void print()
        {
            Rectangle::print();
            cout << "This is a square: " << width << " x " << height << endl;
        }

};
