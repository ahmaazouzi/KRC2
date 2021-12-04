# Pointers and Arrays:
## Introduction:
- _I've managed to mess everything I've touched in the last 9 years! Let me not mess this one up! Let's do this thing step by step and demystify it once and for all._
- A **pointer** is a variable that contains the address of another variable.
- Pointers are important in C because they are sometimes the only to do certain computations. They can also result in "compact and efficient code".
- Pointers and arrays are closely related so this sections will try to study both of them.
- Pointers have a dreadful reputation because some programmers use them to create hard to understand code and it's easy to misuse them. We will try to understand how they work.
- *Actually the main reason I am rereading the book is pointers*.

## Pointers and Addresses:
- Memory can be viewed as a large "array of consecutively numbered or addressed memory cells that may be manipulated individually or in groups". A `char` for example is a single byte _(does a memory cell always have a one-byte size?)_, a `short` is two bytes, an int is probably 4 bytes. A pointer is a group of 2, 4 or 8 cells tht hold an address. The machine on which this is typed has a pointer size of 8 bytes. 
- C provides two important unary operators for handling and manipulating pointers, namely **`&`** and **`*`**.
- The unary operator **`&`** allows us to extract the memory address of a variable as in:
```c
p = &c;
```
- The operator `&` takes the memory address of variable `c` and assigns it to `p`. `p` now points to c. `&` can only be applied to memory objects: variables and array elements, but not to constants, expressions, or register variables.
- The unary operator **`*`** is called the **dereferencing** or **indirection** operator. You apply this operator to a pointer to get the object the pointer points to.
- Let's assume `x` and `y` are `int` variables, and `ip` is a pointer to an `int`. The following examples show the basics of how to use pointers and the `*` and `&` operator:
```c
int x = 1, y = 2, z[10];

int *ip;    // Declaring an int pointer

ip = &x;    // ip now points to x 
y  = *ip;   // y contains the value pointed to by ip 1
*ip = 0;   // ip is 0 so is 0 too
ip = &z[0];
```
- Probably one of the most confusing aspects is when the indirection operator is used in declarations vs. when in use. We declare a pointer with something like this:
```c
int *ip;
```
- The declaration of a pointer looks like the declaration of a variable, but the dereferencing operator is used to differentiate pointers from regular variables. `*ip` itself is a "mnemonic. It says that the expression `*ip` is an `int`.These declarations quickly become more complex and confusing:
```c
double *dp, atof(char *);
```
- In this examples we declare a pointer `*dp` to a double and a function `atof` that returns a double. The function `atof` takes a pointer to a `char` as an argument. 
- A pointer generally points to a specific type of data so a `char` pointer points to a `char`, a `float` pointer points to a `float`, etc. There is one exception to this general case, namely so called *pointer to void* which we will see in a later section.
- When pointer `ip` points the integer `x`, then `*ip` can occur wherever `x` can appear as part of expressions in the context of arithmetic and other kinds of operations. Examples include:
```c
++*ip;
*ip += 10;
(*ip)++;
```
- You wouldn't need parentheses around `*ip` because unary `*` has a generally higher precedence than arithmetic operators. There is a case, however, where you will need parentheses as in `(*ip)++` or `(*ip)--` because `--`, `++` and unary `*` associate right to left. `*ip++` actually increments the pointer ip rather than the value it points to, so we jump to the next address. 
- Pointers are variables. They don't have to only be used with dereferencing. In the following example the pointer `iq` now points to what `ip` points to:
```c
iq = ip; 
```
- The contents of `ip` (the memory address of `x`) is copied to `iq`.

## Pointers and Function Arguments:
- One of the more important contexts where pointers are absolutely necessary is where a function needs to change arguments passed to them. As we already know, C passes arguments by value rather than reference, so using plain old variables, we cannot have a function `swap` like this for swapping the positions of two variables:
```c
swap(a, b);
```
- Such a function would have the following wrong definition:
```c
void swap(int x, int y){
	int temp;
	temp = x;
	x = y;
	y = temp;
}
```
- The function above only changes its local copies of `x` and `y` and never affect the actual arguments passed to it. To achieve the desired result we will need pointers. We give `swap` the addresses of `a` and `b` as arguments:
```c
swap(&a, &b);
```
- The definition of `swap` now becomes:
```c
void swap(int *px, int *py){
	int temp;
	temp = *px;
	*xp = *py;
	*py = temp;
}
```
- Basically, "pointer arguments enable a function to access and change objects in the function that called it."
- In many ways, arrays act like pointers. If you pass an array itself as an argument, you CAN change their values. Arrays are _passed by reference_. But let yourself by tricky situations like the one shown in this example:
```c
#include <stdio.h>

void doublo(int *a){ // This function is not aware it's dealing with an array element.
	*a = *a * 20;
}

int main(){
	int array[] = {1,2,3};
	doublo(&array[0]);
	printf("%d\n", array[0]);
	return 0; 
}
```

