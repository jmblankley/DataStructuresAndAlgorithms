#include <iostream>
#include <list>
using namespace std;

int main(int argc, char *argv[])
{
	list<int> myNumbers;

	for (int i = 1; i < argc; i++)
	{
		myNumbers.push_back(atoi(argv[i]));
	}

	myNumbers.sort();

	for (int val : myNumbers)
	{
		cout << val << endl;
	}

	return 0;
}