#pragma once

#include "Node.h"
#include "CLH.h"
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

	CLH mLinkedList;

	// check if the list is empty
	if (mLinkedList.Empty())
		cout << "initial list is empty \n";
	else
		cout << "initial list is not empty \n";

	// perform insertions and display them for diagnostics
	mLinkedList.Insert(n1, mLinkedList.headNode);
	mLinkedList.Display();
	mLinkedList.Insert(n2, n1);
	mLinkedList.Display();
	mLinkedList.Insert(n3, n2);
	mLinkedList.Display();
	mLinkedList.Insert(n4, n3);
	mLinkedList.Display();
	mLinkedList.Insert(n5, n4);
	mLinkedList.Display();
	mLinkedList.Erase(n3);
	mLinkedList.Display();
}