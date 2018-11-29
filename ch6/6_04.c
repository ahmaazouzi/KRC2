#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int compare (const void *, const void *);

typedef struct{
		int count;
		char *word;
} wordcount;

wordcount wordlist[1000];
int indexo = 0;

int main(int argc, char const *argv[]){
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	qsort (wordlist, indexo, sizeof(wordcount), compare);
	for (int i = 0; i < indexo; ++i)
		printf("%d: %s\n", wordlist[i].count, wordlist[i].word);
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

int compare (const void * a, const void * b){
  wordcount *wordcountA = (wordcount *)a;
  wordcount *wordcountB = (wordcount *)b;
  return (wordcountA->count - wordcountB->count);
}

struct tnode *talloc(void);
char *strdupa(char *);

struct tnode *addtree(struct tnode *p, char *w){
	int cond;

	if (p == NULL){
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p){
	if (p != NULL){
		treeprint(p->left);
		wordlist[indexo].count = p->count;
		wordlist[indexo].word = strdupa(p->word);
		indexo++;
		treeprint(p->right);
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