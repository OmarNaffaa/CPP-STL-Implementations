#pragma once
#include "Node.h"

Node::Node()
{
	data = 0;

	Node* nextNode = '\0';
	Node* prevNode = '\0';
}

Node::Node(int value)
{
	data = value;

	Node* nextNode = '\0';
	Node* prevNode = '\0';
}