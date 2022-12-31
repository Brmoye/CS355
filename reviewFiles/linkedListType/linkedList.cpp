#include "linkedList.h"

bool linkedListType::isEmptyList() const
{
    return (first == nullptr);
}

linkedListType::linkedListType() //default constructor
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

void linkedListType::destroyList()
{
    nodeType *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first != nullptr)   //while there are nodes in
    {                          //the list
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }
    last = nullptr; //initialize last to nullptr; first has
               //already been set to nullptr by the while loop
    count = 0;
}

void linkedListType::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

void linkedListType::print() const
{
    nodeType *current; //pointer to traverse the list

    current = first;    //set current so that it points to
                        //the first node
    while (current != nullptr) //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
}//end print


int linkedListType::length() const
{
    return count;
}  //end length


int linkedListType::front() const
{
    assert(first != nullptr);

    return first->info; //return the info of the first node
}//end front


int linkedListType::back() const
{
    assert(last != nullptr);

    return last->info; //return the info of the last node
}//end back


void linkedListType::copyList(const linkedListType& otherList)
{
    nodeType *newNode; //pointer to create a node
    nodeType *current; //pointer to traverse the list

    if (first != nullptr) //if the list is nonempty, make it empty
       destroyList();

    if (otherList.first == nullptr) //otherList is empty
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.first; //current points to the
                                   //list to be copied
        count = otherList.count;

            //copy the first node
        first = new nodeType;  //create the node

        first->info = current->info; //copy the info
        first->link = nullptr;        //set the link field of
                                   //the node to nullptr
        last = first;              //make last point to the
                                   //first node
        current = current->link;     //make current point to
                                     //the next node

           //copy the remaining list
        while (current != nullptr)
        {
            newNode = new nodeType;  //create a node
            newNode->info = current->info; //copy the info
            newNode->link = nullptr;       //set the link of
                                        //newNode to nullptr
            last->link = newNode;  //attach newNode after last
            last = newNode;        //make last point to
                                   //the actual last node
            current = current->link;   //make current point
                                       //to the next node
        }//end while
    }//end else
}//end copyList

linkedListType::~linkedListType() //destructor
{
   destroyList();
}//end destructor

linkedListType::linkedListType(const linkedListType& otherList)
{
    first = nullptr;
    copyList(otherList);
}//end copy constructor

         //overload the assignment operator
const linkedListType& linkedListType::operator=(const linkedListType& otherList)
{
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else

     return *this;
}

bool search(const int& searchItem){}

void insert(const int& newItem){}

void deleteNode(const int& deleteItem){}



/*TALK ABOUT UNORDERED LIST BEFORE UNCOMMENTING
bool linkedListType::search(const int& searchItem)
{
    nodeType *current; //pointer to traverse the list
    bool found = false;

    current = first; //set current to point to the first
                     //node in the list

    while (current != nullptr && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found;
}//end search


void linkedListType::insert(const int& newItem)
{
    nodeType *newNode; //pointer to create the new node

    newNode = new nodeType; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == nullptr)   //if the list was empty, newNode is also
                        //the last node in the list
        last = newNode;
}//end insert (at front)


void linkedListType::deleteNode(const int& deleteItem)
{
    nodeType *current; //pointer to traverse the list
    nodeType *trailCurrent; //pointer just before current
    bool found;

    if (first == nullptr)    //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //Case 2
        {
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)    //the list has only one node
                last = nullptr;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to
                                   //the second node

            while (current != nullptr && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted
                                       //was the last node
                    last = trailCurrent; //update the value
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode
*/
