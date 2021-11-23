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
- _Variables_ and _constants_ are the data objects programs manipulate. _Operators_ specify what to do with variables and constants. _Expressions_ combine variables and constants using operators to produce new values. Objects (represented by variables and constants) have types. The _type_ of an object determines the range of values this object can have and the operations that can be performed on it. 
- This section will detail most of what one needs to know about types, operators, variables, constants and expressions (and some other things) as specified in the ANSI standard.  

### Names:
- A Variable/constant name can have both letters and digits but must start with a letter (or an underscore **`_`**). It's advisable to avoid starting variable names with underscores because standard library functions tend to have those. 
- By convention, variables tend to have lowercase letters while constants are uppercase.  
- The first 31 characters of an internal variable name are significant but the rest is garbage. As for external variables, fewer first characters are significant. ANSI C guarantees the significance of the first 6 characters. 

### Data Types and Size:
- C has the following **4 data types**:
	- **`char`**: holds a single byte and is used for characters.
	- **`int`**.
	- **`float`**.
	- **`double`**.
- A type can have extra qualifiers resulting in more granular data types such as **`short int`**:
	- **`int`** types can have the qualifiers **`short`** and **`long`**. These qualifiers are not really the same across systems. `short` tends to have the size 16 bits. `int` by itself  is usually 32-bit long even in 64-bit systems. `long` can be 32 but it tends to represent the CPU's architecture so it is 64 bits in 64-bit systems. The main restrictions differentiating these types in C are that shorts and ints must be at least 16-bit, longs at least 32-bit long, and shorts not longer than ints, and ints not longer than longs. When these qualifiers are used, **`int`** is not necessary, so **`long int`** is equivalent to **`long`**.
	- **`int`** can also be **`signed`** and represent positive and negative integers or **`unsigned`** for representing positive integers only. The range of absolute values that can be represented by signed integers is roughly half of what can be represented by its unsigned counterpart. All printable characters (ASCII) are positive regardless of if `char` is signed or unsigned, because even signed chars they are represented by the range 0 to 127.
	- `double` can also qualified by `long` resulting in **`long double`** which might have extra precision than `double` and `float`. Depending on the machine, `float`, `double`, and `long double` might have 1, 2, or 3 distinctive sizes. 
	- The standard header `limits.h` has the sizes of integral types, while `<float.h>` has those of floating-point types. 

### Constants/Literals:
#### Integers and Floating-Points:
- Integer literals can written as:
	- `123` as an `int`. 
	- `123l` or `123L` as a `long int`.
	- `123U` or `123U` as a `unsigned int`.
	- `123UL`, `123ul`, etc. as an `unsigned long int`.
- If an integral literal is too long to fit in an `int`, it is automatically assigned to a `long`. 
- Floating-point literals can be represented as:
	- `123.0` is automatically a `double`.
	- `5e4` or `5.0e4` is also automatically a `double`.
	- `123.0L`/ `123.0l` is a `long double`.
	- `123.0f` and `123f` are for `float`.
- Integers can be represented as octals with leading zeros, so `05` is a `5` in octal.
- Integers can also be represented by hexadecimals using a leading **`0X`** as in **`0X8`**. Hexadecimal and octals can also be followed by `U` and `L` to indicated their long and/or unsigned as in `0XFUL`.

#### Characters:
- A **character constant** (or literal, Imma use literal from now on to refer to what the book calls constant) is an "integer written as a one character within single quotes, such as **`x`**". 
- Certain characters, some of which are invisible, can be represented by escape sequences such as **`n`** both as characters and as part of strings.

| Escape sequence | Description |
| --- | --- |
|  **`\a`** | alert (bell) character |
|  **`\b`** | backspace |
|  **`\f`** | formfeed |
|  **`\n`** | new line |
|  **`\r`** | carriage return |
|  **`\t`** | horizontal tab |
|  **`\v`** | vertical tab |
|  **`\\`** | backslash |
|  **`\?`** | question mark |
|  **`\'`** | single quote |
|  **`\"`** | double quote |
|  **`\ooo`** | octal number |
|  **`\xhh`** | hexadecimal |

