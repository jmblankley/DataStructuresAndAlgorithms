# DatastructuresAndAlgorithms

## CSC36000 Introduction

### C++ Review

- Functions
- Command line arguments
- Pass by value vs pass by reference
- The "const" keyword
- Classes
- Overloaded operators
- Polymorphism
  - Writing a function that have the same names but take different parameters and each one does something different.

### C++ Collection Iterators

Consider the following:

```
double arr[] = {7, 22, 1.08, -6, 9};
for(int index = 0; index < 5; index++)
{
	cout << arr[index] << endl;
}
```

Thanks to a 2011 revision of C++, can be rewritten as:

```
double arr[] = {7, 22, 1.08, -6, 9};
for(double val : arr)
{
	cout << val << endl;
}
```

This requires C++ compiler to use modern extensions:

- Applied by default in Visual Studio
  - Needs the `-std=c++20` option added to the g++ compilation
  - `-std=c++20` must come after `-ansi` (if used) in command

Consider the following:

```
double arr[] = {7, 22, 1.08, -6, 9};
for(double val : arr)
{
	val = -1;
}
for(double val : arr)
{
	cout << val << endl;
}
```

This gives (on seperate lines): 7 22 1.08 -6 9

But the following (addded & for pass by reference):

```
double arr[] = {7, 22, 1.08, -6, 9};
for(double &val : arr)
{
	val = -1;
}
for(double val : arr)
{
	cout << val << endl;
}
```

Gives on seperate lines: -1 -1 -1 -1 -1

### The Standard Template Library (STL)

You can declare lists using STL:

```
list<double> myList;
myList.push_back(3.14);
myList.push_back(2.72);
myList.push_back(-4);
```

You can now use the collection iterator:

```
for(double val : myList)
{
	cout << val << endl;
}
```

This gives on separate lines: 2.72 3.14 -4

You can do similar iteration with set, multiset, or any other container in STL

### The auto C++ Keyword

Don't know what type to declare something? Use auto as the type:

```
auto var1 = 4 // var1 is of type int
auto var2 = 4.0 // var2 is of type double
cout << var1/3 << endl; //prints 1
cout << var2/3 << endl; // prints 1.33333
```

You can use the auto within the collection iterator:

```
for(auto val : myList)
{
	cout << val << endl;
}
```

Note that myList could be of type _anything_!

### static and extern

If you want a global variable to only be visible in the current file/scope:

- Use the `static` keyword to do so

```
// no access outside of current scope
static int soemvar:
```

If you want to access a gloabal vairalbe in another scope:

```
// extern says not to declare a variable,
// just note that is exists elsewhere
extern int someVar;
```

### Inheritance in C++

Just as in Java, one class (a child) can inherit from another (a parent):

```
class Media
{
	private:
		string _title;
	public:
		Media();
		string getTitle();
};
```

```
class Book: public Media
{
	private:
		int _pages;
	public:
		Book();
		int getPages();
};
```

Objects of type Book can call getTitle, since the inheritance is public.!
