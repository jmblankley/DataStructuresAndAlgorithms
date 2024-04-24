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

```c++
double arr[] = {7, 22, 1.08, -6, 9};
for(int index = 0; index < 5; index++)
{
 cout << arr[index] << endl;
}
```

Thanks to a 2011 revision of C++, can be rewritten as:

```c++
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

```c++
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

```c++
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

```c++
list<double> myList;
myList.push_back(3.14);
myList.push_back(2.72);
myList.push_back(-4);
```

You can now use the collection iterator:

```c++
for(double val : myList)
{
 cout << val << endl;
}
```

This gives on separate lines: 2.72 3.14 -4

You can do similar iteration with set, multiset, or any other container in STL

### The auto C++ Keyword

Don't know what type to declare something? Use auto as the type:

```c++
auto var1 = 4 // var1 is of type int
auto var2 = 4.0 // var2 is of type double
cout << var1/3 << endl; //prints 1
cout << var2/3 << endl; // prints 1.33333
```

You can use the auto within the collection iterator:

```c++
for(auto val : myList)
{
 cout << val << endl;
}
```

Note that myList could be of type _anything_!

### static and extern

If you want a global variable to only be visible in the current file/scope:

- Use the `static` keyword to do so

```c++
// no access outside of current scope
static int soemvar:
```

If you want to access a gloabal vairalbe in another scope:

```c++
// extern says not to declare a variable,
// just note that is exists elsewhere
extern int someVar;
```

### Inheritance in C++

Just as in Java, one class (a child) can inherit from another (a parent):

```c++
class Media
{
 private:
  string _title;
 public:
  Media();
  string getTitle();
};
```

```c++
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

```c++
class DVD: private Media
{ // ...
```

- In this case, object of type DVD can _not_ call Media's public methods
- but method implemented in the DVD class _can_ call Media's public methods.

Objects of type Book can call getTitle, since the inheritance is public!

### Virtal Functions

Consider the following:

