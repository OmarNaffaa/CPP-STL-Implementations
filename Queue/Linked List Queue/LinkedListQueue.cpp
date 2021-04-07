#include "stdafx.h"
#include "LinkedListQueue.h"
#include <iostream>

using namespace std;

LinkedListQueue::LinkedListQueue()
{
	qFront = NULL;
	qBack = NULL;
}

bool LinkedListQueue::Empty() const
{
	return (qFront == NULL);
}

void LinkedListQueue::Enqueue(Node* newNode)
{
	if (Empty())
	{
		qFront = newNode;
	}
	else
	{
		qBack->nextNode = newNode;
	}

	qBack = newNode;
}

void LinkedListQueue::Dequeue()
{
	if (Empty())
	{
		cout << "\nThe Queue is empty...\n" << endl;
	}
	else
	{
		Node* tempNode = qFront;
		qFront = qFront->nextNode;
		tempNode = NULL;
		//qFront->nextNode = qFront->nextNode->nextNode;
	}
}

Node* LinkedListQueue::Front()
{
	return (qFront);
}

void LinkedListQueue::Display()
{
	Node* iterator = qFront;

	if (Empty())
	{
		cout << "Nothing to display, queue is empty..." << endl;
		return;
	}

	while (iterator != NULL)
	{
		cout << iterator->data << " ";
		iterator = iterator->nextNode;
	}
}