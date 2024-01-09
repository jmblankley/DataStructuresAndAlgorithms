# Conversion Program

**Authors:** Joshua Blankley

**Date:** January 2024

## Project Description

This project asks the user to input a text file containing a set of data followed by a type of sorting (merge, quick, bubble, heap, and sys) they wish to sort the data by. It then outputs the time complexities of this data into a graph to display the difference in run times for the different types of sorting algorithms.

## Technologies Used

Linux, Github, C++

## Installation

In the terminal:

1. Compile the program using `make`.
2. Execute the program using `./project1 <filename> <sortingtype>`.

## Usage

The following commands are available for interacting with the program:

- `-print` - can be added at the end of the execution line to display the sorted data.

## Example

file.txt:
5
one
two
three
four
five

```console
./project1 file.txt bubble -print
five
four
one
three
two
```
