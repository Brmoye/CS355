#include <iostream>
#include "arrayStack.h"

using namespace std;

int main()
{
	arrayStack<int> myStack(10);
	myStack.push(4);
	myStack.push(12);
	myStack.push(6);

	cout<<myStack.top()<<endl;

	myStack.pop();

	cout<<myStack.top()<<endl;


	return 0;
}

//NOTE: ALSO SEE PAGE 1197 - EXAMPLE 17-1 for a more complete main function
