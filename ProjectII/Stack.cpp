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

// Function: push
// Parameters: none
// Purpose: Push a new activation record onto the stack
void Stack::push(ActivationRecord *newAR)
{
	push_front(newAR);
}

// Function: pop
// Parameters: none
// Purpose: Pop the top activation record from the stack
ActivationRecord *Stack::pop()
{
	// Check if the stack is not empty
	if (!isEmpty())
	{
		// Retrieve the first value (top) of the stack
		ActivationRecord *firstVal = front();
		// Remove the first value from the stack
		pop_front();
		// Return the first value
		return firstVal;
	}

	// If the stack is empty, print an error message
	cerr << "Attempt to pop an empty stack!" << endl;
}

// Function: top
// Parameters: none
// Purpose: Get the top activation record of the stack without removing it
ActivationRecord *Stack::top() const
{
	// Get the first (top) element of the stack
	ActivationRecord *first = front();
	return first;
}

// Function: peek
// Parameters: none
// Purpose: Get the second element from the top of the stack without removing it
ActivationRecord *Stack::peek() const
{
	// Get an iterator pointing to the second element from the beginning of the stack
	auto secondElement = next(begin(), 1);
	// Return the second element
	return *secondElement;
}

// Function: isEmpty
// Paremeters: none
// Purpose: Check if the stack is empty
bool Stack::isEmpty() const
{
	return empty();
}

// Operator Overload: <<
// Parameters: ostream - the place to output to
//				Stack - the object needed to be output
// Purpose: to output the current stack
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
