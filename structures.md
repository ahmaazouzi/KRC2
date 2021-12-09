# Structures:
## Introduction:
- A **structure** can be defined as "a collection of one or more, possibly of different types, grouped together under a single name for convenient handling." *Couldn't be said better!!* They allow for better organization of large programs because they allow you to treat groups of related data as as single units. 
- A structure is basically like an object in OOP languages (of course, minus all the OOP goop like inheritance, etc.). It allows you for example to define a person by name, address, age, purchases,etc. Structures can also have some of their fields as structures, too, so the name field's value would be a structure that has a first, middle, and a last name, for example. 
- Structures are simple in concept, just like pointers but they quickly get more complicated, especially when you have to allocate memory for them, use them with pointers, try to use them with arrays, functions, etc. 
- Structures are also extremely important in C as many data structures are based on them. The language itself doesn't offer any of the juicy things like hash maps, trees and blah blah, so you need to really understand structures to create such data structures or use existing ones. 

## Basics of Structures:
- One of the simplest things that can be represented by a structure is a point in a 2D plane (all planes are 2D, right?!). For such a point we need an x and a y value. Defining a such a structure is done s follows:
```c
struct point {
	int x;
	int y;
};
```
- The **`struct`** keyword is used to declare structures. It's followed by the name of the declaration which is `point` in our example. Following the name is a list of declarations enclosed by braces and separated by semicolons. 
- Notice also that the declaration of a structure is followed by a semicolon, something you wouldn't see in other kinds of blocks such as function declarations or blocks following control flow statements, etc. Let's think of a structure as a literal array which is also always followed by a semicolon.
- Following the keyword `struct` is the so-called **structure tag** which denotes its *kind* ("kind" is a better word for now than "type", so we don't confuse this with actual types like `int` and `char`, etc.) Now we can use this definition to create many particular points that all share the same structure, they all have an integer x an y value and the structure tag acts as a shorthand for the part of structure definition between the braces.
- The list of declarations (variables) inside the structure are called its **members**. They can have the same names as variables defined outside the structure or members of other structures without conflict.
- A `struct` declaration declares a `struct` type. Following the right brace is an optional list of variables of the specified type of structure. You can declare a list of variables of the given structure type in the following manner:
```c
struct { int x; int y;} a, b, c;
```
- Each one of the variables defined in the declaration above: `a`, `b`, `c` is a structure that has has an `x` and a `y` members. They are different from the earlier `point` which had a structure tag you could reuse. This will be clearer when talk about using structures (rather than declaring/defining them).
- When we defined the structure `point` no storage was reserved. All we did was defining a template that can be used later by variables to create structures of type `point`. Well, it can be used latter because it's a tagged structure. On the other hand, the definition `struct { int x; int y;} a, b, c;` actually reserves storage for each of the three defined variables.

### Creating Variables of Tagged Structures and Structure Initialization:
- You can create a structure of the tagged structure type `point` as follows:
```c
struct point somePoint;
```
- This actually reserves storage for `somePoint` which is the same as storage reserved for any other variable of type `point`.
- A structure can also be directly initialized:
```c
struct point anotherPoint = {111, 222};
```
- Now `x` in `point` ha the value 111, and `y` is 222. The order here follows the order of the declarations inside the braces.
- The following attempt to initialize a variable however is wrong:
```c
struct { int x; int y;} a, b, c;
// a = {12, 11}; // WRONG
// struct b = {11, 21}; WRONG
```
- The book also claims that an *automatic structure* (what? a struct inside a function, or it might have a different meaning?!!). Anyways, an automatic structure can be initialized by assignment (what?!) or with a function that returns a structure of a specific type.
- Members can be accessed with the construct:
```
structure-name.member
```
- As in:
```c
printf("x: %d, y: %d\n", somePoint.x, somePoint.y);
```
- These members can also be changed or set with something like:
```c
somePoint.x = 111;
somePoint.y = 222;
```

### Nested Structures:
- You can also nest structures so structures are members of structures. The following image shows how a rectangle can be represent in graphics:
![Rectangle](img/rect.png)
- A rectangle can then be represented by the previously defined `point` in a structure of the form:
```c
struct rectangle = {
	struct point pt1;
	struct point pt2;
}
```
- Imagine we have a variable `screen` of type `rectangle` defined in:
```c
struct rectangle screen;
```
- To access the `x` coordinate of `pt1` of `screen`, we use:
```c
screen.pt1.x
```
- The nesting can get really deep.

## Structure Legal Operations:
- The only legal operations on structures are:
	- Copying to a structure and assigning to structure. This includes:
		- Passing structures are arguments to functions.
		- Returning structures as values from functions:
	- Taking a structure's address with `&`.
	- Accessing members of a structure. 
	- A structure *may* be initialized with a list of literal member values.
	- An automatic might be initialized by a assignment.
- Things you cannot do to a structure include:
	- Compare two structures.

## Structures and Functions:
- This sections deals primarily with how structures are passed to/used by functions and not as much with how functions return structures as that is the same everywhere. 
- Since returning a structure is the same all across let's get it out of the. The following is a declaration of a function that returns a `point` structure:
```c
struct point giveMeAPoint(){
	struct point someStructure;

	// ...

	return someStructure;
}
```
- As for passing a structure or structure data to a function, it can be done in one of three ways:
	- Pass separate data components to the function which uses this data to create a structure.
	- Pass an entire structure to the function.
	- Pass a pointer to the structure to the function.
- The following subsections will give examples of each of these 

### Pass Components Separately:
- The following example should be self-explanatory:
```c
#include <stdio.h>

struct point { int x; int y;};

struct point makePoint(int x, int y){
	struct point pt = {x, y};

	/*
	struct point pt;
	pt.x = x;
	pt.y = y;
	*/

	return pt;
}

int main(){
	struct point a, b, c;

	a = makePoint(1, 2);
	b = makePoint(3, 4);
	c = makePoint(5, 6);

	printf("a.x: %d,  a.y: %d\n", a.x, a.y);
	printf("b.x: %d,  b.y: %d\n", b.x, b.y);
	printf("c.x: %d,  c.y: %d\n", c.x, c.y);

	return 0;
}
```

### Pass Entire Structures:
- At the most basic level, you'd pass some structure to a function and modify its members or maybe use it to create new structures. The following example creates a `rectangle` from existing points:
```c
struct rectangle makeRec(struct point pt1, struct point pt2){
	struct rectangle rec;
	rec.pt1 = pt1;
	rec.pt2 = pt2;

	return rec;
}
```

### Pass Pointer to Structure:
- Structures can and do often get really large, so it can be very inefficient to pass around such large behemoths around. Instead, we can simply pass to our function a pointer to the structure.
- A pointer to a structure is simple just like a pointer to a regular variable:
```c
struct point somePoint, *pp;

pp = &somePoint;
printf("Some point is (%d, %d)\n", (*pp).x, (*pp).y);
```
- The *structure member operator* **`.`** has a higher precedence than the dereferencing operator **`*`** meaning that we absolutely need the parentheses around **`*pp`**. **`(*pp).x`** accesses members of the structure pointed to by `pp`. Without parentheses, **`*pp.x`** is equivalent to **`*(pp.x)`** "which is illegal here because `x` is not a pointer,"  Don't you know?!
- The use of pointers to structures is so ubiquitous that C now includes convenient syntactic sugar to denote accessing a structure member from a pointer to that structure, so instead of writing **`(*p).x`**, we can simply write **`pp-> x`**.
-
- The following examples illustrates passing pointers to structures to functions and the convenience of the **`->`** syntactic sugar:
```c
#include <stdio.h>

struct point { int x; int y;};

struct rectangle {
	struct point pt1;
	struct point pt2;
};

struct rectangle makeRec(struct point *pt1, struct point *pt2){
	struct rectangle rec;
	rec.pt1.x = pt1->x;
	rec.pt1.y = pt1->y;
	rec.pt2.x = pt2->x;
	rec.pt2.y = pt2->y;

	return rec;
}

int main(){
	struct point *pp1, *pp2;
	struct point pt1 = {22, 33};
	struct point pt2 = {44, 66};
	pp1 = &pt1;
	pp2 = &pt2;

	printf("pt1 is (%d, %d)\n", pp1->x, pp1->y);
	printf("pt2 is (%d, %d)\n", pp2->x, pp2->y);

	struct rectangle rec = makeRec(pp1, pp2);

	printf("Some point is (%d, %d)\nThe other point is (%d, %d)\n", 
		rec.pt1.x, rec.pt1.y, rec.pt2.x, rec.pt2.y);

	return 0;
}
```
- One interesting bit from the book this final example. Suppose we have the following declaration:
```c
struct rectangle r, *rp = &r;
```
- The following 4 expressions are the same:
```c
r.pt1.x
rp->pt1.x
(r.pt1).x
(rp->pt1).x
```
- Consider the following declaration:
```c
struct {
	int len;
	char *str;
} *p;
```
- Based on such a declaration
	- **`++p->len`** is equivalent to **`++(p->len)`**. It increments len because `len` is very tightly bound to `p` due to high **`->`** precedence.
	- **`(++p)->len`** increments `p` before accessing `len`.
	- **`*p->str`** is equivalent to **`*(p->str)`**. Since **`str`** is a pointer, this expression dereferences it.
- *Whatever, the last paragraph was more confusing than anything!!!*

## Arrays of Structures:
- By the way, before anything, an array of anything can be a member of a structure.
- Structures can also be placed in arrays. Imagine we want to have an array of structures to keep track of program's source keywords and the number of their occurrences in some program file. Such an array of structures would be defined as:
```c
#define NKWORDS 1000

struct keyword {
	char *word;
	int count;
} keywords[NKWORDS];
```
- There is a lot going on in the definition above. We are defining both a structure tagged as `keyword` and an array `keywords[]`of structures of type `keyword`, meaning that the definition above can be expanded into two parts: 1) Declaring the structure `keyword`, and 2) defining an array `keywords[]` containing `NKWORDS` `keyword` structures:

