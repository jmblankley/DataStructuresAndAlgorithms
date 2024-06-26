# Closest Points

**Author:** Joshua M blankley

**Date:** March 2024

## Description

This project implements an algorithm to efficiently find the distance between the two closest points on a 2-dimensional plane. 
Given a set of points in the plane, the algorithm employs a divide-and-conquer approach to determine the closest pair.

## Technologies Used

C++, Ubuntu Linux, Github

## Installation and Usage

1. Construct executable `run` using the command `make`.
2. Execute the program as follows `./run`.

## Example

**Input:**
test2.txt
```
6
obj1 		1  1
obj2 		-5 20
obj3		20 -7
obj4		10 30
obj5		20 20
obj6 		2  2
```

Console:
```console
./run
Please enter a file name: test2.txt
Min distance: 1.41421
Between: [obj6:(2,2)] and [obj1:(1,1)]
```

## DevLog
- Constructed some comments from the pseudocode. Here is the pseudocode:
```c++
Closest-Pair(p 1 , ..., p n ) {
  Compute separation line L such that half the points
  are on one side and half on the other side.
  δ 1 = Closest-Pair(left half)
  δ 2 = Closest-Pair(right half)
  δ = min(δ 1 , δ 2 )
  Ignore all points further than δ from separation line L
  Sort remaining points by y-coordinate.
  Scan points in y-order and compare distance between
  each point and next 11 neighbors. If any of these
  distances is less than δ, update δ.
  return δ
}
```
- Constructed the 'Point' class to represent a point on the 2-dimensional plane.
- Got initial idea down, just need to fix up the format of the output.
- Struggled figuring out a base case for the recursion. Ended up using the limits library to return a massive float number, this signifies that there are no more points to compare to.
- Fixed up the formatting.
- Got some extra test cases that I was not passing.
- Fixed all the new test cases but one. Had to mess with the base case to get it work. Still need to figure out the last one.
- Figured out the issue with the last test case. It was comparing the delta to a dist of zero causing it to fall into the if statement prematurely.
- BUG: Test case "test2.txt" is giving the correct distance but the wrong points.
  - Tested with a much larger input file and it gets it correct with the correct points as well. Not sure why this specific test case is giving the wrong pair.
  - Tested with files of size 25, 50, 75, 100. The minimun distance is found everytime, but on the file with 100 entries gets the same issue at test2.txt
  - I think the issue is the merge.
