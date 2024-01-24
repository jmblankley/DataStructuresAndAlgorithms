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

Some other notes on inheritance:

- Instead of pulic, a parent can be inherited in a private manner

```
class DVD: private Media
{ // ...
```

- In this case, object of type DVD can _not_ call Media's public methods
- but method implemented in the DVD class _can_ call Media's public methods.

Objects of type Book can call getTitle, since the inheritance is public!

### Virtal Functions

Consider the following:

```
class M<edia
{
public:
	Media();
	virtual string getTitle(); { return "I am Media!";}
	string info() {return "USE Me!";}
};
```

Media m = new Media();
m.getTitle();
m.info();
or
Media \*m = new Media();
m->getTitle();
m->info();

```
class Book: public Media
{
public:
	Book();
	virtual string getTitle {return "I am a Book!";}
	string info() {return "READ Me!";}
};
```

Book b = new Book();
b.getTitle();
b.info();
or
**Media** \*m = new Book();

m->getTitle(); // I am a Book! <- notice that the virtual function does what is expected

m->info(); // USE me! <- the non virutal function gives .info from the Media class

- In the Book declaration since it inherits media, it technically _is_ Media.
- When there is a pointer and you try to call a virtual function it will find the type of what you are actually trying to call and do that instead.

### Destructors

Method that is _automatically_ called as an object either

- is deleted (pointer reference)
- goes out of scope (ex. method ends)

Like constructors, these have a specific name:

- starts with a tilde sign (~)
- followed by the name of the class

By wary:

- usually used to delete dynamically allocated memory
- but ... what if that memory is being used elsewhere?

### Heaps

- Heap Sort Algorithm
  - Upheap:
    - Check the parent of the node and see if it greater than the current node.
    - If it is greater than, swap indicies.
    - If it is not, stay at the current index.
    - This method will put the smallest value at the top.
  - Downheap:
    - Pick off the top value (smallest value).
    - Store it in a different array.
    - Take the bottom value from the tree and put it at the top.
    - Check the left and right child
      - Make sure the child exists
      - Pick the child with the lowest value and swap with it.
    - Repeat from 'Check the left and right child' until the node you are moving is at the bottom.
    - Pick off the top value ... start again.
  - parent **index** = my **index** / 2;
  - left child **index** = my **index** x 2;
  - right child **index** = my **index** x 2 + 1;

## Why Data Structures and Algorithms?

### Data Structures

- "Why not just use a big array?"
- Example Problem:
  - Search for a number k in a set of N numbers
- Solution #1 (Array)
  - Store numbers in an array of size N
  - Iterate through array until find k
  - Number of checks
    - Best Case: 1 (k = 29)
    - Worst Case: N (k = 25)
    - Average Case: N / 2
- Solution #2 (Binary Search Tree)
  - Store numbers in a binary search tree
  - Search tree until find k
  - Number of checks:
    - Best Case: 1 (k = 29)
    - Worst Case: logN (ex. k = 25)
    - Average Case: (logN) / 2
- Analysis
  - Does it matter?
    - Assume:
      - N = 1000000000 = 1 billion (Walmart transactions in 100 days)
      - 1 Ghz processor = 10^9 cycles per second
    - Solution #1
      - Worst Case: 1 billion checks = 10 seconds
    - Solution #2
      - Worst Case log(10^9) = 30 checks = 0.000003 seconds

### Advances Data Structures

- Does it matter?
  - The Message
    - Appropriate data structures ease design and improve performance
  - ???
    - ???

### Purpose

- Why bother analyzing code; isn't getting it to work enough?
  - Prior examples show otherwise
- Estimate time

### Algorithms

- Problem
  - Sppecifies the desired input-output relationship
- Algorithm
  - Well-defined computational ...

### Algorithm Analysis

- Predict resource utilization of an algorithm
  - Running time
  - Memory
- Dependent on Architecutre
  - Serial (what you use every day)
  - Parallel
  - Quantum

