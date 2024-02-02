// Your implementation of the Stack class goes here!!!!

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
	return front();
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
