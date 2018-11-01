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
	int c, tablength, tab, tabstop, columnnumf;
	int columnnum, startatf, startat, flagella, charcount;

	tablength = columnnum = columnnumf = startatf = startat = flagella = charcount = 0;

	tabstop = TABSIZE;

	while (--argc > 0 && (*++argv)[0]){
		if ((*argv)[0] == '-' && (*argv)[1] == 'm') 
			startatf = 1;
		if ((*argv)[0] == '+' && (*argv)[1] == 'n'){
			columnnumf = 1;
			break;
		}
	}

	if (startatf &&  columnnumf)
		flagella = 1;

	if (flagella)
		tabstop = columnnum;
	if (argc > 1){
		startat = atoi(*++argv);
		columnnum = atoi(*++argv);	
	}

	while ((c = getchar()) != EOF){
		++charcount;

		if (argc > 1 && charcount >= startat)
			tabstop = columnnum;

		if (c == '\t'){
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