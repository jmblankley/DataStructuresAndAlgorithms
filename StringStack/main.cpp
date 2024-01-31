#include "Stack.hpp"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  Stack myStack;


  
  for (int index=1; index<argc; index++)
    {
      myStack.push(argv[index]);
    }

  //myStack.push_back("gotcha!");
  
  while (!myStack.isEmpty())
    {
      string val = myStack.pop();
      cout << val << endl;
    }

  return 0;
}
