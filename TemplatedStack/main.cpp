#include "GenericStack.hpp"
#include "GenericStack.tpp"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  Stack<string> myStack;
  Stack<int> intStack;

  for (int index = 1; index < argc; index++)
  {
    myStack.push(argv[index]);
    intStack.push(atoi(argv[index]));
  }

  // myStack.push_back("gotcha!");

  while (!myStack.isEmpty())
  {
    string val = myStack.pop();
    cout << val << endl;
  }

  cout << "===========================================================================" << endl;

  while (!intStack.isEmpty())
  {
    string val = intStack.pop();
    cout << val << endl;
  }

  return 0;
}
