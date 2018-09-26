#include "stdio.h"
#define MAXSYMBS         1000
#define OPENPARANTHESES  '('
#define CLOSEPARANTHESES ')'
#define OPENBRACKET      '['
#define CLOSBRACKET      ']'
#define OPENBRACE        '{'
#define CLOSBRACE        '}'
#define SINGLEQUOTE      '\''
#define DOUBLEQUOTE      '"'
#define BSLASHED         1
#define UNBSLASHED		 0
#define BSLASH			 '\\'
#define LINEEND			 '\n'
#define SLASH			 '/'
#define STAR			 '*'

int main(){
	int c, lineNumber, parantheses, braces, brackets;
	char i;
	char groupers[MAXSYMBS];

	brackets = 0;
	braces = 0;
	parantheses = 0;
	lineNumber = 1;
	i = 0;
	while ((c = getchar()) != EOF){
		if (c == LINEEND){
			++lineNumber;
		}

		if (c == OPENPARANTHESES||c == CLOSEPARANTHESES||
			c == OPENBRACE ||c == CLOSBRACE||
			c == OPENBRACKET||c == CLOSBRACKET){

			groupers[i] = c;
			++i;
		}		
	}
	++i;
	groupers[i] = '\0';

	for (int t = 0; t <= i; ++t){
		if (groupers[t] == OPENPARANTHESES)
			++parantheses;
		if (groupers[t] == OPENBRACKET)
			++brackets;
		if (groupers[t] == OPENBRACE)
			++braces;
		if (groupers[t] == CLOSEPARANTHESES)
			--parantheses;
		if (groupers[t] == CLOSBRACE)
			--braces;
		if (groupers[t] == CLOSBRACKET)
			--brackets;
	}

	if (parantheses < 0)
			printf("Dude, there is no need for this paranthesis\n");
	if (parantheses > 0)
			printf("You added unncessery paranthesis\n");

	return 0;
}

