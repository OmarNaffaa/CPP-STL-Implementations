#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

// List Constructor
LinkedList::LinkedList()
{
	// adds an arbitrary data value to the head node
	headNode = new Node(0);
	listSize = 0;
}

// Checks whether the list is empty
bool LinkedList::Empty()
{
	if (headNode->nextNode == '\0')
		return true;
	else
		return false;
}

// Inserts another node into the list
void LinkedList::Insert(Node* newNode, Node* prevNode)
{
	// set the node to be inserted to point to the node
	// whose spot is being taken
	newNode->nextNode = prevNode->nextNode;

	// once the necessary connection is made, connect the node
	// that is in place before the new node to the newly inserted node
	prevNode->nextNode = newNode;

	listSize++;
}

// Removes a node from the list by disconnecting the node from its
// previous node after setting the previous node to point to the new
// next node
void LinkedList::Erase(Node* prevNode)
{
	// check if there is anything in the list to erase
	// otherwise, do nothing
	if (!Empty())
	{
		// see if the node to be deleted is the special case where 
		// the user wants to delete the last node
		if (prevNode->nextNode != '\0')
		{
			Node* toBeDeleted = prevNode->nextNode;
			// set the previous node to point to the node after the one to be deleted
			prevNode->nextNode = prevNode->nextNode->nextNode;
			// disconnect the node to be deleted
			toBeDeleted->nextNode = '\0';
			listSize--;
		}
		else
		{
			cout << "You entered the last node, which should be erased by\nselecting the previous node" << endl;
		}
	}
}

// Displays the elements of the LinkedList
void LinkedList::Display()
{
	// create an iterator node that starts at the
	// first node by pointing at the same place
	// as the head node
	Node* iterator = headNode->nextNode;

	for (int i = 0; i < listSize; i++) 
	{
		// print the data in each node
		cout << iterator->data << endl;
		// increment the node to be displayed
		iterator = iterator->nextNode;
	}
}