- **`\ooo`** (1 to 3 octal digits)and **`\xhh`** (1 or more hexadecimal digits)allow you to represent a character as an octal or hexadecimal respectively so `x4b` is the character `K` and '\124' is octal for `T`.  This is useful for representing invisible characters or any character as a symbolic constant with the `#define` qualifier.
 
#### Constant Expressions:
- These are expressions involving literals only. They may be evaluated in compile time so can be plugged anywhere a literal can. Examples include:
```c
#define MAXLINE 1000

char line[MAXLINE + 1]; // MAXLINE + 1 is a constant expression.
```

#### String Constant:
- A **string constant** is a "sequence of zero or more characters surrounded by double quotes" (different from characters which are surrounded by single quotes). Double quotes are not part of a string but serve to delimit it. 
- It also looks like **`'"'`** is legal as a character but you need the double quote escape character **`\"`** to represent a double quote in a string!
- String literals can also be concatenated in compile time which is useful when trying to work with long strings that need to be split over multiple source lines. The two following statements print the same thing:
```c
printf("Hello, world!\n");
printf("Hello,"  " world!" "\n");
```
- A string is actually an array of characters terminated by the **`\0`** (so called *null character*). To store a string you need an extra slot in the character array for this terminator. There is no limit on how long a string can be, but programs need to scan the whole string to determine its length. The program reads each characters until it encounters the null encounter and then it knows the length of the string. A popular standard library function for this **strlen**.
- One should always be careful about the difference between characters and strings that might look similar. `x` is an integer representing a single character, while `"x"` is an array of characters containing a character 'x' and a null terminator `\0`. You can have an empty string `""`, but you cannot have an empty character constant `''`.

#### Enumeration Constants:
- **Enumeration constants** are maybe another important kinda literal. They are lists of integers that progress linearly, unless specified otherwise:
```c
enum nums {ZERO, ONE, TWO, THREE};
```
- Elements in the enumeration are automatically initialized to 0, 1, 2, 3. You can specify these value, and if you specify just one, the linear progression will continue for the following elements you don't specify. The following enumeration will have numbers 100, 101, 0, 1:
```c
enum nums {ZERO = 100, ONE, TWO = 0, THREE};
```
- Enumerations offer a few advantages over `#define` such as compile time checking *(Not quite sure about this one)*, and automatic value generation.

### Declarations:
- A declaration must be made before a variable can be used, although "some declarations can be made implicitly by context" *(Oh, really!!! :confused:)*.
- A declaration in C specifies a certain type followed by a list of variables of that type:
```c
int a, b, c;
char c, line[1000];
```
- A declaration can also contain a initialization when it's followed by an assignment operator and an expression.
- If the variable being initialized is an external variable, it is initialized once before the program starts execution. The book says such variable must be initialized to a constant expression. *What is not a constant expression?* :confused:.
- Global and *static* variables *(What are these?!!)* are automatically initialized to 0, but uninitialized local variables have garbage. 

### `const`:
- The qualifier **`const`** can be applied to any variable declaration. It indicates that a variable cannot be changed. Declaring but not initializing an external `const` guarantees its value defaults to 0, but an internal `const` is garbage and stays garbage.
- `const` can also be used to prevent arrays from being changed. The program's behavior when attempting to change a const array is implementation specific:
```c
const char msg[] = "warning: ";
```

### Arithmetic Operators:
- Arithmetic arithmetize. 
- This table details the precedence and associativity of all C operators. Some of these operators we will see in later sections:

