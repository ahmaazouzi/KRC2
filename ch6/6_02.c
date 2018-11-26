#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NKEYS (sizeof keytab / sizeof(struct key))
#define MAXWORD 100

struct key {
	char *word;
	int count;
} keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"do", 0,
	"double", 0,
	"else", 0,
	"enum", 0,
	"extern", 0,
	"float", 0,
	"for", 0,
	"goto", 0,
	"if", 0,
	"int", 0,
	"long", 0,
	"register", 0,
	"return", 0,
	"short", 0,
	"signed", 0,
	"sizeof", 0,
	"static", 0,
	"struct", 0,
	"switch", 0,
	"typedef", 0,
	"union", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

/* Test string constant*/
char s[]= "AAA auto baba";
/* Test comment: volatile AAA auto baba */

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

int main(){
	struct key *p;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((p = binsearch(word, keytab, NKEYS)) != NULL)
				p->count++;
	for (p = keytab; p < keytab + NKEYS; p++)
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
}

struct key *binsearch(char *word, struct key *tab, int n){
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;
	
	while (low < high){
		mid = low + (high - low) / 2;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return NULL;
}

#define INCOMMENT  1
#define OUTCOMMENT 0

int getword(char *word, int lim){
	int c, getch(void), commentstate;
	void ungetch(int);
	char *w = word;
	commentstate = OUTCOMMENT;

	while (isspace(c = getch()) && c != '"' && c != '_')
		;
	if (c == '/' && commentstate == OUTCOMMENT)
		if (getch() == '*'){
			commentstate = INCOMMENT;
			while ((c = getch())!= EOF){
				if (c == '*')
					if (getch() == '/'){
						break;
						commentstate = OUTCOMMENT;	
					}
			}
		}
	if (c == '"')
		while ((c = getch())!= EOF && c != '"')
			;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c) && c != '"'){
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch()) && *w != '_'){
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c){  
	if (bufp >= BUFFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}