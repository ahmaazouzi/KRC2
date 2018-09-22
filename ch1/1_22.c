#include "stdio.h"
#define LINEMAXSIZE 40
#define TABSIZE  8
#define INWORD  1
#define OUTWORD 0
#define MAXWORDSIZE 45

int fold(int blankblock, int state);
void reblank(int blankblock, int state);

int main(){
	int c,lineLength, wordsize, state, wordchar;
	char word[MAXWORDSIZE];

	state = OUTWORD;
	wordchar = 0;
	lineLength = 0;

	while ((c = getchar()) != EOF){
		if (c != ' ' && c != '\t' && c != '\n'){
			if (state == OUTWORD)
				state = INWORD;
			word[wordchar] = c;
			state = INWORD;
			++wordchar;
		} else {
			wordchar = 0;
			state = OUTWORD;
		}

		if (lineLength == LINEMAXSIZE){
			if (wordchar > 0){
					for (int i = 0; i <= wordchar; ++i)
					{
						putchar(word[wordchar]);
					}
					wordchar = 0;
					putchar('\n');
			} else {
					putchar('\n');
			}
			lineLength = 0;
		}
		if (c == '\n'){
			lineLength = 0;
		}


		// putchar(c);
		++lineLength;
	}

	return 0;
}