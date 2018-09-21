#include "stdio.h"
#define TABSIZE 8

int main(){
	int c, tabstart, tablength;

	tabstart = 1;
	tablength = 0;

	while ((c = getchar()) != EOF){

		if (c == '\t'){
			while(tablength <= (TABSIZE - tabstart)){
				putchar(' ');
				tablength++;
			}
			tablength = 0;	
		} else {
			putchar(c);
		}

		++tabstart;	

		if (tabstart == 8)
			tabstart = 1;
	}

	return 0;
}
