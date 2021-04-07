#pragma once

#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	//******* MANUAL INSTANTIATION DRIVER CLASS *******

	Node *n1 = new Node(1);
	Node *n2 = new Node(3);
	Node *n3 = new Node(7);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);

	LinkedList mLinkedList;

	if (mLinkedList.Empty())
		mLinkedList.Insert(n1, mLinkedList.headNode);

	mLinkedList.Insert(n2, n1);
	mLinkedList.Insert(n3, n2);
	mLinkedList.Insert(n4, n3);
	mLinkedList.Insert(n5, n4);
	mLinkedList.Display();
	cout << endl;

	// erase the first node by deleting what the head node is pointing to
	mLinkedList.Erase(mLinkedList.headNode);
	mLinkedList.Display();
	cout << endl;

	// erase the 5th (last) node
	mLinkedList.Erase(n5);
	mLinkedList.Display();
	cout << endl;

	/******* CREATING NODE ARRAY BASED DRIVER CLASS*******
	Node* nArr[5];

	for (int i = 0; i < 5; i++)
	{
		nArr[i] = new Node(i * 2);
	}

	LinkedList mLinkedList;

	if (mLinkedList.Empty())
		mLinkedList.Insert(nArr[0], mLinkedList.headNode);

	for (int k = 0; k < 5; k++)
	{
		mLinkedList.Insert(nArr[k + 1], nArr[k]);
	}

	mLinkedList.Display();
	cout << endl;

	// erase the first node by deleting what the head node is pointing to
	mLinkedList.Erase(mLinkedList.headNode);
	mLinkedList.Display();
	cout << endl;

	// erase the 5th node
	mLinkedList.Erase(nArr[4]);
	mLinkedList.Display();
	cout << endl;
	*/
}