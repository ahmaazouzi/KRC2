#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int linenums[MAXWORD];
	int index;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main(int argc, char const *argv[]){
	int c;
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while ((c = getword(word, MAXWORD)) != EOF){
		if (isalpha(word[0]))
			root = addtree(root, word);
	}
	treeprint(root);

	return 0;
}

int linenum = 1;
int getword(char *word, int lim){
	int c, getch(void), commentstate;
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		if (c == '\n')
			linenum++;
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
		p->word = strdup(w);
		p->index = 0;
		p->linenums[p->index] = linenum; 
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0 && p->linenums[p->index] == linenum)
		;
	else if ((cond = strcmp(w, p->word)) == 0 && p->linenums[p->index] != linenum){
		p->index++;
		p->linenums[p->index] = linenum;
	}
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p){
	if (p != NULL){
		treeprint(p->left);
		printf("%s: ", p->word);
		for (int i = 0; i <= p->index;){
			printf("%d ", p->linenums[i]);
			i++;
		}
		printf("\n");
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