#include "stdio.h"
#define MAXLINESIZE 45
#define MAXWORDSIZE 45

int main(){
	int c, wordsize, lineLength, state;
	char word[MAXWORDSIZE];
	
	wordsize = 0;
	lineLength = 0;

	while ((c = getchar()) != EOF){
		if (c ==  '\n'){
			lineLength = 0;
		}
		if (c == ' ' || c == '\t'){
			if (lineLength == MAXLINESIZE) {
				c = '\n';
				lineLength = 0;
			}
			else if ( wordsize > 0){
				if (lineLength > MAXLINESIZE){
					putchar('\n');
					lineLength = wordsize;
				}
				for (int i = 0; i < wordsize; ++i){
					putchar(word[i]);
				}
			}
			putchar(c);
			wordsize = 0;
		} else {
			word[wordsize] = c;
			++wordsize;
		}

		++lineLength;	
	}
}
