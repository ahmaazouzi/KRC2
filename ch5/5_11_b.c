#include "stdio.h"
#define TABSIZE  8
#define INBLANK  1
#define OUTBLANK 0

void reblank(int blankblock, int state);

int main(){
	int c, blankblock, tabstop, state;

	blankblock = 0;
	tabstop = 1;

	state = OUTBLANK;

	while ((c = getchar()) != EOF){

		if (c == ' '){
			state = INBLANK;
			++blankblock;
		} 
		else {
			reblank(blankblock, state);
			state = OUTBLANK;
			putchar(c);
		}

		if (state == INBLANK && tabstop == 8){
			if (c == ' '){
				blankblock = 0;
				putchar('\t');
			} else {
				reblank(blankblock, state);
			}
		}

		++tabstop;	
		if (tabstop == 9)
			tabstop = 1;
		if (c == '\n')
			tabstop = 1;
	}

	return 0;
}

void reblank(int blankblock, int state){
	if (state == INBLANK){
		while (blankblock > 0){
			putchar(' ');
			--blankblock;
		}
	}	
}