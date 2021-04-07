#include <iostream>
using namespace std;
#include "Stack.h"

void Print(Stack stk)
{
	stk.Display();
}

int main()
{
	int cap;
	cout << "Enter stack capacity: ";
	cin >> cap;

	Stack s(cap);
	cout << "Stack created. Empty: " << boolalpha << s.Empty() << endl;

	cout << "How many elements to add to the stack: ";
	int numItems;
	cin >> numItems;
	for (int i = 1; i <= numItems; i++)
	{
		s.Push(100 * i);
	}
	cout << "Stack empty: " << s.Empty() << endl;

	cout << "Contents of stack s: \n";
	Print(s);
	cout << endl;

	cout << "Check that the stack wasn't modified by print:\n";
	s.Display();
	cout << endl;

	Stack t, u;
	t = s;
	u = s;
	cout << "Contents of stacks t and u after t = u = s:\n";
	cout << "u:\n";
	Print(u);
	cout << endl;
	cout << "t:\n";
	Print(t);
	cout << endl;

	cout << "Top value in t: " << t.Top() << endl;

	while (!t.Empty())
	{
		cout << "Popping t: " << t.Top() << endl;
		t.Pop();
	}

	cout << "Stack t empty: " << boolalpha << t.Empty() << endl;
	cout << "\nNow try to receive top value from t." << endl;
	cout << "Top value in t: " << t.Top() << endl;
	cout << "\nTrying to pop t: " << endl;
	t.Pop();

	system("pause");
	return 0;
}