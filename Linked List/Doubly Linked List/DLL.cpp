#pragma once
#include "DLL.h"
#include "Node.h"
#include <iostream>
using namespace std;

DLL::DLL()
{
	headNode = new Node();
	firstNode = headNode;
	listSize = 0;
}

bool DLL::Empty()
{
	if (firstNode->nextNode == '\0')
		return true;
	else
		return false;
}

void DLL::Insert(Node* tobeInserted, Node* previousNode)
{
	// connect the prev node of the to be inserted node to the node before it
	tobeInserted->prevNode = previousNode;

	// connect the to be inserted node to the node after it
	// (NOTE: does not need to be in the if statement because an error will not be
	//        produced since the next node of the previous node will be set to null
	//        if there is no node after it)
	tobeInserted->nextNode = previousNode->nextNode;

	// if a next node does exist connect it to the new node
	if (previousNode->nextNode != '\0')
		previousNode->nextNode->prevNode = tobeInserted;

	// connect the previous node to the new node LAST
	previousNode->nextNode = tobeInserted;

	listSize++;
}

void DLL::Erase(Node* toBeErased)
{
	// erasing a node that is not the last one
	if (toBeErased->nextNode != '\0')
	{
		toBeErased->nextNode->prevNode = toBeErased->prevNode; // delete 3
	}

	// erasing a node that is not the first one
	if (toBeErased->prevNode != '\0')
	{
		toBeErased->prevNode->nextNode = toBeErased->nextNode; // delete 2
	}

	// erasing the first node
	else 
		firstNode = toBeErased->nextNode;

	// generally applicable nodes to erase (works for all cases)
	toBeErased->nextNode = '\0';
	toBeErased->prevNode = '\0';

	listSize--;
}

void DLL::Display()
{
	Node* iterator = headNode->nextNode;

	cout << "\n*** Current List Contents ***" << endl;
	for (int i = 0; i < listSize; i++)
	{
		cout << iterator->data << endl;
		iterator = iterator->nextNode;
	}
}