# Waste Storage Optimization

**Author:** Joshua Blankley

**Date:** March 2024

## Project Description

This project aims to optimize the storage cost for toxic waste items. It takes an input file containing information about waste items and calculates the lowest possible total storage cost while ensuring all items are stored until their respective deadlines.

## Technologies Used

C++, Linux, Github

## Installation

1. Compile the program using the provided Makefile.
2. Execute the program by running `./program_name <filename>` in the terminal, where `<filename>` is the path to the input file.

## Example

**Input File:**
```console
a 20 2
b 10 1
c 22 2
d 12 1
```
**Terminal:**
```console
./run input6.txt
```

**Output:**
```console
22
```

## Development Log

- Implemented the merge sort algorithm to sort waste items based on deadlines.
- Calculated the initial total storage cost by summing the costs of all waste items.
- Iterated through each day, selecting the waste item with the highest cost due on that day and subtracting its cost from the total storage cost.
- Fixed issues with indexing and looping to ensure correct processing of waste items.
- Conducted thorough testing to verify the correctness of the program.

This README provides installation instructions, an example usage, and a brief development log to give users an overview of the project and its functionality.