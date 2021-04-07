#include "CHDL.h"
#include "Node.h"
#include <iostream>
#include <iomanip>
using namespace std;

CHDL::CHDL()
{
	headNode = new Node();

	// create the first node and set it to the head node
	headNode->nextNode = headNode;
	headNode->prevNode = headNode;

	listSize = 0;
}

bool CHDL::Empty()
{
	if (headNode->nextNode == headNode)
		return true;
	else
		return false;
}

void CHDL::Insert(Node* toBeInserted, Node* succNode)
{
	toBeInserted->nextNode = succNode;
	toBeInserted->prevNode = succNode->prevNode;
	succNode->prevNode->nextNode = toBeInserted;
	succNode->prevNode = toBeInserted;

	listSize++;
}

void CHDL::EraseNode(Node* toBeErased)
{
	Node* pred = toBeErased->prevNode;
	Node* succ = toBeErased->nextNode;

	pred->nextNode = succ;
	succ->prevNode = pred;

	listSize--;
}

int CHDL::EraseNodeByData(int value)
{
	int numberOfDeletedNodes = 0;

	// traverse the list to delete nodes with the specified data value
	Node* iterator = headNode->nextNode; // point the iterator to the first node

	while (iterator->nextNode != headNode)
	{
		if (iterator->data == value)
		{
			EraseNode(iterator);
			numberOfDeletedNodes++;
		}

		iterator = iterator->nextNode;
	}

	return numberOfDeletedNodes;
}

void CHDL::Display()
{
	Node* iterator = headNode->nextNode;

	cout << "*** Current List Contents ***" << endl;
	for (int i = 0; i < listSize; i++)
	{
		if (i % 20 == 0 && i != 0)
			cout << endl;
		cout << setw(4) << iterator->data;
		iterator = iterator->nextNode;
	}

	cout << "\n\nSize of list: " << listSize << endl;
	cout << endl;
}

void CHDL::ReverseDisplay()
{
	Node* iterator = headNode->prevNode;

	cout << "*** Current List Contents In Reverse ***" << endl;
	for (int i = (listSize-1); i >= 0; i--)
	{
		cout << setw(4) << iterator->data;
		if (i % 20 == 0)
			cout << endl;
		iterator = iterator->prevNode;
	}

	cout << "\nSize of list: " << listSize << endl;
	cout << endl;
}

double CHDL::CalculateMean()
{
	Node* iterator = headNode->nextNode;
	double total = 0;

	for (int i = 0; i < listSize; i++)
	{
		total += iterator->data;
		iterator = iterator->nextNode;
	}

	double meanValue = total / listSize;
	return meanValue;
}