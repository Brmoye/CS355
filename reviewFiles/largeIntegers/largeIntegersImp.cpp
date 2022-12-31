#include <iostream>

using namespace std;

#include "largeIntegers.h"

ostream& operator<< (ostream& os, const largeIntegers& num)
{
    for (int i = num.numOfDigits - 1; i >= 0; i--)
        os << num.number[i];
    return os;
}

istream& operator>> (istream& is, largeIntegers& num)
{
    int index;
    int strIndex;
    string numStr;

    cout << "Enter an integer of at most " 
         << num.maxNumOfDigits << " digits: ";
    
    is >> numStr;
    cout << endl;

    num.numOfDigits = numStr.length();
    index = 0;

    if (numStr.length() <= 100)
        for (strIndex = numStr.length() - 1; strIndex >= 0; strIndex--)
        {
            num.number[index] = static_cast<int> (numStr.at(strIndex)) - static_cast<int> ('0');
            index++;
        }
    else
    {
        cout << "This number has more than 100 digits. "
             << "Number is set to 0" << endl;
        num.number[0] = 0;
        num.numOfDigits = 1;
    }

    char discard;
    is.get(discard);

    return is;
}

largeIntegers largeIntegers::operator+(const largeIntegers& num)
{
    largeIntegers temp;

    temp = sumNum(num);

    return temp;
}

largeIntegers largeIntegers::operator-(const largeIntegers& num)
{
    largeIntegers temp;

    largeIntegers temp1 = *this;
    largeIntegers temp2 = num;

    temp = temp1.subtractNum(temp2);
         
    return temp;
}

largeIntegers::largeIntegers()
{
    maxNumOfDigits = 100;
    numOfDigits = 1;
    number[0] = 0;
}

largeIntegers largeIntegers::sumNum(const largeIntegers& num)
{
    largeIntegers temp;

    int sumDigits;

    int index1 = 0;
    int index2 = 0;
    int index = 0;
    int carry = 0;

    while (index1 < numOfDigits && index2 < num.numOfDigits)
    {
        sumDigits = number[index1] + num.number[index2] + carry;

        if (sumDigits < 10)
        {
            temp.number[index] = sumDigits;
            carry = 0;
        }
        else
        {
            temp.number[index] = sumDigits - 10;
            carry = 1;
        }
        index++;
        index1++;
        index2++;
    }

    if (index1 < numOfDigits)
        for (int i = index1; i < numOfDigits; i++)
        {
            sumDigits = number[i] + carry;

            if (sumDigits <= 9)
            {
                temp.number[index] = sumDigits;
                carry = 0;
            }
            else
            {
                temp.number[index] = sumDigits - 10;
                carry = 1;
            }
            index++;
        }
    else if (index2 < num.numOfDigits)
        for (int i = index2; i < num.numOfDigits; i++)
        {
            sumDigits = num.number[i] + carry;

            if (sumDigits <= 9)
            {
                temp.number[index] = sumDigits;
                carry = 0;
            }
            else
            {
                temp.number[index] =  sumDigits - 10;
                carry = 1;
            }
            index++;
          }

    if (index <= maxNumOfDigits && carry == 1)
    {
        temp.number[index] = 1;
        index++;
    }

    if (carry == 1 && index >= maxNumOfDigits)
    {
        cout << "The sum of the numbers overflows. It has " 
             << maxNumOfDigits + 1 << " digits." << endl;
        temp.numOfDigits = 0;
    }

    temp.numOfDigits = index;

    return temp;
}

largeIntegers largeIntegers::subtractNum(const largeIntegers& num)
{
    largeIntegers temp;

    largeIntegers tempNum;
    
    tempNum = *this; //copy this number into tempNum, because this
                     //number might be changed

    int differenceDigits;

    int index1 = 0;
    int index2 = 0;
    int index = 0;

    while (index1 < numOfDigits && index2 < num.numOfDigits)
    {
        if (tempNum.number[index1] >= num.number[index2])
            differenceDigits = tempNum.number[index1] - num.number[index2];
        else
        {
            differenceDigits = 10 + tempNum.number[index1] - num.number[index2];
            
            int i = index1 + 1;

            while (tempNum.number[i] == 0)
                tempNum.number[i++] = 9;

            tempNum.number[i] = tempNum.number[i] - 1;
        }

        temp.number[index] = differenceDigits;
        index++;
        index1++;
        index2++;
    }

    if (index1 < numOfDigits)
    {
        for (int i = index1; i < numOfDigits; i++)
        {
             temp.number[index] = tempNum.number[i];
             index++;
        }

        temp.numOfDigits = numOfDigits;
    }
    else if (index2 < num.numOfDigits)
    {
        for (int i = index2; i < num.numOfDigits; i++)
        {
             temp.number[index] = num.number[i];
             index++;
        }

        temp.numOfDigits = num.numOfDigits;
    }
    else
        temp.numOfDigits = numOfDigits;

    while (temp.number[temp.numOfDigits - 1] == 0 && temp.numOfDigits >= 0)
        temp.numOfDigits--;
  
    if (temp.numOfDigits == 0)
    {
        temp.number[0] = 0;
        temp.numOfDigits = 1;
    }

    return temp;
}
