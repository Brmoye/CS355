
using namespace std;

template <class Type>
class arrayStack
{
public:
    const arrayStack<Type>& operator=(const arrayStack<Type>&);
      //Overload the assignment operator.

    void initializeStack();
      //Function to initialize the stack to an empty state.
      //Postcondition: stackTop = 0

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //               otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //               otherwise returns false.

    void push(const Type& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem
      //               is added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program
      //               terminates; otherwise, the top element
      //               of the stack is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top
      //               element is removed from the stack.

    arrayStack(int stackSize = 100);
      //constructor
      //Create an array of the size stackSize to hold
      //the stack elements. The default stack size is 100.
      //Postcondition: The variable list contains the base
      //               address of the array, stackTop = 0, and
      //               maxStackSize = stackSize.

    arrayStack(const arrayStack<Type>& otherStack);
      //copy constructor

    ~arrayStack();
      //destructor
      //Remove all the elements from the stack.
      //Postcondition: The array (list) holding the stack
      //               elements is deleted.

private:
    int maxStackSize; //variable to store the maximum stack size
    int stackTop;     //variable to point to the top of the stack
    Type *list;       //pointer to the array that holds the
                      //stack elements

    void copyStack(const arrayStack<Type>& otherStack);
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and
      //               assigned to this stack.
};
template <class Type>
arrayStack<Type>::arrayStack(int stackSize)
{
    if (stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;   //set the stack size to
                                    //the value specified by
                                    //the parameter stackSize

    stackTop = 0;                   //set stackTop to 0
    list = new Type[maxStackSize];  //create the array to
                                    //hold the stack elements
}//end constructor

template <class Type>
void arrayStack<Type>::initializeStack()
{
    stackTop = 0;
}//end initializeStack

template <class Type>
bool arrayStack<Type>::isEmptyStack() const
{
    return (stackTop == 0);
}//end isEmptyStack

template <class Type>
bool arrayStack<Type>::isFullStack() const
{
    return (stackTop == maxStackSize);
} //end isFullStack

template <class Type>
void arrayStack<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;   //add newItem to the
                                    //top of the stack
        stackTop++; //increment stackTop
    }
    else
        cout << "Cannot add to a full stack." << endl;
}//end push

template <class Type>
Type arrayStack<Type>::top() const
{

    return list[stackTop - 1];  //return the element of the
                                //stack indicated by
                                //stackTop - 1
}//end top

template <class Type>
void arrayStack<Type>::pop()
{
    if (!isEmptyStack())
        stackTop--;      //decrement stackTop
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop



template <class Type>
arrayStack<Type>::~arrayStack() //destructor
{
    delete [] list; //deallocate the memory occupied
                    //by the array
}//end destructor

template <class Type>
void arrayStack<Type>::copyStack
                (const arrayStack<Type>& otherStack)
{
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    list = new Type[maxStackSize];

        //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)
        list[j] = otherStack.list[j];
} //end copyStack


template <class Type>
arrayStack<Type>::arrayStack(const arrayStack<Type>& otherStack)
{
    list = nullptr;

    copyStack(otherStack);
}//end copy constructor

template <class Type>
const arrayStack<Type>& arrayStack<Type>::operator=
                            (const arrayStack<Type>& otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
} //end operator=


