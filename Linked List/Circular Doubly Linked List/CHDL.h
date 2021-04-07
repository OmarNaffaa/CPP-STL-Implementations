#pragma once
#include "Node.h"

class CHDL
{
public:
	Node* headNode;
	int listSize;

	// functions to be implemented
	CHDL();
	bool Empty();
	void Insert(Node* toBeInserted, Node* succNode);
	void EraseNode(Node* toBeErased);
	int EraseNodeByData(int value);
	void Display();
	void ReverseDisplay();
	double CalculateMean();
};

