#ifndef _MEDIA_HPP_
#define _MEDIA_HPP_

#include <string>

class Media
{
private:
	std::string _title;

public:
	Media() : _title("Generic Media") {}
	virtual std::string getTitle() { return "I am Media!"; }
	std::string info() { return "USE Me!"; }
};

#endif