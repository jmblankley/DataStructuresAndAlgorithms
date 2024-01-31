#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <list>
#include <string>

class Stack : private std::list<std::string>
{
public:
  Stack() {} 

  void push (const std::string &str);
  std::string pop();

  bool isEmpty() const;
};



#endif
