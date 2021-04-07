#include "stdafx.h"
#include <iostream>
using namespace std;
#include "list.h"
#define CAPACITY 1024
typedef int ElementType;

List::List()
{
	listsize = 0;
}

// check the list size to see if the list is empty
bool List::empty()
{
	if (listsize == 0)
		return true;
	else
		return false;
}

// insert an element in the list, if not the last case you push move each value down and then enter
// the value. this makes the complexity O(n) since n items would have to move in the worst case
void List::insert(ElementType item, int pos)
{
	if (listsize == CAPACITY)
		cout << "no space is available for insertion \n";
	else
	{  
		if ((pos < 0) || (pos > listsize))
			cout << "wrong position specified\n";
		else
		{	
			if (listsize == 0)
				dataArray[0] = item;
			else
			{	
				for (int i = listsize; i > pos; i--)
					dataArray[i] = dataArray[i - 1];
				dataArray[pos] = item;
			}
			listsize++;
		}
	}
}

// traverse the list to display its values
void List::display()
{	
	for (int i = 0; i < listsize; i++)
		cout << dataArray[i] << ", ";
	cout << "\n The list size is " << listsize << "\n";
}

// erase an item in the list based on its position and shift the element down one place
void List::erase(int pos)
{	if (empty())
		cout << "\n The list is empty\n";
	else
	{	
		if ((pos < 0) || (pos >= listsize))
			cout << "wrong position\n";
	    else
	    {
			for (int i = pos; i < listsize-1; i++)
			dataArray[i] = dataArray[i + 1];
		    //dataArray[listsize - 1] = 0; // set the last value to 0 since everything was shifted down
		    listsize--;
	  }
   }
}

// copy the contents of one list into another
List List::copy()
{	
	List copiedList;
	for (int i = 0; i < listsize; i++)
		copiedList.insert(dataArray[i], i);
	return copiedList;
}
 