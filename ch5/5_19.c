#include <ctype.h>
#include <string.h>
#include <stdio.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};


int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main(){
	while (gettoken() != EOF){
		strcpy(out, token);
		while (type)
	}
	return 0;
}

int gettoken(void){
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '('){
		/* keep running in spite of spurrious blanks inside function parens*/
		while ((c = getch()) == ' ' || c == '\t')
			;	
		if (c == ')'){
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '['){
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)){
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else {
		return tokentype = c;
	}
}