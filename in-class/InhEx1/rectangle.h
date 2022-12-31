#include <iostream>
using namespace std;

class Rectangle
{
    protected:
        int width;
        int height;

    public:
        Rectangle(int x, int y)
        {
            setDimensions(x, y);
        }
        void setDimensions(int x, int y)
        {
            width = x;
            height = y;
        }
        void setWidth(int w)
        {
            width = w;
        }

        void setHeight(int h)
        {
            height = h;
        }

        int getArea()
        {
            return width * height;
        }

        void print()
        {
            cout << "Hey, this is a rectangle: " << width << "X" << height << endl;
        }
};