| Operators / precedence | Associativity |
| --- | --- |
| **`()`**  **`[]`**  **`->`**  **`.`** | left-to-right |
| **`!`**  **`~`**  **`++`**  **`--`** **`+`**  **`-`**  **`*`**  **`&`** **`(type)`**  **`sizeof`** | right-to-left |
| **`*`**  **`/`**  **`%`** | left-to-right |
| **`+`**  **`-`** | left-to-right |
| **`<<`**  **`>>`** | left-to-right |
| **`<`**  **`<=`**  **`>`**  **`>=`** | left-to-right |
| **`==`**  **`!=`** | left-to-right |
| **`&`** | left-to-right |
| **`^`** | left-to-right |
| **`\|`** | left-to-right |
| **`&&`** | left-to-right |
| **`\|\|`** | right-to-left |
| **`?:`** | right-to-left |
| **`=`**  **`+=`**  **`-=`**  **`*=`** **`/=`**  **`%=`**  **`&=`**  **`^=`** **`\|=`**  **`<<=`**  **`>>=`** | left-to-right |
| **`,`** | left-to-right |

### Logical Operators:
- Just remember as is the case is with other languages, the logical operators **`&&`** and **`||`** stop evaluation if the first operand gives enough information about the truthfulness of the expression. `||` does not check the second operand if the first one is true, and `&&` stops if the first operand is false. 
- Another weird feature found in other languages as well is that `&&` has a higher precedence than `||`. 
- The unary **`!`**, as expected, converts a non-zero operand into a zero and a zero into a one.

### Type Conversions:
- Expressions involving operands of different types might cause operands to be converted automatically. The rules governing automatic type conversions can placed in three large classes:
	- The general rule is that narrower type values can be converted automatically to larger ones without problems or warnings. An `int` can be readily converted into a `float`, a `long` or a `double`. 
	- Some expressions are not allowed such as using a float as an array index.
	- Converting larger types to smaller types can result in loss of information but is totally legal in C although the compiler might throw warnings. 

#### `char` Arithmetic:
- Chars can be used in arithmetic operations just like other integer types. They allow for some nifty tricks like converting between cases or converting character arrays to numbers or vice versa. This is mostly the case with the _ASCII character set_. 
- C guarantees that regardless of what type is used to represent a character, long or short, signed or unsigned, negative or positive, the character will always be shown/represented correctly. This is mainly the result of the fact that ASCII characters are nicely tucked in the lowest 7 bits of integral value. The 8th bit is used for signage so the 127 characters should be fine regardless of the sign. *(I guess I need to learn English first)*.
- Conversion rules can be convoluted when involving different types and lengths, but they generally conform to common sense. Just be aware of these traps, know the type value ranges of your system, and try to force the types you want.
- You can use casting just like Java and others to force an expression to be of the desired type. 

### Increment vs. Decrement:
- One has to be careful about the difference between *postfix* and *prefix* increment/decrement. Prefix increases the value of a variable before using it, while in post fix the value is changed after being used as the following example shows:
```c
int n, x;
n = 5;

x = ++n; // x is 6
x = n++; // x now is still 6, even though n becomes 7 after this increment
```
- This little detail can introduce frustrating bugs especially in loop bodies.

## Conditional Expression with the Ternary Operator:
```c
z = (a > b) ? a : b;
```
- We are all familiar with this. One need to just be careful about the crazy automatic conversion rules as `(a > b)` might behave unexpectedly maybe when one its operands is unsigned or a gloat, etc.

## Control Flow:
- In this section we ill briefly go over a few rules of how *control flow* is done. Control flow basically refer to two loops and conditional statements. 
- Again, we will only focus on those weird and unfamiliar parts of the syntax that are specific to C. 

### Statements and Blocks:
- In addition to expressions, C also consists of **statements**. An expression becomes a statement when followed by a semicolon. Semicolons are not separators but act as statement terminators.
- C also consists of **block** which are delimited by a pair of braces **`{ ... }`**. Blocks are used to group statements together. You can also think of them as some kind of *compound statements*. A block is "syntactically equivalent to [a] statement". A block does not need be followed with a semicolon.

### If-else and Else-if:
- You need a block if your **`if`** statement is followed by multiple statements, but the block braces if it's followed by just one statement. 
- **`else`** is optional which means it can be a source of ambiguity. As a general rule, `else` follows the most recent `if` when there is ambiguity. Sometimes an `if` statement might be followed by just one statement so it does not need braces around the following statement, but statement following `if` might be a complex one spanning multiple lines and would have blocks of its own, etc. In such a case, it's easy to have an ambiguous and hard to find `else`.

