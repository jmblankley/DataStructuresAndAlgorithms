#include <iostream>
#include <stack>
#include "GenericStack.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	Stack<string> stk;

	for (int i = 1; i < argc; i++)
	{
		stk.push(argv[i]);
	}

	while (!stk.isEmpty())
	{
		string val = stk.pop();
		cout << val << endl;
	}

	return 0;
}