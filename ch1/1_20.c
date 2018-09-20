#include "stdio.h"
#define TABSIZE 8
#define INTAB 0
#define OUTAB 1

int main(){
	int c, i, tabstart, state;

	state = OUTAB;
	tabstart = 1;
	
	while ((c = getchar()) != EOF){
		if (tabstart == 9)
			tabstart = 1;
		++tabstart;	

		if (c == '\t'){
			state = INTAB;
		}

		if (state == INTAB){
			putchar('#');
		}
		if (TABSIZE - tabstart < 1 && state == INTAB){
			state = OUTAB;
		}

	}

	return 0;
}
