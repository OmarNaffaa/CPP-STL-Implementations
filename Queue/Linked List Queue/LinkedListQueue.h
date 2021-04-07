#pragma once
#include "Node.h"

class LinkedListQueue
{
public:
	Node* qFront;
	Node* qBack;

	LinkedListQueue();
	bool Empty() const;
	void Enqueue(Node* newNode);
	void Dequeue();
	Node* Front();
	void Display();
};

