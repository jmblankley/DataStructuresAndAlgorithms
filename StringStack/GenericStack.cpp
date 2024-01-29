#include "GenericStack.hpp"
template <class T>

void Stack<T>::push(const T &str)
{
	push_front(str);
}

template <class T>
T Stack<T>::pop()
{
	if (!isEmpty())
	{
		T firstVal = front();
		pop_front();
		return firstVal;
	}
	cerr << "Attempt to pop an empty stack!" << endl;
	return ">>> ERROR - EMPTY STACK POP <<<";
}

template <class T>
bool Stack<T>::isEmpty() const
{
	return empty();
}