#include "Stack.hpp"

#include <iostream>
#include <string>

using namespace std;

// implement the methods from Stack class here !!!
void
Stack::push (const std::string &str)
{
  push_front(str);
}

std::string
Stack::pop()
{
  if (!isEmpty())
    {
      string firstVal = front();
      pop_front();
      return firstVal;
    }

  // if we get here, stack is empty!
  cerr << "Attempt to pop an empty stack!" << endl;
  return ">>>>ERROR - EMPTY STACK POP<<<<";
}

bool
Stack::isEmpty() const
{
  return empty();
}
