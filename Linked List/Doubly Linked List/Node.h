#pragma once
class Node
{
public:
	int data;
	Node* nextNode;
	Node* prevNode;

	// functions to be implemented
	Node();
	Node(int data);
};