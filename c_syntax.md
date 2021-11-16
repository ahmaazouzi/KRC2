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
- The utility of these symbolic constants appears in large programs. Magic numbers represented by a constant can be changed once in one spot, instead of having to be tracked all over the place! The name also help you differentiate between different magic numbers that have the same value.
- Text input and output is treated as a stream of characters. A **text stream** is a sequence of characters divided into lines. Each line consists of zero or more characters followed by a new line escape character `\n`. 
- Important but simple functions for reading and writing one character at a time include **`getchar`** and **`putchar`**.
- **`EOF`** signals the end of a file. It usually has the value -1 in some systems, maybe including UNIX systems.

### var1 = var2 = var3 = 0
- An assignment in C is an expression whose value is the value being assigned to the variable, so the weird but familiar is equivalent to the one next to it:
```c
wc = lc = cc = 0;
```
```c
wc = (lc = (cc = 0));
```

### Arrays:
- **`int digits[10]`** is correct, but **`int[10] digits`** is completely incorrect!!!
- When you declare an array, it is filled with garbage.
- Something like **`'5' - '0'`** should be obvious. I was a little confused by it, but all we are doing here is subtracting the ASCII value of character `0` which is 48, from the ASCII value of `5` which is `48`. The result is 5. _NEAT!!!_

### Functions:
- An interesting eccentricity of C is that to call a function it needs to be defined/declared before the calling function. If not the calling function needs to have a **function prototype** defined before it. A function prototype needs only have the returned type and parameter types of the called function. The following two declarations are both correct and sufficient function prototypes:
```c
int power(int b, int e);
int power(int, int);
``` 
- Parameter names of a function prototypes don't need to be the same as the actual function's parameter names. 
- C functions, like in most languages one would be familiar today such as Java, Python and Javascript, use call by value instead of call by reference, which simply means that when a call to function uses a variable as an input, the function only copies the value of that variable and does not take a reference to it. When the function modifies that argument, it only modifies its private copy of the variable, not the original variable itself as the following examples shows:
```c
#include <stdio.h>
 
void someFun(int a){
 	a = 2 * a;
}

int main(){
	int a = 2;
	someFun(a);
	printf("%d\n", a); // prints 2 
}
```
- To modify an argument to a function, you actually need to pass its address to the function, or so called pointer which we will see later.
- If you pass an array to a function, you can actually directly access and modify its elements. This is the origin of the distinction between reference types such as classes in Java versus the other type (I forgot its name) where you only copy values. 

### Character Arrays:
- A character array containing **`'\0'`** after the last character is a string, and can be printed using `printf` with the symbol **`%s`**.

### External Variables and Scope:
- Local variables, declared and visible only within functions are also called **automatic variables**.
- A function has its private scope with its automatic variables. A block also has its own scope. Variables declared within a scope are not visible to the rest of a function's body.
- Global or as these guys call them, **external variables** are visible to all functions. They live long after the functions that set/initialized them have existed. 
- One weird thing I haven't been aware of is that an external variable "must also be declared in each function that wants to use it. The declaration may be an explicit **`extern`** statement or maybe implicit from the context". _WOW!!_ The following kinda weird code is totally the norm in C, it seems:
```c
#include <stdio.h>

int a;

void seto(){
	extern int a;
	a = 55;
}

void prin(){
	extern int a;
	printf("%d\n", a);
}

int main(){
	seto();
	prin();
}
```
- The extern statement, however, doesn't seem to be absolutely necessary as the external variable is visible to functions anyways.
- The trick, though, is that if a function defines a local variable with the same name as an external variable, the automatic variable shadows the external one. This can still be confusing. 
- A bigger issues that external variables defined in other files are not visible to the function unless they are declared with an `extern` statement. Bu then again, once you use `#include..` you don't need an `extern` statement either. The convention is to define external variables in a **header** file 

### Declaration vs. Definition:
- Richie and Kernighan define **declarations** as "places .. [where] the nature of the variable is state but no storage is allocated", while a **definition** are "places where the variable is created or assigned storage." So an external variable can only be defined once, but can be declared in different contexts. 
- What follows is a gentle warning about the "perils" of global variables. 

## Types, Operators and Expressions:
## Control Flow:
## Functions and Program Structure:
## Pointers and Arrays:
## Structures:
## Input/Output:
## UNIX Interface:
## Notes on the Standard Library: