# Sorting Algorithm Run Times

**Authors:** Joshua Blankley

**Date:** January 2024

## Project Description

This project asks the user to input a text file containing a set of data followed by a type of sorting (merge, quick, bubble, heap, and sys) they wish to sort the data by. I have used this data in conjunction with `time` in the command line to graph the run times compared to O(n^2) and O(nlogn).

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
