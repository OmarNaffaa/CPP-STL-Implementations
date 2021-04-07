#include <iostream>
#include "Node.h"
#include "DLL.h"
using namespace std;

int main()
{
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);

	DLL doublyLinkedList;

	if (doublyLinkedList.Empty() == true)
		cout << "your list is empty \n";
	else
		cout << "your list is not empty \n";

	// inserting the first node
	doublyLinkedList.Insert(n1, doublyLinkedList.headNode);
	doublyLinkedList.Display();

	// inserting the second node
	doublyLinkedList.Insert(n2, n1);
	doublyLinkedList.Display();

	// inserting the thrid node
	doublyLinkedList.Insert(n3, n2);
	doublyLinkedList.Display();

	// inserting the fourth node after the first node (i.e. as the new second node)
	doublyLinkedList.Insert(n4, n1);
	doublyLinkedList.Display();

	// remove the third node n3
	doublyLinkedList.Erase(n3);
	doublyLinkedList.Display();

	// remove the second node n2
	doublyLinkedList.Erase(n2);
	doublyLinkedList.Display();

	// remove the node n4
	doublyLinkedList.Erase(n4);
	doublyLinkedList.Display();

	// remove the first node n1
	doublyLinkedList.Erase(n1);
	doublyLinkedList.Display();
}