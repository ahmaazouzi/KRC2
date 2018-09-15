#include "stdio.h"

/*
I honestly don't know what '\b' is. I used '\n' instead.
*/ 

int main()
{
	int c;

	while((c = getchar()) !=EOF){
		if (c == '\t'){
			putchar('\\');
			c = 't';
		}
		if (c == '\\'){
			putchar('\\');
			c = '\\';
		}
		if (c == '\n'){
			putchar('\\');
			c = 'n';
		}
		putchar(c);	
	}
}