/*-------------------------------------------------------------------------------------
		                 Driver program to test the Stack Class
-------------------------------------------------------------------------------------*/
#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack mStack;
	// boolaplha formats boolean statements to say "true" or "false"
	cout << "Stack created. Empty: " << boolalpha << mStack.Empty() << endl;  

	int numItems;
	cout << "How many elements to add to the stack: ";
	cin >> numItems;
	
	// add numItems amount of random values to the stack
	for (int i = 1; i <= numItems; i++)
	{
		mStack.Push(i);
	}

	cout << "Stack contents:\n";
	mStack.Display();

	cout << "Stack empty: " << boolalpha << mStack.Empty() << endl;
	cout << "Top value: " << mStack.Top() << endl;

	while (!mStack.Empty())
	{
		cout << "Popping " << mStack.Top() << endl;
		mStack.Pop();
	}

	cout << "Stack empty: " << boolalpha << mStack.Empty() << endl;
	cout << "Top value: " << mStack.Top() << endl;
	cout << "Trying to pop: " << endl;
	mStack.Pop();

	system("pause");
	return 0;
}