#include "Stack.h"

#include <iostream>
using namespace std;

Stack::Stack()
{
	myTop = -1;
}

bool Stack::Empty() const
{
	// if the stack is empty (myTop == -1) return true, otherwise return false
	return(myTop == -1);
}

void Stack::Push(const StackElement& value)
{
	if (myTop < STACK_CAPACITY - 1) // if there is space in the stack
	{
		myTop++;
		mArray[myTop] = value;
	}
	else
	{
		cerr << "*** Stack full -- can't add new value ***\n"
			<< "Must increase the value of STACK_CAPACITY in Stack.h\n";
		exit(1); // terminate the program
	}
}

void Stack::Display() const
{
	for (int i = myTop; i >= 0; i--)
	{
		cout << mArray[i] << endl;
	}
}

StackElement Stack::Top() const
{
	if (!Empty())
		return (mArray[myTop]);
	else
	{
		cerr << "*** Stack is empty -- returning incorrect value ***\n";
		StackElement incorrectVal = 1024;
		return incorrectVal;
	}
}

void Stack::Pop()
{
	if (!Empty())
		myTop--;
	else
		cerr << "*** Stack is empty -- can't remove a value ***\n";
}