## Pointers and Arrays:
- It might be safe to say that arrays are syntactic sugar over pointers. The two are extremely related that the would be better discussed together. Anything you can do with array indexing/subscripting, you can achieve with pointers. Pointer operations that do the same things done with array subscripting are faster but are harder to understand for us mere mortals. Let's go over this step by step and try to nail it. 
- The following declaration defines an array `a` of size 10. It is a block of 10 consecutive `int` objects {`a[0]`, ..., `a[9]`}:
```c
a[10];
```
- The following snippet declares a pointer `*pa` and assigns the first element in the array `a` to it:
```c
int *pa;
pa = &a[0];
```
- This means `pa` now contains the address of `a[0]`. The following assignment copies the contents of `a[0]` which are pointed to by `pa` to `x` provided that `x` is of type `int`:
```c
x = *pa;
```
- Other totally legal syntax for using pointer notation to access arrays include:
```c
*pa = a[0]; // No need for the & operator
*a;  // You can use this directly on an array a[] that is declared as an array.
```
- A pointer can point to any element within the array through the use of a notation that looks similar to array subscripting so that `pa + i` for example is equivalent to `a[i]`will point to the `i`th element of the array if `pa` itself points to the zeroth element of the array. You can also use `pa - i` if `pa` points to an element in the array is is smaller than the index point to. If `pa` point to `a[5]` then `pa - 3` points to `a[2]`. 
- Accessing the content of an array element pointed to by our pointer is obviously done with our dereference operator as in:
```c
*(pa + i);
```
- These rules/remarks are true regardless of the size of arrays to the data type they contain. Remember, pointer arithmetic mainly means that something like `pa + 1` points to the next object in an array or whatever. It points to the next memory object of the same size as what's being pointed to currently, and since arrays are blocks of contiguous memory cells, then that holds true as well. 
- The following three statements do the exact same thing:
```c
pa = &a[0];
pa = a[0];
pa = a;
```
- The following two expressions refer the exact same thing which is `a[0]`:
```c
*a;
*(&[0]);
```
- When `a` is declared/defined as an array `a[]` then `a` itself is for all intents and purposes a pointer.
- `a[i]` is equivalent to `*(a + i)`. This means that `&a[i]` is the same as `a + i` which is basically the memory address of the `i`th element in the array `a`.
- If pointer `pa` points to a`0` then `pa` itself can be used with subscripting: `pa[i]` is the same as `*(pa + i)`.
- *Be careful, though! I declared a string as a char pointer and couldn't change its contents with pointer or array arithmetic. I kept getting this `bus error: 10` thing error!*

### Where Array Names and Pointers Don't Behave the Same:
- A bigger problem is that while you can readily use pointer syntax when handling an array or use array syntax with a pointer that points to an array, you cannot treat a pointer as an array and there are things you can do with pointers that you cannot do with arrays.
- Assigning an array name to a pointer with `pa = a`, and incrementing a pointer with `p++` are totally legal operations, but the assigning an array to a pointer `a = pa` or trying to increment an array name are totally wrong `a++`.
- The greater flexibility pointers have can allow you to manipulate arrays in ways in you probably couldn't do with plain old array notation. The book suggests a version of `strlen` (for obtaining the length of a string) that exploits the flexibility of pointer syntax:
```c
int strlen(char *s){
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;

	return n;
}
```
- You can pass an array name to `strlen` since an array name is basically a pointer and all the following function calls are legal:
```c
strlen("zzzzzz");
strlen(ar); // for char ar[100];
strlen(ps); // char *ps;

```
- A pointer can be incremented within the function and manipulated in other ways, and since it's a private variable within the calling function it shouldn't really affect the passed array (unless you dereference it, of course).
- Although defining `char *s` or `char s[]` as parameters to a function can act the same, the book encourages us to rather use `char *s`. You can pass either an array or a pointer where a pointer is a parameter, but passing a pointer to where an array is defined comes with a baggage of segmentation faults and compiler warnings about attempted conversions from arrays to pointers. 

## Address Arithmetic:
- If pointer `p` points to an element in an array, `p++` points to the next elements and `p += i` points `i`th object in the array after what's being currently pointed to. Such operations are called collectively **address arithmetic**. *I don't know if this only refers to pointers pointing to array elements*. 
- To illustrate aspects of address arithmetic the book jumps headlong into implementing a basic memory management package which looks as follows:
```c
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
	if (allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	}
	else
		return 0;
}

void afree(char *p){
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
```
- The code mostly clear in light of what we've seen so far. It's based on the interplay between pointers and arrays. `alloc` allocates chunks of memory to the array that starts at address `allocbuf` as long as these chunks don't go beyond the bounds of the array bounded by `ALLOCSIZE`. Each time we call `alloc` it sets the global pointer `allocp` (global only within this file because `static`) to the end of the allocated chunk, but it returns the current value of `allocp`. This current value of `allocp` will next be used by `afree` to free the last `alloc`ed chunk. 
- One interesting remark about the code above is that the value zero can be used as a pointer value. Constant zero is a valid value for a pointer but zero itself is never a valid data address so it is used to signal that something went wrong.
- `0` or more appropriately `NULL` which is defined in `stdio.h` is special pointer value generally used to signal problems or do other things. It's something like `EOF` in character IO.

