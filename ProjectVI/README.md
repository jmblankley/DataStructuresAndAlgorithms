# Kruskal's Algorithm Example Program

**Author:** Joshua M Blankley

**Date:** April 2024

## Description

This project is an exercise in using graphs to solve a networking problem rather than a functional communication program. 
It aimed to efficiently connect islands with computer network lines, ensuring seamless communication while minimizing costs. 
By representing the problem as a graph and coding a specialized algorithm, the project demonstrates the application of graph theory principles in solving real-world challenges.

## Technologies Used

C++, Ubuntu Linux, Github

## Installation and Usage

1. Construct executable `project6` using the command `make`.
2. Execute the program with `./project6 <filename`.

## Example

**Input:**
hawaii.txt
```
Niihau Kauai		25
Niihau Oahu		100
Kauai Maui		200
Kauai Oahu		90
Oahu Molokai		30
Oahu Lanai		70
Oahu Maui		90
Lanai Maui		35
Maui Hawaii		110
Hawaii Kauai		175
```

Console:
```console
./project6 hawaii.txt
360
```

## DevLog
- Built up the initial idea for the program.
- Built the Edge class to represent the edges in the graph (each edge contains two nodes and a length)
- Added comments in following the pseudocode provided from class lecture (ended up using Kruskal's algorithm).
- Added a struct to represent the singleton set.
- Built up the Kruskals function.
- Tested program with provided input as well as additional test cases.
