#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>
#include <list>
using namespace std;

template <class T>
class Stack : private list<string>
{
public:
	void push(const string &str);
	string pop();
	bool isEmpty() const;
};

#endif