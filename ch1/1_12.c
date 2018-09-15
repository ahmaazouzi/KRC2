#include "stdio.h"

#define IN  1
#define OUT 0

/*
While the solution might seem as simple as replacing blanks with
new lines, mmultiple consecutive blank spaces shouldn't be replaced 
by multiple new lines.
Eventually, any non alphanumeric character can be considered as a separator,
but that's probably out of the scope of this exercise.
*/ 

int main()
{
	int c;
	int state = OUT;

	while((c = getchar()) !=EOF){
		if (c == '\t' || c == ' ' || c == '\n'){
			if (state == IN) putchar('\n');
			c = 0;
			state = OUT;
		}
		else {
			state = IN;
		}
		putchar(c);	
	}
}