```c
struct keyword {
	char *word;
	int count;
};

struct keyword keywords[NKWORDS];
```
- What's even cooler is that you can initialize such arrays with a literal as in:
```c
struct keyword {
	char *word;
	int count;
} keywords[] = {
	{"char", 0},
	{"auto", 0},
	{"register", 0},
	/* ... */
	{"comatose", 0}
};
```
- The inner braces in the initializing literal are not always necessary, especially when the stricture consists of a few  simple types or character strings. This definition, then, can be written as:
```c
struct keyword {
	char *word;
	int count;
} keywords[] = {
	"char", 0,
	"auto", 0,
	"register", 0,
	/* ... */
	"comatose", 0
};
```
- Accessing these structures in the array and their members is also a cake. A given structure in the array can be accessed by its index in the array. The following assignment copies the contents of `keywords[0]` to the struct `charact`
```c
struct keyword charact = keywords[0]; // This basically copying since structs are passed value.
```
- Accessing the members of a structure in an array is equally easy and is done with indexing:
```c
keywords[0].word = "whatever";
keywords[0].count = 1111;
```

### `sizeof`:
- The **`sizeof`** operator allows you to extract of different data sizes including primitive types such as integers, floats, chars, etc. It also extracts the size of such constructs as arrays and structures. Sizes of such data such as arrays and structures are determined at compile time.
- Imagine initialization an array of structures while defining it and this array's size might change in the future as elements might be added or removed from it. Every time you add or remove an element from the array, you will also need to update its size and it's really easy to forget about changing the size of the array. The solution can be something as hacky as changing the size every time the array size change or ending the array with a null pointer to *terminate traversals (not really sure about this last point. I'm cargo-culting here)*.
- A better solution is to use `sizeof` to dynamically recalculate the size of the array every time the program is compiled. You do something like the following:
```c
#define NWORDS (sizeof keywords / sizeof (struct keyword))
```
- You can alternatively divide the array by its first element:
```c
#define NWORDS sizeof keywords / sizeof keywords[0]
```
- The last way of doing things might be better because the `NWORDS` might contain a different type.

## Pointers to Structures:
- There is one important problem explained here (it doesn't even have to do necessarily with structures). Let's say you want to use pointers to get the middle element in an array. You cannot do something like the following:
```c
int mid = (high + low) / 2;
```
- The reason is that you cannot add two pointers. The correct way is:
```c
int mid = low + (high - low).
```
- *I've seen the problem  above before in a different context and I think this might be the reason. That was probably implemented in C.*
- Another problem that also has to do with pointers and arrays is trying to use a pointer outside the bounds of an array. Imagine having an array `arrayWhat[]` of size `SIZE`. `&arrayWhat[-1]` is totally legal, but `array[SIZE]` is illegal to access but is illegal to reference. 
- One cool thing about traversing an array of structures using pointer notation is that C is smart to move using structure sizes. If `*p` points to the beginning of an array, then `p + 1` points to the second element in the array, and `p++` moves forward one structure at a time.
- Another issue that I've been wondering about is that the size of a structure is not determined by the size of data types it contains but is rather determined by number of elements multiplied by the largest data size it contains. This is an *alignment* issue (see our notes on computer systems).
```c
struct fafa {
	char a;
	int zaza;
};
```
- The structure above has a size 8 bytes instead of 5 (at least in x86-64).

## Self-referential Structures:
- *This section delves a bit into data structures, mainly linked lists and binary search trees. I'll mostly focus on the C syntax and its usage. I believe it contains some discussion about memory management*.

## Table Lookup:
## `typedef`:
## Unions:
## Bit-fields: