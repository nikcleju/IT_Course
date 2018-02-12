---
title: Introduction
subtitle: Information Theory Lab 1
documentclass: scrartcl
fontsize: 12pt
---

# Objective

Getting familiar with the IDE and workflow for the Information Theory laboratory.

# Theoretical notions

None today :)

# Practical issues

The laboratory applications will be mostly done in C.

We will use a general purpose C IDE (Code Blocks or Dev C++).

# C details

A C program may receive input arguments from the command line. For this, the
header of the `main()` function must be defined as follows:

```
int main(int argc, char* argv[])
{
	...
}
```

## Explanations:

  * `argc` ("**arg**ument **c**ount") holds the number of input arguments
  * `argv` ("**arg**ument **v**alues") is an *array of strings* which holds all the input arguments (separated by spaces)
  * the first argument `argv[0]` is always the full name of the executable
  
## Example:

`test.exe file1 file2 dostuff`

  * `argc` is 4
  * `argv` is `{"test.exe", "file1", "file2", "dostuff"}`


# Exercises

1. Write a C program that displays all its input arguments, one argument on a separate line.


# Final questions

1. TBD
2. TBD
