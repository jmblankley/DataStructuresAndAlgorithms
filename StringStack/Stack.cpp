#include "Stack copy.tpp"

void Stack::push(const string &str)
{
	push_front(str);
}
string Stack::pop()
{
	if (!isEmpty())
	{
		string firstVal = front();
		pop_front();
		return firstVal;
	}
	cerr << "Attempt to pop an empty stack!" << endl;
	return ">>> ERROR - EMPTY STACK POP <<<";
}
bool Stack::isEmpty() const
{
	return empty();
}