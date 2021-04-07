#include "stdafx.h"
#include "Node.h"

Node::Node()
{
	nextNode = NULL;
	data = 'A';
}

Node::Node(char value)
{
	nextNode = NULL;
	data = value;
}