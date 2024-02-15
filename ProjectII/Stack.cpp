/********************************************************
 * File:Stack.cpp                                       *
 * Author: Joshua M Blankley                            *
 * Date: 1/2024                                         *
 * Purpose: Implementation of the Stack class.			*
 *      	My contributions were an update to			*
 * 			the existing codebase.                      *
 ********************************************************/

#include "Stack.hpp"

#include <iostream>

using namespace std;

void Stack::push(ActivationRecord *newAR)
{
	push_front(newAR);
}

ActivationRecord *Stack::pop()
{
	if (!isEmpty())
	{
		ActivationRecord *firstVal = front();
		pop_front();
		return firstVal;
	}

	cerr << "Attempt to pop an empty stack!" << endl;
}

ActivationRecord *Stack::top() const
{
	ActivationRecord *first = front();
	return first;
}

ActivationRecord *Stack::peek() const
{
	auto secondElement = next(begin(), 1);

	return *secondElement;
}

bool Stack::isEmpty() const
{
	return empty();
}

#include "Stack.hpp"

ostream &operator<<(ostream &os, const Stack &s)
{
	os << "Stack [";

	// Iterate over the stack and print each ActivationRecord pointer
	auto it = s.begin();
	if (it != s.end())
	{
		os << *(*it);
		++it;
	}

	while (it != s.end())
	{
		os << ", " << *(*it);
		++it;
	}

	os << "]";
	return os;
}
