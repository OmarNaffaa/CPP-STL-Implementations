#pragma once
#include <iostream>
#ifndef STACK
#define STACK

const int STACK_CAPACITY = 128;
typedef int StackElement; // change type depending on application

class Stack
{
public:
	Stack();
	bool Empty() const; // means this function can't change any member variables
	void Push(const StackElement& value);
	void Display() const;
	StackElement Top() const;
	void Pop();

private:
	StackElement mArray[STACK_CAPACITY];
	int myTop;
};

#endif