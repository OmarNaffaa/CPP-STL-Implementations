#pragma once
#include "Node.h"

class DLL
{
public:
	Node* headNode;
	Node* firstNode;
	int listSize;

	// functions to be implemented
	DLL();
	bool Empty();
	void Insert(Node* toBeInserted, Node* previousNode);
	void Erase(Node* toBeErased);
	void Display();
};

