#ifndef _GENERIC_STACK_HPP_
#define _GENERIC_STACK_HPP_

#include <list>
#include <string>

template <class T>
class Stack : private std::list<T>
{
public:
  Stack() {}

  void push(const T &genericValue);
  T pop();

  bool isEmpty() const;
};

#endif
