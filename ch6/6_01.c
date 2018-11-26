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
	"int", 0,
	"sizeof", 0,
	"default", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

char s[]= "AAA auto baba";

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main(){
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}

int binsearch(char *word, struct key tab[], int n){
	int cond;
	int low, mid, high;

	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
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
		if (getch() == '*')
			while ((c = getch())!= EOF){
				if (c == '*')
					if (getch() == '/')
						break;	
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
