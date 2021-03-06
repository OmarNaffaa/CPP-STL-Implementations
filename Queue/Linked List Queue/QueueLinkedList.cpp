// QueueLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedListQueue.h"
#include "Node.h"
#include <iostream>

using namespace std;

int main()
{
	LinkedListQueue mQueue;
	
	Node* n1 = new Node('R');
	Node* n2 = new Node('A');
	Node* n3 = new Node('C');
	Node* n4 = new Node('E');
	Node* n5 = new Node('C');
	Node* n6 = new Node('A');
	Node* n7 = new Node('R');

	mQueue.Enqueue(n1);
	mQueue.Enqueue(n2);
	mQueue.Enqueue(n3);
	mQueue.Enqueue(n4);
	mQueue.Enqueue(n5);
	mQueue.Enqueue(n6);
	mQueue.Enqueue(n7);

	for (int i = 0; i < 7; i++)
	{
		mQueue.Display();
		mQueue.Dequeue();
		cout << endl;
	}

	cout << endl;
    return 0;
}