### Allowed Address Arithmetic Operations:
- You can compare and check for equality between two pointers if they belong to the same array with such operators as `==`, `!=`, `<`, `>=`. You can also check of the a pointers equals `NULL`. You can also use the address of the first element past the end of the array in address arithmetic. The behavior of comparing pointers pointing to elements that don't belong to the same array is undefined. 
- You can also add an `n` integer to a pointer to point to the `n`th element after the pointer. This works regardless of the data type of the pointer. The value of `n` is _scaled_ by the size of given pointer data type. 
- You can also use subtraction to have your pointer point to previous elements in the array. 
- In summary:
	+ You can assign pointers of the same type.
	+ You can add and subtract a pointer and an integer.
	+ You can subtract two pointers belonging to the same array.
	+ You can compare two pointers belonging to the same array.
	+ You can assigns and compare a pointer to `NULL`.
- All other pointer operations are illegal including:
	+ You cannot add or subtract two pointers.
	+ You cannot involve a pointer in a division, multiplication, masking or shift operation. 
	+ You cannot add or subtract a `float` or `double` to/from a pointer.
	+ You cannot assign a pointer to another pointer of a different type without a cast, except for the special pointer **`void *`** which we will see later. 

## Character Pointers and Functions:
- A a **string constant** like `"Hello, world!"` is an array of characters terminated by a null character `'\0'` that is not shown in the constant, but it is actually there. The length of a string constant is the number of characters it contain plus the null character. 
- A string constant usually appears as an argument to a function as in `printf("Hello, world!")`. In this case, `printf` receives a pointer to the first character of the string. So a string constant can also be defined using a pointer as in:
```c
char *cp;
cp = "Hello, world!";
```
- We have previously seen array characters and now we will look at strings as pointers:
```c
char *charP = "Hello, world!";
char charA[] = "Hello, world!";
```
- The two definitions above define 2 strings whose content is the same: `"Hello, world!"`, but there are some fundamental differences between the two definitions, name a string defined as a character array vs. a string defined as a character pointer.:
	- `charA` Always refers to the same storage (one block of memory), but the contents of this memory block can be changed.
	- `charP` is a pointer initialized to point to a string constant. `charP` may be modified to point to another character or string constant. However if you try to modify the contents of the string defined by/pointed to by `charP` you'd get an undefined behavior. 

### Copying a String:
- `string.h` provides many basic string manipulation functions such `strcpy` which copies it's send argument to its first argument. `strcpy` is basically defined as:
```c
 void strcpy(char *s, char *t){
 	while ((*s++ = *t++))  // same as ((*s = *t) != '\0'){s++; t++; }
 		;
 	}
 }
 ``` 
 - *To be honest, I still don't know how the construct above copies the null character. Ok, what seems to be happening is that each character from `t` is first fetched, copied to `s` and then incremented because we are using postfix increment. The evaluation of whether `t` equals `\0` happens after the character is already copied.. I don't know!! Main thing to know is that when the assignment happens before the functions knows that the last character is a `\0`. Maybe the incrementation happens after this evaluation.*
 - We are passing pointers to `strcpy` but we are passing them by value still, incrementing `s`, and `t` doesn't change the actual pointers! We are basically just copying the values of pointers to the function. *This might seem a little counter-intuitive, if not straight confusing because one of the reasons we use pointers in the first place is to avoid the shortcomings of passing by value. I have actually tried testing my understanding of this point by devising the following nonsensical example for swapping two strings. In this example, I am passing pointers to a function by reference rather than by value using the `&` operand:*
```c
#include <stdio.h>

void swappo(char **s, char **t){ // note pointers to pointers
	char *temp = *s;
	*s = *t;
	*t = temp;
}

int main(){
	char *s = "SSS";
	char *t = "TTT";

	swappo(&s, &t);

	printf("S is: %s\n", s); //prints TTT
	printf("T is: %s\n", t); // prints SSS
}
 ```

### Idiomatic Pushing unto/Popping from a Stack:
- The following two idioms are used for pushing unto and popping from a stack:
```c
 *p++ = val; // push: assigns val to p then increment pointer.
 val = *--p; // pop: assign current value of p to val then decrement p.
``` 

## Pointer Arrays, Pointers to Pointers:
- This section deals with _arrays of pointers_. Pointers themselves, like any other kind of variable, can also be placed nicely into arrays. To illustrate the importance of such a data structure, the book uses it to sort the lines of a given text. The [program](storlines.c) basically read its input extract lines as strings and stores them in a buffer. It also maintains an array of pointers. These pointers point to each of the buffered strings representing the lines. To sort the lines, the program doesn not actually sort the lines themselves which would be cumbersome and probably costly. Instead only the pointers to these lines are sorted as the following diagram shows:
![Sorting strings](img/sortStrings.png)
- To write the lines to output, the array of ordered pointers is traversed and the correctly-ordered lines are printed to output.





