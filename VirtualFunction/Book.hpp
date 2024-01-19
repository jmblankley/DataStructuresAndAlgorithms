#ifndef _BOOK_HPP_
#define _BOOK_HPP_

#include "Media.hpp"

class Book : public Media
{
private:
	int _npages;

public:
	Book() : _npages(100)
	{ /* automatically calls parent class constructor*/
	}
	virtual std::string getTitle() { return "I am a Book!"; }
	std::string info() { return "READ Me!"; }
	int getPages() { return _npages; }
};

#endif