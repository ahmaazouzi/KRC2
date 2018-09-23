#include "stdio.h"
#define MAXLINESIZE 45
#define MAXWORDSIZE 45
#define LESSTHANMAX 0
#define MORETHANMAX 1

int main(){
	int c, wordsize, lineLength, state;

	char word[MAXWORDSIZE];
	wordsize = 0;
	state = LESSTHANMAX;


	lineLength = 0;
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n'){
			if (lineLength >= MAXLINESIZE){
				c = '\n';
				// lineLength = 0;
			}
			if (wordsize > 0){
				if (state == MORETHANMAX){
					putchar('\n');
				}
				for (int i = 0; i < wordsize; ++i){
					putchar(word[i]);
				}
			}
			putchar(c);
			wordsize = 0;
		} else {
			if (lineLength >= MAXLINESIZE){
				state = MORETHANMAX;
				lineLength = 0;
			}
			word[wordsize] = c;
			++wordsize;
		}

		if (lineLength < MAXLINESIZE){
			state = LESSTHANMAX;
		}

		++lineLength;	
	}
}
