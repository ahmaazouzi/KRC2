#include "stdio.h"
#include <stdlib.h>
#include <string.h>

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);

int main(){
	install("a", "a");
	install("b", "b");
	install("c", "c");
	install("d", "d");
	
	undef("a");
	struct nlist *baba = lookup("a");

	if (baba)
		printf("%s\n", baba->defn);
	else
		printf("Element doesn't exist in table!!\n");
	return 0;
}

unsigned hash(char *s){
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;

}

char *strdupa(char *);

struct nlist *install(char *name, char *defn){
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL){
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdupa(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else 
		free((void *) np-> defn);
	if ((np->defn = strdupa(defn)) == NULL)
		return NULL;
	return np;
}

void undef(char *name){
	struct nlist *dp;
	dp = lookup(name);
	if (dp != NULL && dp->next != NULL)
		*dp = *dp->next;
	else 
		/* a little hack, but I can't do any better */
		dp->name = "s";
}

char *strdupa(char *s){
	char *p;

	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}



