/* Skipped one requirement, namely, having the 6 limit as a command line input*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NKEYS (sizeof keytab / sizeof(struct key))
#define MAXWORD 100
#define MAXITEM 30
#define LIMITUS 6

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

struct tnode {
	char *word[MAXITEM];
	int index;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int binsearch(char *, struct key *, int);

int main(int argc, char const *argv[]){
	struct tnode *root;
	char word[MAXWORD];
	int n;

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) < 0)
				root = addtree(root, word);
	treeprint(root);
	return 0;
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

struct tnode *talloc(void);
char *strdupa(char *);

struct tnode *addtree(struct tnode *p, char *w){
	int cond;

	if (p == NULL){
		p = talloc();
		p->index = 0;
		p->word[p->index] = strdupa(w);
		p->left = p->right = NULL;
	} 
	else if ((p->word[p->index] != NULL) && (strcmp(w, p->word[p->index])) == 0)
		;
	else if ((p->word[p->index] != NULL) && ((cond = strncmp(p->word[p->index], w, LIMITUS)) == 0)){
		p->index++;
		p->word[p->index] = strdupa(w);
	}
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p){
	if (p != NULL){
		treeprint(p->right);
		for (int i = 0; i <= p->index;)
			printf("%s ", p->word[i++]);
		printf("\n");
		treeprint(p->left);
	}
}

#include <stdlib.h>

struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdupa(char *s){
	char *p;

	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

#define BUFFSIZE 100000

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