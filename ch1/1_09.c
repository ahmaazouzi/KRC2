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