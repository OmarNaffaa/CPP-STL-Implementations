#pragma once
#define CAPACITY 1024
typedef int ElementType;
class List
{
	int listsize;
	ElementType dataArray[CAPACITY];
public:
	List();
	bool empty();
	void insert(ElementType item, int pos);
	void erase(int pos);
	void display();
	List copy();
};

