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
