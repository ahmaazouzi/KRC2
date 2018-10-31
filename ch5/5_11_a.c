/* Not sure exactly what a list of tabstops means.
 * I am assuming that each argument represents the
 * number of columns separating the presopective 
 * tabstop from the previous one.
 */

#include "stdio.h"
#include <ctype.h>
#include <stdlib.h>

#define TABSIZE 8

int main(int argc, char *argv[]){
	int c, tablength, tab, tabstop;

	tablength = 0;

	while ((c = getchar()) != EOF){

		if (c == '\t'){
			tabstop = ((--argc > 0 && isdigit((*++argv)[0])) ? atoi(*argv) : TABSIZE);
			while(tablength < tabstop) {
				putchar(' ');
				tablength++;
			}
			tablength = 0;	
		} else {
			putchar(c);
			tablength++;
		}	
	}

	return 0;
}