### What to Analyze

- Running Time T(N)
  - N is typically the size of the input
  - Sorting?
  - Multiplying two integers?
  - Multiplying two matricies?
  - Traversing a graph?
- T(N) measures number of primitive operations performed
  - e.g., addition, multiplication, comparison, assignment, ...
- Example:

  ```
  int sum(int n)						// Cost
  {
  	int partialSum;					// 0

  	partialSum = 0;					// 1
  	for(int i = 1; i <= n; i++)		// 1 + (N + 1) + 1
  	{
  		partialSum += i * i * i;	// N * (1 + 1 + 2)
  	}
  	return partialSum;				// 1
  }
  									// T(N) = 6N + 4
  ```

- Worst-Case running time T_worst(N)
- Average-Case running time T_avg(N)
- T_avg(N) <= T_worst(N)
- Typically analyze worst-case behavior
- Average case hard to compute
- Worst-case gives guaranteed upper bound

### Rate of Growth

- Exact expressions for T(N) meaningless and hard to compare
- Rate of Growth:
  - Asymptotic behavior of T(N) as N gets big
  - Usually expressed as fastest growing term in T(N), dropping constant coefficients
    - e.g., T(N) = 3N^2 + N + 1 -> Θ(N^2)
  - Θ is read as "big-theta"
- T(N) = O(f(N)) if there\_ are positive constants c and n_0 such that T(N) <= c\*f(N) when N >= n_0
  - Asymptotic upper bound
  - "Big-Oh" notation
- T(N) = OMEGA(g(N)) if there are ...

### Maximum Subsequence Example
- Maximum subsequence sum problem
	- Given (possibly negative) integers,A_1, A_2, ..., A_N, find the maximum value of:
   ...

	- Algorithm 1
		```
		MaxSubSum1(A,N)
			maxSum = 0;
			for i = 1 to N
				for j = i to N
					sum = 0;
					for k = i to j
						sum = sum + A[k]
					if(sum > maxSum)
						maxSum = sum
			return maxSum
		```
		- This is Θ(N^3)
 
	- Algorithm 2
		```
		MaxSubSum2(A,N)
			maxSum = 0;
			for i = 1 to N
				sum = 0;
				for j = i to N
					sum = sum + A[j];
					if sum > maxSum
						maxSum = sum
		return maxSum
		```
		- This is Θ(N^2)

	- Algorithm 3
		- Recursive, divide and conquer
			- Divide sequence in half: A[1 ... center] and A[center+1 ... N]
				- Recursively compute MaxSubSum of left half
				- Recursively compute MaxSubSum of right half
				- Compute MaxSubSum of sequence containing the two elements A[center] and A[center + 1]
			- Return the max of these
		 ```
		 MaxSubSum3(A, i, j)
				if(i = j and A[i] >= 0)
					return A[i]
				if(i = j and A[i] < 0)
					return ...
		 ```
		- This give T(N) = Θ(N*log(N))

	- Algorithm 4
		```
		MaxSubSum4(A,N)
		maxSum = 0
		sum = 0
		for j = 1 to N
			sum = sum + A[j]
			if(sum > maxSum)
				maxSum = sum
			else if(sum < 0)
				sum = 0
		return maxSum
		```
		- This gives T(N) = Θ(N)
    
### Exponentiation

- Write an algorithm to calculate
  - x^N where x is a double and N is a positive integer
- Most obvious solution s something like:
  ```
  Power(x, N)
  	prod=1
  	for(i=1; i<=N; i++)
  	{
  		prod *= x
  	}
  	return prod;
  ```
  - T(N) = Θ(N) ... can we do better?
- We know from math that:
	- x^0 = 1 and x^1 = x
 	- x^N = x^2*N/2 = (x^2)N/2
- Works great for even values of N... what if N is an odd number (N/2 would not be an integer)?
	- x^N = x^N-1*x = x^2 ...
 	- Note the recursive nature of this calculation
