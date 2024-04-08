# Waste Disposal (Dynamic Programming Algorithm)

**Author:** Joshua M blankley

**Date:** April 2024

## Description

This program is an exercise to learn dynamic programming algorithms. This program takes in an input file that contains an integer that is the total number of items, an integer that is the total time alloted, and then the items listed out with their names, weight, and time it would take to store. It then uses this file and the dynamic programming algorithm to find the lowest penalty possible.

## Technologies Used

C++, Ubuntu Linux, Github

## Installation and Usage

1. Construct executable `project5` using the command `make`.
2. Execute the program as follows `./project5`.
3. Optional `-print` tag can be added at the end to see what items have been stored.

## Example

**Input:**
test.txt
```
5 11
item1 1 1
item2 6 2
item3 18 5
item4 22 6
item5 28 7
```

Console:
```console
./project5 test.txt -print
TOTAL PENALTY: 35
ITEMS STORED: item1 item2 item5
```

## DevLog
- Constructed README and got some notes written down for initial ideas.
- Constructed the totalCost funciton, got initial idead down but it is not fully working yet.
- Decided to use the knapsack algorithm for this as they are very similar problems. 
- Got the 2d array for the knapsack algorithm working, still need to figure out how to get the correct answer.
- Got the answer by adding up the cost of all the items, then subtracting M[n][W] from it.
- Implemented the "-print" functionality to the program, it runs in O(n^2) though so it will need to be fixed before it gets turned in.