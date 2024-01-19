#include <iostream>

#include "Book.hpp"
#include "Media.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "======= Calls with object being of type Media =======" << endl;
	Media m;
	cout << m.getTitle() << endl;
	cout << m.info() << endl;
	cout << "=====================================================" << endl
		 << endl;

	cout << "======= Calls with object being of type Book ========" << endl;
	Book b;
	cout << b.getTitle() << endl;
	cout << b.info() << endl;
	cout << "=====================================================" << endl
		 << endl;

	cout << "= Calls with object being of type Media*, pointing at Media ="
		 << endl;
	Media *mptr = new Media;
	cout << mptr->getTitle() << endl;
	cout << mptr->info() << endl;
	cout << "============================================================="
		 << endl
		 << endl;

	cout << "= Calls with object being of type Book*, pointing at Book ="
		 << endl;
	Book *bptr = new Book;
	cout << bptr->getTitle() << endl;
	cout << bptr->info() << endl;
	cout << "===========================================================" << endl
		 << endl;

	cout << "= Calls with object being of type Media*, pointing at (!!) Book (!!)  ="
		 << endl;
	mptr = new Book;
	cout << mptr->getTitle() << endl;
	cout << mptr->info() << endl;
	cout << "======================================================================="
		 << endl
		 << endl;

	return 0;
}