## Functions and Program Structure:
- This section will tackle functions and program structures. The latter is about programs that spread over multiple source files.

### Function Basics:
- Function definitions have the following form:
```
return-type function-name(argument declarations){
	declarations and statements
}
```
- You can define a function that does nothing and returns nothing like:
```c
nothing() { }
```
- The function above returns nothing, but the compiler or something assumes it returns an `int` whose value is 0.
- At the top level scope, a program consists of a group of definitions of variables and functions. Functions communicate with each other through arguments, returned values and external variables. It doesn't matter what order functions are in in a source file. They can also be spread over multiple source files, but a function must be defined in one file and cannot be split among multiple files. 
- A function can **`return`** any kind of expression including a function call.
- There is also some imprecise bullshit about if `return` needs to be followed by an expression or not, and that it's legal but can result in problems, etc. 
- To compile a multiple-file program, you'd do something like this:
```
gcc file0.c file1.c file2.c
```

### Functions Returning Non-Integers:
- When your function returns a value of a non-integer type, you really need to use a function prototype atop the calling function, or declare the function as you would declare an external variable that is defined elsewhere but you don't need the `extern` keyword. You shouldn't rely on the compiler to figure this for you. Those automatic conversions that C does are another of C's curses. This is especially pernicious _(I learned this word from this book)_ in multiple-file programs. Let's say we have defined a function `baba` that converts a string of characters to a `double`. To make use of that value in our `main` function, we need to redeclare the function within our `main` body. This looks a little weird, but it works and it would save us a lot of headaches:
```c
int main(){
	double baba(char []); // Is this a variable? a functon call?
	printf("%s\n", baba(-123.33));
}
```
- When the compiler first encounters a name followed by a left parenthesis, it assumes the name refers to a function. If it hasn't been told the return type by a function prototype or an explicit declaration, it assumes it returns an `int` and the returned value will be garbage. 
- The declaration must match the return type of the definition as well as its parameters so that the compiler can interpret the function correctly. Mismatching arguments are as problematic as mismatching return types. 
- To avoid trouble, the book suggests that we use `void` for arguments to declare a function that takes no arguments:
```c
double tata(void); 
```
- Something like `tata()` simply means don't assume anything about the arguments. The function might or might not take arguments. *Wow!!! I didn't even know this.*

### External Variables:
- The global/top level scope in C consists of functions and external variables. Functions themselves cannot be nested in C. External variables are not defined within any particular function which makes them visible to all functions. All references to external variables are references to the same thing, even "from functions compiled separately" in what is called **external linkage**. 
- There is apparently a way to define external variables and functions accessible only in their source files. _We will apparently see this later!!_
- When you have many functions that share a lot of data, it might be tempting to use shared external variables instead of passing a bunch of arguments around, but this is generally considered a bad practice! It's probably better to keep functions self-contained instead of having a bunch of functions changing the same variables. It's hard to know when and if a variable has been changed by some function buried in some file deep away from where the external variable is defined.
- There might be still situations when external variable use can be tolerated because of their higher scope and longer lifetime, but their use should still be limited and done carefully!
- The book goes on to illustrate that it can sometimes be useful to share external variables between functions when done judiciously.
- Although an external variable is visible to all functions, it looks like there is some kind of _lexical scoping_ used in a single file _at least_ (Here I am showing my ignorance of a lot of basic things). Anyways, check the following example:
```c
#include <stdio.h>

int main(){
	printf("%d\n", a); // Error: as far as main is conserned 'a' is undeclared.
}

extern int a  = 44; 
```
- The code above results in an error. An external variable defined after a function (in the following lines) is not visible to that function.


## Pointers and Arrays:
## Structures:
## Input/Output:
## UNIX Interface:
## Notes on the Standard Library: