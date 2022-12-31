
#include <iostream> 
#include "L13arrayListType.h" 
 
using namespace std;

bool arrayListType::isEmpty() const
{
    return (length == 0);
} //end isEmpty

bool arrayListType::isFull() const  
{
    return (length == maxSize);
} //end isFull

int arrayListType::listSize() const
{
	return length;
} //end listSize

int arrayListType::maxListSize() const
{
	return maxSize;
} //end maxListSize

void arrayListType::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
} //end print

bool arrayListType::isItemAtEqual(int location, int item)  const
{
    if (location < 0 || location >= length)
    {
        cout << "The location of the item to be removed "
             << "is out of range." << endl;

        return false;
    }
    else
        return (list[location] == item);
} //end isItemAtEqual

void arrayListType::removeAt(int location)
{
    if (location < 0 || location >= length)
        cout << "The location of the item to be removed "
             << "is out of range." << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i+1];

        length--;
    }
} //end removeAt

void arrayListType::retrieveAt(int location, int& retItem) const
{
    if (location < 0 || location >= length)
        cout << "The location of the item to be retrieved is "
             << "out of range" << endl;
    else
        retItem = list[location];
} //end retrieveAt

void arrayListType::clearList()
{
    length = 0;
} //end clearList

arrayListType::arrayListType(int size)
{
    if (size <= 0)
    {
        cout << "The array size must be positive. Creating "
             << "an array of the size 100." << endl;

        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;

    list = new int[maxSize];
} //end constructor

arrayListType::~arrayListType()
{
    delete [] list;
} //end destructor

arrayListType::arrayListType(const arrayListType& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;

    list = new int[maxSize]; 	//create the array

    for (int j = 0; j < length; j++)  //copy otherList
        list [j] = otherList.list[j];
}//end copy constructor

//===========
void arrayListType::insertAt(int location, int insertItem) 
{
    if (location < 0 || location >= maxSize)
        cout << "The position of the item to be inserted "
             << "is out of range." << endl;
    else if (length >= maxSize)  //list is full
        cout << "Cannot insert in a full list" << endl;
    else
    {
        for (int i = length; i > location; i--)
            list[i] = list[i - 1];	//move the elements down

        list[location] = insertItem; //insert the item at 
                                     //the specified position

        length++;	//increment the length
    }
} //end insertAt

void arrayListType::insertEnd(int insertItem)
{
    if (length >= maxSize)  //the list is full
        cout << "Cannot insert in a full list." << endl;
    else
    {
        list[length] = insertItem; //insert the item at the end
        length++; //increment the length
    }
} //end insertEnd

int arrayListType::seqSearch(int searchItem) const
{
    int loc;
    bool found = false;

    loc = 0;

    while (loc < length && !found)
        if (list[loc] == searchItem)
            found = true;
        else
            loc++;

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch


void arrayListType::remove(int removeItem)
{
    int loc;

    if (length == 0)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
                 << endl;
    }
} //end remove

void arrayListType::replaceAt(int location, int repItem)
{
    if (location < 0 || location >= length)
        cout << "The location of the item to be "
             << "replaced is out of range." << endl;
    else
        list[location] = repItem;
} //end replaceAt
