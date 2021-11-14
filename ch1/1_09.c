#include "stdio.h"

/*
blank block lengths are tracked. When the length of a block 
excheeds zero, the first blank in the block is putchared and then
getchar is set to zero, thus preventing the outputting 
of consective blanks.
when a non-blank is encoutered, the block length is reset to zero.
*/ 

int main()
{
	int c, block_of_blanks_length=0;

	while((c = getchar()) !=EOF){
		if (c != ' '){
			block_of_blanks_length = 0;
		}
		if ( block_of_blanks_length > 0){
			c= 0;
		}
		if (c == ' ')
			block_of_blanks_length++;
		putchar(c);	
	}
}

/* 
The following is a more generalized program, something that kinda trims text 
of all double whitespace that includes tabs, newlinees and blanks.
/*


/*
#include <stdio.h>

int main(){
	int c;
	int tab, space, newline;
	tab = space = newline = 0;

	while ((c = getchar()) != EOF){
		if (c == '\n'){
			if (newline) ;
			else {
				putchar(c);
				newline = 1;
			}
		}
		else if (c == '\t'){
			if (tab) ;
			else {
				putchar(c);
				tab = 1;
			}
		}
		else if (c == ' '){
			if (space) ;
			else {
				putchar(c);
				space = 1;
			}
		} 
		else {
			if (tab) tab = 0;
			else if (newline) newline = 0;
			else if (space) space = 0;
			putchar(c);
		}
	}
}
*/