/* Not sure exactly what a list of tabstops means.
 * I am assuming that each argument represents the
 * number of columns separating the presopective 
 * tabstop from the previous one.
 * Starting at column m. Does this mean there are no
 * tabstops before m? I am assuming that's  the case. As
 * for the default behavior, the there is a tabstopafter 
 * every 8 characters.
 */

#include "stdio.h"
#include <ctype.h>
#include <stdlib.h>

#define TABSIZE 8

int main(int argc, char *argv[]){
	int c, tablength, tab, tabstop, columnnumf, columnnum, startatf, startatf, flagella;

	tablength = columnnum = columnnumf = startatf = startat = flagella = 0;

	tabstop = TABSIZE;
	
	while (--argc > 0 && (*++argv)[0]){
		if ((*argv)[0] == '-' )
			startatf = 1
		if ((*argv)[0] == '+')
			tabstop  =  atoi(*argv);
	}

	printf("%d\n", tabstop);
	printf("%d\n", startat);


	// while ((c = getchar()) != EOF){

	// 	if (c == '\t'){
	// 		tabstop = ((--argc > 0 && isdigit((*++argv)[0])) ? atoi(*argv) : TABSIZE);
	// 		while(tablength < tabstop) {
	// 			putchar('#');
	// 			tablength++;
	// 		}
	// 		tablength = 0;	
	// 	} else {
	// 		putchar(c);
	// 		tablength++;
	// 	}	
	// }

	return 0;
}