#pragma once
#include "Node.h"

class CLH
{
public:
	Node* headNode;
	int listSize;

	// DID NOT ADD FIRST NODE ON PRACTICE ATTEMPT
	Node* firstNode;

	// functions to be implemented
	CLH();
	bool Empty();
	void Insert(Node* newNode, Node* prevNode);
	void Erase(Node* prevNode);
	void Display();
};

