#include <iostream>
#include "Node.h"
#include "CHDL.h"
using namespace std;

const int SIZE = 100;

int main()
{
	// generate a set of random numbers
	srand(1024);
	int randomNumber;

	// instantiate 100 node objects with random data values in the range [60, 100]
	Node* mArray[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		randomNumber = rand() % (100 + 1 - 60) + 60; // random number between 50 - 100 inclusive
		mArray[i] = new Node(randomNumber);
	}

	// create the CHDL list
	CHDL mList;

	// insert all nodes with headNode as the succeeding node since
	// it is at the end
	for (int i = 0; i < SIZE; i++)
	{
		mList.Insert(mArray[i], mList.headNode);
	}

	// display all nodes and the size of the list
	mList.Display();

	// display all nodes and the size of the list IN REVERSE
	mList.ReverseDisplay();

	// calculate and display the mean
	mList.CalculateMean();

	// delete the first node
	mList.EraseNode(mArray[0]);

	// display all the nodes and the size of the list
	mList.Display();

	// display all the nodes and the size of the list IN REVERSE
	mList.ReverseDisplay();

	// calculate and display the mean
	cout << "Calculated Mean: " << endl;
	cout << mList.CalculateMean();
	cout << '\n' << endl;

	// erase all nodes with the data value 1
	cout << "Nodes with value 70 erased: " << mList.EraseNodeByData(70) << "\n\n";

	// display all the nodes and the size of the list
	mList.Display();

	// display all the nodes and the size of the list IN REVERSE
	mList.ReverseDisplay();

	// calculate and display the mean
	cout << "Calculated Mean: " << endl;
	cout << mList.CalculateMean();
}