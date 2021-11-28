# Pointers and Arrays:
## Introduction:
- _I've managed to mess everything I've touched in the last 9 years! Let me not mess this one up! Let's do this thing step by step and demystify it once and for all._
- A **pointer** is a variable that contains the address of another variable.
- Pointers are important in C because they are sometimes the only to do certain computations. They can also result in "compact and efficient code".
- Pointers and arrays are closely related so this sections tries to study both of them.
- Pointers have a dreadful reputation because some programmers use them to create hard to understand code and it's easy to misuse them. We will try to understand how they work.
- *Actually the main reason I am rereading the book is pointers*.

## Pointers and Addresses:
- Memory can be viewed as a large "array of consecutively numbered or addressed memory cells that may be manipulated individually or in groups". A `char` for example is a single byte _(does a memory cell always have a one-byte size?)_, a `short` is two bytes, an int is probably 4 bytes. A pointer is a group of 2, 4 or 8 cells tht hold an address. The machine on which this is typed has a pointer size of 8 bytes. 
- C provides with two important unary operators for handling and manipulating pointers, namely **`&`** and **`*`**.
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








