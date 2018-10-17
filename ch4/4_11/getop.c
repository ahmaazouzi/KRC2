#include "stdio.h"
#include "ctype.h"
#include "calc.h"

int getop(char s[]){
	int i, c;
	static int bufp;

	while ((s[0] = c = getch(bufp = 0)) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch(bufp)))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch(bufp)))
			;
	s[i] = '\0';
	if (c != EOF)
		buf[bufp++] = c;

	return NUMBER;
}