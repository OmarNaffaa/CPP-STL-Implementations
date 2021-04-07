#pragma once
#include "CLH.h"
#include "Node.h"
#include <iostream>
using namespace std;

typedef Node* nodePtr;

// Default constructor
CLH::CLH()
{
	// initialize the head node with arbitrary data
	headNode = new Node();

	// DID NOT ADD FIRST NODE ON PRACTICE ATTEMPT
	firstNode = headNode;
	firstNode->nextNode = firstNode;

	// initialize the size of the list to 0
	listSize = 0;
}

bool CLH::Empty() {
	// since the list is circular, if the headnode is pointing
	// to itself there must be nothing else in the list

	// DID NOT ADD FIRST NODE ON PRACTICE ATTEMPT
	if (firstNode->nextNode == firstNode)
		return true;
	else
		return false;
}

void CLH::Insert(nodePtr newNode, nodePtr prevNode)
{
	// attach the new node to the list first
	newNode->nextNode = prevNode->nextNode;
	// afterwards, connect the previous node to the new node
	prevNode->nextNode = newNode;
	// increment the size of the list
	listSize++;
}

void CLH::Erase(nodePtr prevNode)
{
	nodePtr toBeDeleted;
	if (Empty())
		cout << "\nThe list is empty; there is nothing to erase" << endl;
	else
	{
		/* 
		// entering the last node will erase the first node rather than creating a
		// null pointer exception since the list is circular, therefore no additional
		// checks are needed
		*/
		// copy the address of the node to be deleted to avoid memory leaks
		toBeDeleted = prevNode->nextNode;
		// reconnect the previous node before erasing the node to be erased
		prevNode->nextNode = prevNode->nextNode->nextNode;
		// delete the node to be deleted by setting it to a null pointer
		toBeDeleted = '\0';
		// decrement the size of the list
		listSize--;
	}
}

void CLH::Display()
{
	cout << "\*** Current List Contents ***\n";

	// create an iterator node to traverse the list without losing
	// the position of the headnode
	nodePtr iterator = headNode->nextNode;

	for (int i = 0; i < listSize; i++)
	{
		cout << iterator->data << endl;
		iterator = iterator->nextNode;
	}
}