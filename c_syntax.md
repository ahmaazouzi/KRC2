# Notes on C Syntax:
- These notes for myself picked from _The C Programming Language_ focused mainly on things particular to C, especially those that make it in a class of languages different the class of languages that includes Java and Python; Things like pointers, macros, Loose typing and dynamic memory management. I will mostly skip parts where C is identical to Java (at least syntactically). I will probably spend half the time on pointers, structures and memory allocation and use outside sources to help understand how these work. My notes on the memory chapters from *Computer Systems, a Programmer's perspective* will be especially helpful here. 
- I spent most of the last third of 2018 going though exercises in the book and focused too much on the exercises and didn't give myself time to understand and remember the particularities of C. If I have time, I might revisit some of those exercises. 
- The main reason for writing these notes is to have them around in an easily searchable format is googling tends to be distracting and would usually throw me in inescapable rabbit holes.

## Preliminaries:
- A C program is a made of functions and variables.
- A function consists of statements specifying operations and variables. 
- Functions can have any names they like, but ***main*** function (its name) is special and acts as the entry point to your program.
- Characters like `\n` are called **escape characters**.
- Data sizes are machine dependent. 
- Integer division, as elsewhere, truncates: fractional parts are discarded.  
- **`printf`** is not part of C but comes from the `<stdio.h>` standard library package. It handles formatting of all kinds. For example:
	- **`%d`**, **`%f`** correctly formats the corresponding data types so a float types is printed correctly and would displayed wrong if we try to show it as an integer. 
	- It handles all kinds of escape characters such as `\t` and `\n`.
	- It handles aesthetic aspects such as **right justifying** printed numbers wit constructs like **`%5d`** which makes sure that even one digit would be preceded by 4 empty spaces while a 5-digit number will not (you get the idea).
	- Something like **`%f4.0`** specifies that float needs to be displayed in at least 4 characters, with no fractions. A fraction can be displayed without it's fractional part, or can have several trailing zeros after the 0 even when unnecessary. 4 is for width and the number following the dot is for the fractional part. 
	- **`%c`** is for characters, **`%x`** for hexadecimals, **`%o`** for octals, and **`%%`** for `%`.

### Symbolic Constants:
- Magic numbers had better be named as constants with the _qualifier_ (is it a qualifier) **`#define`** as in:
```c
#define ZERO 0
```
- How do we know if ZERO is an integer, float or whatever?!?!
- This name should by convention be capitalized.
- No semicolon follows a `#define` statement. _Weird!_

### Basic I/O:
- Text input and output is treated as a stream of characters. A **text stream** is a sequence of characters divided into lines. Each line consists of zero or more characters followed by a new line escape character `\n`. 
- Important but simple functions for reading and writing one character at a time include **`getchar`** and **`putchar`**.
- **`EOF`** signals the end of a file. It usually has the value -1 in some systems, maybe including UNIX systems.

## Types, Operators and Expressions:
## Control Flow:
## Functions and Program Structure:
## Pointers and Arrays:
## Structures:
## Input/Output:
## UNIX Interface:
## Notes on the Standard Library: