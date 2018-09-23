#include "stdio.h"
#define MAXLINESIZE  45
#define MAXWORDSIZE  45
#define BEFORELINEEND 1
#define AFTERLINEEND  0

int main(){
	int c, wordsize, lineLength, LineEndState;
	char word[MAXWORDSIZE];
	
	LineEndState = BEFORELINEEND;
	wordsize = 0;
	lineLength = 0;
	while ((c = getchar()) != EOF){
		if (c ==  '\n'){
			lineLength = 0;
			LineEndState = AFTERLINEEND;
		}
		if (c == ' ' || c == '\t'){
			if (lineLength == MAXLINESIZE) {
				c = '\n';
				lineLength = 0;
				LineEndState = AFTERLINEEND;
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
			if (LineEndState == AFTERLINEEND){
				c = '\0';
				--lineLength;
			}
			putchar(c);
			wordsize = 0;
		} else {
			if (LineEndState == AFTERLINEEND){
				LineEndState = BEFORELINEEND;
				putchar('\n');
			}
			word[wordsize] = c;
			++wordsize;
		}
		++lineLength;	
	}
}
