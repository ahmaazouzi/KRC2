#include "stdio.h"
#include <ctype.h>
#define MAXLINE 500

int main(){
	int c, linelen;
	linelen = 0;

	while ((c = getchar()) != EOF){
		linelen++;
		if (linelen >= MAXLINE && isspace(c)){
			putchar('\n');
			linelen = 0;
		}

		if (c >= 0 && c <= 32){
			if (c == '\t' || c == ' ')
				putchar(c);
			else if (c == '\n'){
				putchar(c);
				linelen = 0;
			} else 
				printf("%x", c);
		} else if (c == 127)
			printf("%x", c);
		else
			putchar(c);
	}
	return 0;
}
