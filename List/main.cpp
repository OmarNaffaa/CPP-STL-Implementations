// listexp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "list.h"
#define CAPACITY 1024
typedef int ElementType;

int main()
{
	List scores;
	if (scores.empty())
		cout << "\n The list is empty\n";
	scores.insert(1, 0);
	scores.insert(3, 1);
	scores.insert(5, 2);
	scores.insert(7, 3);
	scores.insert(9, 4);
	scores.display();
	scores.insert(4, 2);
	scores.display();
	scores.erase(2);
	scores.display();
	List cs=scores.copy();
	cs.display();

    return 0;
}

