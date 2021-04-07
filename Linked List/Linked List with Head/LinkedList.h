#pragma once

#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList
{
public:
	Node* headNode;
	int listSize;

	// functions to be implemented
	LinkedList();
	bool Empty();
	void Insert(Node* newNode, Node* prevNode);
	void Erase(Node* prevNode);
	void Display();
};