```c++
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

```c++
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

  ```c++
  int sum(int n)      // Cost
  {
   int partialSum;     // 0

   partialSum = 0;     // 1
   for(int i = 1; i <= n; i++)  // 1 + (N + 1) + 1
   {
    partialSum += i * i * i; // N * (1 + 1 + 2)
   }
   return partialSum;    // 1
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

    ```c++
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

    ```c++
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

    ```c++
    MaxSubSum3(A, i, j)
      if(i = j and A[i] >= 0)
       return A[i]
      if(i = j and A[i] < 0)
       return ...
    ```

    - This give T(N) = Θ(N\*log(N))

  - Algorithm 4

    ```c++
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

  ```c++
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
  - x^N = x^2\*N/2 = (x^2)N/2
- Works great for even values of N... what if N is an odd number (N/2 would not be an integer)?
  - x^N = x^N-1\*x = x^2 ...
  - Note the recursive nature of this calculation

### The List ADT

- List of size N: A*0, A_1, ..., A*(n-1)
- Each element A_k has a unique position in the list
- Elements can be arbitrarily complex.
- Operations:
  - insert(X, k)
  - remove(k)
  - find(X)
  - findKth(k)
  - printList()

### List Implemented with Arrays

Operations:

```c++
Insert(X,k); // O(N)
remove(k);  // O(N)
find(X); // O(N)
findKth(k); // O(1)
printList(); // O(N)
```

### List Implemented With Linked Lists

- Elements not stroed in continguos memory

- ...

Operations:

```c++
Insert(X,k); // O(1)
remove(k);  // O(1)
find(X); // O(N)
findKth(k); // O(N)
printList(); // O(N)
```

### Stack

- Stack is a container where insert and remove take place only at the "top".

Operations

```c++
push() // insert element on top of stack
pop() // remove element from top of stack
top() // return element at top of stack
isEmpty() // true if nothing in stack, false otherwise
```

### Stack Application - Balancing Symbols

GOAL: Make sure that all opening/closing pairs of symbols in input stream are balanced:

- every { has a }, every ( has a ), every [ has a ].
- The clostings do not "isolate" an opening.
- Legal sequences: "{[()]}", "{{()[][][[[]]]}}"
- Leet code problem 20.

### Stack Application - Postfix Evaluation

Postfix Expressions

- The operator is listed after the operands, not between them:
  - 25+ = 7, 825+_=8_(2+5) = 56, 82*5+ = (8*2) + 5 = 21, ...
- Can be evaluated using a stack:

  ```c++
  tok = next symbol in input
  if(tok is a nullptr)
  {
   push tok;
  }
  else
  {
   pop val1;
   pop val2;
   push(val2 <operator specified by tok> val1);
  }
  ```

### Stack Implementation

Could implement the stack with:

- Array
  - Bounded, so limited stack size
- Linked List
  - Unbounded
  - But perhaps more complex
    - Unless you just use/inherit the STL list

### Queue

- Queue is a container where
  - Insert takes place at back,
  - but remove takes place at the front
- Operations
  - _Enqueue_ (insert) element at the back of the queue
  - _Dequeue_ (remove and return) element from the fron tof the queue
- FIFO
  - First in First Out

### Queue Applications

- Job scheduling
- Unix pipes
- Graph traversals
- Queuing theory simultions
- Priority queues
  - Not really FIFO queues
  - Cannot be implemented like the above example

### Queue Implementation

- Array Version
  - Bounded by size of array
  - Usually a "circular buffer" is used
    - The front may end up at an index greater than the end
- Linked List Version
  - Unbounded
  - No "circular buffer" issues
  - Must be able to manage dynamic memory
    - Contiguous memory block (i.e. arrays) might be faster

## Trees

- Trees
  - Note that trees do not have to be binary
  - Each child can be thought of as a sub tree

### Expression Trees

- Constructing an expression tree from postfix notation:
  - Use a stack of pointers to binary trees
  - Read postfix expression left to right
  - If operand, then push on stack
  - If operator, then
    - Create a Binary Tree node with operator as the element
    - Pop top two items off stack
    - Insert these items as left and right child of new node
    - Push pointer to node on the stack

### Binary Seach Tree

- We want to support the following operations:
  - bool contains(Object elementToFind)
  - Object maxElement()
  - Object minElement()
  - bool insert(Object newElement)
  - bool remove(Object existingElement)
- Analysis - Average Case
  - Complexity of Contain, FindMax, FindMin, Insert, Remove is O(d) where d is the depth of the tree.

### Balanced BSTs

- AVL Tree
  - Height of left and right subtrees at every node in BST differ by at most 1
  - Maintained via _rotations_.
  - AVL Tree height always O(log N)
- Splay Tree
  - After a node is accessed, push it to the root via AVL rotations
  - Average depth per operation is O(log N)

### AVL Trees

- AVL (Adelson-Velskii and Landis, 1962)
- For every node in the BST, the heights of its left and right subtrees differ by at most 1
- Height of AVL BST is O(log N)
- Goal: All tree operations can be performed in O(logN) time.
- For now, do "lazy deletion".

### AVL Tree Height

- Height of AVL BST is BigTheta(log N)
  - Maximum number of nodes N = F(h) in AVL tree of height h:
    - F(h) = F(h - 1) + F(h - 1) + 1, F(0) = 1
    - F(h) = O(2^h)
      - So, since N = F(h) = O(2^h), h = BigOmega(log N)
  - Minimum number of nodes N = F(h) in AVL tree of height h:
    - F(h) = F(h - 1) + F(h - 2) + 1, F(0) = 1, F(1) = 2
    - Similar to the Fibbonacci sequence, so F(h) = BigTheta(1.44^h)
      - So, since N = F(h), h = O(log N)
      - Acutally, h ~= 1.44log(N + 2) - 1.328

### AVL Insertion

- Insertion can upset the balance
- Can be fixed by _rotation_.
- Core Idea:
  - Only nodes along path to insertion have their balance altered
  - Follow path back to root, looking for violations
  - Fix violation using single or double "rotation"
- Assume node k needs to be balanced
  - Four cases leading to violation
    1. An insertion into the left subtree of the left child of k
    2. An insertion into the right subtree of the left child of k
    3. An insertion into the left subtree of the right child of k
    4. An inserstion into the right subtree of the right child of k

## Greedy Algorithms

### The Interval Scheduling Problem

- Interval Scheduling:
  - Job j starts at s_j finishes at f_j.
  - Two jobs ...
- Greedy Algorithm Ideas
  - Greedy Template: Consider jobs in some order. Take each job provided it's compatible with the ones already taken.
    - [Earliest Start Time] Consider jobs ascending order

### Interval Partitioning: Lower Bound on Optimal Solution

- The depth of a set of open intervals is the maximum number that contain any given time
- Key Observation: Number of classrooms needed >= depth.
- Ex. Depth of schedule below = 3 => schedul ebelow is optimal.
- Q: Does there always exist a schedule equal to depth of intervals?

### Interval Partitioning: Greedy Algorithm

- Consider lecutres in increasing order of start time: assign lecture to any compatible classroom.
- This implementation in O(n log n).

### Interval Partitioning: Greedy Analysis

- Observation: Greedy algorithm never schedules two incompatible lectures in the same classroom.
- Theorem: Greedy algorithm is optimal.
- Proof:
  - Let d = number of classrooms that the greedy algorithm allocates.
  - Classroom d is openened because we needed to schedule a job, say j, that is incompatible with all d-1 other classrooms.
  - Since we sorted by start time, all theses incompatibilities ...

### Scheduling to Minimizing Lateness

- Single resource processes one job at a time
- Job j requires t_j unites of processing time and is due at time d_j.
- If j starts t time s_j, it finishes at time f_j = s_j + t_j.
- Lateness: L_j = max{0, f_j - d_j}. // 0 if job finishes on time
- Goal: Schedule all jobs (find a starting time s_j for each job)
  - Make sure to minimize maximum lateness L = max L_j.
- Greedy Template:
  - Consider jobs in some order
  - [Shortest Processing Time First] Consider jobs in ascending order of processing time t_j.

## Divide and Conquer Algorithms

### Divide and Conquer Algorithm

- Divide and Conquer
  - Break up into subproblems
  - Solve each part recursively
  - Combine solutions to sub-problems into overall solution
- Most Common Usage
  - Break up problem of size n into two equal parts of size 1/2n
  - Solve two parts recursively
  - Combine two solutions into overall solution in linear time
- Consequence
  - Brute force: O(n^2)
  - Divide and conquer: O(nlogn)

### Merge Sort
  
- Divide array into two havles
- Recursively sort each half
- Merge two havles to make sorted whole

### Merging

- Merging
  - Combine two pre-sorted lists into a sorted whole
- How to merge efficiently?
  - Linear number of comparisons.
  - User temporary array
- Merge
  - Keep track of smallest element in each sorted half
  - Insert smallest of two elements into auxiliary array
  - Repeat until done

### A Useful Recurrence Relation

- T(n) = number of comparisons to mergesort an input of size n
- Mergesort recurrence
- Solution: T(n) = O(nlogn)
- Assorted proofs. Several ways to prove this securrence. Initially we assume n is a power of 2 and replace <= with =.

### Counting Inversions

- Music site tries to match your song preferences with others
  - You rank n songs
  - Music site consults databae to find people with similar tastes
- Similarity metric: number of inversions between two rankings
  - My rank: 1, 2, ..., n
  - Your rank: a1, a2, ..., aN
  - Songs i and j inverted if i < j, but ai > aj
- Brute Force
  - Check all BigTheta(n^2) pairs i and j
- Divide and conquer
  - Separate into two pieces
  - Conquer: recursively count inversions in each half
  - Combine: Count inversions where ai and aj are in different halves, and ...

## Dynamic Programming

### Algorithmic Paradigms

- Greed: Build a solution incrementally, myopically optimizing some local criterion.
- Divide and Conquer: Break up a problem into two sub-problems, solve each sub-problem independently, and comibe solution to sub-...

### Dynamic Programmin History

- Bellman
  - Pioneered the systematic study of dynamic programming in the 1950s
- Etymology
  - Dynamic programming = planning over time.
  - Secretary of Defense was hostile to mathematical research.
  - Bellman sought an impressive name to avoid confrontation.
  - "It's possible to use dynamic in a pejorative sense."
  - "Something not even a Congressman could object to."

### Dynamic Programmin Applications

- Areas
  - Bioinformatics
  - Control theory
  - Information theory
  - Operations research
  - Computer science: theory, graphics, AI, systems
- Some famous dynamic programmin algorithms
  - Viterbi for hidden Markov models
  - Unix diff for comparing two files
  - Smith-Waterman for sequence alignment
  - Bellman-Ford for shortest path routing in networks
  - Cocke-Kasami-Younger for parsing context free grammar

## Graphs

### Graph Representations

- Adjacency List: Node indexed array of lists
  - Two Representations of each edge
  - Space proportional to m + n
  - Checking if (u, v) is an edge takes O(deg(u)) time
  - Identifying all edges takes ...

- Adjacency Matrix: n by n matrix with A_uv =1 if (u, v) is an edge.
  - Two representations of each edge.
  - Space proportional to n^2.
  - Checking if (u, v) is an edge takes BigTheta(1) time.
  - Identifying all edges takes BigTheta(n^2) time.

### Paths and Connectivity

- A path in an undirected graph G = (V, E) is a sequence P of nodes with the property that each consecutive pair is joined by an edge in E.
- A path is simple if all nodes are distinct
- An undirected graph is connected if for every pair of nodes u and v, there is a path between u and v.

### Cycles

- A cycle is a path in which v_1 = v_2, k > 2, and the first k through 1 noes are all distinct.

### Trees(Graph Theory)

- An undirected graph is a tree if it is connectd and does not contain a cycle.
- Theorem:
  - Let G be an undirected graph on n nodes. Any two of the following statements imply the third.
    - G is connected
    - G does not contain a cycle
    - G has n-1 edges

### Rooted Trees

- Given a tree T, choose a root node r and orient each edge away from r.
- Importance: Models hierarchical structure.

### Connectivity

- s-t Connectivity Problem: Given two nodes s and t, is there a path between s and t?
- s-t Shortest Path Problem: Given two nodes s and t, what is the length of the shortest path (measure in "hop count") between s and t?
- Applications:
  - Maze traversal
  - Kevin Bacon number
  - Fewest number of hops in a communication network

### Breadth First Search (BFS)

- Explore outware from s in all possible directions, adding nodes one "layer" at a time.
- BFS Theorem
  - For each i, L_i consists of all nodes at distance exactly i from s. There is a path from s to t iff t appears in some layer.
- BFS runs in O(m + n) time if the graph is gvien by its adjacency representation.

### Greedy Algorithms

- Simplifying Assumption
  - All edge costs c are distinct.
- Cut Property
  - Let S be any subset of nodes, and let e be the minimum cost edge with exactly one endpoint in S. Then the MST contains e.
- Cycle Property
  - Let C be any cycle, and let f be the max cost edge belonging to C. Then the MST does not contain f.

### Prim's Algorithm

- Implementation
  - Maintain set of explored nodes S.
  - For each unexplored node v, maintain attachment const a[v] = cost of cheapest edge v to a node in S.
  - O(n^2) with an array; O(nlogn) with a binary heap (or balanced tree).
- Pseudocode
  ```c++
  Prim(G, c){
    for each (v in V) a[v] <- infinity
      Initialize an empty priority queue Q
    for each (v in V){
      insert v onto Q, keyed on a[v]
      Initialize set of explored nodes S <- empty
    }
    while (Q is not empty) {
      u <- delete min element from Q
      S <- S union {u}
      for each (edge e = (u, v))
      {
        if((v not in S) and (c < a[v]))
          decrease priority of a[v] to c
      }
    }
  }
  ```

### Kruskal's Algorithm

- Implementation
  - Build set T of edges in the MST
  - Maintain set for each connected component.
  - O(nlogn) for sorting and O(m alpha(m,n)) for union-find.
- Psuedocode:
```c++
Kruskal(G, c) {
  Sort edges e so that c_1 <= c_2 <= ... <= c_m
  T <- empty

  for each(c in V)
  {
    make a set containing  single ton u
  }

  for (i = 1 to m){
    (u,v) = theta
    if (u and v are ij different sets)
    {
      T <- T U {e}
      merge the sets containing u and v
    }
  }
  return T
}
```

## Intractability & NP Completeness

### Classify Problems

- Classify problems according to those that can be solved in polynomial-time and those that cannot

- Probably requires exponential-time
  - ex. Given a board position in an n-by-n generalization of chess, can black guarantee a win?

- Frustrating News
  - Huge number of fundamental problems have defied classification for decades.

- New Goal
  - Show that these fundamental problems are "computationally equivalent" and appear to be different manifestations of one really hard problems.

### Polynomial-Time Reduction

- Suppose we could sove problem Y in polynomial-time. What else could we solve in polynomial time?
- Problem X polynomial reduces to problem Y if arbitrary instances of problem X can be solved using
  - Polynomial number of standard computational steps, plus
  - Polynomial number of calls to oracle that solves problem Y
    - Oracle: computational model supplemented by special piece of hardware that solves instaces of Y in a single step
- We pay for time to write down instances sent to the oracle => instances of Y must be of polynomial size.
- Purpose
  - Classify problems according to realtive difficulty.
- Design Algorithms
  - If X <= Y and Y can be solved in ploynomial-time, then X can alos be solved in polynomial time.
- Establish Intractability
  - If X <= Y and X cannot be solved in polynomial time, then Y cannot be solved in polynomial time.
- Establish Equivalence
  - If X <= Y and Y <= X, we use notation X == Y. (RARE)

### Independent Set

- Given a graph G = (V, E) and an integer k, is there a subset of verticies S from V such that |S| >= k, and for each edge at most one of its endpoints is in S?

### Vertex Cover

- Given a graph G = (V, E) and an integer k, is there a subset of verticies S from V such that |S| <= k, and for each edge at least one of its endpoints is in S?

### Vetex Cover and Independent Set

- VERTEX-COVER =opp. INDEPENDENT-SET
- We show S is an independent set iff V - S is a vertext cover.
- Claim - VERTEX COVER =opp. INDEPENDENT SET
  - Proof: We show S is an independent set iff V - S is a vertex cover.
    => 
      - Let S be any independent set
      - Consider an arbitrary edge (u, v).
      - S independent => u is not in S or v is not in S => u is in V - S or v is in V - S
      - Thus, V - S covers (u, v)
    =>
      - Let V - S be any vertex cover
      - Consider two nodes u in S and v in S (i.e. u and v are not in vertex cover)
      - Observe that (u, v) not in E since V - S is a vertex cover
      - Thus, no two nodes in S are joined by an edge => S independent

### Set Cover

- Given a set of U of elements, a collection S_1, S_2, ..., S_m of subsets of U, and an integer k, does there exist a collection of <= k of these sets whose union is equal to U?
- Sample Application
  - Set U of n capabilites that we would like our system to have
  - m available pieces of software
  - The ith piece of software provides the set S_i containted in U of capabilites
  - Goal
    - Achieve all n capabilities using k (or fewer) pieces of software

### Vertex Cover REduces to Set Cover

- Given a VERTEX-COVER instance G = (V, E), k, we construct a set cover instance whose size equals the size of the vertex cover instance.

### Satisfiability

- A boolen variable or its negation
- A disjunction of literals
- Conjuctive Normal Form
  - A propositional formula OMEGA that is the conjuction of clauses
- Given CNF formula OMEGA, does it have a satisfying truth assignment?
- SAT where each clause contains exactly 3 literals.

### Self-Reducability

- Descision Problem
  - Does there exist a vertex cover of size <= k?
- Serach Problem
  - Find vertex cover of minimum cardinality.
- Self-Reducability
  - Applies to all (NP-Complete) problems
  - Justifies focus on decision problem

### Decision Problems

- Decision Problem
  - X is a set of strings
  - Instance: string s
  - Algorithm A solves decision problem X: A(s) = yes iff s in X
- Polynomial Time
  - Algorithm A runs in poly-time if for every string s, A(s) terminates in at most p(|s|) "steps", where p(.) is some polynomial
- PRIMES: X = {2,3,5,7,13,17,23,29,31,37, ...}
- Algorithm
  - Agrawal-Kayal-Saxena, 2002
  - p(|s|) = |s|^8

### Definition of P

- Decision problems for which there is a poly-time algorithm

### Definition of NP

- Certification Algorithn Intuition
  - Certifier views things from "managerial" viewpoint
  - Certifier doesn't determine whetehr s in X on its own; rather, it checks a proposed proof t that s in X.
- Algorithm C(s,t) is a certifier for problem X if for every string s, s in X iff there exists a string t such that C(s,t) = yes
- NP
  - Decision problems for which there exists a poly-time certifier

### Cerifiers and Certificates: Composite

- Certificate
  - A nontrivial factor t of s. Note that such a certificiate exists iff s is composite. Moreover |t| <= |s|.

### Cerifiers and Certificates: 3-Satisfiability

- SAT: Given a CNF formula omega, is there a satisfying assignment?
- Certificate: An assignment of truth values to the n boolean variables
- Certifier: Check that each clause in omega has at least on true literal.
- 3-SAT is in NP

### P, NP, EXP

- P
  - Decision problems for which there is a poly-time algorithm.
- EXP
  - Decision problems for which there is an exponential-time algorithm.
- P
  - Decision problems for which there is a poly-time certifier.
- P is in NP
- NP is in EXP

### NP-Complete

- NP-Complete
  - A problem Y in NP with the porperty that for every problem X in NP, X <= Y.
- Theorem
  - Suppose Y is an NP-Complete problem. Then Y is solvable in poly-time iff P = NP.

### Circuit Satisfiability

- Circuit-SAT
  - Given a combinational circuit built out of AND, OR, and NOT gates, is there a way to set the circuit inputs so that the output is 1?
- The "First" NP-Complete Problem
  - Any algorithm that takes a fixed number of bits n as input and produces a yes/no answer can be represented by such a circuit. Moreover, if algorithm takes poly-time, then circuit is of poly-size.

### Establishing NP-Completeness

-Once we establish first 'natural' NP-Complete problem, others fall like dominoes.
- Recipe to establish NP-Completeness of problem Y
  - Step 1: Show that Y is in NP
  - Step 2: Choose an NP-Complete problem X.
  - Step 3: Prove that X <=_p Y.
- Justification
  - If X in an NP-Complete problem, and Y is a problem in NP with the property that is X <=_p Y then Y is NP-Complete.

## Approximation Algorithms

- Q: Suppose I need to solve an NP-Complete problem. What should I do?
- A: Theory says you're unlikely to find a poly-time algorithm.
- Must sacrifice on of three desired features
  - Solve porblem to optimality.
  - Solve problem in poly-time.
  - Solve arbitrary instances of the problem.
- roh-approximation algorithm
  - Guaranteed to solve arbitrary instance of the problem
  - Guaranteeded to solve arbitrary instance of the problem.
  - Guaranteed to find solution within ratio roh of true optimum

### Center Selection Problem

- Input: Set of n sites s_1, ..., s_n
- Center Selection Problem: Select a set C made up of k centers so that maximum disance from a site to nearest center is minimized.
- Notation
  - dist(x,y) = distance between x and y
  - dist(s,C) = min_(cinC)dist(s,c) = distance from s_i to closest center
  - r(C) = max, dist(s,C) = best (smallest) covering radius
- Goal: Find set of centers C that minimizes r(C), subject to |C| = k.
- Distance Function Properties
  - dist(x,y) = 0
  - dist(x,y) = dist(y,x)
  - dist(x,y) <= dist(x,z) + dist(z,y)

### Greedy Algorithm: A False Start

- Put the first center at the best possible location for a single center, and then keep adding centers so as to reduce the covering radius each time by as much as possible.
- Remark: arbitarily bad!

