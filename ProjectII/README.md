# Stack Practice

**Authors:** Joshua Blankley

**Date:** February 2024

## Project Description

This project is used as an exercise in implementing a stack class then using that stack class to solve a problem. The program itself takes an input file and conducts different operations using keywords found in the input file. 

## Technologies Used

Linux, Github, C++

## Installation

In the terminal:

1. Compile the program using `make`.
2. Execute the program using `./p2 <filename>`.

## Example

5_factorial.txt:
```console
func factorial

     skipnz  $$,2
     retv    1

     sub     $$,1,nm1
     param   nm1
     call    factorial
     storet  recVal
     mul     recVal,$$,answer
     retv    answer
     
func main

     printS  Enter a value:
     read    var

     param   var
     call    factorial
     storet  facVal

     printNL
     printN  var
     printS  !=
     printN  facVal
     printNL
     exit
```

Terminal:
```console
./project1 5_factorial.txt
Enter a value: 5

5!=120
```

## Dev Log
- Built up the whole program pretty quick and got through all test cases except for 5_factorial.txt.
- Got some guidance and figured out I was not using the provided getValue function when I should have been.
- Switched my stoi() values to getValue values and fixed the program.

